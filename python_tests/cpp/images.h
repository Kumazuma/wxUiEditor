///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/gdicmn.h>

#if wxCHECK_VERSION(3, 1, 6)
    #include <wx/bmpbndl.h>
#else
    #include <wx/image.h>
#endif

wxImage wxueImage(const unsigned char* data, size_t size_data);

namespace wxue_img
{
#if wxCHECK_VERSION(3, 1, 6)
    wxBitmapBundle bundle_wiztest_png();
    wxBitmapBundle bundle_wiztest2_png();
    wxBitmapBundle bundle_english_png();
    wxBitmapBundle bundle_french_png();
    wxBitmapBundle bundle_japanese_png();
#else

    wxImage image_english_png();
    wxImage image_french_png();
    wxImage image_japanese_png();
    wxImage image_wiztest2_png();
    wxImage image_wiztest_png();
#endif

    extern const unsigned char english_png[541];
    extern const unsigned char french_png[252];
    extern const unsigned char japanese_png[377];
    extern const unsigned char wiztest2_png[6797];
    extern const unsigned char wiztest_png[1239];
}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
