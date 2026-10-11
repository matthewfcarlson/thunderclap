// STATUS: equivalent (tools/equiv.py level 3: 156 inputs, branch coverage 22/22)
// pure3d::TextureBuilder::vfunc_2 @ 0x002ae6c0
struct PixelFormat {
    int count;
    char pad04[4];
    int bits;
    char pad0c[0x18 - 0xc];
    int shlR;
    int shlG;
    int shlB;
    int shlA;
    int shrR;
    int shrG;
    int shrB;
    int shrA;
    unsigned int FUN_002addb0(unsigned int color);
};

namespace pure3d {
class TextureBuilder {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(const unsigned char *src);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();

    int active;
    unsigned int *palette;
    PixelFormat *format;
    int stride;
    unsigned char *dest;
    int rows;
};
}

void pure3d::TextureBuilder::vfunc_2(const unsigned char *src)
{
    if (active == 0)
        return;
    int bits = format->bits;
    if (bits == 16) {
        unsigned short *out = (unsigned short *)dest;
        for (int i = 0; i < format->count; i++) {
            unsigned int px = palette[*src];
            PixelFormat *f = format;
            unsigned int v = ((px & 0xff) >> f->shrB) << f->shlB;
            v |= ((px & 0xff0000) >> f->shrR) << f->shlR;
            v |= ((px & 0xff000000) >> f->shrA) << f->shlA;
            v |= ((px & 0xff00) >> f->shrG) << f->shlG;
            *out++ = (unsigned short)v;
            src++;
        }
    } else if (bits == 32) {
        unsigned int *out = (unsigned int *)dest;
        for (int i = 0; i < format->count; i++) {
            *out = format->FUN_002addb0(palette[*src]);
            out++;
            src++;
        }
    } else if (bits == 8) {
        unsigned char *out = dest;
        for (int i = 0; i < format->count; i++)
            *out++ = *src++;
    } else if (bits == 4) {
        unsigned char *out = dest;
        for (int i = 0; i < format->count; i += 2) {
            *out++ = (unsigned char)((src[1] << 4) | (src[0] & 0xf));
            src += 2;
        }
    }
    dest = dest + stride;
    rows = rows + 1;
}
