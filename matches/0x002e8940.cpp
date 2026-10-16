#include "decls/data/engine/core.h"

extern "C" double __cdecl fabs(double);
extern int __cdecl _fwprintf(void* stream, const char* format, ...);

struct PngStruct_2e8940 {
    char pad00[0x60];
    unsigned int mode;
};

struct PngInfo_2e8940 {
    char pad00[8];
    unsigned int valid;
};

void __cdecl FUN_002e69a0(PngStruct_2e8940* p, const char* msg);
void __cdecl FUN_002e69d0(PngStruct_2e8940* p, const char* msg);
int __cdecl FUN_002e81e0(PngStruct_2e8940* p, unsigned int length);
void __cdecl FUN_002e7580(PngStruct_2e8940* p, unsigned char* buf, unsigned int n);
unsigned int __cdecl FUN_002e7500(const unsigned char* buf);
void __cdecl FUN_002eb180(PngStruct_2e8940* p, PngInfo_2e8940* info, double wx, double wy, double rx, double ry, double gx,
                          double gy, double bx, double by);

void FUN_002e8940(PngStruct_2e8940* png_ptr, PngInfo_2e8940* info_ptr, unsigned int length) {
    unsigned char buf[4];
    float white_x, white_y, red_x, red_y, green_x, green_y, blue_x, blue_y;

    if (!(png_ptr->mode & 1)) {
        FUN_002e69a0(png_ptr, "Missing IHDR before sBIT");
    } else if (png_ptr->mode & 4) {
        FUN_002e69d0(png_ptr, "Invalid cHRM after IDAT");
        FUN_002e81e0(png_ptr, length);
        return;
    } else if (png_ptr->mode & 2) {
        FUN_002e69d0(png_ptr, "Missing PLTE before cHRM");
    } else if (info_ptr != 0 && (info_ptr->valid & 4) && !(info_ptr->valid & 0x800)) {
        FUN_002e69d0(png_ptr, "Duplicate cHRM chunk");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    if (length != 0x20) {
        FUN_002e69d0(png_ptr, "Incorrect cHRM chunk length");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    FUN_002e7580(png_ptr, buf, 4);
    white_x = (float)FUN_002e7500(buf) * 1e-5f;
    FUN_002e7580(png_ptr, buf, 4);
    white_y = (float)FUN_002e7500(buf) * 1e-5f;
    if (white_x < 0 || white_x > 0.8 || white_y < 0 || white_y > 0.8 || white_y + white_x > 1.0) {
        FUN_002e69d0(png_ptr, "Invalid cHRM white point");
        FUN_002e81e0(png_ptr, 0x18);
        return;
    }

    FUN_002e7580(png_ptr, buf, 4);
    red_x = (float)FUN_002e7500(buf) * 1e-5f;
    FUN_002e7580(png_ptr, buf, 4);
    red_y = (float)FUN_002e7500(buf) * 1e-5f;
    if (red_x < 0 || red_x > 0.8 || red_y < 0 || red_y > 0.8 || red_y + red_x > 1.0) {
        FUN_002e69d0(png_ptr, "Invalid cHRM red point");
        FUN_002e81e0(png_ptr, 0x10);
        return;
    }

    FUN_002e7580(png_ptr, buf, 4);
    green_x = (float)FUN_002e7500(buf) * 1e-5f;
    FUN_002e7580(png_ptr, buf, 4);
    green_y = (float)FUN_002e7500(buf) * 1e-5f;
    if (green_x < 0 || green_x > 0.8 || green_y < 0 || green_y > 0.8 || green_y + green_x > 1.0) {
        FUN_002e69d0(png_ptr, "Invalid cHRM green point");
        FUN_002e81e0(png_ptr, 8);
        return;
    }

    FUN_002e7580(png_ptr, buf, 4);
    blue_x = (float)FUN_002e7500(buf) * 1e-5f;
    FUN_002e7580(png_ptr, buf, 4);
    blue_y = (float)FUN_002e7500(buf) * 1e-5f;
    if (blue_x < 0 || blue_x > 0.8f || blue_y < 0 || blue_y > 0.8f || blue_y + blue_x > 1.0f) {
        FUN_002e69d0(png_ptr, "Invalid cHRM blue point");
        FUN_002e81e0(png_ptr, 0);
        return;
    }

    if (FUN_002e81e0(png_ptr, 0))
        return;

    if (info_ptr->valid & 0x800) {
        if (fabs(white_x - 0.3127f) > 0.001 || fabs(white_y - 0.329f) > 0.001 ||
            fabs(red_x - 0.64f) > 0.001 || fabs(red_y - 0.33f) > 0.001 || fabs(green_x - 0.3f) > 0.001 ||
            fabs(green_y - 0.6f) > 0.001 || fabs(blue_x - 0.15f) > 0.001 || fabs(blue_y - 0.06f) > 0.001) {
            FUN_002e69d0(png_ptr, "Ignoring incorrect cHRM value when sRGB is also present");
            _fwprintf(((char*)&DAT_004d9a30), "wx=%f, wy=%f, rx=%f, ry=%f\n", white_x, white_y, red_x, red_y);
            _fwprintf(((char*)&DAT_004d9a30), "gx=%f, gy=%f, bx=%f, by=%f\n", green_x, green_y, blue_x, blue_y);
        }
        return;
    }
    FUN_002eb180(png_ptr, info_ptr, white_x, white_y, red_x, red_y, green_x, green_y, blue_x, blue_y);
}
