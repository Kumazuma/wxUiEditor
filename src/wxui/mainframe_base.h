///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/event.h>
#include <wx/frame.h>
#include <wx/gdicmn.h>
#include <wx/menu.h>
#include <wx/toolbar.h>

class MainFrameBase : public wxFrame
{
public:
    MainFrameBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString,
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1000, 1000),
        long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL, const wxString &name = wxFrameNameStr);

    enum
    {
        id_AlignBottom = wxID_HIGHEST + 1,
        id_AlignCenterHorizontal,
        id_AlignCenterVertical,
        id_AlignLeft,
        id_AlignRight,
        id_AlignTop,
        id_AppendCrafter,
        id_AppendFormBuilder,
        id_AppendGlade,
        id_AppendSmith,
        id_AppendWinRes,
        id_AppendXRC,
        id_BorderBottom,
        id_BorderLeft,
        id_BorderRight,
        id_BorderTop,
        id_Expand,
        id_GenerateCode,
        id_Magnify,
        id_MoveDown,
        id_MoveLeft,
        id_MoveRight,
        id_MoveUp,
        id_NewProject,
        id_OpenProject,
        id_OptionsDlg,
        id_PreviewForm,
        id_SaveProjectAs,
        id_ShowHidden,
        id_insert_widget
    };

protected:

    // Virtual event handlers -- override them in your derived class

    virtual void OnAbout(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAppendCrafter(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAppendFormBuilder(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAppendGlade(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAppendSmith(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAppendXRC(wxCommandEvent& event) { event.Skip(); }
    virtual void OnBrowseDocs(wxCommandEvent& event) { event.Skip(); }
    virtual void OnBrowsePython(wxCommandEvent& event) { event.Skip(); }
    virtual void OnChangeAlignment(wxCommandEvent& event) { event.Skip(); }
    virtual void OnChangeBorder(wxCommandEvent& event) { event.Skip(); }
    virtual void OnClose(wxCloseEvent& event) { event.Skip(); }
    virtual void OnCopy(wxCommandEvent& event) { event.Skip(); }
    virtual void OnCut(wxCommandEvent& event) { event.Skip(); }
    virtual void OnDelete(wxCommandEvent& event) { event.Skip(); }
    virtual void OnDuplicate(wxCommandEvent& event) { event.Skip(); }
    virtual void OnFindDialog(wxCommandEvent& event) { event.Skip(); }
    virtual void OnGenerateCode(wxCommandEvent& event) { event.Skip(); }
    virtual void OnImportWindowsResource(wxCommandEvent& event) { event.Skip(); }
    virtual void OnInsertWidget(wxCommandEvent& event) { event.Skip(); }
    virtual void OnOpenProject(wxCommandEvent& event) { event.Skip(); }
    virtual void OnOptionsDlg(wxCommandEvent& event) { event.Skip(); }
    virtual void OnPaste(wxCommandEvent& event) { event.Skip(); }
    virtual void OnPreviewXrc(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSaveAsProject(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSaveProject(wxCommandEvent& event) { event.Skip(); }
    virtual void OnToggleExpandLayout(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUpdateBrowseDocs(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnUpdateBrowsePython(wxUpdateUIEvent& event) { event.Skip(); }

    // Class member variables

    wxMenu* m_menuEdit;
    wxMenu* m_menuFile;
    wxMenu* m_menuHelp;
    wxMenu* m_menuTools;
    wxMenu* m_submenu_recent;
    wxMenuBar* m_menubar;
    wxToolBar* m_toolbar;
};

namespace wxue_img
{
    // Images declared in this class module:

    extern const unsigned char alignbottom_svg[658];
    extern const unsigned char aligncenter_svg[898];
    extern const unsigned char alignleft_svg[688];
    extern const unsigned char alignright_svg[690];
    extern const unsigned char aligntop_svg[688];
    extern const unsigned char alignvertcenter_svg[911];
    extern const unsigned char bottom_svg[585];
    extern const unsigned char expand_svg[819];
    extern const unsigned char generate_svg[780];
    extern const unsigned char hidden_svg[2111];
    extern const unsigned char left_svg[585];
    extern const unsigned char magnify_svg[3953];
    extern const unsigned char new_project_svg[921];
    extern const unsigned char right_svg[599];
    extern const unsigned char save_svg[717];
    extern const unsigned char top_svg[586];
    extern const unsigned char wxPython_1_5x_png[765];
    extern const unsigned char wxPython_2x_png[251];
    extern const unsigned char wxPython_png[399];
    extern const unsigned char xrc_preview_svg[469];
}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
