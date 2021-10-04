////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/gdicmn.h>
#include <wx/toolbar.h>

class NavToolbar : public wxToolBar
{
public:
    NavToolbar(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxTB_NODIVIDER);

    enum
    {
        id_NavCollExpand = wxID_HIGHEST + 1,
        id_NavCollapse,
        id_NavExpand,
        id_NavMoveDown,
        id_NavMoveLeft,
        id_NavMoveRight,
        id_NavMoveUp
    };

protected:
};

namespace wxue_img
{
    // Images declared in this class module:

    extern const unsigned char nav_coll_expand_png[332];
    extern const unsigned char nav_collapse_png[315];
    extern const unsigned char nav_expand_png[503];
}