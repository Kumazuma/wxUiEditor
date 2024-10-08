///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>

class EditCustomMockupBase : public wxDialog
{
public:
    EditCustomMockupBase() {}
    EditCustomMockupBase(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Mockup Widget Settings",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }
    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Mockup Widget Settings",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

    const wxString& get_WidgetType() const { return m_widget_type; }
    void set_WidgetType(const wxString& value) { m_widget_type = value; }
    int get_Width() const { return m_width; }
    void set_Width(int value) { m_width = value; }
    const wxString& get_Height() const { return m_height; }
    void set_Height(const wxString& value) { m_height = value; }

    wxString GetResults() { return m_result; }

protected:

    // Event handlers

    void OnInit(wxInitDialogEvent& event);
    void OnOK(wxCommandEvent& event);
    void OnSelect(wxCommandEvent& event);

    // Validator variables

    int m_width;
    wxString m_height;
    wxString m_widget_type;

    // Class member variables

    wxCheckBox* m_check_centered;
    wxChoice* m_widget_types;
    wxStaticBoxSizer* m_static_box;
    wxStaticText* m_static_text2;
    wxStaticText* m_static_text3;
    wxStaticText* m_static_text;
    wxTextCtrl* m_text_static;

    wxString m_result;
};

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
