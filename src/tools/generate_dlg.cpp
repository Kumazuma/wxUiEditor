///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/valgen.h>

#include "generate_dlg.h"

bool GenerateDlg::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* dlg_sizer = new wxBoxSizer(wxVERTICAL);

    m_staticText = new wxStaticText(this, wxID_ANY, "Choose the code you want to generate:");
    dlg_sizer->Add(m_staticText, wxSizerFlags().Border(wxALL));

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    m_checkBaseCode = new wxCheckBox(this, wxID_ANY, "C++ &Base");
    m_checkBaseCode->SetValidator(wxGenericValidator(&m_gen_base_code));
    box_sizer->Add(m_checkBaseCode, wxSizerFlags().Border(wxALL));

    m_checkDerived = new wxCheckBox(this, wxID_ANY, "C++ &Derived");
    m_checkDerived->SetValidator(wxGenericValidator(&m_gen_inherited_code));
    m_checkDerived->SetToolTip("Generate any derived files that don\'t currently exist");
    box_sizer->Add(m_checkDerived, wxSizerFlags().Border(wxALL));

    m_checkPython = new wxCheckBox(this, wxID_ANY, "&Python");
    m_checkPython->SetValidator(wxGenericValidator(&m_gen_python_code));
    box_sizer->Add(m_checkPython, wxSizerFlags().Border(wxALL));

    m_checkRuby = new wxCheckBox(this, wxID_ANY, "&Ruby");
    m_checkRuby->SetValidator(wxGenericValidator(&m_gen_ruby_code));
    box_sizer->Add(m_checkRuby, wxSizerFlags().Border(wxALL));

    m_checkXRC = new wxCheckBox(this, wxID_ANY, "&XRC");
    m_checkXRC->SetValidator(wxGenericValidator(&m_gen_xrc_code));
    box_sizer->Add(m_checkXRC, wxSizerFlags().Border(wxALL));

    dlg_sizer->Add(box_sizer, wxSizerFlags().Border(wxALL));

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    dlg_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(dlg_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &GenerateDlg::OnInit, this);

    return true;
}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************

/////////////////// Non-generated Copyright/License Info ////////////////////
// Purpose:   Dialog for choosing and generating specific language file(s)
// Author:    Ralph Walden
// Copyright: Copyright (c) 2021-2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/config.h>  // wxConfig base header

#include "gen_base.h"         // BaseCodeGenerator -- Generate Src and Hdr files for Base Class
#include "gen_results.h"      // Code generation file writing functions
#include "image_handler.h"    // ImageHandler class
#include "mainframe.h"        // MainFrame -- Main window frame
#include "node.h"             // Node class
#include "project_handler.h"  // ProjectHandler class

#include "../wxui/dlg_gen_results.h"

#if defined(INTERNAL_TESTING)
static bool gen_base_code = true;
static bool gen_derived_code = false;
static bool gen_python_code = false;
static bool gen_ruby_code = false;
static bool gen_xrc_code = false;
#endif

// This generates the base class files. For the derived class files, see OnGenInhertedClass()
// in generate/gen_codefiles.cpp
void MainFrame::OnGenerateCode(wxCommandEvent&)
{
    ProjectImages.UpdateEmbedNodes();
    bool code_generated = false;
    GenResults results;
    auto output_type = Project.getOutputType();

    // First check to see if there is only one code output type. If so, then we can skip the
    // dialog.

    if (output_type == OUTPUT_CPLUS)
    {
        GenerateCodeFiles(results);
        code_generated = true;
    }
    else if (output_type == OUTPUT_DERIVED)
    {
        GenInhertedClass(results);
        code_generated = true;
    }
    else if (output_type == OUTPUT_PYTHON)
    {
        GeneratePythonFiles(results);
        code_generated = true;
    }
    else if (output_type == OUTPUT_RUBY)
    {
        GenerateRubyFiles(results);
        code_generated = true;
    }
    else if (output_type == OUTPUT_XRC)
    {
        GenerateXrcFiles(results);
        code_generated = true;
    }

    if (!code_generated)
    {
        GenerateDlg dlg(this);
        if (dlg.ShowModal() == wxID_OK)
        {
            if (dlg.is_gen_base())
            {
                GenerateCodeFiles(results);
                code_generated = true;
#if defined(INTERNAL_TESTING)
                gen_base_code = true;
#endif
            }
            if (dlg.is_gen_inherited())
            {
                GenInhertedClass(results);
                code_generated = true;
#if defined(INTERNAL_TESTING)
                gen_derived_code = true;
#endif
            }
            if (dlg.is_gen_python())
            {
                GeneratePythonFiles(results);
                code_generated = true;
#if defined(INTERNAL_TESTING)
                gen_python_code = true;
#endif
            }
            if (dlg.is_gen_ruby())
            {
                GenerateRubyFiles(results);
                code_generated = true;
#if defined(INTERNAL_TESTING)
                gen_ruby_code = true;
#endif
            }
            if (dlg.is_gen_xrc())
            {
                GenerateXrcFiles(results);
                code_generated = true;
#if defined(INTERNAL_TESTING)
                gen_xrc_code = true;
#endif
            }

#if defined(INTERNAL_TESTING)
            auto* config = wxConfig::Get();
            config->SetPath("/preferences");
            config->Write("gen_base_code", gen_base_code);
            config->Write("gen_python_code", gen_python_code);
            config->Write("gen_ruby_code", gen_ruby_code);
            config->Write("gen_xrc_code", gen_xrc_code);
            config->SetPath("/");
#endif
        }
    }

    if (code_generated)
    {
        if ((results.updated_files.size() || results.msgs.size()))
        {
            GeneratedResultsDlg results_dlg;
            results_dlg.Create(this);
            for (auto& iter: results.updated_files)
            {
                iter.make_relative(Project.getProjectPath());
                results_dlg.m_lb_files->Append(iter);
            }

            if (results.updated_files.size() == 1)
                results.msgs.emplace_back("1 file was updated");
            else
                results.msgs.emplace_back() << results.updated_files.size() << " files were updated";

            for (auto& iter: results.msgs)
            {
                results_dlg.m_lb_info->Append(iter);
            }

            results_dlg.ShowModal();
        }
        else if (results.file_count)
        {
            tt_string msg;
            msg << '\n' << "All " << results.file_count << " generated files are current";
            wxMessageBox(msg, "Code Generation", wxOK, this);
        }
    }

    UpdateWakaTime();
}

void GenerateDlg::OnInit(wxInitDialogEvent& event)
{
#if defined(INTERNAL_TESTING)
    auto* config = wxConfig::Get();
    config->SetPath("/preferences");
    gen_base_code = config->ReadBool("gen_base_code", true);
    gen_python_code = config->ReadBool("gen_python_code", false);
    gen_ruby_code = config->ReadBool("gen_ruby_code", false);
    gen_xrc_code = config->ReadBool("gen_xrc_code", false);
    config->SetPath("/");
#endif

    auto output_type = Project.getOutputType();

    auto language = Project.getCodePreference(wxGetFrame().getSelectedNode());

    if (language == GEN_LANG_CPLUSPLUS)
    {
        m_gen_python_code = false;
        m_gen_ruby_code = false;
        m_gen_base_code = true;
        m_gen_xrc_code = false;

        if (not(output_type & OUTPUT_XRC))
        {
            m_checkXRC->Hide();
        }
        if (not(output_type & OUTPUT_PYTHON))
        {
            m_checkPython->Hide();
        }
        if (not(output_type & OUTPUT_RUBY))
        {
            m_checkRuby->Hide();
        }
    }
    else if (language == GEN_LANG_PYTHON)
    {
        m_gen_python_code = true;
        m_gen_ruby_code = false;
        m_gen_base_code = false;
        m_gen_xrc_code = false;

        if (not(output_type & OUTPUT_XRC))
        {
            m_checkXRC->Hide();
        }
        if (not(output_type & OUTPUT_CPLUS))
        {
            m_checkBaseCode->Hide();
        }
        if (not(output_type & OUTPUT_DERIVED))
        {
            m_checkDerived->Hide();
        }
        if (not(output_type & OUTPUT_RUBY))
        {
            m_checkRuby->Hide();
        }
    }
    else if (language == GEN_LANG_RUBY)
    {
        m_gen_python_code = false;
        m_gen_ruby_code = true;
        m_gen_base_code = false;
        m_gen_xrc_code = false;

        if (not(output_type & OUTPUT_XRC))
        {
            m_checkXRC->Hide();
        }
        if (not(output_type & OUTPUT_CPLUS))
        {
            m_checkBaseCode->Hide();
        }
        if (not(output_type & OUTPUT_DERIVED))
        {
            m_checkDerived->Hide();
        }
        if (not(output_type & OUTPUT_PYTHON))
        {
            m_checkPython->Hide();
        }
    }
    else if (language == GEN_LANG_XRC)
    {
        m_gen_python_code = false;
        m_gen_ruby_code = false;
        m_gen_base_code = false;
        m_gen_xrc_code = true;

        // For XRC preferred files, we still display all the other languages in case the user
        // is combining XRC with one of those languages.
    }
    else
    {
        m_gen_python_code = false;
        m_gen_ruby_code = false;
        m_gen_base_code = false;
        m_gen_xrc_code = false;

        // We get here if a new language preference has been added but we haven't updated this
        // dialog to support it yet.
    }
#if defined(INTERNAL_TESTING)
    if (output_type & OUTPUT_PYTHON)
    {
        m_gen_python_code = gen_python_code;
    }
    if (output_type & OUTPUT_RUBY)
    {
        m_gen_ruby_code = gen_ruby_code;
    }
    if (output_type & OUTPUT_CPLUS)
    {
        m_gen_base_code = gen_base_code;
    }
    if (output_type & OUTPUT_XRC)
    {
        m_gen_xrc_code = gen_xrc_code;
    }
#endif

    // Some checkboxes may be hidden at this point, so we need to resize the dialog to fit.

    // You have to reset minimum size to allow the window to shrink
    SetMinSize(wxSize(-1, -1));
    Fit();

    event.Skip();
}
