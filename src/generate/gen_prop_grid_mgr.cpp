/////////////////////////////////////////////////////////////////////////////
// Purpose:   wxPropertyGridManager and wxPropertyGridPage generators
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/event.h>             // Event classes
#include <wx/propgrid/manager.h>  // wxPropertyGridManager

#include "gen_common.h"       // GeneratorLibrary -- Generator classes
#include "mainframe.h"        // MainFrame -- Main window frame
#include "node.h"             // Node class
#include "project_handler.h"  // ProjectHandler class
#include "utils.h"            // Utility functions that work with properties
#include "utils_prop_grid.h"  // PropertyGrid utilities

#include "gen_prop_grid_mgr.h"

//////////////////////////////////////////  PropertyGridManagerGenerator  //////////////////////////////////////////

wxObject* PropertyGridManagerGenerator::CreateMockup(Node* node, wxObject* parent)
{
    auto widget = new wxPropertyGridManager(wxStaticCast(parent, wxWindow), wxID_ANY, DlgPoint(parent, node, prop_pos),
                                            DlgSize(parent, node, prop_size), GetStyleInt(node));

    if (node->HasValue(prop_extra_style))
    {
        widget->SetExtraStyle(node->prop_as_int(prop_extra_style));
    }

    widget->Bind(wxEVT_LEFT_DOWN, &BaseGenerator::OnLeftClick, this);
    widget->Bind(wxEVT_PG_PAGE_CHANGED, &PropertyGridManagerGenerator::OnPageChanged, this);

    return widget;
}

void PropertyGridManagerGenerator::OnPageChanged(wxPropertyGridEvent& event)
{
    if (auto pgm = wxDynamicCast(event.GetEventObject(), wxPropertyGridManager); pgm)
    {
        if (auto cur_page = pgm->GetCurrentPage(); cur_page)
        {
            auto page_index = cur_page->GetIndex();
            if (auto parent = GetMockup()->GetNode(event.GetEventObject()); parent)
            {
                for (size_t idx_page = 0; idx_page < parent->GetChildCount(); ++idx_page)
                {
                    if ((to_int) idx_page == page_index)
                    {
                        wxGetFrame().SelectNode(parent->GetChildNodePtrs()[idx_page].get());
                        break;
                    }
                }
            }
        }
    }
    event.Skip();
}

void PropertyGridManagerGenerator::AfterCreation(wxObject* wxobject, wxWindow* /* wxparent */, Node* node,
                                                 bool /* is_preview */)
{
    auto pgm = wxStaticCast(wxobject, wxPropertyGridManager);
    for (auto& child: node->GetChildNodePtrs())
    {
        if (child->isGen(gen_propGridPage))
        {
            auto* page = pgm->AddPage(child->prop_as_wxString(prop_label), child->prop_as_wxBitmapBundle(prop_bitmap));

            AfterCreationAddItems(page, child.get());
        }
    }

    if (node->GetChildCount())
    {
        pgm->SelectPage(0);
    }

    if (node->as_bool(prop_show_header))
    {
        pgm->ShowHeader();
    }
    pgm->Update();
}

bool PropertyGridManagerGenerator::ConstructionCode(Code& code)
{
    code.AddAuto().NodeName().CreateClass().ValidParentName().Comma().Add(prop_id);
    code.PosSizeFlags(false, "wxPGMAN_DEFAULT_STYLE");

    if (code.HasValue(prop_extra_style))
        code.Eol().NodeName().Function("SetExtraStyle(").Add(prop_extra_style).EndFunction();

    return true;
}

bool PropertyGridManagerGenerator::GetIncludes(Node* node, std::set<std::string>& set_src, std::set<std::string>& set_hdr)
{
    InsertGeneratorInclude(node, "#include <wx/propgrid/propgrid.h>", set_src, set_hdr);
    InsertGeneratorInclude(node, "#include <wx/propgrid/manager.h>", set_src, set_hdr);

    if (CheckAdvancePropertyInclude(node))
    {
        InsertGeneratorInclude(node, "#include <wx/propgrid/advprops.h>", set_src, set_hdr);
    }

    return true;
}
bool PropertyGridManagerGenerator::AfterChildrenCode(Code& code)
{
    if (code.IsTrue(prop_show_header))
    {
        code.NodeName().Function("ShowHeader(").AddTrue().EndFunction();
        return true;
    }
    else
    {
        return false;
    }
}

//////////////////////////////////////////  PropertyGridPageGenerator  //////////////////////////////////////////

bool PropertyGridPageGenerator::ConstructionCode(Code& code)
{
    if (code.HasValue(prop_bitmap))
    {
        auto is_bitmaps_list = BitmapList(code, prop_bitmap);
        code.AddAuto().NodeName().Str(" = ").ParentName().Function("AddPage(").QuotedString(prop_label);
        code.Comma();
        if (is_bitmaps_list)
        {
            if (code.is_cpp() && Project.value(prop_wxWidgets_version) == "3.1")
            {
                code.Eol() += "#if wxCHECK_VERSION(3, 1, 6)\n\t";
            }
            if (code.is_cpp())
                code += "wxBitmapBundle::FromBitmaps(bitmaps)";
            else
                code += "wx.BitmapBundle.FromBitmaps(bitmaps)";
            if (code.is_cpp() && Project.value(prop_wxWidgets_version) == "3.1")
            {
                code.Eol().Str("#else").Eol();
                tt_string bundle_code;
                GenerateBundleCode(code.node()->as_string(prop_bitmap), bundle_code);
                code.CheckLineLength(bundle_code.size());
                code += bundle_code;
                code.Eol() += "#endif";
            }
        }
        else
        {
            if (code.is_cpp())
            {
                tt_string bundle_code;
                GenerateBundleCode(code.node()->as_string(prop_bitmap), bundle_code);
                code.CheckLineLength(bundle_code.size());
                code += bundle_code;
            }
            else
            {
                PythonBundleCode(code, prop_bitmap);
            }
        }
        code.EndFunction();
    }
    else
    {
        code.AddAuto().NodeName().Str(" = ").ParentName().Function("AddPage(").QuotedString(prop_label).EndFunction();
    }

    return true;
}