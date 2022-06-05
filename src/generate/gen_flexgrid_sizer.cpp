/////////////////////////////////////////////////////////////////////////////
// Purpose:   wxFlexGridSizer generator
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/sizer.h>

#include "gen_common.h"  // GeneratorLibrary -- Generator classes
#include "node.h"        // Node class

#include "pugixml.hpp"  // xml read/write/create/process

#include "gen_flexgrid_sizer.h"

wxObject* FlexGridSizerGenerator::CreateMockup(Node* node, wxObject* /*parent*/)
{
    wxFlexGridSizer* sizer = new wxFlexGridSizer(node->prop_as_int(prop_rows), node->prop_as_int(prop_cols),
                                                 node->prop_as_int(prop_vgap), node->prop_as_int(prop_hgap));

    if (auto& growable = node->prop_as_string(prop_growablecols); growable.size())
    {
        auto num_cols = node->prop_as_int(prop_cols);
        ttlib::multiview values(growable, ',');
        for (auto& iter: values)
        {
            auto value = iter.atoi();
            if (value <= num_cols)
            {
                int proportion = 0;
                if (auto pos = iter.find(':'); ttlib::is_found(pos))
                {
                    proportion = ttlib::atoi(ttlib::find_nonspace(iter.data() + pos + 1));
                }
                sizer->AddGrowableCol(value, proportion);
            }
        }
    }
    if (auto& growable = node->prop_as_string(prop_growablerows); growable.size())
    {
        auto num_rows = node->prop_as_int(prop_rows);
        ttlib::multiview values(growable, ',');
        for (auto& iter: values)
        {
            auto value = iter.atoi();
            if (value <= num_rows)
            {
                int proportion = 0;
                if (auto pos = iter.find(':'); ttlib::is_found(pos))
                {
                    proportion = ttlib::atoi(ttlib::find_nonspace(iter.data() + pos + 1));
                }
                sizer->AddGrowableRow(value, proportion);
            }
        }
    }

    sizer->SetMinSize(node->prop_as_wxSize(prop_minimum_size));
    sizer->SetFlexibleDirection(node->prop_as_int(prop_flexible_direction));
    sizer->SetNonFlexibleGrowMode((wxFlexSizerGrowMode) node->prop_as_int(prop_non_flexible_grow_mode));

    return sizer;
}

std::optional<ttlib::cstr> FlexGridSizerGenerator::GenConstruction(Node* node)
{
    // The leading tab is in case we indent in a brace block later on
    ttlib::cstr code("\t");
    if (node->IsLocal())
        code << "auto ";

    code << node->get_node_name() << " = new wxFlexGridSizer(";
    auto rows = node->prop_as_int(prop_rows);
    auto cols = node->prop_as_int(prop_cols);
    auto vgap = node->prop_as_int(prop_vgap);
    auto hgap = node->prop_as_int(prop_hgap);

    // If rows is empty, only columns are supplied and wxFlexGridSizer will deduece the number of rows to use
    if (rows != 0)
    {
        code << rows << ", ";
    }
    code << cols << ", " << vgap << ", " << hgap << ");";

    // If growable settings are used, there can be a lot of lines of code generated. To make it a bit clearer, we put it in
    // braces
    bool isExpanded = false;

    if (auto& growable = node->prop_as_string(prop_growablecols); growable.size())
    {
        ttlib::multiview values(growable, ',');
        for (auto& iter: values)
        {
            auto val = iter.atoi();
            if (val <= cols)
            {
                if (!isExpanded)
                {
                    code << "\n\t{";
                    isExpanded = true;
                }
                int proportion = 0;
                if (auto pos = iter.find(':'); ttlib::is_found(pos))
                {
                    proportion = ttlib::atoi(ttlib::find_nonspace(iter.data() + pos + 1));
                }
                code << "\n\t    " << node->get_node_name() << "->AddGrowableCol(" << val;
                if (proportion > 0)
                    code << ", " << proportion;
                code << ");";
            }
        }
    }

    if (auto& growable = node->prop_as_string(prop_growablerows); growable.size())
    {
        ttlib::multiview values(growable, ',');
        for (auto& iter: values)
        {
            auto val = iter.atoi();
            if (val <= rows)
            {
                if (!isExpanded)
                {
                    code << "\n\t{";
                    isExpanded = true;
                }
                int proportion = 0;
                if (auto pos = iter.find(':'); ttlib::is_found(pos))
                {
                    proportion = ttlib::atoi(ttlib::find_nonspace(iter.data() + pos + 1));
                }
                code << "\n\t    " << node->get_node_name() << "->AddGrowableRow(" << val;
                if (proportion > 0)
                    code << ", " << proportion;
                code << ");";
            }
        }
    }

    auto& direction = node->prop_as_string(prop_flexible_direction);
    if (direction.empty() || direction.is_sameas("wxBOTH"))
    {
        if (isExpanded)
            code << "\n\t}";
        return code;
    }

    code << (isExpanded ? "\n\t    " : "\n\t") << node->get_node_name() << "->SetFlexibleDirection(" << direction << ");";

    auto& non_flex_growth = node->prop_as_string(prop_non_flexible_grow_mode);
    if (non_flex_growth.empty() || non_flex_growth.is_sameas("wxFLEX_GROWMODE_SPECIFIED"))
    {
        if (isExpanded)
            code << "\n\t}";
        return code;
    }
    code << (isExpanded ? "\n\t    " : "\n\t") << node->get_node_name() << "->SetNonFlexibleGrowMode(" << non_flex_growth
         << ");";

    if (isExpanded)
        code << "\n\t}";
    return code;
}

bool FlexGridSizerGenerator::GetIncludes(Node* node, std::set<std::string>& set_src, std::set<std::string>& set_hdr)
{
    InsertGeneratorInclude(node, "#include <wx/sizer.h>", set_src, set_hdr);
    return true;
}