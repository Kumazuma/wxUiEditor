/////////////////////////////////////////////////////////////////////////////
// Purpose:   wxListBox generator
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/listbox.h>  // wxListBox class interface

#include "gen_common.h"  // GeneratorLibrary -- Generator classes
#include "node.h"        // Node class
#include "utils.h"       // Utility functions that work with properties

#include "gen_listbox.h"

wxObject* ListBoxGenerator::CreateMockup(Node* node, wxObject* parent)
{
    auto widget =
        new wxListBox(wxStaticCast(parent, wxWindow), wxID_ANY, DlgPoint(parent, node, prop_pos),
                      DlgSize(parent, node, prop_size), 0, nullptr, node->prop_as_int(prop_type) | GetStyleInt(node));

    auto& items = node->prop_as_string(prop_contents);
    if (items.size())
    {
        auto array = ConvertToArrayString(items);
        for (auto& iter: array)
            widget->Append(wxString::FromUTF8(iter));

        if (node->prop_as_string(prop_selection_string).size())
        {
            widget->SetStringSelection(wxString::FromUTF8(node->prop_as_string(prop_selection_string)));
        }
        else
        {
            int sel = node->prop_as_int(prop_selection_int);
            if (sel > -1 && sel < (to_int) array.size())
                widget->SetSelection(sel);
        }
    }

    widget->Bind(wxEVT_LEFT_DOWN, &BaseGenerator::OnLeftClick, this);

    return widget;
}

std::optional<ttlib::cstr> ListBoxGenerator::GenConstruction(Node* node)
{
    ttlib::cstr code;
    if (node->IsLocal())
        code << "auto ";
    code << node->get_node_name() << GenerateNewAssignment(node);
    code << GetParentName(node) << ", " << node->prop_as_string(prop_id);

    if (node->prop_as_string(prop_window_name).empty() && node->prop_as_string(prop_type) == "wxLB_SINGLE" &&
        node->prop_as_string(prop_style).empty() && node->prop_as_string(prop_window_style).empty())
    {
        GeneratePosSizeFlags(node, code);
    }
    else
    {
        // We have to generate a default validator before the window name, which GeneratePosSizeFlags doesn't do. We don't
        // actually need that validator, since GenSettings will create it, but we have to supply something before the window
        // name.

        code << ", ";
        GenPos(node, code);
        code << ", ";
        GenSize(node, code);
        code << ", 0, nullptr, ";

        auto& type = node->prop_as_string(prop_type);
        auto& style = node->prop_as_string(prop_style);
        auto& win_style = node->prop_as_string(prop_window_style);

        if (type == "wxLB_SINGLE" && style.empty() && win_style.empty())
            code << "0";
        else
        {
            code << type;
            if (style.size())
            {
                code << '|' << style;
            }
            if (win_style.size())
            {
                code << '|' << win_style;
            }
        }

        if (node->prop_as_string(prop_window_name).size())
        {
            code << ", wxDefaultValidator, " << node->prop_as_string(prop_window_name);
        }
        code << ");";
    }

    return code;
}

std::optional<ttlib::cstr> ListBoxGenerator::GenSettings(Node* node, size_t& /* auto_indent */)
{
    ttlib::cstr code;

    if (node->prop_as_bool(prop_focus))
    {
        if (code.size())
            code << '\n';
        code << node->get_node_name() << "->SetFocus()";
    }

    if (node->prop_as_string(prop_contents).size())
    {
        auto array = ConvertToArrayString(node->prop_as_string(prop_contents));
        for (auto& iter: array)
        {
            if (code.size())
                code << "\n";
            code << node->get_node_name() << "->Append(" << GenerateQuotedString(iter) << ");";
        }

        if (node->prop_as_string(prop_selection_string).size())
        {
            code << "\n";
            code << node->get_node_name() << "->SetStringSelection("
                 << GenerateQuotedString(node->prop_as_string(prop_selection_string)) << ");";
        }
        else
        {
            int sel = node->prop_as_int(prop_selection_int);
            if (sel > -1 && sel < (to_int) array.size())
            {
                code << "\n";
                code << node->get_node_name() << "->SetSelection(" << node->prop_as_string(prop_selection_int) << ");";
            }
        }
    }

    return code;
}

std::optional<ttlib::cstr> ListBoxGenerator::GenEvents(NodeEvent* event, const std::string& class_name)
{
    return GenEventCode(event, class_name);
}

bool ListBoxGenerator::GetIncludes(Node* node, std::set<std::string>& set_src, std::set<std::string>& set_hdr)
{
    InsertGeneratorInclude(node, "#include <wx/listbox.h>", set_src, set_hdr);
    return true;
}