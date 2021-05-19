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
#include <wx/textctrl.h>

class NewFrameBase : public wxDialog
{
public:
    NewFrameBase(wxWindow* parent, wxWindowID id = wxID_ANY,
        const wxString& title = wxString::FromUTF8("New wxFrame window"),
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE);

protected:

    // Validator variables

    bool m_has_mainframe { true };
    bool m_has_menu { true };
    bool m_has_statusbar { true };
    bool m_has_toolbar { true };
    wxString m_base_class { wxString::FromUTF8("MyFrameBase") };

    // Class member variables

    wxCheckBox* m_checkBox_mainframe;
    wxCheckBox* m_checkBox_menu;
    wxCheckBox* m_checkBox_statusbar;
    wxCheckBox* m_checkBox_toolbar;
    wxTextCtrl* m_classname;

    // Virtual event handlers -- override them in your derived class

    virtual void OnCheckMainFrame(wxCommandEvent& event) { event.Skip(); }
};