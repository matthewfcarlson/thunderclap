// STATUS: equivalent (tools/equiv.py level 3: 185 inputs, branch coverage 26/26)
// pure3d::ImageFontLoader::vfunc_5 @ 0x002bf680
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
#include "decls/address.h"
#include "decls/data/engine/content.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }
void *thunk_FUN_0008d690(unsigned int size);
void *__cdecl FUN_0008d6d0(int size);
void __cdecl thunk_FUN_00267090(void *p);

struct Stream {
    void FUN_002647e0(void *dest, unsigned int count, unsigned int size, int flag);
};

struct Reader {
    char pad[0x284];
    Stream *stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

class Image {
public:
    virtual void AddRef();
    virtual void Release();
};

struct NameField_2bf680 {
    unsigned int keyLo;
    unsigned int keyHi;
    void FUN_0027b040(const char *name);
};

struct Glyph_2bf680 {
    unsigned short a, b, c, d, e, f;
    Glyph_2bf680() : a(0), b(0), c(0), d(0), e(0), f(0) {}
};

namespace content {
class ObjectLoader {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
};
}

namespace pure3d {
class ImageLoader : public content::ObjectLoader {
public:
    Image *FUN_002c0590(Reader *r, int tag);
};
}

struct Registry_2bf680 {
    content::ObjectLoader *FUN_00265310(int id);
};


class __declspec(novtable) ImageFontBase {
public:
    virtual void v0();
    char pad04[4];
    NameField_2bf680 name;
    void FUN_0027b070();
    ImageFontBase() { FUN_0027b070(); }
};

namespace pure3d {
class ImageFont : public ImageFontBase {
public:
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    Image *image;
    int f2c;
    unsigned int count;
    Glyph_2bf680 *glyphs;
    ImageFont() : f10(0), f14(0), f18(0), f1c(0), f20(0), f24(-1), image(0), f2c(0), count(0), glyphs(0) {}
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
};

class ImageFontLoader {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int vfunc_5(ImageFont **out, unsigned __int64 *outKey, Reader *r, void *ctx);
};
}

int pure3d::ImageFontLoader::vfunc_5(ImageFont **out, unsigned __int64 *outKey, Reader *r, void *ctx)
{
    struct Frame {
        union {
            int val;
            ImageLoader *loader;
        } uv;
        union {
            unsigned char n;
            unsigned short s0;
            int cell;
        } u0;
        union {
            unsigned short s;
            int cell;
        } c4;
        union {
            unsigned short s;
            int cell;
        } c2;
        union {
            unsigned short s;
            int cell;
        } c3;
        union {
            unsigned short s;
            int cell;
        } c1;
        union {
            int x1;
            int w4;
        } u1;
        int pad1c;
        int cnt;
        char name[0x100];
    } f;

    r->stream->FUN_002647e0(&f.u1.x1, 1, 4, 1);
    void *mem = thunk_FUN_0008d690(0x38);
    ImageFont *font = 0;
    if (mem)
        font = new (mem) ImageFont();
    r->stream->FUN_002647e0(&f.u0.n, 1, 1, 1);
    r->stream->FUN_002647e0(f.name, f.u0.n, 1, 1);
    f.name[f.u0.n] = 0;
    font->name.FUN_0027b040(f.name);
    r->stream->FUN_002647e0(&f.uv.val, 1, 4, 1);
    font->f10 = f.uv.val;
    r->stream->FUN_002647e0(&f.uv.val, 1, 4, 1);
    font->f14 = f.uv.val;
    r->stream->FUN_002647e0(&f.uv.val, 1, 4, 1);
    font->f18 = f.uv.val;
    r->stream->FUN_002647e0(&f.uv.val, 1, 4, 1);
    font->f1c = f.uv.val;

    f.uv.loader = dynamic_cast<ImageLoader *>((*(Registry_2bf680**)&DAT_00527c58)->FUN_00265310(0x19001));
    f.uv.loader->AddRef();
    while (r->FUN_002669f0()) {
        int id = r->FUN_00266a30();
        if (id == 0x19001) {
            Image *img = f.uv.loader->FUN_002c0590(r, 0x20);
            if (img)
                img->AddRef();
            if (font->image)
                font->image->Release();
            font->image = img;
        } else if (id == 0x22003) {
            if (font->glyphs)
                thunk_FUN_00267090((char *)font->glyphs - 4);
            r->stream->FUN_002647e0(&f.cnt, 1, 4, 1);
            unsigned int cnt = f.cnt;
            font->count = cnt;
            Glyph_2bf680 *arr = 0;
            int *blk = (int *)FUN_0008d6d0(cnt * 12 + 4);
            if (blk) {
                *blk = cnt;
                arr = (Glyph_2bf680 *)(blk + 1);
                for (int k = 0; k < (int)cnt; k++)
                    new (&arr[k]) Glyph_2bf680();
            }
            font->glyphs = arr;
            for (unsigned int i = 0; i < font->count; i++) {
                r->stream->FUN_002647e0(&f.u0.s0, 1, 2, 1);
                font->glyphs[i].a = f.u0.s0;
                r->stream->FUN_002647e0(&f.c1.s, 1, 2, 1);
                font->glyphs[i].b = f.c1.s;
                r->stream->FUN_002647e0(&f.c2.s, 1, 2, 1);
                font->glyphs[i].c = f.c2.s;
                r->stream->FUN_002647e0(&f.c3.s, 1, 2, 1);
                font->glyphs[i].d = f.c3.s;
                r->stream->FUN_002647e0(&f.c4.s, 1, 2, 1);
                font->glyphs[i].e = f.c4.s;
                r->stream->FUN_002647e0(&f.u1.w4, 1, 4, 1);
                font->glyphs[i].f = (unsigned short)f.u1.w4;
            }
        }
        r->FUN_00266be0();
    }
    f.uv.loader->Release();
    *out = font;
    unsigned __int64 key = FUN_002672f0(f.name, 0, 0);
    *outKey = key;
    return (int)key;
}
