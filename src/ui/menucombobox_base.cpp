////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>

#include "ribbon_ids.h"
#include "gen_enums.h"     // Enumerations for generators

using namespace GenEnum;

#include "menucombobox_base.h"

#include <wx/mstream.h>  // Memory stream classes

// Convert a data array into a wxImage
inline wxImage GetImageFromArray(const unsigned char* data, size_t size_data)
{
    wxMemoryInputStream strm(data, size_data);
    wxImage image;
    image.LoadFile(strm);
    return image;
};

namespace wxue_img
{
    extern const unsigned char bmp_combo_box_png[508];
    extern const unsigned char wxChoice_png[346];
    extern const unsigned char wxComboBox_png[249];
}

MenuCombobox::MenuCombobox() : wxMenu()
{
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    auto menu_item = Append(gen_wxComboBox, wxString::FromUTF8("Insert wxComboBox"));
    menu_item->SetBitmap(GetImageFromArray(wxue_img::wxComboBox_png, sizeof(wxue_img::wxComboBox_png)));

    auto menu_item_2 = Append(gen_wxChoice, wxString::FromUTF8("Insert wxChoice"));
    menu_item_2->SetBitmap(GetImageFromArray(wxue_img::wxChoice_png, sizeof(wxue_img::wxChoice_png)));

    auto menu_item_3 = Append(gen_wxBitmapComboBox, wxString::FromUTF8("Insert wxBitmapComboBox"));
    menu_item_3->SetBitmap(GetImageFromArray(wxue_img::bmp_combo_box_png, sizeof(wxue_img::bmp_combo_box_png)));
}

namespace wxue_img
{

    const unsigned char bmp_combo_box_png[508] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
    0,0,0,9,112,72,89,115,0,0,10,240,0,0,10,240,1,66,172,52,152,0,0,1,158,73,68,65,84,56,203,237,148,75,75,66,65,20,199,127,234,53,175,175,
    52,74,237,69,208,34,232,33,25,20,229,39,104,213,42,104,219,50,8,34,10,90,180,83,91,181,108,209,174,85,187,136,62,64,16,161,68,148,65,
    194,13,138,162,8,122,35,101,114,123,209,203,123,167,157,80,154,136,216,174,255,106,102,56,231,199,127,206,153,57,240,175,191,150,33,
    28,14,139,114,67,67,161,16,82,44,22,43,43,116,126,110,22,0,9,32,26,141,22,12,62,216,219,41,10,58,54,49,157,93,75,0,187,253,65,244,19,
    5,156,14,140,237,61,244,44,173,230,36,117,4,250,10,66,35,145,200,183,189,4,96,63,87,104,11,84,67,115,19,135,231,73,180,247,59,158,46,
    86,112,183,140,150,228,28,192,8,128,205,6,62,47,248,124,216,187,45,60,197,3,200,233,41,212,196,0,250,167,90,82,173,37,0,156,14,168,245,
    162,249,92,216,60,91,184,42,31,49,200,94,204,22,149,151,235,69,32,152,77,240,119,5,115,32,251,74,60,191,227,76,117,61,201,71,157,100,
    58,141,236,124,198,80,81,5,114,29,38,123,35,226,117,179,32,36,31,52,11,110,152,89,32,97,30,102,116,187,141,55,163,3,44,30,176,120,16,
    214,90,52,97,250,213,225,111,208,108,41,92,173,126,214,156,58,106,111,59,151,47,27,212,88,171,192,218,136,48,185,145,92,157,144,162,
    168,235,231,56,62,58,122,224,88,55,226,111,105,34,33,198,185,79,101,120,207,200,168,55,105,108,222,193,210,155,183,188,126,134,198,7,
    169,211,43,54,42,252,40,202,16,218,237,46,115,225,73,76,102,119,222,119,90,20,56,50,209,245,227,184,19,24,201,251,163,138,30,66,251,
    74,188,236,67,168,35,208,135,65,8,33,248,215,95,234,11,202,133,136,93,101,50,109,11,0,0,0,0,73,69,78,68,174,66,96,130
    };

    const unsigned char wxChoice_png[346] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
    0,0,0,9,112,72,89,115,0,0,10,240,0,0,10,240,1,66,172,52,152,0,0,0,252,73,68,65,84,56,203,237,147,49,78,195,64,16,69,223,238,206,58,161,
    224,42,52,73,69,207,37,16,5,5,34,220,194,162,228,8,225,10,92,37,55,224,20,17,20,196,145,61,20,187,177,199,27,167,76,231,47,173,70,30,
    173,158,191,255,151,97,214,172,82,110,181,122,213,107,128,5,96,183,219,94,188,112,200,243,152,103,7,180,192,195,122,195,219,231,150,
    16,210,126,17,211,140,2,31,143,155,4,190,4,92,152,231,110,226,78,240,3,212,123,136,1,36,24,199,125,46,206,1,160,170,61,252,104,160,109,
    49,113,9,26,5,188,75,208,73,176,170,114,200,47,248,209,113,244,173,5,50,56,253,254,122,31,237,238,95,106,0,188,253,116,231,28,203,236,
    186,51,199,66,155,124,78,121,222,61,213,35,104,40,29,47,141,203,219,12,47,29,54,197,78,2,84,2,235,231,154,155,92,72,21,13,248,23,248,
    83,237,221,150,121,54,101,182,89,149,36,120,148,161,184,83,161,2,16,115,73,123,213,179,130,166,160,173,1,135,48,64,109,121,87,251,65,
    102,205,58,215,63,115,35,70,125,252,77,219,229,0,0,0,0,73,69,78,68,174,66,96,130
    };

    const unsigned char wxComboBox_png[249] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
    0,0,0,9,112,72,89,115,0,0,10,240,0,0,10,240,1,66,172,52,152,0,0,0,155,73,68,65,84,56,203,99,96,24,5,180,6,140,13,13,13,255,169,109,104,
    125,125,61,3,203,129,3,7,168,106,232,148,9,29,12,12,12,12,12,44,12,12,12,12,251,247,239,199,171,248,234,197,147,68,25,154,83,80,1,103,
    179,16,235,18,109,125,115,188,242,141,141,141,40,124,22,82,188,73,172,203,25,24,24,24,152,104,149,42,88,72,213,160,99,96,129,33,118,
    229,194,9,202,93,140,110,8,54,67,201,14,10,152,97,184,12,165,40,140,241,25,58,56,34,15,61,157,82,197,96,228,28,69,116,33,116,229,194,
    9,170,23,66,218,250,230,12,140,255,255,255,255,207,48,10,104,9,0,42,152,44,128,9,231,17,89,0,0,0,0,73,69,78,68,174,66,96,130
    };

}