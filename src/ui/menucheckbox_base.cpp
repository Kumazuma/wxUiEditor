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

#include "menucheckbox_base.h"

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
    extern const unsigned char check3state_png[194];
    extern const unsigned char wxCheckBox_png[202];
}

MenuCheckbox::MenuCheckbox() : wxMenu()
{
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    auto menu_item = Append(gen_wxCheckBox, wxString::FromUTF8("Insert wxCheckBox"),
        wxString::FromUTF8("Insert a normal two-state checkbox"), wxITEM_NORMAL);
    menu_item->SetBitmap(GetImageFromArray(wxue_img::wxCheckBox_png, sizeof(wxue_img::wxCheckBox_png)));

    auto menu_item_2 = Append(gen_Check3State, wxString::FromUTF8("Insert 3-state wxCheckBox"),
        wxString::FromUTF8("Insert a 3-state checkbox"), wxITEM_NORMAL);
    menu_item_2->SetBitmap(GetImageFromArray(wxue_img::check3state_png, sizeof(wxue_img::check3state_png)));
}
