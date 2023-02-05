/////////////////////////////////////////////////////////////////////////////
// Purpose:   PropertyGrid utilities
// Author:    Ralph Walden
// Copyright: Copyright (c) 2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/propgrid/propgrid.h>  // wxPropertyGrid

#include "gen_enums.h"  // Enumerations for generators
#include "node.h"       // Node class

#include "utils_prop_grid.h"

void AfterCreationAddItems(wxPropertyGridInterface* pgi, Node* node)
{
    for (const auto& child: node->GetChildNodePtrs())
    {
        if (child->isGen(gen_propGridItem))
        {
            if (child->prop_as_string(prop_type) == "Category")
            {
                pgi->Append(new wxPropertyCategory(child->prop_as_wxString(prop_label), child->prop_as_wxString(prop_label)));
            }
            else
            {
                wxPGProperty* prop = wxDynamicCast(
                    wxCreateDynamicObject("wx" + (child->prop_as_string(prop_type)) + "Property"), wxPGProperty);
                if (prop)
                {
                    prop->SetLabel(child->as_wxString(prop_label));
                    prop->SetName(child->as_wxString(prop_label));
                    pgi->Append(prop);

                    if (child->HasValue(prop_help))
                    {
                        pgi->SetPropertyHelpString(prop, child->as_wxString(prop_help));
                    }
                }
            }
        }
    }
}
