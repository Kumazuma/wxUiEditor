////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/event.h>
#include <wx/frame.h>
#include <wx/gdicmn.h>
#include <wx/menu.h>
#include <wx/statusbr.h>

class MainFrameBase : public wxFrame
{
public:
    MainFrameBase(wxWindow* parent, wxWindowID id = wxID_ANY,
        const wxString& title = wxString::FromUTF8("wxUiTesting"),
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500, 300),
        long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL);

protected:

    // Class member variables

    wxStatusBar* m_statusBar;

    // Virtual event handlers -- override them in your derived class

    virtual void OnChoicebook(wxCommandEvent& event) { event.Skip(); }
    virtual void OnCommonDialog(wxCommandEvent& event) { event.Skip(); }
    virtual void OnListbook(wxCommandEvent& event) { event.Skip(); }
    virtual void OnNotebook(wxCommandEvent& event) { event.Skip(); }
    virtual void OnOtherCtrls(wxCommandEvent& event) { event.Skip(); }
    virtual void OnQuit(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRibbonDialog(wxCommandEvent& event) { event.Skip(); }
    virtual void OnToolbook(wxCommandEvent& event) { event.Skip(); }
    virtual void OnTreebook(wxCommandEvent& event) { event.Skip(); }
    virtual void OnWizard(wxCommandEvent& event) { event.Skip(); }
};
