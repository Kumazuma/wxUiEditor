////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/spinctrl.h>
#include <wx/textctrl.h>

class NewDialogBase : public wxDialog
{
public:
    NewDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY,
        const wxString& title = wxString::FromUTF8("New Dialog"),
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE);

protected:

    // Validator variables

    bool m_has_std_btns { true };
    bool m_has_tabs { false };
    int m_num_tabs { 3 };
    wxString m_base_class { wxString::FromUTF8("MyDialogBase") };
    wxString m_title;

    // Class member variables

    wxCheckBox* m_check_tabs;
    wxSpinCtrl* m_spinCtrlTabs;
    wxTextCtrl* m_textCtrl_title;

    // Virtual event handlers -- override them in your derived class

    virtual void OnInit(wxInitDialogEvent& event) { event.Skip(); }
};