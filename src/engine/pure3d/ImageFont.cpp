// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002bf100..0x002bfad0 (kind game, layer engine, confidence high), dominant class pure3d::ImageFont
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/content.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fae89b52 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fae89b52 {} using namespace fn_fae89b52;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fae89b52 {
extern "C" char DAT_0042e9bc[];
typedef unsigned int u32_2bf100;
struct ImageFont : public Entity_0027b070 {
    volatile hulk_uintptr vt;
    char pad[12];
    volatile u32_2bf100 a, b, c, d, e;
    volatile int f;
    volatile u32_2bf100 g, h, i, j;
    ImageFont();
};
class Obj_2bf140 {
    char pad[0x10];

  public:
    unsigned int value;
};
struct X_2bf150 {
    char pad[0x14];
    unsigned value;
};
class C_2bf180 {
    char pad[0x20];

  public:
    unsigned int value;
};
} // namespace fn_fae89b52
namespace pure3d {
class Entity_2bf1e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x100];
};
}
namespace fn_fae89b52 {
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
extern void* hulk_at_0042e9bc[];
class Ref_2bf9f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Entity_2bf9f0 {
  public:
    void* vptr;
    void Fin_0027afd0();
};
class ImageFont_2bf9f0 : public Entity_2bf9f0 {
  public:
    char pad4[0x24];
    Ref_2bf9f0* m28;
    char pad2c[8];
    char* m34;
    ~ImageFont_2bf9f0() throw();
};
extern "C" char DAT_0042ea08[];
class ImageFontLoader {
  public:
    hulk_intptr vf;
    int a;
    int b;
    int c;
    int d;
    ImageFontLoader();
};


// 0x002bf100 FUN_002bf100 (54 B): matches/0x002bf100.cpp
// sym: ??0ImageFont@fn_fae89b52@@QAE@XZ
ImageFont::ImageFont() : Entity_0027b070() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    vt = ((hulk_intptr)DAT_0042e9bc);
    f = -1;
    g = 0;
    h = 0;
    i = 0;
    j = 0;
}


// 0x002bf140 pure3d::ImageFont::vfunc_5 (4 B): matches/0x002bf140.cpp
// sym: ?FUN_002bf140@fn_fae89b52@@YIIPAVObj_2bf140@1@@Z
// Same code shape as 0x00059a30 (propagated; names are from that function)
unsigned int __fastcall FUN_002bf140(Obj_2bf140* self) {
    return self->value;
}


// 0x002bf150 pure3d::ImageFont::vfunc_6 (4 B): matches/0x002bf150.cpp
// sym: ?target@fn_fae89b52@@YIIPAUX_2bf150@1@@Z
// Same code shape as 0x000862d0 (propagated; names are from that function)
unsigned __fastcall target(X_2bf150* self) {
    return self->value;
}


// 0x002bf160 pure3d::ImageFont::vfunc_7 (4 B): matches/0x002bf160.cpp
// sym: ?FUN_002bf160@fn_fae89b52@@YIHH@Z
// Same code shape as 0x00059a40 (propagated; names are from that function)
int __fastcall FUN_002bf160(hulk_intptr object) {
    return *(int*)(object + 0x18);
}

} // namespace fn_fae89b52

// 0x002bf170 pure3d::ImageFont::vfunc_8 (4 B): matches/0x002bf170.cpp
// sym: ?vfunc_8@ImageFont@pure3d@@UAEHXZ
// Same code shape as 0x00222300 (propagated; names are from that function)
int pure3d::ImageFont::vfunc_8() {
    return *(int*)((char*)this + 0x1c);
}

namespace fn_fae89b52 {

// 0x002bf180 pure3d::ImageFont::vfunc_12 (4 B): matches/0x002bf180.cpp
// sym: ?target@fn_fae89b52@@YIIPAVC_2bf180@1@@Z
// Same code shape as 0x00086280 (propagated; names are from that function)
unsigned int __fastcall target(C_2bf180* self) {
    return self->value;
}

} // namespace fn_fae89b52

// 0x002bf190 pure3d::ImageFont::vfunc_13 (18 B): matches/0x002bf190.cpp
// sym: ?vfunc_13@ImageFont@pure3d@@UAEXI@Z
void pure3d::ImageFont::vfunc_13(unsigned int x) {
    this->f_20 = (x > 0U ? 0xffffffffU : 0U) & x;
}


// 0x002bf1b0 pure3d::ImageFont::vfunc_14 (12 B): matches/0x002bf1b0.cpp [wrapped: conflict: pure3d::ImageFont]
// sym: ?vfunc_14@ImageFont@pure3d@fn_002bf1b0@@UAE?AUResult@23@XZ
namespace fn_002bf1b0 {
namespace pure3d {
struct Result {
    int n;
};
class ImageFont {
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
    virtual Result vfunc_14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    char pad[0x20];
    Result value;
};
Result ImageFont::vfunc_14() {
    return value;
}
} // namespace pure3d
} // namespace fn_002bf1b0


// 0x002bf1c0 pure3d::ImageFont::vfunc_15 (10 B): matches/0x002bf1c0.cpp
// sym: ?vfunc_15@ImageFont@pure3d@@UAEXH@Z
// Same code shape as 0x00083d60 (propagated; names are from that function)
void pure3d::ImageFont::vfunc_15(int v) {
    this->f_24 = v;
}


// 0x002bf1d0 pure3d::ImageFont::vfunc_3 (3 B): matches/0x002bf1d0.cpp
// sym: ?vfunc_3@ImageFont@pure3d@@UAE_NXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
bool pure3d::ImageFont::vfunc_3() {
    return (bool)(0);
}


// 0x002bf1e0 pure3d::ImageFont::vfunc_4 (3 B): matches/0x002bf1e0.cpp
// sym: ?vfunc_4@ImageFont@pure3d@@UAEPAXXZ
// Same code shape as 0x002a1130 (propagated; names are from that function)
 // namespace pure3d
void* pure3d::ImageFont::vfunc_4() {
    return (void*)(this);
}


// 0x002bf1f0 pure3d::ImageFont::vfunc_9 (56 B): equivalent/0x002bf1f0.cpp
// sym: ?vfunc_9@ImageFont@pure3d@@UAEHH@Z @aeebd2af2a9b @w4a682f8c3cbc
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// pure3d::ImageFont::vfunc_9 @ 0x002bf1f0
int pure3d::ImageFont::vfunc_9(hulk_intptr __p0) { const unsigned short * text = (const unsigned short *)__p0;
 if (!text) return 0; int result = this->f_18; int increment = (*(int *)&this->f_20) + result; while (*text) { if (*text == 10) result += increment; ++text; } return result; }


// 0x002bf230 pure3d::ImageFont::vfunc_10 (105 B): matches/0x002bf230.cpp [wrapped: conflict: ImageFont]
// sym: ?vfunc_10@ImageFont@fn_002bf230@@UAEIPBF@Z
namespace fn_002bf230 {
class ImageFont {
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
    virtual unsigned int vfunc_10(const short* s);
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual unsigned int Width(const short* s);
};
unsigned int ImageFont::vfunc_10(const short* s) {
    if (!s)
        return 0;
    unsigned int best = 0;
    int i = 0;
    if (*s != 0) {
        const short* p = s;
        do {
            unsigned int w = Width(p);
            if (w > best)
                best = w;
            short c = *p;
            while (c != 0 && c != 10) {
                i++;
                c = s[i];
            }
            p = s + i;
        } while (*p != 0);
    }
    return best;
}
} // namespace fn_002bf230


// 0x002bf2a0 pure3d::ImageFont::vfunc_11 (166 B): equivalent/0x002bf2a0.cpp [wrapped: conflict: pure3d::ImageFont]
// sym: ?vfunc_11@ImageFont@pure3d@fn_002bf2a0@@UAEXPAVCanvas@3@HHPBGI@Z @d22f9455b15d @w2d0b41e34549
namespace fn_002bf2a0 {
// STATUS: equivalent (tools/equiv.py level 3: 2781 inputs, branch coverage 18/18)
// pure3d::ImageFont::vfunc_11 @ 0x002bf2a0
class Canvas {
public:
    virtual void begin();
    virtual void end();
};

namespace pure3d {
class ImageFont {
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
    virtual unsigned int vfunc_9(const unsigned short *text);
    virtual void v10();
    virtual void vfunc_11(Canvas *canvas, int a2, int y, const unsigned short *text, unsigned int flags);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void vfunc_17(Canvas *canvas, int a2, int y, const unsigned short *text, unsigned int flags);
    char pad04[0x18 - 4];
    int f18;
    char pad1c[4];
    int f20;
};
}

void pure3d::ImageFont::vfunc_11(Canvas *canvas, int a2, int y, const unsigned short *text, unsigned int flags)
{
    if (text == 0)
        return;
    if (canvas == 0)
        return;
    canvas->begin();
    int lineHeight = f20 + f18;
    unsigned int half = 0;
    if (flags & 2)
        half = vfunc_9(text) >> 1;
    y -= half;
    int i = 0;
    if (text[0] != 0) {
        do {
            vfunc_17(canvas, a2, y, text, flags);
            while (text[i] != 0 && text[i] != 10)
                i++;
            if (text[i] == 10)
                i++;
            y += lineHeight;
        } while (text[i] != 0);
    }
    canvas->end();
}
} // namespace fn_002bf2a0


// 0x002bf350 FUN_002bf350 (143 B): equivalent/0x002bf350.cpp [wrapped: macros]
// sym: ?FUN_002bf350@KeyTable@fn_002bf350@@QAEHG@Z @beb4fce086d9 @wdfe46f33a85a
namespace fn_002bf350 {
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 18/18)
// FUN_002bf350 @ 0x002bf350
class KeyTable {
public:
    char pad00[0x30];
    int count;               // 0x30
    char *entries;           // 0x34, 12-byte records with the key at +0x0a
    int FUN_002bf350(unsigned short key);
};

// Binary search of the entry with the given key; -1 when absent.
int KeyTable::FUN_002bf350(unsigned short key) {
    char *base = entries;
    int hi = count - 1;
    int lo = 0;
    int mid = hi / 2;
#define KEY(i) (*(unsigned short *)(base + (i) * 12 + 0xa))
    if (KEY(0) == key)
        return 0;
    if (KEY(hi) == key)
        return hi;
    if (hi > 1) {
        do {
            if (!(KEY(lo) < key))
                break;
            if (!(KEY(hi) > key))
                break;
            unsigned short m = KEY(mid);
            if (m == key)
                return mid;
            if (m < key)
                lo = mid;
            else
                hi = mid;
            mid = lo + (hi - lo) / 2;
        } while (hi - lo > 1);
    }
    if (KEY(mid) == key)
        return mid;
    return -1;
#undef KEY
}
} // namespace fn_002bf350
#undef KEY


// 0x002bf490 pure3d::ImageFont::vfunc_16 (93 B): equivalent/0x002bf490.cpp [wrapped: conflict: pure3d::ImageFont]
// sym: ?vfunc_16@ImageFont@pure3d@fn_002bf490@@QAEHPBG@Z @18ecf42b896f @w3856dfb88fbd
namespace fn_002bf490 {
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 12/12)
// pure3d::ImageFont::vfunc_16 @ 0x002bf490
namespace pure3d { struct ImageFont { char pad0[0x2c]; int fallback; char pad30[4]; struct Glyph { char pad[8]; unsigned short width; char rest[2]; }; Glyph *glyphs; int FUN_002bf350(unsigned int); int vfunc_16(const unsigned short *text); }; int ImageFont::vfunc_16(const unsigned short *text) { if (!text || !*text || *text == 10) return 0; int total = 0; while (*text && *text != 10) { int index = FUN_002bf350(*text); if (index < 0) index = fallback; total += glyphs[index].width; ++text; } return total; } }
} // namespace fn_002bf490

namespace fn_fae89b52 {

// 0x002bf4f0 pure3d::ImageFont::vfunc_17 (388 B): equivalent/0x002bf4f0.cpp
// sym: ?FUN_002bf4f0@ImageFont_2bf4f0@fn_fae89b52@@QAEXPAUCanvas@2@HHPBGI@Z @cee9dedc6859 @w11235f86717a
// STATUS: equivalent (tools/equiv.py level 3: 4989 inputs, branch coverage 22/22)
// pure3d::ImageFont::vfunc_17 @ 0x002bf4f0
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

} // namespace fn_fae89b52

// 0x002bf680 pure3d::ImageFontLoader::vfunc_5 (875 B): equivalent/0x002bf680.cpp [wrapped: conflict: content::ObjectLoader; pure3d::ImageFont; pure3d::ImageFontLoader; pure3d::ImageLoader]
// sym: ?vfunc_5@ImageFontLoader@pure3d@fn_002bf680@@UAEHPAPAVImageFont@23@PA_KPAUReader@3@PAX@Z @b9c659ceac05 @w9c6e7ccdb11b
inline void *operator new(size_t, void *p) throw() { return p; }
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_002bf680 {
// STATUS: equivalent (tools/equiv.py level 3: 185 inputs, branch coverage 26/26)
// pure3d::ImageFontLoader::vfunc_5 @ 0x002bf680
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)


void *thunk_FUN_0008d690(unsigned int size);
extern "C" void *__cdecl FUN_0008d6d0(int size);
void __cdecl thunk_FUN_00267090(void *p);

struct Stream {
    void FUN_002647e0(void *dest, unsigned int count, unsigned int size, int flag);
};

struct Reader {
    char pad[0x284];
    Stream *stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
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


class __declspec(novtable) Entity_2bf680 {
public:
    virtual void v0_00038290();
    char pad04[4];
    NameField_2bf680 name;
    void FUN_0027b070();
    Entity_2bf680() { FUN_0027b070(); }
};

namespace pure3d {
class ImageFont : public Entity_2bf680 {
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
    virtual void v1_000382a0();
    virtual void* v2_002bfa70(char);
    virtual void v3_002bf1d0();
    virtual void v4_002bf1e0();
    virtual void v5_002bf140();
    virtual void v6_002bf150();
    virtual void v7_002bf160();
    virtual void v8_002bf170();
    virtual int v9_002bf1f0(hulk_intptr);
    virtual int v10_002bf230(void*);
    virtual void v11_002bf2a0(void*, int, int, void*, int);
    virtual void v12_002bf180();
    virtual void v13_002bf190(int);
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
    void *mem = thunk_FUN_0008d690((int)sizeof(ImageFont));
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
} // namespace fn_002bf680
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fae89b52 {

// 0x002bf9f0 FUN_002bf9f0 (55 B): matches/0x002bf9f0.cpp
// sym: ??1ImageFont_2bf9f0@fn_fae89b52@@QAE@XZ
ImageFont_2bf9f0::~ImageFont_2bf9f0() throw() {
    vptr = hulk_at_0042e9bc;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m34)
        operator delete[](m34 - 4);
    Fin_0027afd0();
}


// 0x002bfa30 FUN_002bfa30 (27 B): matches/0x002bfa30.cpp
// sym: ??0ImageFontLoader@fn_fae89b52@@QAE@XZ
ImageFontLoader::ImageFontLoader() {
    a = 0;
    b = 0x22002;
    c = 0;
    d = 0;
    vf = ((hulk_intptr)DAT_0042ea08);
}

} // namespace fn_fae89b52

// 0x002bfa50 pure3d::ImageFontLoader::vfunc_2 (31 B): matches/0x002bfa50.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002bfa50@@UAEPAV123@E@Z
namespace fn_002bfa50 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_2bfa50 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_2bfa50 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002bfa50


// 0x002bfa70 pure3d::ImageFont::vfunc_2 (76 B): matches/0x002bfa70.cpp [wrapped: conflict: ImageFont]
// sym: ?f2@ImageFont@fn_002bfa70@@QAEPAV12@E@Z
namespace fn_002bfa70 {
extern "C" void _ReadWriteBarrier();
extern char ImageFont_vftable[];
class Ref_2bfa70 {
  public:
    virtual void f0();
    virtual void f1();
};
class Entity_2bfa70 {
  public:
    void BaseDtor_0027afd0();
};
extern void __cdecl FUN_00263f30(void*);
extern void __cdecl thunk_FUN_00267090(void*);
class ImageFont : public Entity_2bfa70 {
  public:
    void* vptr;
    char p[0x24];
    Ref_2bfa70* m28;
    char p2c[8];
    char* m34;
    ImageFont* f2(unsigned char);
};
ImageFont* ImageFont::f2(unsigned char flags) {
    vptr = ((char*)DAT_0042e9bc);
    _ReadWriteBarrier();
    if (m28) {
        m28->f1();
        m28 = 0;
    }
    if (m34)
        thunk_FUN_00267090(m34 - 4);
    BaseDtor_0027afd0();
    if (flags & 1)
        FUN_00263f30(this);
    return this;
}
} // namespace fn_002bfa70

