// STATUS: equivalent (tools/equiv.py level 3: 3023 inputs, branch coverage 15/15)
// pure3d::ImageConverter::vfunc_6 @ 0x002ded30
#include "gen/pure3d.h"

struct Image_2ded30 {
    char pad[0x10];
    int width;
    int height;
};

struct Surface_2ded30 {
    int width;
    int height;
    char pad08[4];
    int rows;
    int format;
    char pad14[0x4c - 0x14];
    int stride;
    int cursor;
};

void __stdcall FUN_002de5a0(Image_2ded30 *img, Surface_2ded30 *s);
void __stdcall FUN_002de990(Image_2ded30 *img, Surface_2ded30 *s);
void __stdcall FUN_002de9c0(Image_2ded30 *img, Surface_2ded30 *s);

void pure3d::ImageConverter::vfunc_6(int __p0, int __p1, int row) { Image_2ded30 * img = (Image_2ded30 *)__p0; Surface_2ded30 * s = (Surface_2ded30 *)__p1;

    if (img->width != s->width || img->height != s->height || row >= s->rows)
        return;
    int saved = s->cursor;
    s->cursor = s->stride * row + saved;
    switch (s->format) {
    case 1:
    case 2:
    case 3:
    case 4:
        FUN_002de990(img, s);
        break;
    case 6:
        FUN_002de9c0(img, s);
        break;
    case 7:
        FUN_002de5a0(img, s);
        break;
    }
    s->cursor = saved;
}
