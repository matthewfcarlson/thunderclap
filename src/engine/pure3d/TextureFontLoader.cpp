// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00294b00..0x00295c40 (kind game, layer engine, confidence high), dominant class pure3d::TextureFontLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/loaders.h"
#include "decls/data/engine/content.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f54d8eff {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f54d8eff {} using namespace fn_f54d8eff;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f54d8eff {
char __cdecl FUN_00345b90(int c);
class Obj_294d70 {
  public:
    char pad[0x14];
    int a;
    int b;
    int c;
    int d;
    int e;
    void Init_002c3aa0();
    Obj_294d70* Target();
};
const float zero_294e50 = 0.0f;
struct Rect_294f10 {
    float l, t, r, b;
};
struct Source_294f10 {
    char pad0[0x18];
    Rect_294f10 uv;
};
struct VertexSink_294f10 {
    char pad0[8];
    float *pos;
    char pad0c[4];
    unsigned int *color;
    float *tex;
    void FUN_0008ef00();
};
class Quad_294f10 {
public:
    char pad0[0x18];
    float height;
    char pad1c[0x24 - 0x1c];
    unsigned int color;
    void Emit(VertexSink_294f10 *out, Source_294f10 *src, float x, float w);
};
class Base {
  public:
    virtual void f();
    char pad[12];
    Base();
};
class Font_2950c0 : public Base {
  public:
    int a, b, c, d, e;
    Font_2950c0() : Base(), a(0), b(0), c(0), d(0), e(0) {}
};
class TextureFont : public Font_2950c0 {
  public:
    virtual void m_vf1_000382a0();
    virtual void _m_vf2();
    virtual void m_vf3_0027afe0();
    virtual void m_vf4_0027aff0();
    virtual void m_vf5_00295100();
    virtual void m_vf6_00295110();
    virtual void m_vf7_00295120();
    virtual void m_vf8_00295130();
    virtual double m_vf9_00294e00(void*);
    virtual float vfunc_10(short*);
    virtual void m_vf11_002c3ad0(void*, int);
    virtual void m_vf12_00295140();
    virtual void m_vf13_00295150(float);
    virtual void* m_vf14_00295180(hulk_intptr);
    virtual void m_vf15_00295190(int);
    virtual void m_vf16_002951a0();
    virtual void m_vf17_00295220(void*);
    virtual float vfunc_18_00295270(short*);
    virtual void m_vf19_002952e0(void*, char);
    TextureFont();
    int x;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
    int m;
};
class Font_295150 {
    char pad[0x20];
};
extern const float zero_295150;
class Obj_295220 {
  public:
    virtual void First();
    virtual void Release();
};
class Other_295250 {
  public:
    int Fng_00294ed0(int);
};
extern "C" char DAT_0042d1b0[];
class TextureFontLoader : public HulkChunkHandler {
  public:
    TextureFontLoader();
};


// 0x00294b00 FUN_00294b00 (126 B): equivalent/0x00294b00.cpp
// sym: ?FUN_00294b00@fn_f54d8eff@@YAHPBD0H@Z @911e35209858 @w4a8064d6e764
// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 18/20, incomplete)
// FUN_00294b00 @ 0x00294b00
// Case-insensitive comparison of at most n characters (strnicmp-style): returns -1, 0 or 1.
int FUN_00294b00(const char* a, const char* b, int n)
{
    for (; *a != 0; a++, b++, n--) {
        if (*b == 0 || n == 0)
            return (*b == 0) ? 1 : 0;
        char ca = FUN_00345b90(*a);
        char cb = FUN_00345b90(*b);
        if (ca > cb)
            return 1;
        if (ca < cb)
            return -1;
    }
    return (*b != 0) ? -1 : 0;
}


// 0x00294b80 FUN_00294b80 (25 B): matches/0x00294b80.cpp
// sym: _FUN_00294b80
extern "C" int FUN_00294b80(const unsigned short* p) {
    int n = 0;
    if (p)
        while (p[n] != 0)
            ++n;
    return n;
}


// 0x00294c70 FUN_00294c70 (73 B): matches/0x00294c70.cpp
// sym: _FUN_00294c70
extern "C" int FUN_00294c70(char* src, unsigned short* dst, int limit) {
    int i;
    if (dst == 0 || src == 0)
        return 0;
    unsigned char c = (unsigned char)src[0];
    i = 0;
    if (c != 0) {
        int m = limit - 1;
        do {
            if (i >= m)
                break;
            unsigned int v = (char)src[i];
            dst[i] = (unsigned short)(0xff & v);
            c = (unsigned char)src[i + 1];
            ++i;
        } while (c != 0);
    }
    dst[i] = 0;
    return i;
}


// 0x00294d70 FUN_00294d70 (34 B): matches/0x00294d70.cpp
// sym: ?Target@Obj_294d70@fn_f54d8eff@@QAEPAV12@XZ
Obj_294d70* Obj_294d70::Target() {
    Init_002c3aa0();
    a = 0;
    b = 0;
    c = 0;
    d = 0x3f800000;
    e = 0x3f800000;
    return this;
}

} // namespace fn_f54d8eff

// 0x00294db0 FUN_00294db0 (18 B): matches/0x00294db0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Font@pure3d@fn_00294db0@@QAE@XZ
namespace fn_00294db0 {
namespace pure3d {
class Base_294db0 {
  public:
    Base_294db0();
    virtual void V();
};
class Font : public Base_294db0 {
  public:
    Font();
    virtual void V();
};
void Font::V() {}
Font::Font() {}
} // namespace pure3d
} // namespace fn_00294db0


// 0x00294de0 pure3d::Font::vfunc_2 (30 B): matches/0x00294de0.cpp
// sym: ??_GFont@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::Font::~Font() {}


// 0x00294e00 pure3d::TextureFont::vfunc_9 (73 B): equivalent/0x00294e00.cpp [wrapped: conflict: pure3d::TextureFont]
// sym: ?vfunc_9@TextureFont@pure3d@fn_00294e00@@QAEMPBG@Z @9a086b4d24c7 @w22d4b7ef2fc9
namespace fn_00294e00 {
// STATUS: equivalent (tools/equiv.py level 3: 18355 inputs, branch coverage 8/8)
// pure3d::TextureFont::vfunc_9 @ 0x00294e00

namespace pure3d {
struct TextureFont {
    char padding[0x18];
    float height;
    char padding2[4];
    float spacing;
    hulk_freg vfunc_9(const unsigned short* text);
};
hulk_freg TextureFont::vfunc_9(const unsigned short* text)
{
    if (!text) return (*(float*)&DAT_003f32e0);
    hulk_freg result = height;
    float lineStep = spacing + height;
    while (*text) {
        if (*text == 10) result += lineStep;
        ++text;
    }
    return result;
}
}
} // namespace fn_00294e00

namespace fn_f54d8eff {

// 0x00294e50 pure3d::TextureFont::vfunc_10 (123 B): matches/0x00294e50.cpp
// sym: ?vfunc_10@TextureFont@fn_f54d8eff@@UAEMPAF@Z
float TextureFont::vfunc_10(short* s) {
    if (!s)
        return zero_294e50;
    float best = 0.0f;
    int i = 0;
    while (s[i] != 0) {
        float v = vfunc_18_00295270(s + i);
        if (v > best)
            best = v;
        short c = s[i];
        while (c != 0 && c != 10) {
            ++i;
            c = s[i];
        }
        if (s[i] == 10)
            ++i;
    }
    return best;
}

} // namespace fn_f54d8eff

// 0x00294ed0 FUN_00294ed0 (56 B): matches/0x00294ed0.cpp
// sym: ?FUN_00294ed0@Search_294ed0@owners@@QAEHG@Z
int owners::Search_294ed0::FUN_00294ed0(unsigned short key) {
    int low = 0;
    int high = count - 1;
    if (high >= 0) {
        do {
            int mid = (high + low) >> 1;
            unsigned short value = values[mid];
            if (key == value)
                return mid;
            if (key < value)
                high = mid - 1;
            else
                low = mid + 1;
        } while (low <= high);
    }
    return -1;
}

namespace fn_f54d8eff {

// 0x00294f10 FUN_00294f10 (422 B): equivalent/0x00294f10.cpp
// sym: ?Emit@Quad_294f10@fn_f54d8eff@@QAEXPAUVertexSink_294f10@2@PAUSource_294f10@2@MM@Z @18a67d6aae9f @wda30ba67ecc2
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00294f10 @ 0x00294f10
void Quad_294f10::Emit(VertexSink_294f10 *out, Source_294f10 *src, float x, float w)
{
    float h = height;
    float uv0 = src->uv.l;
    float uv1 = src->uv.t;
    float uv2 = src->uv.r;
    float uv3 = src->uv.b;
    unsigned int c = color;

    // two triangles of a strip-less quad, one vertex at a time
    *out->color = c;
    out->tex[0] = uv0;
    out->tex[1] = uv1;
    out->pos[0] = x;
    out->pos[1] = 0;
    out->pos[2] = 0;
    out->FUN_0008ef00();

    *out->color = c;
    out->tex[0] = uv0;
    out->tex[1] = uv3;
    out->pos[0] = x;
    out->pos[1] = h;
    out->pos[2] = 0;
    out->FUN_0008ef00();

    float x2 = x + w;
    *out->color = c;
    out->tex[0] = uv2;
    out->tex[1] = uv3;
    out->pos[0] = x2;
    out->pos[1] = h;
    out->pos[2] = 0;
    out->FUN_0008ef00();

    *out->color = c;
    out->tex[0] = uv0;
    out->tex[1] = uv1;
    out->pos[0] = x;
    out->pos[1] = 0;
    out->pos[2] = 0;
    out->FUN_0008ef00();

    *out->color = c;
    out->tex[0] = uv2;
    out->tex[1] = uv3;
    out->pos[0] = x2;
    out->pos[1] = h;
    out->pos[2] = 0;
    out->FUN_0008ef00();

    *out->color = c;
    out->tex[0] = uv2;
    out->tex[1] = uv1;
    out->pos[0] = x2;
    out->pos[1] = 0;
    out->pos[2] = 0;
    out->FUN_0008ef00();
}


// 0x002950c0 FUN_002950c0 (63 B): matches/0x002950c0.cpp
// sym: ??0TextureFont@fn_f54d8eff@@QAE@XZ
TextureFont::TextureFont() : Font_2950c0() {
    _ReadWriteBarrier();
    x = -1;
    _ReadWriteBarrier();
    g = 0;
    h = 0;
    i = 0;
    j = 0;
    k = 0;
    l = 0;
    m = 0;
}

} // namespace fn_f54d8eff

// 0x00295100 pure3d::TextureFont::vfunc_5 (4 B): matches/0x00295100.cpp
// sym: ?vfunc_5@TextureFont@pure3d@@UAEMXZ
// Same code shape as 0x0005d1d0 (propagated; names are from that function)
hulk_freg pure3d::TextureFont::vfunc_5() {
    return this->f_10;
}


// 0x00295110 pure3d::TextureFont::vfunc_6 (4 B): matches/0x00295110.cpp
// sym: ?vfunc_6@TextureFont@pure3d@@UAEMXZ
// Same code shape as 0x00069050 (propagated; names are from that function)
hulk_freg pure3d::TextureFont::vfunc_6() {
    return this->f_14;
}


// 0x00295120 pure3d::TextureFont::vfunc_7 (4 B): matches/0x00295120.cpp
// sym: ?vfunc_7@TextureFont@pure3d@@UAEMXZ
// Same code shape as 0x00069060 (propagated; names are from that function)
hulk_freg pure3d::TextureFont::vfunc_7() {
    return this->f_18;
}


// 0x00295130 pure3d::TextureFont::vfunc_8 (4 B): matches/0x00295130.cpp
// sym: ?vfunc_8@TextureFont@pure3d@@UAEMXZ
// Same code shape as 0x00069070 (propagated; names are from that function)
hulk_freg pure3d::TextureFont::vfunc_8() {
    return this->f_1c;
}


// 0x00295140 pure3d::TextureFont::vfunc_12 (4 B): matches/0x00295140.cpp
// sym: ?vfunc_12@TextureFont@pure3d@@UAEMXZ
// Same code shape as 0x00069080 (propagated; names are from that function)
hulk_freg pure3d::TextureFont::vfunc_12() {
    return this->f_20;
}


// 0x00295150 pure3d::TextureFont::vfunc_13 (37 B): matches/0x00295150.cpp
// sym: ?vfunc_13@TextureFont@pure3d@@UAEXM@Z
void pure3d::TextureFont::vfunc_13(float x) {
    if (x > 0.0f)
        *(float*)((char*)this + 0x20) = x;
    else
        *(int*)((char*)this + 0x20) = 0;
}


// 0x00295180 pure3d::TextureFont::vfunc_14 (12 B): matches/0x00295180.cpp
// sym: ?vfunc_14@TextureFont@pure3d@@UAEPAXH@Z
 // namespace pure3d
void* pure3d::TextureFont::vfunc_14(hulk_intptr __p0) { int * output = (int *)__p0;

    *output = this->f_24;
    return (void*)(output);
}


// 0x00295190 pure3d::TextureFont::vfunc_15 (10 B): matches/0x00295190.cpp
// sym: ?vfunc_15@TextureFont@pure3d@@UAEXH@Z
// Same code shape as 0x00083d60 (propagated; names are from that function)
void pure3d::TextureFont::vfunc_15(int v) {
    this->f_24 = v;
}


// 0x002951a0 pure3d::TextureFont::vfunc_16 (4 B): matches/0x002951a0.cpp
// sym: ?vfunc_16@TextureFont@pure3d@@UAEIXZ
// Same code shape as 0x000862a0 (propagated; names are from that function)
hulk_uintptr pure3d::TextureFont::vfunc_16() {
    return this->f_28;
}


// 0x00295220 pure3d::TextureFont::vfunc_17 (38 B): matches/0x00295220.cpp
// sym: ?vfunc_17@TextureFont@pure3d@@UAEXPAX@Z
void pure3d::TextureFont::vfunc_17(void* __p0) { Obj_295220 * p = (Obj_295220 *)__p0;

    if (p)
        p->First();
    if ((*(Obj_295220 * *)&this->f_28))
        (*(Obj_295220 * *)&this->f_28)->Release();
    (*(Obj_295220 * *)&this->f_28) = p;
}


// 0x00295250 FUN_00295250 (32 B): matches/0x00295250.cpp
// sym: ?FUN_00295250@C_295250@owners@@QAE_NH@Z
bool owners::C_295250::FUN_00295250(int x) {
    int r = ((Other_295250*)this)->Fng_00294ed0(x);
    if (r >= 0) {
        value = r;
        return true;
    }
    return false;
}


// 0x00295270 pure3d::TextureFont::vfunc_18 (105 B): equivalent/0x00295270.cpp [wrapped: conflict: pure3d::TextureFont]
// sym: ?vfunc_18@TextureFont@pure3d@fn_00295270@@UAEMPBG@Z @dcbd1a6e7fc9 @we4dc30828e8a
namespace fn_00295270 {
// STATUS: equivalent (tools/equiv.py level 3: 18349 inputs, branch coverage 12/12)
// pure3d::TextureFont::vfunc_18 @ 0x00295270
struct Glyph_295270 {
    char pad0[0xc];
    float advance;
    char pad10[0x28 - 0x10];
};
namespace pure3d {
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
    virtual hulk_freg vfunc_18(const unsigned short* text);
    char pad04[0x34 - 4];
    int defaultGlyph;
    char pad38[4];
    Glyph_295270* glyphs;
    int FUN_00294ed0(unsigned int ch);
};
hulk_freg TextureFont::vfunc_18(const unsigned short* text) {
    if (text == 0)
        return 0.0f;
    unsigned short ch = *text;
    if (ch == 0 || ch == 10)
        return 0.0f;
    double width = 0.0f; // the original accumulates in an x87 register
    while (ch != 10) {
        int idx = FUN_00294ed0(ch);
        if (idx >= 0)
            width += glyphs[idx].advance;
        else
            width += glyphs[defaultGlyph].advance;
        text++;
        ch = *text;
        if (ch == 0)
            break;
    }
    return width;
}
}
} // namespace fn_00295270


// 0x002952e0 pure3d::TextureFont::vfunc_19 (573 B): equivalent/0x002952e0.cpp [wrapped: conflict: TextureFont]
// sym: ?vfunc_19@TextureFont@fn_002952e0@@UAEXPBGD@Z @66b8676eb649 @w64d9b29f0dc6
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_002952e0 {
// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 43/46, incomplete)
// pure3d::TextureFont::vfunc_19 @ 0x002952e0
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
} // namespace fn_002952e0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00295520 FUN_00295520 (157 B): equivalent/0x00295520.cpp [wrapped: conflict: pure3d::TextureFont]
// sym: ??1TextureFont@pure3d@fn_00295520@@UAE@XZ @f9ddd5953911 @wf93631554206
namespace fn_00295520 {
// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 14/14)
// FUN_00295520 @ 0x00295520
struct Resource_295520 {
    virtual void unused();
    virtual void release();
};
struct FontEntry {
    char data[0x28];
    void FUN_002c3ac0();
};
struct ArrayHeader { unsigned count; };
void __cdecl FUN_0008d340(void*);
namespace pure3d {
struct TextureFont {
    virtual ~TextureFont();
    char padding[0x24];
    Resource_295520* resource;
    unsigned resourceCount;
    Resource_295520** resources;
    char padding34[8];
    FontEntry* entries;
    void* allocation;
    void FUN_0027afd0();
};
TextureFont::~TextureFont() {
    if (resource) {
        resource->release();
        resource = 0;
    }
    for (unsigned i = 0; i < resourceCount; ++i) {
        Resource_295520** slot = resources + i;
        if (*slot) {
            (*slot)->release();
            *slot = 0;
        }
    }
    FUN_0008d340(resources);
    if (entries) {
        ArrayHeader* header = reinterpret_cast<ArrayHeader*>(entries) - 1;
        unsigned count = header->count;
        FontEntry* end = entries + count;
        if (static_cast<int>(count - 1) >= 0) {
            do {
                --end;
                end->FUN_002c3ac0();
            } while (--count);
        }
        FUN_0008d340(header);
    }
    FUN_0008d340(allocation);
    FUN_0027afd0();
}
}
} // namespace fn_00295520

namespace fn_f54d8eff {

// 0x002955c0 FUN_002955c0 (27 B): matches/0x002955c0.cpp
// sym: ??0TextureFontLoader@fn_f54d8eff@@QAE@XZ
TextureFontLoader::TextureFontLoader() {
    refs = 0;
    id = 0x22000;
    f0c = 0;
    f10 = 0;
    vftable = (void*)DAT_0042d1b0;
}

} // namespace fn_f54d8eff

// 0x002955e0 pure3d::TextureFontLoader::vfunc_2 (31 B): matches/0x002955e0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002955e0@@UAEPAV123@E@Z
namespace fn_002955e0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_2955e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_2955e0 {
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
} // namespace fn_002955e0


// 0x00295620 pure3d::TextureFontLoader::vfunc_5 (1530 B): equivalent/0x00295620.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster; content::LoadInventory::DynamicCasterBase; pure3d::Entity; pure3d::Shader (+1)]
// sym: ?F@TextureFontLoader@fn_00295620@@QAEXPAPAVTextureFont@pure3d@2@PA_KPAUStream@2@PAVFactory_295620@2@@Z @2153c5843d07 @w589bf722d11e
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_00295620 {
// STATUS: equivalent (tools/equiv.py level 3: 120 inputs, branch coverage 46/50, incomplete)
// pure3d::TextureFontLoader::vfunc_5 @ 0x00295620
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


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *memset(void *dst, int c, unsigned int n);
#endif

extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);
void *thunk_FUN_0008d690(unsigned int size);
void __cdecl thunk_FUN_00267090(void *p);


namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

namespace pure3d { class Shader; }

struct Name_295620 {
    char data[8];
    void FUN_0027b040(const char *s);
};

struct Reader {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

class ObjectLoader {
public:
    virtual void v0();
    virtual void v1();
};

class Texture {
public:
    virtual void v0();
    virtual void v1();
};

class TextureLoader : public ObjectLoader {
public:
    Texture *FUN_002c2370(Stream *s);
};

struct Registry_295620 {
    ObjectLoader *FUN_00265310(int id);
};

struct ShaderSlots {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void set(int code, int flag);
};

namespace pure3d {
class Shader {
public:
    char pad0[0x10];
    ShaderSlots *slots;
    char pad14[0x20 - 0x14];
    Shader *FUN_0028edb0();
};
}

class Factory_295620 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual pure3d::Shader *f3(content::LoadInventory::DynamicCaster<pure3d::Shader> *caster, unsigned int lo,
                               unsigned int hi);
};

struct Glyph_295620 {
    float f0, f4, f8, fc;
    unsigned short w10;
    short pad12;
    int f14;
    float f18, f1c, f20, f24;
    void FUN_002c3aa0();
    void FUN_002c3ac0();
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void e0_00038290();
    char pad4[4];
    Name_295620 name;
    void FUN_0027b070();
    Entity() throw() { FUN_0027b070(); }
};

class TextureFont : public Entity {
public:
    virtual void t1_000382a0();
    virtual void t2();
    virtual void t3_0027afe0();
    virtual void t4_0027aff0();
    virtual void t5_00295100();
    virtual void t6_00295110();
    virtual void t7_00295120();
    virtual void t8_00295130();
    virtual double t9_00294e00(void*);
    virtual double t10_00294e50(void*);
    virtual void t11_002c3ad0(void*, int);
    virtual void t12_00295140();
    virtual void t13_00295150(float);
    virtual void* t14_00295180(hulk_intptr);
    virtual void t15_00295190(int);
    virtual void t16_002951a0();
    virtual void setShader_00295220(pure3d::Shader *sh);
    int f10, f14, f18, f1c, f20, f24, f28;
    unsigned int pageCount;
    Texture **pages;
    int defIdx;
    unsigned int glyphCount;
    Glyph_295620 *glyphs;
    unsigned short *codes;
    TextureFont() throw()
    {
        f10 = 0;
        f14 = 0;
        f18 = 0;
        f1c = 0;
        f20 = 0;
        f24 = -1;
        f28 = 0;
        pageCount = 0;
        pages = 0;
        defIdx = 0;
        glyphCount = 0;
        glyphs = 0;
        codes = 0;
    }
};
}

class TextureFontLoader {
public:
    void F(pure3d::TextureFont **out, unsigned __int64 *outId, Stream *s, Factory_295620 *fac);
};

void TextureFontLoader::F(pure3d::TextureFont **out, unsigned __int64 *outId, Stream *s, Factory_295620 *fac)
{
    struct Frame {
        char pad10[3];
        unsigned char len;
        int v14, v18, v1c, v20, v24, v28, v2c, v30, v34, v38, v3c, v40, v44, v48, v4c;
        char N[0x100];
        char N2[0x100];
    } fr;

    s->reader->FUN_002647e0(&fr.v20, 1, 4, 1);
    void *mem = thunk_FUN_0008d690(0x48);
    pure3d::TextureFont *font = 0;
    if (mem)
        font = new (mem) pure3d::TextureFont();
    s->reader->FUN_002647e0(&fr.len, 1, 1, 1);
    int n = fr.len;
    s->reader->FUN_002647e0(fr.N, n, 1, 1);
    fr.N[n] = 0;
    font->name.FUN_0027b040(fr.N);
    s->reader->FUN_002647e0(&fr.len, 1, 1, 1);
    n = fr.len;
    s->reader->FUN_002647e0(fr.N2, n, 1, 1);
    fr.N2[n] = 0;
    unsigned __int64 h = FUN_0027b020(fr.N2);
    new (&fr.v14) content::LoadInventory::DynamicCaster<pure3d::Shader>();
    pure3d::Shader *sh = fac->f3((content::LoadInventory::DynamicCaster<pure3d::Shader> *)&fr.v14,
                                 (unsigned int)h, (unsigned int)(h >> 32));
    if (!sh) {
        void *m2 = thunk_FUN_0008d690(0x20);
        if (m2)
            sh = ((pure3d::Shader *)m2)->FUN_0028edb0();
        else
            sh = 0;
        sh->slots->set(0x54494c, 0);
        sh->slots->set(0x444d4c42, 1);
        sh->slots->set(0x444d4946, 1);
        sh->slots->set(0x54535441, 0);
    }
    font->setShader_00295220(sh);
    s->reader->FUN_002647e0(&fr.v14, 1, 4, 1);
    font->f10 = fr.v14;
    s->reader->FUN_002647e0(&fr.v14, 1, 4, 1);
    font->f14 = fr.v14;
    s->reader->FUN_002647e0(&fr.v14, 1, 4, 1);
    font->f18 = fr.v14;
    s->reader->FUN_002647e0(&fr.v14, 1, 4, 1);
    font->f1c = fr.v14;
    s->reader->FUN_002647e0(&fr.v14, 1, 4, 1);
    unsigned int cnt = fr.v14;
    font->pageCount = cnt;
    font->pages = (Texture **)FUN_0008d6d0(cnt * sizeof(Texture *));
    memset(font->pages, 0, font->pageCount * 4);
    TextureLoader *tl = dynamic_cast<TextureLoader *>((*(Registry_295620**)&DAT_00527c58)->FUN_00265310(0x19000));
    tl->v0();
    if (s->FUN_002669f0()) {
        fr.v1c = 0;
        do {
            int id = s->FUN_00266a30();
            if (id == 0x19000) {
                Texture *tex = tl->FUN_002c2370(s);
                Texture **slot = (Texture **)((char *)font->pages + fr.v1c);
                if (tex)
                    tex->v0();
                if (*slot)
                    (*slot)->v1();
                fr.v1c += 4;
                *slot = tex;
            } else if (id == 0x22001) {
                if (font->glyphs) {
                    int *raw = (int *)font->glyphs - 1;
                    int gc = *raw;
                    Glyph_295620 *end = font->glyphs + gc;
                    for (int i = gc; i > 0; i--) {
                        end--;
                        end->FUN_002c3ac0();
                    }
                    thunk_FUN_00267090(raw);
                    thunk_FUN_00267090(font->codes);
                }
                s->reader->FUN_002647e0(&fr.v4c, 1, 4, 1);
                unsigned int g = fr.v4c;
                font->glyphCount = g;
                int *blk = (int *)FUN_0008d6d0(g * 40 + 4);
                Glyph_295620 *arr = 0;
                if (blk) {
                    *blk = g;
                    arr = (Glyph_295620 *)(blk + 1);
                    for (int i = 0; i < (int)g; i++) {
                        arr[i].FUN_002c3aa0();
                        arr[i].f14 = 0;
                        arr[i].f18 = 0;
                        arr[i].f1c = 0;
                        arr[i].f20 = 1.0f;
                        arr[i].f24 = 1.0f;
                    }
                }
                font->glyphs = arr;
                font->codes = (unsigned short *)FUN_0008d6d0(font->glyphCount * 2);
                unsigned int k = 0;
                unsigned int off = 0;
                if (font->glyphCount != 0) {
                    do {
                        s->reader->FUN_002647e0(&fr.v40, 1, 4, 1);
                        *(int *)((char *)font->glyphs + off + 0x14) = fr.v40;
                        s->reader->FUN_002647e0(&fr.v30, 1, 4, 1);
                        *(float *)((char *)font->glyphs + off + 0x18) = *(float *)&fr.v30;
                        s->reader->FUN_002647e0(&fr.v24, 1, 4, 1);
                        *(float *)((char *)font->glyphs + off + 0x1c) = *(float *)&fr.v24;
                        s->reader->FUN_002647e0(&fr.v38, 1, 4, 1);
                        *(float *)((char *)font->glyphs + off + 0x20) = *(float *)&fr.v38;
                        s->reader->FUN_002647e0(&fr.v48, 1, 4, 1);
                        *(float *)((char *)font->glyphs + off + 0x24) = *(float *)&fr.v48;
                        s->reader->FUN_002647e0(&fr.v28, 1, 4, 1);
                        *(float *)((char *)font->glyphs + off + 0) = *(float *)&fr.v28;
                        s->reader->FUN_002647e0(&fr.v2c, 1, 4, 1);
                        *(float *)((char *)font->glyphs + off + 4) = *(float *)&fr.v2c;
                        s->reader->FUN_002647e0(&fr.v34, 1, 4, 1);
                        *(float *)((char *)font->glyphs + off + 8) = *(float *)&fr.v34;
                        s->reader->FUN_002647e0(&fr.v3c, 1, 4, 1);
                        *(float *)((char *)font->glyphs + off + 0xc) = *(float *)&fr.v3c;
                        s->reader->FUN_002647e0(&fr.v20, 1, 4, 1);
                        *(unsigned short *)((char *)font->glyphs + off + 0x10) = (unsigned short)fr.v20;
                        Glyph_295620 *gl = (Glyph_295620 *)((char *)font->glyphs + off);
                        if (gl->w10 == 0x76)
                            gl->fc = gl->fc - 2.0f;
                        Glyph_295620 *gl2 = (Glyph_295620 *)((char *)font->glyphs + off);
                        unsigned short wc = gl2->w10;
                        if (wc == 0x6f || wc == 0x72)
                            gl2->fc = gl2->fc - 1.0f;
                        font->codes[k] = *(unsigned short *)((char *)font->glyphs + off + 0x10);
                        k++;
                        off += 0x28;
                    } while (k < font->glyphCount);
                }
            }
            s->FUN_00266be0();
        } while (s->FUN_002669f0());
    }
    tl->v1();
    int hi = (int)font->glyphCount - 1;
    int lo = 0;
    if (hi >= 0) {
        unsigned short *codes = font->codes;
        unsigned short key = (*(unsigned short*)&DAT_00554be0);
        do {
            int mid = (hi + lo) >> 1;
            unsigned short c = codes[mid];
            if (key == c) {
                if (mid >= 0)
                    font->defIdx = mid;
                break;
            }
            if (key < c)
                hi = mid - 1;
            else
                lo = mid + 1;
        } while (lo <= hi);
    }
    *out = font;
    *outId = FUN_002672f0(fr.N, 0, 0);
}
} // namespace fn_00295620
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

