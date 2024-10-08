///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/infobar.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>

class NewPanel : public wxDialog
{
public:
    NewPanel() {}
    NewPanel(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Create New Panel", const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }
    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Create New Panel", const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

protected:

    // Event handlers

    void OnInit(wxInitDialogEvent& event);

private:

    // Validator variables

    bool m_tab_traversal { true };
    wxString m_base_class { "MyPanelBase" };
    wxString m_sizer_type;

    // Class member variables

    wxBoxSizer* m_class_sizer;
    wxInfoBar* m_infoBar;
    wxTextCtrl* m_classname;

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// ***********************************************
    // ***********************************************

public:
    void WantFormVersion() { m_is_form = true; }
    void createNode();
    void VerifyClassName();

private:
    bool m_is_form { false };
    bool m_is_info_shown { false };
};
