///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/stattext.h>

#include <unordered_set>

#include "unused_gen_dlg.h"

#include "gen_enums.h"
#include "node.h"
#include "project_handler.h"

bool UnusedGenerators::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* dlg_sizer = new wxBoxSizer(wxVERTICAL);

    auto* staticText = new wxStaticText(this, wxID_ANY, "Unused generators in the entire project");
    staticText->Wrap(200);
    dlg_sizer->Add(staticText, wxSizerFlags().Border(wxALL));

    m_listbox = new wxListBox(this, wxID_ANY);
    m_listbox->SetMinSize(ConvertDialogToPixels(wxSize(120, 100)));
    dlg_sizer->Add(m_listbox, wxSizerFlags().Expand().Border(wxALL));

    auto* btn = new wxButton(this, wxID_ANY, "&Save...");
    dlg_sizer->Add(btn, wxSizerFlags().Border(wxALL));

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK);
    dlg_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(dlg_sizer);
    Centre(wxBOTH);

    // Event handlers
    btn->Bind(wxEVT_BUTTON, &UnusedGenerators::OnSave, this);
    Bind(wxEVT_INIT_DIALOG, &UnusedGenerators::OnInit, this);

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
// Author:    Ralph Walden
// Copyright: Copyright (c) 2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

void FindGenerators(Node* node, std::unordered_set<std::string>& used)
{
    if (node->isGen(gen_Images))
        return;
    if (!node->isGen(gen_folder) && !node->isGen(gen_sub_folder) && !node->isGen(gen_Images))
    {
        if (!used.contains(map_GenNames[node->gen_name()]))
        {
            used.emplace(map_GenNames[node->gen_name()]);
        }
    }
    if (node->GetChildCount())
    {
        for (auto& child: node->GetChildNodePtrs())
        {
            FindGenerators(child.get(), used);
        }
    }
}

// clang-format off

const auto gen_ignore_list = {

    gen_VerticalBoxSizer,
    gen_gbsizeritem,
    gen_name_array_size,
    gen_oldbookpage,
    gen_sizer_dimension,
    gen_sizeritem,
    gen_splitteritem,
    gen_unknown,

};

// clang-format on

void UnusedGenerators::OnInit(wxInitDialogEvent& event)
{
    std::unordered_set<std::string> used;

    for (const auto& child: Project.ProjectNode()->GetChildNodePtrs())
    {
        FindGenerators(child.get(), used);
    }

    bool skipping = true;
    for (auto& iter: rmap_GenNames)
    {
        bool ignored_gen = false;
        for (auto& ignore: gen_ignore_list)
        {
            if (ignore == iter.second)
            {
                ignored_gen = true;
                break;
            }
        }
        if (ignored_gen)
        {
            continue;
        }

        if (skipping)
        {
            if (iter.second != gen_BookPage)
            {
                continue;
            }
            else
            {
                skipping = false;
            }
        }

        if (!used.contains(iter.first.as_str()))
        {
            m_listbox->Append(iter.first.make_wxString());
        }
    }

    event.Skip();
}

#include <wx/filedlg.h>

void UnusedGenerators::OnSave(wxCommandEvent& WXUNUSED(event))
{
    auto filename = wxSaveFileSelector("Save unused", "txt", wxEmptyString, this);
    if (filename.empty())
        return;

    tt_string_vector file;
    for (unsigned int idx = 0; idx < m_listbox->GetCount(); ++idx)
    {
        file.emplace_back(m_listbox->GetString(idx).ToStdString());
    }

    if (auto result = file.WriteFile(filename.utf8_string()); !result)
    {
        wxMessageBox(wxString("Cannot create or write to the file ") << filename, "Save unused");
    }
}