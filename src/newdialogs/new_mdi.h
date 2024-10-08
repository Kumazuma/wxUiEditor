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

class NewMdiForm : public wxDialog
{
public:
    NewMdiForm() {}
    NewMdiForm(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "New MDI Application",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }
    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "New MDI Application",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

    const wxString& get_folder_name() const { return m_folder_name; }
    const wxString& get_app_class() const { return m_app_class; }
    bool is_aui_frame() const { return m_aui_frame; }
    bool is_doc_frame() const { return m_doc_frame; }
    const wxString& get_view_type() const { return m_view_type; }
    const wxString& get_view_class() const { return m_view_class; }
    const wxString& get_description() const { return m_description; }
    const wxString& get_doc_class() const { return m_doc_class; }
    const wxString& get_default_extension() const { return m_default_extension; }
    const wxString& get_filter() const { return m_filter; }

    void createNode();
    void VerifyClassName();

protected:

    // Event handlers

    void OnOK(wxCommandEvent& event);
    void OnViewType(wxCommandEvent& event);

private:

    // Validator variables

    bool m_aui_frame { true };
    bool m_doc_frame { false };
    wxString m_app_class { "DocViewAppBase" };
    wxString m_default_extension;
    wxString m_description;
    wxString m_doc_class { "DocumentTextCtrlBase" };
    wxString m_filter;
    wxString m_folder_name { "Mdi Application" };
    wxString m_view_class { "TextViewBase" };
    wxString m_view_type;

    // Class member variables

    wxInfoBar* m_infoBar;
};

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
