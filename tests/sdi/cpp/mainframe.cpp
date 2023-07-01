///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/accel.h>
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>

#include "images.h"

#include "mainframe.h"

#include <wx/mstream.h>  // memory stream classes

// Convert a data array into a wxImage
inline wxImage wxueImage(const unsigned char* data, size_t size_data)
{
    wxMemoryInputStream strm(data, size_data);
    wxImage image;
    image.LoadFile(strm);
    return image;
};

namespace wxue_img
{
    // Ainsi ça se passe.png
    extern const unsigned char Ainsi_c3_a_se_passe_png[148];
    extern const unsigned char debug_32_png[1701];
    extern const unsigned char english_png[541];
    extern const unsigned char wxNotebook_png[177];
    extern const unsigned char wxPython_1_5x_png[765];
    extern const unsigned char wxPython_2x_png[251];
    extern const unsigned char wxPython_png[399];
}

bool MainFrame::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{

    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    if (!wxFrame::Create(parent, id, title, pos, size, style, name))
        return false;

    splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D);
    splitter->SetSashGravity(0.0);
    splitter->SetMinimumPaneSize(150);
    splitter->SetMinSize(ConvertDialogToPixels(wxSize(200, 200)));

    propertyGridManager = new wxPropertyGridManager(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize,
        wxPG_AUTO_SORT|wxPG_BOLD_MODIFIED|wxPG_SPLITTER_AUTO_CENTER|wxPG_DESCRIPTION|wxPG_TOOLBAR|wxPG_NO_INTERNAL_BORDER);
    propertyGridManager->SetExtraStyle(wxPG_EX_MODE_BUTTONS);

    propertyGridPage = propertyGridManager->AddPage("Animal Page", wxue_img::bundle_wxPython_1_5x_png());

    propertyGridItem_7 = propertyGridPage->Append(new wxPropertyCategory("Pets", "Pets"));

    propertyGridItem_2 = propertyGridPage->Append(new wxStringProperty("dog", "Woof!"));

    propertyGridItem = propertyGridPage->Append(new wxStringProperty("cat", "Meow!"));

    propertyGridItem_5 = propertyGridPage->Append(new wxPropertyCategory("Big Animals", "Big Animals"));

    propertyGridItem_8 = propertyGridPage->Append(new wxStringProperty("horses", wxEmptyString));

    propertyGridPage_2 = propertyGridManager->AddPage("Number Page", wxue_img::bundle_english_png());

    propertyGridItem_6 = propertyGridPage_2->Append(new wxPropertyCategory("Numbers", "Numbers"));

    propertyGridItem_3 = propertyGridPage_2->Append(new wxIntProperty("1", wxEmptyString));

    propertyGridItem_4 = propertyGridPage_2->Append(new wxIntProperty("2", wxEmptyString));

    grid = new wxGrid(splitter, wxID_ANY);
    {
        grid->CreateGrid(5, 5);
        grid->EnableDragGridSize(false);
        grid->SetMargins(0, 0);
        grid->SetDefaultCellAlignment(wxALIGN_LEFT, wxALIGN_TOP);
        grid->SetColLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
        grid->SetColLabelSize(wxGRID_AUTOSIZE);
        grid->SetRowLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
        grid->SetRowLabelSize(wxGRID_AUTOSIZE);
    }
    splitter->SplitHorizontally(propertyGridManager, grid);

    auto* menubar = new wxMenuBar();

    menu = new wxMenu();
    auto* menuQuit = new wxMenuItem(menu, wxID_EXIT);
    {
        wxAcceleratorEntry entry;
        #if wxCHECK_VERSION(3, 1, 6)
        if (entry.FromString("ALT+X"))
            menuQuit->AddExtraAccel(entry);
        #endif
    }

    menuQuit->SetBitmap(
#if wxCHECK_VERSION(3, 1, 6)
        wxArtProvider::GetBitmapBundle(wxART_QUIT, wxART_MENU)
#else
        wxBitmap(wxArtProvider::GetBitmap(wxART_QUIT, wxART_MENU))
#endif
    );

    menu->Append(menuQuit);
    menubar->Append(menu, wxGetStockLabel(wxID_FILE));

    auto* menuDialogs = new wxMenu();
    auto* menu_item_3 = new wxMenuItem(menuDialogs, wxID_ANY, "MainTestDlg");
    menu_item_3->SetBitmap(
#if wxCHECK_VERSION(3, 1, 6)
        wxue_img::bundle_debug_32_png()
#else
        wxBitmap(wxueImage(wxue_img::debug_32_png, sizeof(wxue_img::debug_32_png)))
#endif
    );

    menuDialogs->Append(menu_item_3);
    auto* menu_item_4 = new wxMenuItem(menuDialogs, wxID_ANY, "BookTestDlg");
    menu_item_4->SetBitmap(
#if wxCHECK_VERSION(3, 1, 6)
        wxue_img::bundle_wxNotebook_png()
#else
        wxBitmap(wxueImage(wxue_img::wxNotebook_png, sizeof(wxue_img::wxNotebook_png)))
#endif
    );

    menuDialogs->Append(menu_item_4);
    auto* menu_item_2 = new wxMenuItem(menuDialogs, wxID_ANY, "PythonDlg");
    {
#if wxCHECK_VERSION(3, 1, 6)
        wxVector<wxBitmap> bitmaps;
        bitmaps.push_back(wxueImage(wxue_img::wxPython_png, sizeof(wxue_img::wxPython_png)));
        bitmaps.push_back(wxueImage(wxue_img::wxPython_1_5x_png, sizeof(wxue_img::wxPython_1_5x_png)));
        bitmaps.push_back(wxueImage(wxue_img::wxPython_2x_png, sizeof(wxue_img::wxPython_2x_png)));
#endif
        menu_item_2->SetBitmap(
#if wxCHECK_VERSION(3, 1, 6)
            wxBitmapBundle::FromBitmaps(bitmaps)
#else
            wxBitmap(wxueImage(wxue_img::wxPython_png, sizeof(wxue_img::wxPython_png)))
#endif
        );
    }

    menuDialogs->Append(menu_item_2);
    auto* menuItem_2 = new wxMenuItem(menuDialogs, wxID_ANY, "Common Controls...", "Common controls", wxITEM_NORMAL);
    menuItem_2->SetBitmap(
#if wxCHECK_VERSION(3, 1, 6)
        wxArtProvider::GetBitmapBundle(wxART_TIP, wxART_MENU)
#else
        wxBitmap(wxArtProvider::GetBitmap(wxART_TIP, wxART_MENU))
#endif
    );

    menuDialogs->Append(menuItem_2);
    auto* menuItem3 = new wxMenuItem(menuDialogs, wxID_ANY, "Wizard");
    menuDialogs->Append(menuItem3);
    menuDialogs->AppendSeparator();

    auto* submenu = new wxMenu();
    auto* menu_item_5 = new wxMenuItem(submenu, wxID_ANY, "DlgIssue_956");
    menu_item_5->SetBitmap(
#if wxCHECK_VERSION(3, 1, 6)
        wxue_img::bundle_debug_32_png()
#else
        wxBitmap(wxueImage(wxue_img::debug_32_png, sizeof(wxue_img::debug_32_png)))
#endif
    );

    submenu->Append(menu_item_5);
    auto* menu_item_6 = new wxMenuItem(submenu, wxID_ANY, "DlgIssue_960");
    menu_item_6->SetBitmap(
#if wxCHECK_VERSION(3, 1, 6)
        wxue_img::bundle_Ainsi_c3_a_se_passe_png()
#else
        wxBitmap(wxueImage(wxue_img::Ainsi_c3_a_se_passe_png, sizeof(wxue_img::Ainsi_c3_a_se_passe_png)))
#endif
    );

    submenu->Append(menu_item_6);
    auto* submenu_item = menuDialogs->AppendSubMenu(submenu, "Issue Dialogs");
    submenu_item->SetBitmap(
#if wxCHECK_VERSION(3, 1, 6)
        wxBitmapBundle::FromBitmap(wxueImage(wxue_img::wxDialog_png, sizeof(wxue_img::wxDialog_png)))
#else
        wxBitmap(wxueImage(wxue_img::wxDialog_png, sizeof(wxue_img::wxDialog_png)))
#endif
    );
    menubar->Append(menuDialogs, "&Dialogs");

    SetMenuBar(menubar);

    m_toolBar = CreateToolBar();

    auto* tool_dropdown = m_toolBar->AddTool(wxID_ANY, wxEmptyString,
#if wxCHECK_VERSION(3, 1, 6)
        wxArtProvider::GetBitmapBundle(wxART_EXECUTABLE_FILE, wxART_MENU)
#else
        wxBitmap(wxArtProvider::GetBitmap(wxART_EXECUTABLE_FILE, wxART_MENU))
#endif
    , wxEmptyString, wxITEM_DROPDOWN);
    auto* tool_dropdown_menu = new wxMenu;
    auto* menu_item = new wxMenuItem(tool_dropdown_menu, wxID_ANY, "Wizard...");
    menu_item->SetBitmap(
#if wxCHECK_VERSION(3, 1, 6)
        wxArtProvider::GetBitmapBundle(wxART_FIND, wxART_MENU)
#else
        wxBitmap(wxArtProvider::GetBitmap(wxART_FIND, wxART_MENU))
#endif
    );

    tool_dropdown_menu->Append(menu_item);
    tool_dropdown->SetDropdownMenu(tool_dropdown_menu);
    auto* tool_4 = m_toolBar->AddTool(wxID_ANY, "MainTestDlg",
#if wxCHECK_VERSION(3, 1, 6)
        wxue_img::bundle_debug_32_png()
#else
        wxBitmap(wxueImage(wxue_img::debug_32_png, sizeof(wxue_img::debug_32_png)))
#endif
    );

    auto* tool_5 = m_toolBar->AddTool(wxID_ANY, "BookTestDlg",
#if wxCHECK_VERSION(3, 1, 6)
        wxue_img::bundle_wxNotebook_png()
#else
        wxBitmap(wxueImage(wxue_img::wxNotebook_png, sizeof(wxue_img::wxNotebook_png)))
#endif
    );

    m_toolBar->AddSeparator();
    auto* tool_3 = m_toolBar->AddTool(wxID_ANY, "PythonDlg",
#if wxCHECK_VERSION(3, 1, 6)
        wxue_img::bundle_wxPython_1_5x_png()
#else
        wxBitmap(wxueImage(wxue_img::wxPython_1_5x_png, sizeof(wxue_img::wxPython_1_5x_png)))
#endif
    );

    m_toolBar->AddStretchableSpace();

    auto* tool_2 = m_toolBar->AddTool(wxID_ANY, "Common Controls...",
#if wxCHECK_VERSION(3, 1, 6)
        wxArtProvider::GetBitmapBundle(wxART_TIP, wxART_TOOLBAR)
#else
        wxBitmap(wxArtProvider::GetBitmap(wxART_TIP, wxART_TOOLBAR))
#endif
    );

    m_toolBar->Realize();

    m_statusBar = CreateStatusBar(2);
    {
        const int sb_field_widths[2] = {100, -1};
        m_statusBar->SetStatusWidths(2, sb_field_widths);
        const int sb_field_styles[2] = {100, -1};
        m_statusBar->SetStatusStyles(2, sb_field_styles);
    }


    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_MENU, &MainFrame::OnQuit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MainFrame::OnMainTestDlg, this, menu_item_3->GetId());
    Bind(wxEVT_MENU, &MainFrame::OnBookTestDlg, this, menu_item_4->GetId());
    Bind(wxEVT_MENU, &MainFrame::OnPythonDlg, this, menu_item_2->GetId());
    Bind(wxEVT_MENU, &MainFrame::OnCommonDialog, this, menuItem_2->GetId());
    Bind(wxEVT_MENU, &MainFrame::OnWizard, this, menuItem3->GetId());
    Bind(wxEVT_MENU, &MainFrame::OnDlgIssue_956, this, menu_item_5->GetId());
    Bind(wxEVT_MENU, &MainFrame::OnDlgIssue_960, this, menu_item_6->GetId());
    Bind(wxEVT_MENU, &MainFrame::OnWizard, this, menu_item->GetId());
    Bind(wxEVT_TOOL, &MainFrame::OnMainTestDlg, this, tool_4->GetId());
    Bind(wxEVT_TOOL, &MainFrame::OnBookTestDlg, this, tool_5->GetId());
    Bind(wxEVT_TOOL, &MainFrame::OnPythonDlg, this, tool_3->GetId());
    Bind(wxEVT_TOOL, &MainFrame::OnCommonDialog, this, tool_2->GetId());

    return true;
}

namespace wxue_img
{

    const unsigned char wxDialog_png[636] {
        137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,9,112,72,89,
        115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,2,46,73,68,65,84,56,203,181,149,65,107,19,81,16,199,127,187,217,
        46,137,169,105,83,208,131,232,197,107,192,226,169,7,191,128,199,30,122,211,66,17,5,253,6,94,68,68,16,252,0,
        94,42,42,222,122,216,67,234,41,7,233,61,34,74,48,17,4,111,193,92,114,73,147,26,105,179,111,198,195,190,221,
        108,146,110,155,82,58,176,204,123,59,239,205,155,249,207,127,222,131,11,18,39,30,188,218,237,168,0,168,130,
        2,42,168,234,196,7,160,98,255,99,215,136,34,170,44,184,138,43,35,158,111,222,114,0,92,128,23,59,191,180,176,
        0,225,247,109,138,190,67,216,120,75,49,159,195,252,120,143,52,63,112,185,232,195,207,143,148,22,125,150,74,
        121,150,75,5,202,165,2,229,165,34,43,229,69,252,205,199,56,247,158,80,44,149,120,250,238,155,2,120,0,234,122,
        236,127,217,6,136,116,101,43,153,83,217,162,111,199,253,191,163,140,124,35,233,255,51,140,140,51,54,61,219,
        249,173,215,87,252,76,176,156,105,15,199,138,114,116,20,210,238,236,243,250,209,109,199,3,200,231,224,206,
        213,206,185,11,214,117,111,114,56,56,32,129,34,142,39,168,214,216,88,191,155,232,88,42,171,107,167,58,109,
        53,234,92,242,29,188,28,99,199,216,138,167,157,6,213,90,242,239,79,103,190,108,68,5,35,66,194,10,75,158,115,
        75,14,16,35,227,136,213,158,18,71,152,214,0,189,110,123,46,199,161,8,146,142,88,84,207,132,103,214,154,208,
        72,18,164,155,198,56,222,16,235,160,90,75,190,105,167,211,107,34,144,73,58,52,130,34,106,102,90,141,58,149,
        213,53,90,141,250,12,28,233,234,103,173,17,219,238,99,40,82,24,199,27,78,163,86,6,47,16,77,21,207,24,51,97,
        94,190,114,99,102,75,92,192,147,108,32,152,208,164,89,49,75,183,207,141,201,123,161,185,23,176,117,127,227,
        68,155,24,65,109,144,238,52,221,230,145,188,111,47,26,135,164,211,162,204,199,29,225,29,183,177,215,109,211,
        220,11,200,178,125,173,5,89,247,80,34,94,86,84,113,218,103,181,77,56,238,15,134,180,135,215,80,149,136,210,
        26,245,189,147,162,145,216,58,68,201,198,175,140,157,171,146,115,29,134,135,3,122,7,102,242,170,126,240,242,
        147,138,68,79,141,138,32,106,181,49,72,124,160,229,188,138,36,205,16,209,75,163,23,77,148,221,55,15,29,46,
        82,254,3,136,174,81,14,10,69,149,111,0,0,0,0,73,69,78,68,174,66,96,130
    };

}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************

/////////////////// Non-generated Copyright/License Info ////////////////////
// Purpose:   Main Window
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    // true forces the frame to close
    Close(true);
}
