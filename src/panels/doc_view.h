///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/toolbar.h>

class CustomEvent;
class wxWebView;
class MainFrame;

class DocViewPanel : public wxPanel
{
public:
    DocViewPanel() {}
    DocViewPanel(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size =
        wxDefaultSize, long style = 0, const wxString &name = wxPanelNameStr)
    {
        Create(parent, id, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size =
        wxDefaultSize, long style = 0, const wxString &name = wxPanelNameStr);

    enum
    {
        ID_CPLUS = wxID_HIGHEST + 1,
        ID_PYTHON,
        ID_RUBY
    };

protected:

    // Event handlers

    void OnBack(wxCommandEvent& event);
    void OnCPlus(wxCommandEvent& event);
    void OnForward(wxCommandEvent& event);
    void OnHome(wxCommandEvent& event);
    void OnPython(wxCommandEvent& event);
    void OnRuby(wxCommandEvent& event);
    void OnUpdateBack(wxUpdateUIEvent& event);
    void OnUpdateForward(wxUpdateUIEvent& event);

private:

    // Class member variables

    wxBoxSizer* m_parent_sizer;
    wxToolBar* m_toolBar;

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
    // clang-format on
    // ***********************************************

public:
    DocViewPanel(wxWindow* parent, MainFrame* frame);

    void ActivatePage();

protected:
    void OnNodeSelected(CustomEvent& event);

private:
    MainFrame* m_mainframe { nullptr };
    wxWebView* m_webview { nullptr };

    int m_language { GEN_LANG_CPLUSPLUS };
};
