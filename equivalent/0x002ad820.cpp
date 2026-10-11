// STATUS: equivalent (tools/equiv.py level 3: 20 inputs, branch coverage 18/18)
// FUN_002ad820 @ 0x002ad820
struct PngInfo;
struct PngRead;

struct PngColor {
    unsigned char red, green, blue;
};

extern int __cdecl FUN_002d7ed0(PngRead *png, PngInfo *info);
extern int __cdecl FUN_002d7ef0(PngRead *png, PngInfo *info);
extern int __cdecl FUN_002d8550(PngRead *png, PngInfo *info, PngColor **palette, int *count);
extern unsigned __cdecl FUN_002d7e90(PngRead *png, PngInfo *info, unsigned flag);
extern int __cdecl FUN_002d8630(PngRead *png, PngInfo *info, unsigned char **trans, int *count, void *values);
extern int __cdecl FUN_002d7eb0(PngRead *png, PngInfo *info);
extern void *__cdecl FUN_00266e00(int count, int size);
extern void __cdecl FUN_002d7440(PngRead *png, unsigned char *row, unsigned char *display);
extern void __cdecl FUN_00267090(void *p);

class TextureSink {
public:
    virtual void vfunc_0(int width, int height, int format, int flags, unsigned *palette);
    virtual void vfunc_1();
    virtual void vfunc_2(unsigned char *scanline);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
};

struct Frame {
    int pad0c;
    int width;
    int height;
    int paletteCount;
    PngColor *paletteIn;
    unsigned char *trans;
    int transCount;
    unsigned palette[256];
};

// equiv-conv: FUN_002ad820 eax stack stack
void FUN_002ad820(PngInfo *info, PngRead *png, TextureSink *sink)
{
    Frame f;
    f.width = FUN_002d7ed0(png, info);
    f.height = FUN_002d7ef0(png, info);
    f.paletteCount = 0;
    FUN_002d8550(png, info, &f.paletteIn, &f.paletteCount);
    for (int i = 0; i < 256; i++)
        f.palette[i] = 0;
    for (int i = 0; i < f.paletteCount; i++) {
        PngColor *c = &f.paletteIn[i];
        f.palette[i] = 0xff000000 | (c->red << 16) | (c->green << 8) | c->blue;
    }
    if (FUN_002d7e90(png, info, 0x10)) {
        FUN_002d8630(png, info, &f.trans, &f.transCount, 0);
        for (int i = 0; i < f.transCount; i++)
            f.palette[i] = (f.trans[i] << 24) | (f.palette[i] & 0xffffff);
    }
    int width = f.width;
    int height = f.height;
    sink->vfunc_0(width, height, 4, 0, f.palette);
    unsigned char *row = (unsigned char *)FUN_00266e00(1, FUN_002d7eb0(png, info));
    unsigned char *line = (unsigned char *)FUN_00266e00(1, width);
    if (height > 0) {
        int half = width / 2;
        for (int y = height; y != 0; y--) {
            FUN_002d7440(png, row, 0);
            for (int x = 0; x < half; x++) {
                line[x * 2] = row[x] >> 4;
                line[x * 2 + 1] = row[x] & 0xf;
            }
            sink->vfunc_2(line);
        }
    }
    FUN_00267090(row);
    FUN_00267090(line);
    sink->vfunc_10();
}
