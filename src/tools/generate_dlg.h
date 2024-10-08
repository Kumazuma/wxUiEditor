///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/stattext.h>

class GenerateDlg : public wxDialog
{
public:
    GenerateDlg() {}
    GenerateDlg(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Generate Code", const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }
    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Generate Code", const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

    bool is_gen_base() const { return m_gen_base_code; }
    bool is_gen_inherited() const { return m_gen_inherited_code; }
    bool is_gen_python() const { return m_gen_python_code; }
    bool is_gen_ruby() const { return m_gen_ruby_code; }
    bool is_gen_xrc() const { return m_gen_xrc_code; }

protected:

    // Event handlers

    void OnInit(wxInitDialogEvent& event);

    // Validator variables

    bool m_gen_base_code { false };
    bool m_gen_inherited_code { false };
    bool m_gen_python_code { false };
    bool m_gen_ruby_code { false };
    bool m_gen_xrc_code { false };

    // Class member variables

    wxCheckBox* m_checkBaseCode;
    wxCheckBox* m_checkDerived;
    wxCheckBox* m_checkPython;
    wxCheckBox* m_checkRuby;
    wxCheckBox* m_checkXRC;
    wxStaticText* m_staticText;
};

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
