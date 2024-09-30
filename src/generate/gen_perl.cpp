/////////////////////////////////////////////////////////////////////////////
// Purpose:   Generate Perl code files
// Author:    Ralph Walden
// Copyright: Copyright (c) 2024 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <set>
#include <thread>
#include <unordered_set>

#include "mainframe.h"

#include "base_generator.h"   // BaseGenerator -- Base widget generator class
#include "code.h"             // Code -- Helper class for generating code
#include "file_codewriter.h"  // FileCodeWriter -- Classs to write code to disk
#include "gen_base.h"         // BaseCodeGenerator -- Generate Src and Hdr files for Base Class
#include "gen_common.h"       // Common component functions
#include "gen_results.h"      // Code generation file writing functions
#include "image_gen.h"        // Functions for generating embedded images
#include "image_handler.h"    // ImageHandler class
#include "node.h"             // Node class
#include "project_handler.h"  // ProjectHandler class
#include "utils.h"            // Miscellaneous utilities
#include "write_code.h"       // Write code to Scintilla or file

#include "pugixml.hpp"

using namespace code;
using namespace GenEnum;

static bool GeneratePerlForm(Node* form, GenResults& results, std::vector<tt_string>* pClassList = nullptr);

// clang-format off

inline constexpr const auto txt_PoundCmtBlock =
R"===(###############################################################################
# Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
#
# Do not edit any code above the "End of generated code" comment block.
# Any changes before that block will be lost if it is re-generated!
###############################################################################

)===";

// clang-format on

// This *must* be written on a line by itself with *no* indentation.
const char* perl_begin_cmt_block = "=pod";

// This *must* be written on a line by itself with *no* indentation.
const char* perl_end_cmt_block = "=cut";

void MainFrame::OnGenSinglePerl(wxCommandEvent& WXUNUSED(event))
{
    auto form = wxGetMainFrame()->getSelectedNode();
    if (form && !form->isForm())
    {
        form = form->getForm();
    }
    if (!form)
    {
        wxMessageBox("You must select a form before you can generate code.", "Code Generation");
        return;
    }

    GenResults results;
    GeneratePerlForm(form, results);

    tt_string msg;
    if (results.updated_files.size())
    {
        if (results.updated_files.size() == 1)
            msg << "1 file was updated";
        else
            msg << results.updated_files.size() << " files were updated";
        msg << '\n';
    }
    else
    {
        msg << "Generated file is current";
    }

    if (results.msgs.size())
    {
        for (auto& iter: results.msgs)
        {
            msg << '\n';
            msg << iter;
        }
    }

    wxMessageBox(msg, "Perl Code Generation", wxOK | wxICON_INFORMATION);
}

void BaseCodeGenerator::GeneratePerlClass(PANEL_PAGE panel_type)
{
    Code code(m_form_node, GEN_LANG_PERL);

    m_embedded_images.clear();
    SetImagesForm();
    std::set<std::string> img_include_set;

    std::thread thrd_get_events(&BaseCodeGenerator::CollectEventHandlers, this, m_form_node, std::ref(m_events));
    std::thread thrd_collect_img_headers(&BaseCodeGenerator::CollectImageHeaders, this, m_form_node,
                                         std::ref(img_include_set));

    // If the code files are being written to disk, then UpdateEmbedNodes() has already been called.
    if (panel_type != NOT_PANEL)
    {
        ProjectImages.UpdateEmbedNodes();
    }

    std::vector<Node*> forms;
    Project.CollectForms(forms);

    m_panel_type = panel_type;

    m_header->Clear();
    m_source->Clear();
    m_source->SetLastLineBlank();

#if !defined(_DEBUG)
    if (m_panel_type == NOT_PANEL)
#else
    if (m_panel_type != NOT_PANEL)
    {
        m_source->writeLine(
            "-- The following comment block is only displayed in a _DEBUG build, or when written to a file.\n\n");
    }
#endif  // _DEBUG
    {
        m_source->writeLine(txt_PoundCmtBlock);
    }

    if (Project.hasValue(prop_perl_project_preamble))
    {
        WritePropSourceCode(Project.getProjectNode(), prop_perl_project_preamble);
    }

    std::set<std::string> imports;

    auto GatherImportModules = [&](Node* node, auto&& GatherImportModules) -> void
    {
        if (auto* gen = node->getGenerator(); gen)
        {
            // gen->GetRubyImports(node, imports);
        }
        for (auto& child: node->getChildNodePtrs())
        {
            GatherImportModules(child.get(), GatherImportModules);
        }
    };
    GatherImportModules(m_form_node, GatherImportModules);

    if (m_form_node->isGen(gen_Images))
    {
        thrd_get_events.join();
        thrd_collect_img_headers.join();
        // GeneratePerlImagesForm();
        return;
    }

    m_set_enum_ids.clear();
    m_set_const_ids.clear();
    BaseCodeGenerator::CollectIDs(m_form_node, m_set_enum_ids, m_set_const_ids);

    int id_value = wxID_HIGHEST;
    for (auto& iter: m_set_enum_ids)
    {
        m_source->writeLine(tt_string() << '$' << iter << " = " << id_value++);
    }
    for (auto& iter: m_set_const_ids)
    {
        if (tt::contains(iter, " wx"))
        {
            tt_string id = '$' + iter;
            id.Replace(" wx", " wx.", true, tt::CASE::exact);
            m_source->writeLine(id);
        }
        else
        {
            m_source->writeLine('$' + iter);
        }
    }

    thrd_collect_img_headers.join();
    if (m_embedded_images.size())
    {
        m_source->writeLine();

        // TODO: [Randalphwa - 07-13-2023] Need to figure out how to handle images in wxPerl.
    }

    auto generator = m_form_node->getNodeDeclaration()->getGenerator();
    code.clear();
    if (generator->ConstructionCode(code))
    {
        m_source->writeLine(code);
        m_source->writeLine();
        m_source->Indent();
        m_source->Indent();

        id_value = wxID_HIGHEST;
        for (auto& iter: m_set_enum_ids)
        {
            m_source->writeLine(tt_string() << '@' << iter << id_value++);
        }

        if (id_value > 1)
        {
            // If at least one id was set, add a blank line
            m_source->writeLine();
        }
    }

    code.clear();
    if (generator->SettingsCode(code))
    {
        if (code.size())
        {
            m_source->writeLine(code);
            m_source->writeLine();
        }
    }

    if (m_form_node->getPropPtr(prop_window_extra_style))
    {
        code.clear();
        code.GenWindowSettings();
        if (code.size())
        {
            m_source->writeLine(code);
        }
    }

    m_source->SetLastLineBlank();
    for (const auto& child: m_form_node->getChildNodePtrs())
    {
        if (child->isGen(gen_wxContextMenuEvent))
            continue;
        GenConstruction(child.get());
    }

    code.clear();
    if (generator->AfterChildrenCode(code))
    {
        if (code.size())
        {
            m_source->writeLine();
            m_source->writeLine(code);
        }
    }

    // TODO: [Randalphwa - 07-13-2023] Need to figure out if wxPerl supports persistence

    // Delay calling join() for as long as possible to increase the chance that the thread will
    // have already completed.
    thrd_get_events.join();
    if (m_events.size())
    {
        m_source->writeLine();
        m_source->writeLine("# Event handlers");
        GenSrcEventBinding(m_form_node, m_events);

        m_source->writeLine("\tend", indent::none);
        m_source->SetLastLineBlank();

        m_source->ResetIndent();
        m_source->writeLine();
        m_source->Indent();
        // GenPerlEventHandlers(events);
    }
    else
    {
        m_source->ResetIndent();
        m_source->writeLine("\t}", indent::none);
    }

    if (m_form_node->isGen(gen_wxWizard))
    {
        code.clear();
        code.Eol().Str("# Add the following below the comment block to add a simple");
        code.Eol().Str("# Run() function to launch the wizard").Eol();
        m_source->writeLine(code);
    }

    // Make certain indentation is reset after all construction code is written
    m_source->ResetIndent();
    m_source->writeLine("}\n\n", indent::none);

    m_header->ResetIndent();

    // TODO: [Randalphwa - 07-13-2023] If we use embedded images, we need to write them out here.
#if 0
    std::sort(m_embedded_images.begin(), m_embedded_images.end(),
              [](const EmbeddedImage* a, const EmbeddedImage* b)
              {
                  return (a->array_name.compare(b->array_name) < 0);
              });
#endif
}

static bool GeneratePerlForm(Node* form, GenResults& results, std::vector<tt_string>* pClassList)
{
    auto [path, has_base_file] = Project.GetOutputPath(form, GEN_LANG_PERL);
    if (!has_base_file)
    {
#if !defined(_DEBUG)
        // For a lot of wxPerl testing of projects with multiple dialogs, there may only be a
        // few forms where wxPerl generation is being tested, so don't nag in Debug builds.
        // :-)
        results.msgs.emplace_back() << "No Perl filename specified for " << form->as_string(prop_class_name) << '\n';
#endif  // _DEBUG
        return false;
    }
    BaseCodeGenerator codegen(GEN_LANG_PERL, form);

    auto h_cw = std::make_unique<FileCodeWriter>(path);
    codegen.SetHdrWriteCode(h_cw.get());

    path.replace_extension(".pl");
    auto cpp_cw = std::make_unique<FileCodeWriter>(path);
    codegen.SetSrcWriteCode(cpp_cw.get());

    codegen.GeneratePerlClass();
    int flags = flag_no_ui;
    if (pClassList)
        flags |= flag_test_only;
    auto retval = cpp_cw->WriteFile(GEN_LANG_PERL, flags);

    if (auto warning_msgs = codegen.getWarnings(); warning_msgs.size())
    {
        for (auto& iter: warning_msgs)
        {
            results.msgs.emplace_back() << iter << '\n';
        }
    }

    if (retval > 0)
    {
        if (!pClassList)
        {
            results.updated_files.emplace_back(path);
        }
        else
        {
            if (form->isGen(gen_Images))
                pClassList->emplace_back(GenEnum::map_GenNames[gen_Images]);
            if (form->isGen(gen_Data))
                pClassList->emplace_back(GenEnum::map_GenNames[gen_Data]);
            else
                pClassList->emplace_back(form->as_string(prop_class_name));
            return true;
        }
    }

    else if (retval < 0)
    {
        results.msgs.emplace_back() << "Cannot create or write to the file " << path << '\n';
    }
    else  // retval == result::exists
    {
        ++results.file_count;
    }
    return true;
}
