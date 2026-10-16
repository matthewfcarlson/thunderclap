// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 43/46, incomplete)
// pure3d::TextureFont::vfunc_19 @ 0x002952e0
#include "decls/address.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/engine/pure3d/prop.h"
struct Glyph_2952e0 {
    float x;
    int f4;
    int f8;
    float advance;
    int f10;
    int page;
    char pad18[0x10];
};

struct Slot_2952e0 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void set(int what, int value);
};

struct Material_2952e0 {
    char pad[0x10];
    Slot_2952e0* slot;
};

struct Texture {
    char pad[0x10];
    int handle;
};

struct Device_2952e0 {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void begin(int arg);
    virtual void end(int arg);
};

struct Context {
    Device_2952e0* device;
    void FUN_00293d40(float a, float b, int c);
};

struct Gfx {
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void r24();
    virtual void r25();
    virtual void r26();
    virtual void r27();
    virtual void r28();
    virtual void r29();
    virtual int create(Slot_2952e0* slot, int a, int kind, int count, int b);
    virtual void destroy(int handle);
};


class TextureFont {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual float vfunc_18(const unsigned short* text);
    virtual void vfunc_19(const unsigned short* text, char flags);
    char pad04[0x14];
    float top;
    float bottom;
    char pad20[8];
    Material_2952e0* material;
    unsigned int pageCount;
    Texture** pages;
    int defaultGlyph;
    int glyphCount;
    Glyph_2952e0* glyphs;
    unsigned short* codes;
    void FUN_00294f10(int handle, Glyph_2952e0* g, float x, int f8);
};

void TextureFont::vfunc_19(const unsigned short* text, char flags)
{
    if (text == 0 || *text == 0 || *text == 0xa)
        return;

    (*(Context**)&DAT_0052c2ac)->device->begin(0);

    float scale;
    if (flags & 1)
        scale = vfunc_18(text) * -0.5f;
    else
        scale = 0.0f;
    (*(Context**)&DAT_0052c2ac)->FUN_00293d40(scale, bottom - top, 0);

    for (unsigned int i = 0; i < pageCount; i++)
        DAT_0052c318[i] = 0;

    int k = 0;
    unsigned short c = *text;
    while (c != 0 && c != 0xa) {
        int idx = defaultGlyph;
        int hi = glyphCount - 1;
        if (hi >= 0) {
            unsigned short* tbl = codes;
            int lo = 0;
            do {
                int mid = (hi + lo) >> 1;
                unsigned short cc = tbl[mid];
                if (c == cc) {
                    if (mid != 0 && mid != -1)
                        idx = mid;
                    break;
                }
                if (c > cc)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            } while (lo <= hi);
        }
        Glyph_2952e0* g = &glyphs[idx];
        ((Glyph_2952e0**)&DAT_0052c398)[k] = g;
        DAT_0052c318[g->page & 0x1f]++;
        k++;
        c = text[k];
    }

    int total = 0;
    for (unsigned int i = 0; i < pageCount; i++) {
        if (DAT_0052c318[i] > 0) {
            Texture* tex = pages[i];
            float x = 0.0f;
            material->slot->set(0x584554, tex ? tex->handle : 0);
            int handle = DAT_0052c2a8->create(material->slot, 0, 0x2021, DAT_0052c318[i] * 6, 0);
            for (int j = 0; j < k; j++) {
                Glyph_2952e0* g = ((Glyph_2952e0**)&DAT_0052c398)[j];
                if (g->page == (int)i)
                    FUN_00294f10(handle, g, x + g->x, g->f8);
                x = x + g->advance;
            }
            DAT_0052c2a8->destroy(handle);
            total = total + DAT_0052c318[i];
            if (total == k)
                break;
        }
    }
    (*(Context**)&DAT_0052c2ac)->device->end(0);
}
