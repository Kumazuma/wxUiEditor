#ifndef FRENCH_PNG_H
#define FRENCH_PNG_H

#include <wx/mstream.h>
#include <wx/image.h>
#include <wx/bitmap.h>

static const unsigned char french_png[] =
{
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 
	0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x13, 
	0x00, 0x00, 0x00, 0x0F, 0x08, 0x06, 0x00, 0x00, 0x00, 0x06, 
	0x44, 0xF4, 0x2C, 0x00, 0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 
	0x73, 0x00, 0x00, 0x0B, 0x13, 0x00, 0x00, 0x0B, 0x13, 0x01, 
	0x00, 0x9A, 0x9C, 0x18, 0x00, 0x00, 0x00, 0xB4, 0x49, 0x44, 
	0x41, 0x54, 0x38, 0xCB, 0xED, 0x94, 0xBD, 0x0E, 0xC1, 0x60, 
	0x18, 0x85, 0x9F, 0xB7, 0xFD, 0x5A, 0x83, 0x04, 0xF1, 0x13, 
	0x2B, 0x6B, 0x13, 0x71, 0x3B, 0x6E, 0xC1, 0x64, 0x34, 0xB8, 
	0x17, 0xA3, 0xC1, 0x75, 0xB8, 0x01, 0x8B, 0x49, 0x83, 0x44, 
	0xD2, 0x48, 0xD4, 0xF2, 0x21, 0x68, 0xF5, 0xB3, 0x18, 0x94, 
	0x18, 0x24, 0x5D, 0x24, 0x3D, 0xE3, 0x49, 0xDE, 0xE7, 0xBC, 
	0xCB, 0x39, 0xA2, 0xF5, 0xC9, 0x44, 0x71, 0x42, 0x92, 0x18, 
	0x5E, 0xE5, 0xBA, 0x36, 0xCA, 0x16, 0xDE, 0x65, 0xE2, 0x08, 
	0x13, 0x5D, 0x52, 0x9E, 0x58, 0x36, 0xA2, 0x1C, 0x54, 0x78, 
	0xB8, 0xB0, 0x5C, 0x69, 0x4E, 0xE7, 0x08, 0x0C, 0xF0, 0xBC, 
	0xEF, 0x78, 0x55, 0x1A, 0xB5, 0x02, 0xAF, 0x11, 0x02, 0xDC, 
	0xC3, 0x80, 0xDB, 0x62, 0xF6, 0x24, 0x1B, 0x10, 0xC1, 0x2E, 
	0x96, 0x70, 0xDA, 0x5D, 0xD4, 0x6A, 0x73, 0x64, 0x32, 0xF5, 
	0x09, 0x76, 0xE7, 0x54, 0xDA, 0xA0, 0xEF, 0x51, 0x2E, 0xD7, 
	0x3F, 0x3E, 0xBB, 0xFA, 0x73, 0xF4, 0x78, 0x98, 0xF2, 0x54, 
	0xB3, 0x45, 0xA5, 0x37, 0xC2, 0x22, 0x43, 0xE5, 0xB0, 0x1C, 
	0xF6, 0x77, 0x30, 0x59, 0x6F, 0x42, 0xF3, 0x53, 0x37, 0xF7, 
	0xDB, 0xAF, 0xDD, 0x94, 0x2C, 0x57, 0xE3, 0x01, 0x4F, 0x12, 
	0x54, 0xFA, 0x52, 0xAB, 0x90, 0x57, 0x00, 0x00, 0x00, 0x00, 
	0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82, 
};

wxBitmap& french_png_to_wx_bitmap()
{
	static wxMemoryInputStream memIStream( french_png, sizeof( french_png ) );
	static wxImage image( memIStream, wxBITMAP_TYPE_PNG );
	static wxBitmap bmp( image );
	return bmp;
}


#endif //FRENCH_PNG_H