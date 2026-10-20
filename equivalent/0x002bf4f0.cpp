// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 21/22, incomplete)
// pure3d::ImageFont::vfunc_17 @ 0x002bf4f0
struct Items_2bf4f0 {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual int vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual int vfn17(int index);
};
struct Canvas {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12(Items_2bf4f0 *src, int a, int b, int c, int d, int x, int y);
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15(int index, int item);
    char pad[0x14];
    int mode;
};
struct GlyphEntry {
    unsigned short w[6];
};
class ImageFont_2bf4f0 {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual int vfn16(const unsigned short *str);
    char pad0[0x14];
    int f18;
    int f1c;
    char pad1[8];
    Items_2bf4f0 *items;           // 0x28
    int defaultGlyph;       // 0x2c
    char pad2[4];
    GlyphEntry *glyphs;     // 0x34
    int FUN_002bf350(int ch);
    void FUN_002bf4f0(Canvas *canvas, int x, int y, const unsigned short *str, unsigned int flags);
};

void ImageFont_2bf4f0::FUN_002bf4f0(Canvas *canvas, int x, int y, const unsigned short *str, unsigned int flags)
{
    if (str == 0 || str[0] == 0 || str[0] == 0xa) return;
    if (canvas->mode == 8) {
        Items_2bf4f0 *it = items;
        int n = it->vfn14();
        for (int i = 0; i < n; i++) {
            canvas->vfn15(i, it->vfn17(i));
        }
    }
    int off = 0;
    if (flags & 1) {
        int len = vfn16(str);
        off = -(len / 2);
    }
    x += off;
    y += f18 - f1c;
    for (; *str != 0 && *str != 0xa; str++) {
        int idx = FUN_002bf350(*str);
        if (idx == 0) idx = defaultGlyph;
        canvas->vfn12(items, 0, 0, glyphs[idx].w[1], f18, x, y);
        x += glyphs[idx].w[1];
        canvas->vfn12(items, glyphs[idx].w[0], 0, glyphs[idx].w[3], f18, x, y);
        x += glyphs[idx].w[3];
        canvas->vfn12(items, 0, 0, glyphs[idx].w[2], f18, x, y);
        x += glyphs[idx].w[2];
    }
}
