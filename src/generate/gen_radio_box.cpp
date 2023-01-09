/////////////////////////////////////////////////////////////////////////////
// Purpose:   wxRadioBox generator
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/radiobox.h>  // wxRadioBox declaration

#include "gen_common.h"     // GeneratorLibrary -- Generator classes
#include "gen_xrc_utils.h"  // Common XRC generating functions
#include "node.h"           // Node class
#include "pugixml.hpp"      // xml read/write/create/process
#include "utils.h"          // Utility functions that work with properties

#include "gen_radio_box.h"

wxObject* RadioBoxGenerator::CreateMockup(Node* node, wxObject* parent)
{
    auto choices = node->prop_as_wxArrayString(prop_contents);
    if (!choices.Count())
    {
        choices.Add("at least one choice required");
    }

    auto widget = new wxRadioBox(wxStaticCast(parent, wxWindow), wxID_ANY, node->prop_as_wxString(prop_label),
                                 DlgPoint(parent, node, prop_pos), DlgSize(parent, node, prop_size), choices,
                                 node->prop_as_int(prop_majorDimension), GetStyleInt(node, "rb_"));

    if (int selection = node->prop_as_int(prop_selection); (to_size_t) selection < choices.Count())
    {
        widget->SetSelection(selection);
    }

    // This is the only event generated when a button within the box is clicked
    widget->Bind(wxEVT_RADIOBOX, &RadioBoxGenerator::OnRadioBox, this);

    return widget;
}

bool RadioBoxGenerator::OnPropertyChange(wxObject* widget, Node* node, NodeProperty* prop)
{
    if (prop->isProp(prop_label))
    {
        wxStaticCast(widget, wxRadioBox)->SetLabel(node->prop_as_wxString(prop_label));
        return true;
    }
    else if (prop->isProp(prop_selection))
    {
        wxStaticCast(widget, wxRadioBox)->SetSelection(prop->as_int());
        return true;
    }

    return false;
}

void RadioBoxGenerator::OnRadioBox(wxCommandEvent& event)
{
    if (auto window = wxStaticCast(event.GetEventObject(), wxRadioBox); window)
        GetMockup()->SelectNode(window);
}

bool RadioBoxGenerator::ConstructionCode(Code& code)
{
    auto array = ConvertToArrayString(code.node()->as_string(prop_contents));
    ttlib::cstr choice_name;
    if (code.is_cpp() && array.size())
    {
        code.OpenBrace();
        choice_name = (code.node()->get_node_name());
        if (choice_name.starts_with("m_"))
            choice_name.erase(0, 2);
        choice_name << "_choices";
        code.Str("wxString ") << choice_name << "[] = {";
        for (auto& iter: array)
        {
            code.Eol().Tab().QuotedString((iter)) += ",";
        }
        code.m_code.pop_back();  // remove the last comma
        code.Eol().Str("};").Eol();
    }

    code.Str((code.is_cpp() ? "// " : "# ")).Str("Trailing spaces added to avoid clipping").Eol();
    if (code.is_cpp() && code.is_local_var())
        code << "auto* ";
    code.NodeName().CreateClass();
    code.ValidParentName().Comma().as_string(prop_id).Comma().QuotedString(prop_label);
    code.Comma().Pos().Comma().WxSize().Comma();
    if (code.is_cpp())
    {
        code.itoa(array.size()).Comma();
        if (array.size())
            code.Str(choice_name);
        else
            code.Str("nullptr");
    }
    else
    {
        code.Str("[");
        for (auto& iter: array)
        {
            code.QuotedString((iter)) += ",";
        }
        code.m_code.pop_back();  // remove the last comma
        code << "]";
    }
    code.Comma().CheckLineLength(3).Str(prop_majorDimension);
    code.Comma().Style("rb_");
    if (code.HasValue(prop_window_name))
    {
        code.Comma().Str("wxDefaultValidator").Comma().QuotedString(prop_window_name);
    }
    code.EndFunction();
    code.CloseBrace();

    return true;
}

bool RadioBoxGenerator::SettingsCode(Code& code)
{
    if (auto sel = code.IntValue(prop_selection); sel > 0)
    {
        code.NodeName().Function("SetSelection(").Str(prop_selection).EndFunction();
    }

    return true;
}

bool RadioBoxGenerator::GetIncludes(Node* node, std::set<std::string>& set_src, std::set<std::string>& set_hdr)
{
    InsertGeneratorInclude(node, "#include <wx/radiobox.h>", set_src, set_hdr);
    if (node->prop_as_string(prop_validator_variable).size())
        InsertGeneratorInclude(node, "#include <wx/valgen.h>", set_src, set_hdr);

    return true;
}

// ../../wxSnapShot/src/xrc/xh_radbx.cpp
// ../../../wxWidgets/src/xrc/xh_radbx.cpp

int RadioBoxGenerator::GenXrcObject(Node* node, pugi::xml_node& object, size_t xrc_flags)
{
    auto result = node->GetParent()->IsSizer() ? BaseGenerator::xrc_sizer_item_created : BaseGenerator::xrc_updated;
    auto item = InitializeXrcObject(node, object);

    GenXrcObjectAttributes(node, item, "wxRadioBox");

    ADD_ITEM_PROP(prop_label, "label")
    ADD_ITEM_PROP(prop_majorDimension, "dimension")
    ADD_ITEM_PROP(prop_selection, "selection")

    if (node->HasValue(prop_contents))
    {
        auto content = item.append_child("content");
        auto array = ConvertToArrayString(node->prop_as_string(prop_contents));
        for (auto& iter: array)
        {
            content.append_child("item").text().set(iter);
        }
    }

    GenXrcPreStylePosSize(node, item, (node->value(prop_style) == "columns") ? "wxRA_HORIZONTAL" : "wxRA_VERTICAL");
    GenXrcWindowSettings(node, item);

    if (xrc_flags & xrc::add_comments)
    {
        GenXrcComments(node, item);
    }

    return result;
}

void RadioBoxGenerator::RequiredHandlers(Node* /* node */, std::set<std::string>& handlers)
{
    handlers.emplace("wxRadioBoxXmlHandler");
}
