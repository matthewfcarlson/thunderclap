// pure3d::RawImageHandler::vfunc_9 @ 0x002ddf10
#include "compat/ptr.h"
#include "gen/pure3d.h"

struct Stream_2ddf10 {
    void FUN_002647e0(void *dest, unsigned int count, unsigned int size, int flag);
};

struct Image_2ddf10 {
    virtual void SetFormat(unsigned int a, unsigned int b, unsigned int c, int d, int e);   // slot 0
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void *GetPixels();                                                              // slot 4
    virtual void *GetPalette();                                                             // slot 5
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void Finish();                                                                  // slot 10
};

struct RawHeader {
    unsigned int magic;
    unsigned int words[6];
};

namespace pure3d {

}
void pure3d::RawImageHandler::vfunc_9(hulk_intptr __p0, hulk_intptr __p1) { Stream_2ddf10 * stream = (Stream_2ddf10 *)__p0; Image_2ddf10 * image = (Image_2ddf10 *)__p1;

    RawHeader hdr;
    stream->FUN_002647e0(&hdr, 7, 4, 1);
    if (hdr.magic != 0x49443350)    // "P3DI"
        return;

    image->SetFormat(hdr.words[1], hdr.words[2], hdr.words[3], 0, 0);
    if (hdr.words[4] > 0) {
        void *palette = image->GetPalette();
        if (palette != 0)
            stream->FUN_002647e0(palette, hdr.words[4], 1, 1);
    }
    void *pixels = image->GetPixels();
    if (pixels != 0)
        stream->FUN_002647e0(pixels, hdr.words[5], 1, 1);
    image->Finish();
}
