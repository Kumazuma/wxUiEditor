////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>

#include "ui_images.h"

#include "ribbon_ids.h"
#include "gen_enums.h"     // Enumerations for generators

using namespace GenEnum;

#include "menubarbox_base.h"

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
    extern const unsigned char spin_ctrl_png[300];
    extern const unsigned char toolStretchable_png[578];
    extern const unsigned char tool_dropdown_png[447];
    extern const unsigned char toolspacer_png[459];
    extern const unsigned char wxComboBox_png[233];
}

MenuBarTools::MenuBarTools() : wxMenu()
{
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    auto* menu_item = Append(gen_tool, "Add Tool",
        "Insert a normal button tool", wxITEM_NORMAL);
    menu_item->SetBitmap(wxBitmapBundle::FromBitmap(wxueImage(wxue_img::tool_png, sizeof(wxue_img::tool_png))));

    auto* menu_item_2 = Append(gen_Check3State, "Add Dropdown",
        "Add Dropdown tool that you can add menu items to.", wxITEM_NORMAL);
    menu_item_2->SetBitmap(wxue_img::bundle_tool_dropdown_png());

    auto* menu_item_4 = Append(gen_toolSeparator, "Add Separator",
        "Add space to separate tools", wxITEM_NORMAL);
    menu_item_4->SetBitmap(wxue_img::bundle_toolspacer_png());

    auto* menu_item_5 = Append(gen_toolStretchable, "Add Stretchable Space",
        "Add space to separate tools", wxITEM_NORMAL);
    menu_item_5->SetBitmap(wxue_img::bundle_toolStretchable_png());

    AppendSeparator();

    auto* menu_item_3 = Append(gen_wxComboBox, "Add Combobox",
        "Add a wxComboBox control", wxITEM_NORMAL);
    menu_item_3->SetBitmap(wxue_img::bundle_wxComboBox_png());

    auto* menu_item_6 = Append(gen_wxSlider, "Add Slider",
        "Add a wxSlider control", wxITEM_NORMAL);
    menu_item_6->SetBitmap(wxBitmapBundle::FromBitmap(wxueImage(wxue_img::slider_png, sizeof(wxue_img::slider_png))));

    auto* menu_item_7 = Append(gen_wxSpinCtrl, "Add Spin Control",
        "Add a wxSpinCtrl control", wxITEM_NORMAL);
    menu_item_7->SetBitmap(wxue_img::bundle_spin_ctrl_png());
}

namespace wxue_img
{

    const unsigned char slider_png[248] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,9,112,72,89,115,0,0,11,
    19,0,0,11,19,1,0,154,156,24,0,0,0,170,73,68,65,84,56,203,99,96,24,5,67,22,48,98,19,44,204,79,249,15,99,247,79,156,195,
    72,21,131,11,243,83,254,127,141,61,15,231,115,47,54,36,203,112,22,108,130,109,178,75,25,190,127,251,193,240,241,211,103,
    134,185,12,11,201,10,10,38,92,18,255,25,254,83,20,198,44,12,12,12,12,187,119,174,133,155,178,109,219,118,12,69,200,242,
    196,0,87,247,96,70,150,221,59,215,254,55,52,208,102,192,103,48,178,60,49,96,247,206,181,255,89,92,221,131,25,177,186,
    8,41,186,206,95,184,202,64,178,139,97,12,140,164,246,31,85,33,213,34,143,129,145,145,242,200,67,7,85,143,163,17,233,152,
    193,112,112,229,188,81,48,10,48,1,0,147,201,58,106,65,245,61,80,0,0,0,0,73,69,78,68,174,66,96,130
    };

    const unsigned char tool_png[629] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,9,112,72,89,115,0,0,11,
    19,0,0,11,19,1,0,154,156,24,0,0,2,39,73,68,65,84,56,203,213,149,221,75,211,81,24,199,63,191,223,111,56,167,27,110,86,
    164,38,89,22,211,236,101,80,68,73,140,94,144,192,134,18,5,117,213,69,4,18,4,93,245,87,140,174,194,91,241,50,6,17,68,236,
    206,178,192,20,28,17,193,102,182,222,148,84,212,153,45,231,203,246,123,57,167,139,213,84,104,235,103,181,139,190,87,207,
    121,120,158,239,121,206,243,125,206,57,74,56,28,150,148,1,74,60,30,47,11,177,99,227,226,118,199,161,45,37,223,27,136,
    219,35,110,186,25,33,40,158,17,52,7,16,40,155,2,69,165,85,176,223,236,84,137,36,111,217,175,248,227,84,154,246,99,71,
    217,117,184,21,75,172,251,165,181,176,41,233,209,107,149,217,111,46,251,196,0,53,129,78,86,247,127,45,153,180,215,233,
    131,120,180,100,140,74,153,240,255,17,59,126,229,172,118,55,35,139,76,183,162,128,249,169,138,158,179,61,64,194,62,113,
    36,26,35,82,90,23,46,183,93,36,112,36,205,196,164,159,61,77,73,123,196,87,67,199,137,61,125,64,173,219,137,170,169,168,
    170,134,20,18,33,5,243,139,43,156,60,127,5,253,131,69,235,1,47,203,43,217,173,181,34,176,111,59,233,76,134,207,169,28,
    93,103,2,248,124,94,114,186,206,187,228,251,252,92,75,3,195,208,8,4,42,25,124,222,200,238,198,41,123,226,57,52,141,133,
    244,26,179,86,29,83,211,211,204,167,230,88,203,174,33,127,52,94,72,3,211,132,92,14,218,79,212,48,154,168,181,73,236,168,
    192,235,113,225,22,115,72,105,161,40,10,85,46,23,63,245,20,66,199,52,193,178,192,52,161,235,92,61,131,163,174,210,175,
    219,221,135,111,105,214,198,105,104,168,99,101,121,9,85,115,20,78,49,61,51,195,120,214,79,167,191,131,238,238,122,0,12,
    35,191,129,148,146,251,143,199,8,157,46,210,227,59,151,90,128,150,146,83,49,50,172,99,24,121,219,178,96,112,120,130,196,
    228,34,75,186,9,84,23,23,239,119,16,66,39,151,147,68,163,175,8,6,219,240,185,43,184,118,193,9,56,215,91,241,39,63,136,
    199,19,194,178,178,172,174,62,97,219,142,16,167,218,219,120,49,50,198,151,84,244,239,174,107,111,239,203,66,49,125,253,
    9,25,139,101,229,208,80,70,246,245,39,10,126,229,95,188,11,27,9,111,92,63,168,80,78,124,7,242,8,218,165,105,87,170,11,
    0,0,0,0,73,69,78,68,174,66,96,130
    };

}