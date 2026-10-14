// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 12/12)
// pure3d::ImageConverter::vfunc_6 @ 0x002ded30
struct Image {
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

void __stdcall FUN_002de5a0(Image *img, Surface_2ded30 *s);
void __stdcall FUN_002de990(Image *img, Surface_2ded30 *s);
void __stdcall FUN_002de9c0(Image *img, Surface_2ded30 *s);

class ImageConverter {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void vfunc_6(Image *img, Surface_2ded30 *s, int row);
    virtual void v7();
    virtual void v8();
};

void ImageConverter::vfunc_6(Image *img, Surface_2ded30 *s, int row)
{
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
