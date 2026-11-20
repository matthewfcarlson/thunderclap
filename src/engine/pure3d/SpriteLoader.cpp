// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x002bd430..0x002bf100 (kind game, layer engine, confidence high), dominant class pure3d::SpriteLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/loaders.h"
#include "decls/sprite.h"
#include "decls/drawable_container.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d.h"
#include "decls/shader.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f43dee86 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f43dee86 {} using namespace fn_f43dee86;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f43dee86 {
struct Thing_2bd430 {
    virtual void A();
    virtual void B();
};
extern void __cdecl thunk_FUN_00267090(void*);   // (x64t20) the free by its address name ("Free" had no native definition)
class ParamValue_2bd4b0 {
  public:
    virtual void vfunc_0();
    virtual int vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
struct Rect_2bd790 {
    int left;      // 0
    int top;       // 4
    int right;     // 8
    int bottom;    // 0xc
};
class Surface_2bd790 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setSize(int a, int b);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int getPixel(int row, int col);
    virtual void setPixel(int row, int col, int color);
    virtual void begin(int v);
    virtual void blit(int src, int srcY, int srcX, int h, int w, int dstY, int dstX);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual int getPixel8(int row, int col);
    char pad04[0x14];
    int format;    // 0x18
};
class Image {
public:
    virtual void AddRef();
};
class Factory_2bd790 {
public:
    virtual void v0();
    virtual Image *create(Surface_2bd790 *s, int flag);
};
class Frame9 : public HulkSprite {   // (x64t19, D94) the sprite (decls/sprite.h; was a 32-bit pad view)
public:
    void FUN_002bd790(int index, Rect_2bd790 *r, int a2, int a3, hulk_intptr src, Surface_2bd790 *s, Factory_2bd790 *f);
};
struct RectInts {
    int i0;
    int i4;
    int i8;
    int ic;
    int i10;
    int i14;
};
class QuadBatch : public HulkSprite {   // (x64t19, D94) the sprite (decls/sprite.h; was a 32-bit pad view)
public:
    void FUN_002bdaf0(int index, const RectInts *r, int w, int h);
};
struct Sprite_2bdd00 : HulkSprite {   // (x64t19, D94) the sprite: 0x002bdd00 sets its quads' colour (was gen owners::
    void FUN_002bdd00(int color);      // Thing_2bdd00, a pad view: natively the count, quads and colour were elsewhere)
};
class A_2bdce0 : public HulkSprite {   // (x64t19, D94) the sprite: slot 7 returns its shader
};
struct Vec3_2bdd40 {
    float x, y, z;
};
struct Shader_2bdd40 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void SetTexture(int id, void *tex);
};
struct Material_2bdd40 {           // (x64t19) a pure3d::Shader: Entity's words, then the pddi shader (gen's f_10:
    void *vftable;                 // natively at +0x18; a pad of 0x10 put it at +0x10)
    int words[3];
    Shader_2bdd40 *shader;
};
struct Quad_2bdd40 {
    Vec3_2bdd40 pos;
    float w;
    float uv[2];
};
struct Batch_2bdd40 {               // (x64t19) the pddi primitive stream (unk_08ed50.cpp's Stream: the vftable, the
    void FUN_0008ef00();           // stride, then the current vertex and the three auxiliary pointers; natively the
    void *vftable;                 // pointers are 8 bytes from +0x10, where pads put them at +8)
    unsigned int stride;
    Vec3_2bdd40 *pos;
    void *aux1;
    float *w;
    float *uv;
};
} // namespace fn_f43dee86
class Gfx {
public:
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
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual Batch_2bdd40 *CreateBatch(void *obj, int a, int b, int c, int d);
    virtual void Submit(Batch_2bdd40 *b);
};
namespace fn_f43dee86 {
struct Texture_2bdd40 {             // (x64t19) a pure3d::Texture: Entity's words, then the pddi texture (gen's f_10:
    void *vftable;                 // natively at +0x18)
    int words[3];
    void *tex;
};
struct Verts {
    Quad_2bdd40 corner[4];
};
// (x64t19) pure3d::SpriteObject's record (decls/drawable_container.h), not polymorphic: the container's constructor
// 0x002a4e10 by its address name, then the game's vftable 0x0042e914 by address (the local polymorphic stand-ins got
// clang's own vftable natively)
class DrawableContainer_2bdee0 : public HulkSpriteObject {
  public:
    void* FUN_002a4e10(unsigned int);
    DrawableContainer_2bdee0(int one) { FUN_002a4e10(one); }
};
class SpriteObject : public DrawableContainer_2bdee0 {
  public:
    SpriteObject();
};
extern "C" char DAT_0042e914[];
typedef unsigned int u32_2bdf50;
void* __cdecl alloc_00263ea0(unsigned int);
} // namespace fn_f43dee86
namespace pure3d {
class Builder_2bdf50 {
  public:
    void init_002a4e40(pure3d::SpriteObject*);
};
}
namespace fn_f43dee86 {
struct ThisCall_002a4500 {
    void FUN_002a4500(int, void*);   // (x64t19) the drawable as a pointer (as defined: an int did not bind natively)
};
extern "C" void __fastcall FUN_002ae910(void*);   // (decl1) as defined (ImageHandler_3.cpp)
extern void thunk_FUN_00267090(CCollisionAction*);
struct Name_2bdfc0 {
    unsigned int lo, hi;
};
struct Stream {
};
struct Reader {
    char pad0[0x284];
    Stream *stream;
    HULK_TYPE64(char, bool) FUN_002669f0();
    int FUN_00266a30();   // (x64t15) i32 as defined (natively a hulk_intptr result did not bind)
    void FUN_00266be0();
    void FUN_00266ca0(int v);
};
struct Frame_2bdfc0 {
    short unk10;
    unsigned char len;
    char flag;
    int a;
    int b;
    char buf1[0x80];
    char buf2[0x100];
};
class Other_2be3d0 {
  public:
    void call_000f6e90(void*);
};
} // namespace fn_f43dee86
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int atexit(void (*)());
#endif
namespace fn_f43dee86 {
struct Rec_2be720 {
    char pad0[0x10];
    int lo;
    int hi;
};
struct Row_2be720 {
    Rec_2be720 recs[1];
};
struct ImageConverter_nv_2be720 {
    void FUN_002de230();
};
class Source_2be720 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual int v18(int arg);
    char pad04[0x14];              // (x64t19) a pure3d::Image8 / Image32: Entity's words, gen's f_10 .. f_20; the
    int kind;                      // pixels pointer before the flags (a pad of 4 put f28 at +0x2c natively, not +0x30)
    char pad1c[4];
    int f20;
    void *pixels;
    char f28;
    char f29;
};
class Obj_2be720 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15();
    virtual void v16(int arg);
    char pad04[0x1c];              // (x64t19) as Source_2be720: an Image8 / Image32 with its pixels pointer
    int f20;
    void *pixels;
    char f28;
    char f29;
};
class ObjSmall : public Obj_2be720 {   // pure3d::Image32 (0x30 bytes on the 32-bit builds)
public:
    ObjSmall *FUN_002bffc0();
    char pad2c[0x4];
};
HULK_SIZE32(ObjSmall, 0x30);
class ObjBig : public Obj_2be720 {     // pure3d::Image8 (0x438)
public:
    ObjBig *FUN_002bfcb0();
    char pad2c[0x40c];
};
HULK_SIZE32(ObjBig, 0x438);
extern "C" void *FUN_00266e00(int pool, int size);
void *FUN_0008d6d0(unsigned int size);
int FUN_00267090(void *p);
extern "C" void FUN_003647b0();
class Loader_2be720 : public HulkSprite {   // (x64t19, D94) the sprite (decls/sprite.h; was a 32-bit pad view)
public:
    int FUN_002bd570(Row_2be720 **rows, int *rowCount, int *recCount);
    void FUN_002bd790(int idx, Rec_2be720 *rec, int lo, int hi, Source_2be720 *src, Obj_2be720 *obj, pure3d::ImageConverter *aux);
    void FUN_002bdaf0(int idx, Rec_2be720 *rec, int lo, int hi);

    int Load(Source_2be720 *src, pure3d::ImageConverter *aux);
};
class Obj_2bea10 {
  public:
    virtual void f0();
    virtual void f1();
};
extern void* hulk_at_0042e914[];
class DrawableContainer_2bea70 {
  public:
    void Destroy_002a4ff0(); // FUN_00236d60, __thiscall, this in ecx
};
class SpriteObject_2bea70 : public DrawableContainer_2bea70 {
  public:
    SpriteObject_2bea70* vfunc_5(signed char flags);
};
class V {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
};
struct Wrapper_2beaa0 {
    V* p;
};
class I_2beab0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void target();
};
struct Mid_2beab0 {
    I_2beab0* p;
};
extern "C" char DAT_0042e974[];
class A_2beac0 {
  public:
    virtual void f();
    virtual void g();
};
class B_2beac0 {
  public:
    virtual void f(int);
};
class C_2beac0 {
  public:
    void run_002ae910();
};
struct Sprite : HulkSprite {       // (x64t19, D94) the sprite (decls/sprite.h): 0x002bd430 is its destructor's body
    void Tail_002a50a0();
    void Destroy();
};
// (x64t19) pure3d::SpriteLoader's destructor body 0x002beac0 (was a field of the same mixed view): the loader's record
struct SpriteLoader_2beac0 : HulkSpriteLoader {
    void target();
};
// (x64t19) a pure3d::Image8 / Image32 (what the image registry's 0x002aed60 / 0x002aecb0 return): Entity's words, gen's
// f_10 .. f_20, the pixels, the flag f_28 (natively the name at +0x0c and the flag at +0x30: the mixed view had them
// at +0x08 / +0x28)
struct Image_2bdfc0 {
    void *vftable;
    int refs;
    Name_2bdfc0 name;
    int words[5];
    void *pixels;
    char flag;
};
struct Factory_2bdfc0 {
    char pad0[0x8c];
    int f8c;
    Image_2bdfc0 *FUN_002aecb0(char *name);
};
class SpriteLoader {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Image_2bdfc0 *vfunc_8(Reader *r, int unused);
    virtual void v9();
    HULK_SPRITELOADER_WORDS     // (x64t15) decls/loaders.h (a 0x18-byte pad put the factory at +0x20 natively)
    Factory_2bdfc0 *factory;
};
extern int hulk_at_0042e974, hulk_at_003f6098;
extern void Free2_0008d330(void*);
class Obj_2bed30 {
  public:
    void Fini_002ae910();
};
class Ref_2bed30 {
  public:
    virtual void f0();
    virtual void Rel();
};
class Ref2 {
  public:
    virtual void Del(int);
};
class SpriteLoader_2bed30 : public HulkSpriteLoader {   // (x64t19) the loader's record (was a 32-bit pad view)
  public:
    SpriteLoader_2bed30* vfunc2(unsigned char f);
};


// 0x002bd430 FUN_002bd430 (81 B): matches/0x002bd430.cpp
// sym: ?Destroy@Sprite@fn_f43dee86@@QAEXXZ
void Sprite::Destroy() {
    vftable = (void*)((hulk_intptr)DAT_0042e8d8);
    ((Thing_2bd430*)shader)->B();
    for (int i = 0; i < count; ++i)
        ((Thing_2bd430**)textures)[i]->B();
    thunk_FUN_00267090(textures);
    thunk_FUN_00267090(quads);
    Tail_002a50a0();
}

} // namespace fn_f43dee86

// 0x002bd490 pure3d::Sprite::vfunc_3 (3 B): matches/0x002bd490.cpp
// sym: ?vfunc_3@Sprite@pure3d@@UAE_NXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
bool pure3d::Sprite::vfunc_3() {
    return (bool)(0);
}


// 0x002bd4a0 pure3d::Sprite::vfunc_4 (3 B): matches/0x002bd4a0.cpp
// sym: ?vfunc_4@Sprite@pure3d@@UAEPAXXZ
 // namespace pure3d
void* pure3d::Sprite::vfunc_4() {
    return (void*)(this);
}


// 0x002bd4b0 pure3d::Sprite::vfunc_5 (6 B): matches/0x002bd4b0.cpp
// sym: ?vfunc_5@Sprite@pure3d@@UAEHXZ
// Same code shape as 0x00234f10 (propagated; names are from that function)
int pure3d::Sprite::vfunc_5() {
    return 8;
}

namespace fn_f43dee86 {

// 0x002bd4c0 pure3d::Sprite::vfunc_10 (1 B): matches/0x002bd4c0.cpp
// sym: ?FUN_002bd4c0@fn_f43dee86@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_002bd4c0() {}

} // namespace fn_f43dee86

// 0x002bd570 FUN_002bd570 (544 B): equivalent/0x002bd570.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_002bd570@Mosaic@fn_002bd570@@QAEHPAPAUTile_2bd570@2@PAH1@Z @728c47bea0cf @w46df60ac55d4 @v63ca7d6a9352
namespace fn_002bd570 {
// STATUS: equivalent (tools/equiv.py level 3: 16310 inputs, branch coverage 40/42, incomplete)
// FUN_002bd570 @ 0x002bd570
struct Tile_2bd570 {
    int x0;
    int y0;
    int x1;
    int y1;
    int w;
    int h;
};

extern "C" int __cdecl FUN_00356c30(int value);

// (x64t19, D94) the sprite (decls/sprite.h; was a 32-bit pad view). The tiles' x runs along the record's height
// (+0x54), their y along its width (+0x58), as 0x002bd790 copies them.
struct Mosaic : HulkSprite {
    int FUN_002bd570(Tile_2bd570 **tiles, int *rows, int *cols);
    int Chunk(int remaining);
};

int Mosaic::Chunk(int rem)
{
    int c = maxTile;
    if (rem >= maxTile)
        return c;
    if (rem <= minTile)
        return rem;
    if (rem != 0 && (rem & (rem - 1)) == 0)
        c = rem;
    else
        c = 1 << FUN_00356c30(rem);
    return c - border * 2;
}

int Mosaic::FUN_002bd570(Tile_2bd570 **tiles, int *rows, int *cols)
{
    if (noBorder) {
        if (tiles == 0) {
            *rows = 1;
            *cols = 1;
            return 1;
        }
        (*tiles)->y0 = 0;
        (*tiles)->y1 = width;
        (*tiles)->h = width;
        (*tiles)->x0 = 0;
        (*tiles)->x1 = height;
        (*tiles)->w = height;
        return 1;
    }

    int rowCount = 0;
    int y = 0;
    Tile_2bd570 **row = tiles;
    while (y < width) {
        int h = Chunk(width - y);
        int y1 = y + h;
        if (tiles != 0) {
            for (int j = 0; j < *cols; j++) {
                row[0][j].y0 = y;
                row[0][j].y1 = y1;
                row[0][j].h = h;
            }
        }
        y = y1;
        rowCount++;
        row++;
    }

    int colCount = 0;
    int x = 0;
    int offset = 0;
    while (x < height) {
        int w = Chunk(height - x);
        int x1 = x + w;
        if (tiles != 0) {
            for (rowCount = 0; rowCount < *rows; rowCount++) {
                // the original reloads tiles[rowCount] before each store (a store may alias the pointer array)
                ((Tile_2bd570 *)((char *)tiles[rowCount] + offset))->x0 = x;
                ((Tile_2bd570 *)((char *)tiles[rowCount] + offset))->x1 = x1;
                ((Tile_2bd570 *)((char *)tiles[rowCount] + offset))->w = w;
            }
        }
        x = x1;
        colCount++;
        offset += sizeof(Tile_2bd570);
    }

    if (tiles == 0) {
        *rows = rowCount;
        *cols = colCount;
    }
    return colCount * rowCount;
}
} // namespace fn_002bd570

namespace fn_f43dee86 {

// 0x002bd790 FUN_002bd790 (855 B): equivalent/0x002bd790.cpp
// sym: ?FUN_002bd790@Frame9@fn_f43dee86@@QAEXHPAURect_2bd790@2@HHHPAVSurface_2bd790@2@PAVFactory_2bd790@2@@Z @23f281d72377 @wf5cc594eca22 @v9d1307a5c3fb
// STATUS: equivalent (tools/equiv.py level 3: 138 inputs, branch coverage 73/80, incomplete)
// FUN_002bd790 @ 0x002bd790
void Frame9::FUN_002bd790(int index, Rect_2bd790 *r, int a2, int a3, hulk_intptr src, Surface_2bd790 *s, Factory_2bd790 *f)
{
    s->setSize(a2, a3);
    s->begin(0);

    // (x64t19) the tile's left / right run along the sprite's +0x54 (the record's height), top / bottom along +0x58
    int b = border;
    int top = r->top;
    int t0 = top > b ? top - b : 0;
    int bot = r->bottom;
    int b1 = (width - bot > b) ? bot + b : width;
    int left = r->left;
    int l0 = left > b ? left - b : 0;
    int right = r->right;
    int r1 = (height - right > b) ? right + b : height;

    int h1 = b1 - t0;
    int w1 = r1 - l0;
    int tp = top > b ? 0 : b - top;
    int th = tp + h1;
    int lp = left > b ? 0 : b - left;
    int tw = lp + w1;

    s->blit(src, t0, l0, h1, w1, tp, lp);

    int i;
    if (h1 < a2) {
        if (tp > 0) {
            for (i = tp - 1; i >= 0; i--)
                s->blit(src, t0, l0, 1, w1, i, lp);
        }
        if (th < a2) {
            for (i = th; i < a2; i++)
                s->blit(src, b1 - 1, l0, 1, w1, i, lp);
        }
    }
    if (w1 < a3) {
        for (i = lp - 1; i >= 0; i--)
            s->blit(src, t0, l0, h1, 1, tp, i);
        if (tw < a3) {
            for (i = tw; i < a3; i++)
                s->blit(src, t0, r1 - 1, h1, 1, tp, i);
        }
    }
    if (tp > 0) {
        if (lp > 0) {
            int color = s->format == 8 ? s->getPixel8(tp, lp) : s->getPixel(tp, lp);
            for (int row = tp - 1; row >= 0; row--)
                for (int col = lp - 1; col >= 0; col--)
                    s->setPixel(row, col, color);
        }
        if (tw < a3) {
            int color = s->format == 8 ? s->getPixel8(tp, tw - 1) : s->getPixel(tp, tw - 1);
            for (int row = tp - 1; row >= 0; row--)
                for (int col = tw; col < a3; col++)
                    s->setPixel(row, col, color);
        }
    }
    if (th < a2) {
        if (lp > 0) {
            int color = s->format == 8 ? s->getPixel8(th - 1, lp) : s->getPixel(th - 1, lp);
            for (int row = th; row < a2; row++)
                for (int col = lp - 1; col >= 0; col--)
                    s->setPixel(row, col, color);
        }
        if (tw < a3) {
            int color = s->format == 8 ? s->getPixel8(th - 1, tw - 1) : s->getPixel(th - 1, tw - 1);
            for (int row = th; row < a2; row++)
                for (int col = tw; col < a3; col++)
                    s->setPixel(row, col, color);
        }
    }
    ((Image **)textures)[index] = f->create(s, noBorder);
    ((Image **)textures)[index]->AddRef();
}


// 0x002bdaf0 FUN_002bdaf0 (464 B): equivalent/0x002bdaf0.cpp
// sym: ?FUN_002bdaf0@QuadBatch@fn_f43dee86@@QAEXHPBURectInts@2@HH@Z @f3976fd21337 @we4cf9008f1e1 @ve840d3a910a2
// STATUS: equivalent (tools/equiv.py level 3: 19780 inputs, branch coverage 2/2)
// FUN_002bdaf0 @ 0x002bdaf0
void QuadBatch::FUN_002bdaf0(int index, const RectInts *r, int w, int h)
{
    // x87 (docs/native-float.md): the int->float conversions are exact in the register; W, H, bf, Q, R and bottomV
    // go through float frame slots (rounded), the texture coordinates s0..s2 stay in registers until stored.
    hulk_freg s0, s1, s2;
    float bottomV;
    if (noBorder) {
        s0 = 0.0f;
        s1 = r->i14;
        s2 = 0.0f;
        bottomV = (float)r->i10;
    } else {
        int borderI = border;
        int right = r->i14 + borderI;
        int bottom = r->i10 + borderI;
        volatile float W = (float)w;   // volatile: MSVC 7.1 turns two divisions by W (or H) into a reciprocal multiply
        float Q = (float)(1.0 / ((double)w + w));
        volatile float H = (float)h;
        float R = (float)(1.0 / ((double)h * 4.0f));
        float bf = (float)borderI;
        s2 = (double)borderI / W + Q;
        s1 = (double)right / W + Q;
        bottomV = (float)(1.0 - bf / H - R);
        s0 = 1.0 - (double)bottom / H - R;
    }

    quads[index].v[0].color = -1;
    quads[index].v[1].color = -1;
    quads[index].v[2].color = -1;
    quads[index].v[3].color = -1;

    HulkSpriteVertex *v;
    float x, y;

    v = &quads[index].v[0];
    y = (float)(height - r->i8) * invScaleY;
    x = (float)r->ic * invScaleX;
    v->z = 0;
    v->x = x;
    v->y = y;
    quads[index].v[0].u = s1;
    quads[index].v[0].v = s0;

    v = &quads[index].v[1];
    y = (float)(height - r->i8) * invScaleY;
    x = (float)r->i4 * invScaleX;
    v->z = 0;
    v->x = x;
    v->y = y;
    quads[index].v[1].u = s2;
    quads[index].v[1].v = s0;

    v = &quads[index].v[2];
    y = (float)(height - r->i0) * invScaleY;
    x = (float)r->ic * invScaleX;
    v->z = 0;
    v->x = x;
    v->y = y;
    quads[index].v[2].u = s1;
    quads[index].v[2].v = bottomV;

    v = &quads[index].v[3];
    y = (float)(height - r->i0) * invScaleY;
    x = (float)r->i4 * invScaleX;
    v->z = 0;
    v->x = x;
    v->y = y;
    quads[index].v[3].u = s2;
    quads[index].v[3].v = bottomV;
}


// 0x002bdce0 pure3d::Sprite::vfunc_7 (4 B): matches/0x002bdce0.cpp
// sym: ?target@fn_f43dee86@@YIIPAVA_2bdce0@1@@Z
// Same code shape as 0x00086380 (propagated; names are from that function)
hulk_uintptr __fastcall target(A_2bdce0* self) {   // (x64t19) the shader, pointer-sized (gen's slot 7)
    return (hulk_uintptr)self->shader;
}

} // namespace fn_f43dee86

// 0x002bdcf0 pure3d::Sprite::vfunc_9 (14 B): matches/0x002bdcf0.cpp
// sym: ?vfunc_9@Sprite@pure3d@@UAEEXZ
unsigned char pure3d::Sprite::vfunc_9() {   // (x64t19) the shader's flag (gen's _pad_14: natively +0x20, not +0x14)
    if ((*(void * *)&this->f_4c))
        return *(unsigned char*)((::pure3d::Shader *)this->f_4c)->_pad_14;
    return 0;
}


// 0x002bdd00 FUN_002bdd00 (61 B): matches/0x002bdd00.cpp
// sym: ?FUN_002bdd00@Sprite_2bdd00@fn_f43dee86@@QAEXH@Z
namespace fn_f43dee86 {
void Sprite_2bdd00::FUN_002bdd00(int c) {
    this->color = c;
    for (int i = 0; i < count * 4; ++i) {
        hulk_intptr off = i * 0x18;   // each corner (HulkSpriteVertex) its colour word
        *(int*)((char*)off + (hulk_intptr)quads + 0xc) = this->color;
    }
}
} // namespace fn_f43dee86


// 0x002bdd40 pure3d::Sprite::vfunc_6 (405 B): equivalent/0x002bdd40.cpp
// sym: ?vfunc_6@Sprite@pure3d@@UAEXXZ @da40eec26eaf @w385339cefae0 @v4472acbae5a7
// STATUS: equivalent (tools/equiv.py level 3: 5709 inputs, branch coverage 4/4)
// pure3d::Sprite::vfunc_6 @ 0x002bdd40
void pure3d::Sprite::vfunc_6() {
    for (int i = 0; i < this->f_40; i++) {
        Texture_2bdd40 *t = (*(Texture_2bdd40 ** *)&this->f_48)[i];
        (*(Material_2bdd40 * *)&this->f_4c)->shader->SetTexture(0x584554, t->tex);
        Batch_2bdd40 *b = DAT_0052c2a8->CreateBatch((*(Material_2bdd40 * *)&this->f_4c)->shader, 1, 0x2021, 4, 0);
        for (int k = 0; k < 4; k++) {
            Quad_2bdd40 *q = &(*(Verts * *)&this->f_44)[i].corner[k];
            float w = q->w;
            Vec3_2bdd40 *p = b->pos;
            p->x = q->pos.x;
            p->y = q->pos.y;
            p->z = q->pos.z;
            *b->w = w;
            b->uv[0] = q->uv[0];
            b->uv[1] = q->uv[1];
            b->FUN_0008ef00();
        }
        DAT_0052c2a8->Submit(b);
    }
}

namespace fn_f43dee86 {

// 0x002bdee0 FUN_002bdee0 (20 B): matches/0x002bdee0.cpp
// sym: ??0SpriteObject@fn_f43dee86@@QAE@XZ
SpriteObject::SpriteObject() : DrawableContainer_2bdee0(1) { vftable = (void*)DAT_0042e914; }

} // namespace fn_f43dee86

// 0x002bdf00 pure3d::SpriteObject::vfunc_3 (3 B): matches/0x002bdf00.cpp
// sym: ?vfunc_3@SpriteObject@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::SpriteObject::vfunc_3() {
    return true;
}


// 0x002bdf10 pure3d::SpriteObject::vfunc_15 (6 B): matches/0x002bdf10.cpp
// sym: ?vfunc_15@SpriteObject@pure3d@@UAEHXZ
// Same code shape as 0x00274850 (propagated; names are from that function)
int pure3d::SpriteObject::vfunc_15() {
    return (int)(0x10);
}


// 0x002bdf50 pure3d::SpriteObject::vfunc_4 (44 B): matches/0x002bdf50.cpp
// sym: ?vfunc_4@SpriteObject@pure3d@@UAEPAXXZ
 // namespace pure3d
void* pure3d::SpriteObject::vfunc_4() {
    pure3d::SpriteObject* p = (pure3d::SpriteObject*)alloc_00263ea0(sizeof(HulkSpriteObject));   // (x64t19) natively 0x70
    if (p) {
        ((Builder_2bdf50*)p)->init_002a4e40(this);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0042e914);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x002bdf80 pure3d::SpriteObject::vfunc_22 (15 B): matches/0x002bdf80.cpp
// sym: ?vfunc_22@SpriteObject@pure3d@@UAEXH@Z
void pure3d::SpriteObject::vfunc_22(hulk_intptr p) {
    ((ThisCall_002a4500*)(this))->FUN_002a4500(0, (void*)p);
}

// 0x002bdf90 pure3d::SpriteObject::vfunc_8 (5 B): not yet verified
namespace fn_f43dee86 {

// 0x002bdfa0 FUN_002bdfa0 (30 B): matches/0x002bdfa0.cpp
// sym: ?vfunc_2@CCollisionAction@fn_f43dee86@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    FUN_002ae910((void*)(this));
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x002bdfc0 pure3d::SpriteLoader::vfunc_8 (488 B): equivalent/0x002bdfc0.cpp
// sym: ?vfunc_8@SpriteLoader@fn_f43dee86@@UAEPAUImage_2bdfc0@2@PAUReader@2@H@Z @01dead05ab17 @wb6a65f9c8d37 @v33ae22b6a54d
// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 10/12, incomplete)
// pure3d::SpriteLoader::vfunc_8 @ 0x002bdfc0
Image_2bdfc0 *SpriteLoader::vfunc_8(Reader *r, int unused)
{
    Frame_2bdfc0 f;
    Image_2bdfc0 *result = 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((void*)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    int len = f.len;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((void*)(f.buf1), (hulk_intptr)len, 1, (hulk_intptr)1);
    f.buf1[len] = 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((void*)(&f.a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((void*)(&f.a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((void*)(&f.a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((void*)(&f.a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((void*)(&f.b), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((void*)(&f.b), (hulk_intptr)1, 4, (hulk_intptr)1);
    int kind = f.b;
    f.flag = (kind == 1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((void*)(&f.b), (hulk_intptr)1, 4, (hulk_intptr)1);
    factory->f8c = f.a;
    while (r->FUN_002669f0()) {
        int id = r->FUN_00266a30();
        if (id == 0x19002) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((void*)(&f.a), (hulk_intptr)1, 4, (hulk_intptr)1);
            hulk_intptr v = ((hulk_intptr)((owners::Target_266c90 *)r)->FUN_00266c90());   // (x64t16) the stream
            result = ((Image_2bdfc0 *)((owners::SomeClass_2aed60 *)factory)->FUN_002aed60((void *)v, (void *)(hulk_uintptr)(int)(f.b)));
            r->FUN_00266ca0((int)v);
        } else if (id == 0x19003) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((void*)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1);
            int n = f.len;
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((void*)(f.buf2), (hulk_intptr)n, 1, (hulk_intptr)1);
            f.buf2[n] = 0;
            result = factory->FUN_002aecb0(f.buf2);
        }
        r->FUN_00266be0();
    }
    if (result) {
        ((owners::Target_27b040 *)&(result->name))->FUN_0027b040((hulk_uintptr)(f.buf1));
        result->flag = f.flag;
    }
    return result;
}

} // namespace fn_f43dee86

// 0x002be1b0 pure3d::SpriteLoader::vfunc_9 (522 B): equivalent/0x002be1b0.cpp [wrapped: conflict: Reader; Sprite; content::ObjectLoader; pure3d::SpriteLoader]
// sym: ?vfunc_9@SpriteLoader@pure3d@fn_002be1b0@@UAEPAUSprite@3@PAUReader@3@H@Z @4c27c6456024 @w4f7916c5efa8 @v42610a3088a4
namespace fn_002be1b0 {
// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 16/16)
// pure3d::SpriteLoader::vfunc_9 @ 0x002be1b0
struct StrField_2be1b0 {
    int a, b;
    void FUN_0027b040(const char *s);
};

struct Sprite {                    // (x64t18) a pure3d::Texture: Entity's words, the name after the reference count
    void *vftable;
    int refs;
    StrField_2be1b0 name;
};

// (x64t18) the image registry (decls/loaders.h HulkImageRegistry: the word at +0x8c is the bit depth; a pad put it
// inside the handler pointers natively)
struct SpriteData_2be1b0 : HulkImageRegistry {
    void FUN_002ae950(int a, int b, int c, int d);
    Sprite *FUN_002aedd0(const char *name);
    Sprite *FUN_002aeec0(hulk_intptr a, int b, int c);   // (x64t16) the stream: pointer-sized
};

struct Stream {
    bool FUN_002647e0(void *dst, int a, int b, int c);
};

struct Reader {
    char pad0[0x284];
    Stream *stream;
    bool FUN_002669f0();
    int FUN_00266a30();   // (x64t15) i32 as defined (natively a hulk_intptr result did not bind)
    void FUN_00266be0();
    hulk_intptr FUN_00266c90();   // (x64t16) the stream: pointer-sized
    void FUN_00266ca0(int v);
};

namespace content {
class ObjectLoader {
public:
    virtual void v0();
};
}

namespace pure3d {
class SpriteLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual Sprite *vfunc_9(Reader *r, int unused);
    HULK_SPRITELOADER_WORDS     // (x64t15) decls/loaders.h (a 0x18-byte pad put the factory at +0x20 natively)
    SpriteData_2be1b0 *data;
};
}

Sprite *pure3d::SpriteLoader::vfunc_9(Reader *r, int unused)
{
    struct Frame {
        char pad[3];
        unsigned char len;
        int a;
        int b;
        char buf[0x180];
    } fr;

    Sprite *result = 0;
    r->stream->FUN_002647e0(&fr.len, 1, 1, 1);
    unsigned int n = fr.len;
    r->stream->FUN_002647e0(fr.buf, n, 1, 1);
    fr.buf[n] = 0;
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.b, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.b, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.b, 1, 4, 1);

    data->f8c = fr.a;
    switch (fr.b) {
    case 0xb:
        data->FUN_002ae950(8, 0, 0xd, 0);
        break;
    case 0xc:
        data->FUN_002ae950(8, 0, 0xe, 0);
        break;
    case 0xd:
        data->FUN_002ae950(8, 0, 0xf, 0);
        break;
    case 0xe:
        data->FUN_002ae950(8, 0, 0x10, 0);
        break;
    default:
        break;
    }

    if (r->FUN_002669f0()) {
        do {
            int id = r->FUN_00266a30();
            if (id == 0x19002) {
                r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
                hulk_intptr h = r->FUN_00266c90();
                result = data->FUN_002aeec0(h, fr.a, fr.b);
                r->FUN_00266ca0((int)h);
            } else if (id == 0x19003) {
                r->stream->FUN_002647e0(&fr.len, 1, 1, 1);
                unsigned int m = fr.len;
                char *name2 = &fr.buf[0x80];
                r->stream->FUN_002647e0(name2, m, 1, 1);
                name2[m] = 0;
                result = data->FUN_002aedd0(name2);
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
        if (result != 0)
            result->name.FUN_0027b040(fr.buf);
    }
    return result;
}
} // namespace fn_002be1b0


// 0x002be3d0 pure3d::Sprite::vfunc_11 (16 B): matches/0x002be3d0.cpp
// sym: ?vfunc_11@Sprite@pure3d@@UAEXPAX@Z
void pure3d::Sprite::vfunc_11(void* __p0) { Other_2be3d0 * obj = (Other_2be3d0 *)__p0;

    obj->call_000f6e90(&((HulkSprite *)this)->minX);   // (x64t19) the bounding box (natively not at +0x78)
}


// 0x002be3e0 pure3d::Sprite::vfunc_12 (42 B): matches/0x002be3e0.cpp
// sym: ?vfunc_12@Sprite@pure3d@@UAEXPAX@Z
void pure3d::Sprite::vfunc_12(void* __p0) { unsigned int * out = (unsigned int *)__p0;

    out[0] = this->f_90;
    out[1] = this->f_94;
    out[2] = this->f_98;
    out[3] = this->f_9c;
}


// 0x002be410 pure3d::SpriteObject::vfunc_21 (6 B): matches/0x002be410.cpp
// sym: ?vfunc_21@SpriteObject@pure3d@@UAEHXZ
hulk_intptr pure3d::SpriteObject::vfunc_21() {   // (x64t19) the group's drawable, pointer-sized
    return *(*(hulk_intptr * *)&this->f_48);
}


// 0x002be420 pure3d::Sprite::vfunc_2 (30 B): matches/0x002be420.cpp
// sym: ?vfunc_2@Sprite_2be420@fn_f43dee86@@QAEPAU12@E@Z
// scalar deleting destructor: the destructor's body 0x002bd430, then (flags & 1) the free.
// (x64t20) an explicit function on the record: gen's `pure3d::Sprite::~Sprite() {}` stood for it, which natively
// defines no function for the vftable slot (the release of the copyright sprite reached `hulk_x_002be420`)
namespace fn_f43dee86 {
void __cdecl thunk_FUN_00267090(void*);
struct Sprite_2be420 : HulkSprite {
    void FUN_002bd430();   // the destructor's body (Sprite::Destroy above)
    Sprite_2be420* vfunc_2(unsigned char flags);
};
Sprite_2be420* Sprite_2be420::vfunc_2(unsigned char flags) {
    FUN_002bd430();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_f43dee86


// 0x002be440 FUN_002be440 (731 B): equivalent/0x002be440.cpp [wrapped: conflict: Gfx; pure3d::Sprite]
// sym: ??0Sprite@pure3d@fn_002be440@@QAE@PAPAUItem_2be440@2@HHHPAUShader_2be440@2@HHHH@Z @b698a168cd56 @w55de26632eab @v7794094fca0a
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_002be440 {
// STATUS: equivalent (tools/equiv.py level 3: 15363 inputs, branch coverage 24/24)
// FUN_002be440 @ 0x002be440
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
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
extern "C" double sqrt(double);
#endif



struct Tile_2be440 {
    virtual void t0(); virtual void t1(); virtual void t2(); virtual void t3();
    virtual void t4();
    virtual int v5();
    virtual int v6();
};

class Mode_2be440 {
public:
    virtual void m0();
    virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5();
    virtual void m6(int tag, int flag);
};

struct Shader_2be440 {             // (x64t18) a pure3d::Shader: Entity's words, then the pddi shader (gen's f_10:
    virtual void h0();             // natively at +0x18; a pad of 0xc put it at +0x14)
    int words[3];
    Mode_2be440 *mode;             // 0x10
    Shader_2be440 *FUN_0028edb0();
};

struct Gfx {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual int v84();
};

struct Item_2be440 {               // (x64t18) a pure3d::Texture: Entity's words, then the pddi texture (gen's f_10:
    void *vftable;                 // natively at +0x18; a pad of 0x10 put it at +0x10)
    int words[3];
    Tile_2be440 *tile;             // 0x10
};

extern void *thunk_FUN_0008d690(unsigned int size);
extern void *__cdecl FUN_0008d6d0(unsigned int size);

namespace pure3d {

struct Rect_2be440 {
    int x0, y0, x1, y1, extra;
};

// (x64t19, D94) the sprite record (decls/sprite.h), not polymorphic: DrawablePrimitive's constructor 0x002a5060 by its
// address name, then the game's vftable 0x0042e8d8 by address (the local polymorphic stand-in got clang's own vftable
// natively, whose slots had no definition)
class SpriteBase_2be440 : public HulkSprite {
public:
    void FUN_002a5060();
    SpriteBase_2be440() { FUN_002a5060(); }
};

class Sprite : public SpriteBase_2be440 {
public:
    Sprite(Item_2be440 **items, int w, int h, int count, Shader_2be440 *mgr, int margin, int a7, int a8, int a9);
    void FUN_002bdaf0(int index, Rect_2be440 *r, int w, int h);
    void FUN_002bdd00(int v);
};

}

pure3d::Sprite::Sprite(Item_2be440 **items_, int w_, int h_, int count_, Shader_2be440 *mgr, int margin_, int a7, int a8, int a9)
{
    vftable = (void *)DAT_0042e8d8;
    noBorder = 0;
    DAT_004d0898 = 0x20;
    int m = margin_;
    if (!(margin_ >= 0))
        m = border;
    border = m;
    int span = m * 2;
    int dispv = DAT_0052c2a8->v84();
    double r = 1.0f / (double)a7;
    maxTile = dispv - span;
    minTile = DAT_004d0898 - span;
    scale = a7;
    scaleArg = a8;
    maxZ = 0;
    minZ = 0;
    minY = 0;
    minX = 0;
    invScaleX = (float)r;
    invScaleY = (float)r;
    double t = (double)w_ * r;
    volatile float tf = (float)t; // rounded frame copy (the original reuses it for centerX and radius)
    maxX = tf;
    double u = r * h_;
    maxY = (float)u;
    centerZ = 0;
    centerY = (float)(u * 0.5f);
    centerX = tf * 0.5f;
    radius = (float)sqrt(*(volatile float *)&maxX * *(volatile float *)&maxX + *(volatile float *)&maxY * *(volatile float *)&maxY);
    Shader_2be440 *mm;
    if (mgr == 0) {
        void *mem = thunk_FUN_0008d690(0x20);
        if (mem != 0)
            mm = ((Shader_2be440 *)mem)->FUN_0028edb0();
        else
            mm = 0;
    } else {
        mm = mgr;
    }
    shader = (::pure3d::Shader *)mm;
    mm->h0();
    if (mgr == 0) {
        ((Shader_2be440 *)shader)->mode->m6(0x54494c, 0);
        ((Shader_2be440 *)shader)->mode->m6(0x444d4c42, 1);
        ((Shader_2be440 *)shader)->mode->m6(0x444d5655, 1);
    }
    height = h_;
    width = w_;
    textures = (::pure3d::Texture **)items_;
    quads = (HulkSpriteQuad *)FUN_0008d6d0(count_ * sizeof(HulkSpriteQuad));   // (x64t19) by size (0x60 a quad)
    count = count_;
    if (((Item_2be440 **)textures)[0]->tile->v6() == h_ && ((Item_2be440 **)textures)[0]->tile->v5() == w_)
        border = 0;
    int x = -border;
    int hh = 0;
    int idx = 0;
    if (x < h_ - 1) {
        do {
            int pos = -border;
            if (pos < w_ - 1) {
                do {
                    int ww = ((Item_2be440 **)textures)[idx]->tile->v5();
                    hh = ((Item_2be440 **)textures)[idx]->tile->v6();
                    int a = border + x;
                    int b = border + pos;
                    int p;
                    if (((Item_2be440 **)textures)[idx]->tile->v5() > w_)
                        p = w_;
                    else
                        p = ww - border * 2;
                    int q;
                    if (((Item_2be440 **)textures)[idx]->tile->v6() > h_)
                        q = h_;
                    else
                        q = hh - border * 2;
                    Rect_2be440 rc;
                    rc.x0 = a;
                    rc.y0 = b;
                    rc.x1 = q + a;
                    rc.y1 = p + b;
                    rc.extra = q;
                    FUN_002bdaf0(idx, &rc, ww, hh);
                    pos += ww - border * 2;
                    idx++;
                } while (pos < w_ - 1);
            }
            x += hh - border * 2;
        } while (x < h_ - 1);
    }
    FUN_002bdd00(-1);
}
} // namespace fn_002be440
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f43dee86 {

// 0x002be720 FUN_002be720 (740 B): equivalent/0x002be720.cpp
// sym: ?Load@Loader_2be720@fn_f43dee86@@QAEHPAVSource_2be720@2@PAVImageConverter@pure3d@@@Z @750a8750f25f @w463ed3f8836d @vbbfd1b2cac8c
// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 36/36)
// FUN_002be720 @ 0x002be720
// FUN_002be720 @ 0x002be720
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
int Loader_2be720::Load(Source_2be720 *src, pure3d::ImageConverter *aux)
{
    // frame layout of the original: rows, rowCount, a spare word, recCount, and a zeroed word that a callee
    // reads past &recCount
    struct { Row_2be720 **rows; int rowCount; int spare; int recCount; volatile int zero; } fr;
    int &rowCount = fr.rowCount;
    int &recCount = fr.recCount;
    fr.zero = 0;
    fr.rows = 0;

    count = FUN_002bd570(0, &rowCount, &recCount);
    fr.rows = (Row_2be720 **)FUN_00266e00(1, rowCount * (int)sizeof(Row_2be720 *));
    for (int i = 0; i < rowCount; i++)
        fr.rows[i] = (Row_2be720 *)FUN_00266e00(1, recCount * 24);
    FUN_002bd570(fr.rows, &rowCount, &recCount);

    // (x64t19) the texture pointers and the quads by their sizes (the pointers were count * 4 bytes natively)
    textures = (::pure3d::Texture **)FUN_0008d6d0(count * (int)sizeof(::pure3d::Texture *));
    quads = (HulkSpriteQuad *)FUN_0008d6d0(count * (int)sizeof(HulkSpriteQuad));

    if (aux == 0) {
        if ((DAT_00554bd4 & 1) == 0) {
            DAT_00554bd4 |= 1;
            ((ImageConverter_nv_2be720*)&((*(pure3d::ImageConverter*)&DAT_00554bd0)))->FUN_002de230();
            atexit(FUN_003647b0);
        }
        aux = ((pure3d::ImageConverter*)&DAT_00554bd0);
    }

    Obj_2be720 *obj = 0;
    if (noBorder) {
        ObjSmall *mem = (ObjSmall *)thunk_FUN_0008d690(sizeof(ObjSmall));   // (x64t19) by size: natively 0x38
        if (mem)
            obj = mem->FUN_002bffc0();
        obj->f29 = src->f29;
    } else if (src->kind == 8) {
        ObjBig *mem = (ObjBig *)thunk_FUN_0008d690(sizeof(ObjBig));       // natively 0x440
        if (mem)
            obj = mem->FUN_002bfcb0();
        Source_2be720 *s = src;
        Obj_2be720 *o = obj;
        o->v16(s->v18(0x100));
    } else if (src->kind == 0x20) {
        ObjSmall *mem = (ObjSmall *)thunk_FUN_0008d690(sizeof(ObjSmall));
        if (mem)
            obj = mem->FUN_002bffc0();
        obj->f29 = src->f29;
    }

    obj->f28 = src->f28;
    obj->f20 = src->f20;
    obj->v0();

    int step = border * 2;
    int index = 0;
    Row_2be720 **row = fr.rows;
    for (int r = rowCount; r > 0; r--) {
        int off = 0;
        for (int c = recCount; c > 0; c--) {
            Rec_2be720 *rec = (Rec_2be720 *)((char *)*row + off);
            int lo = rec->hi;
            int limit = minTile;
            if (lo > limit)
                lo += step;
            else
                lo = DAT_004d0898;
            int hi = rec->lo;
            if (hi > limit)
                hi += step;
            else
                hi = DAT_004d0898;
            FUN_002bd790(index, rec, lo, hi, src, obj, aux);
            FUN_002bdaf0(index, (Rec_2be720 *)((char *)*row + off), lo, hi);
            index++;
            off += 0x18;
        }
        row++;
    }

    obj->v1();
    for (int i = 0; i < rowCount; i++)
        FUN_00267090(fr.rows[i]);
    return FUN_00267090(fr.rows);
}

} // namespace fn_f43dee86

// 0x002bea10 pure3d::Sprite::vfunc_8 (83 B): matches/0x002bea10.cpp
// sym: ?vfunc_8@Sprite@pure3d@@UAEXPAX@Z
void pure3d::Sprite::vfunc_8(void* __p0) { Obj_2bea10 * p = (Obj_2bea10 *)__p0;

    if (p)
        p->f0();
    if ((*(Obj_2bea10 * *)&this->f_4c))
        (*(Obj_2bea10 * *)&this->f_4c)->f1();
    (*(Obj_2bea10 * *)&this->f_4c) = p;
    int x = ((::pure3d::Shader *)p)->f_18;   // (x64t19) the shader's word (natively +0x24)
    if (x == 2 || x == 4 || x == 5 || x == 6 || x == 1 || x == 3 || x == 7)
        this->f_10 = 1;
}

namespace fn_f43dee86 {

// 0x002bea70 pure3d::SpriteObject::vfunc_2 (36 B): matches/0x002bea70.cpp
// sym: ?vfunc_5@SpriteObject_2bea70@fn_f43dee86@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
SpriteObject_2bea70* SpriteObject_2bea70::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0042e914;
    Destroy_002a4ff0();
    if (flags & 1) {
        thunk_FUN_00267090(this);   // (x64t20) the free by its address name
    }
    return this;
}

} // namespace fn_f43dee86

// 0x002beaa0 pure3d::SpriteObject::vfunc_19 (10 B): matches/0x002beaa0.cpp
// sym: ?vfunc_19@SpriteObject@pure3d@@UAEXXZ
void pure3d::SpriteObject::vfunc_19() {
    (*(Wrapper_2beaa0 * *)&this->f_48)->p->f11();
}


// 0x002beab0 pure3d::SpriteObject::vfunc_20 (10 B): matches/0x002beab0.cpp
// sym: ?vfunc_20@SpriteObject@pure3d@@UAEXXZ
void pure3d::SpriteObject::vfunc_20() {
    (*(Mid_2beab0 * *)&this->f_48)->p->target();
}

namespace fn_f43dee86 {

// 0x002beac0 FUN_002beac0 (63 B): matches/0x002beac0.cpp
// sym: ?target@SpriteLoader_2beac0@fn_f43dee86@@QAEXXZ
void SpriteLoader_2beac0::target() {
    vftable = (void*)((hulk_intptr)DAT_0042e974);
    ((A_2beac0*)images)->g();
    if (converter)
        ((B_2beac0*)converter)->f(1);
    C_2beac0* q = (C_2beac0*)registry;
    if (q) {
        q->run_002ae910();
        ::operator delete(q);
    }
    vftable = (void*)((hulk_intptr)DAT_003f6098);
}

} // namespace fn_f43dee86

// 0x002beb00 pure3d::SpriteLoader::vfunc_6 (10 B): matches/0x002beb00.cpp
// sym: ?vfunc_6@SpriteLoader@pure3d@@UAEXE@Z
void pure3d::SpriteLoader::vfunc_6(unsigned char value) {
    this->f_21 = value;
}


// 0x002beb10 pure3d::SpriteLoader::vfunc_7 (4 B): matches/0x002beb10.cpp
// sym: ?vfunc_7@SpriteLoader@pure3d@@UAE_NXZ
bool pure3d::SpriteLoader::vfunc_7() {
    return (*(bool *)&this->f_21);
}


// 0x002beb20 FUN_002beb20 (381 B): equivalent/0x002beb20.cpp [wrapped: conflict: Gfx; pure3d::Sprite]
// sym: ??0Sprite@pure3d@fn_002beb20@@QAE@PAUDesc_2beb20@2@PAVShader_2beb20@2@HHHH@Z @abc71c5eb10a @wee405a72b7c2 @v12e5e01a222c
namespace fn_002beb20 {
// STATUS: equivalent (tools/equiv.py level 3: 20029 inputs, branch coverage 10/10)
// FUN_002beb20 @ 0x002beb20
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
extern "C" double sqrt(double);
#endif

void *FUN_00263ea0(unsigned int size);

class Attr_2beb20 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(unsigned int tag, int value);
};

class Shader_2beb20 {              // (x64t18) a pure3d::Shader: Entity's words, then the pddi shader (gen's f_10;
public:                            // natively at +0x18)
    virtual void v0();
    int words[3];
    Attr_2beb20 *attr;
    char pad14[0xc];
    Shader_2beb20 *FUN_0028edb0();
};

struct Desc_2beb20 {               // (x64t18) a pure3d::Image8 / Image32 (gen's f_10 width, f_14 height, f_24 the pixels,
    void *vftable;                 // f_28 the flag: natively after Entity's 0x14 bytes and a pointer)
    int words[3];
    int width;
    int height;
    int f18, f1c, f20;
    void *pixels;
    unsigned char flag;
};

class Gfx {
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual int v84();
};

namespace pure3d {

// (x64t19, D94) the sprite record (decls/sprite.h), not polymorphic: DrawablePrimitive's constructor 0x002a5060 by its
// address name, then the game's vftable 0x0042e8d8 by address (as 0x002be440)
class SpriteBase_2beb20 : public HulkSprite {
public:
    void FUN_002a5060();
    SpriteBase_2beb20() { FUN_002a5060(); }
};

class Sprite : public SpriteBase_2beb20 {
public:
    void FUN_002be720(Desc_2beb20 *d, int a);
    void FUN_002bdd00(int a);
    Sprite(Desc_2beb20 *d, Shader_2beb20 *r, int s, int a4, int a5, int a6);
};

Sprite::Sprite(Desc_2beb20 *d, Shader_2beb20 *r, int s, int a4, int a5, int a6)
{
    vftable = (void *)DAT_0042e8d8;
    noBorder = (*(char*)&DAT_004d0894);
    if ((*(char*)&DAT_004d0894) != 0) {
        border = 0;
    } else {
        if (s >= 0)
            border = s;
        else
            border = border;
    }
    int two = border * 2;
    int base = DAT_0052c2a8->v84();
    maxTile = base - two;
    minTile = DAT_004d0898 - two;
    scale = a4;
    scaleArg = a5;
    maxZ = 0;
    minZ = 0;
    minY = 0;
    minX = 0;
    hulk_freg inv = 1.0f / (float)a4;
    invScaleX = inv;
    invScaleY = inv;
    maxX = d->width * inv;
    maxY = d->height * inv;
    centerY = maxY * 0.5f;
    centerZ = 0;
    centerX = maxX * 0.5f;
    radius = (float)sqrt((double)maxX * maxX + (double)maxY * maxY);
    if (r != 0) {
        shader = (::pure3d::Shader *)r;
    } else {
        Shader_2beb20 *m = (Shader_2beb20 *)FUN_00263ea0(sizeof(HulkShader));
        if (m)
            shader = (::pure3d::Shader *)m->FUN_0028edb0();
        else
            shader = 0;
    }
    ((Shader_2beb20 *)shader)->v0();
    if (r == 0) {
        ((Shader_2beb20 *)shader)->attr->v6(0x54494c, 0);
        ((Shader_2beb20 *)shader)->attr->v6(0x444d4c42, d->flag);
        ((Shader_2beb20 *)shader)->attr->v6(0x444d5655, 1);
    }
    height = d->height;
    width = d->width;
    FUN_002be720(d, a6);
    FUN_002bdd00(-1);
}
}
} // namespace fn_002beb20
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x002beca0 FUN_002beca0 (138 B): equivalent/0x002beca0.cpp [wrapped: conflict: pure3d::SpriteLoader]
// sym: ??0SpriteLoader@pure3d@fn_002beca0@@QAE@XZ @802e70e179de @we398b04921f0 @v8cc88d7e0bf1
namespace fn_002beca0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002beca0 @ 0x002beca0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
extern "C" void* __cdecl FUN_0008d690(unsigned size);
void* __cdecl thunk_FUN_0008d690(unsigned size);
struct ImageConverter_2beca0 { ImageConverter_2beca0* FUN_002de230(); };
class ImageLoader_2beca0 { public: virtual void v0(); ImageLoader_2beca0* FUN_002c0c40(); };
struct Table_2beca0 { Table_2beca0* FUN_002af2d0(); };
extern "C" char DAT_0042e974[];   // (x64t7) pure3d::SpriteLoader's vftable (the local class's own was a stub natively)
namespace pure3d {
// (x64t7, x64t8) the loader's record (decls/loaders.h HulkSpriteLoader) with its vftable stored by address; the image
// converter (0x002de230), the image loader (0x002c0c40) and the image registry (0x002af2d0) allocated at their
// records' sizes
class SpriteLoader : public HulkSpriteLoader {
public:
    SpriteLoader();
};
SpriteLoader::SpriteLoader() {
    vftable = (void*)DAT_0042e974;
    refs = 0;
    id = 0x19005;
    f0c = 0;
    f10 = 0;
    f20 = 0;
    f21 = 0;
    void* m = FUN_0008d690(sizeof(FUN_002de230));
    converter = m ? (FUN_002de230*)((ImageConverter_2beca0*)m)->FUN_002de230() : 0;
    void* c = thunk_FUN_0008d690(sizeof(HulkImageLoader));
    ImageLoader_2beca0* ch = c ? ((ImageLoader_2beca0*)c)->FUN_002c0c40() : 0;
    images = (HulkImageLoader*)ch;
    ch->v0();
    void* t = FUN_0008d690(sizeof(FUN_002af2d0));
    registry = t ? (FUN_002af2d0*)((Table_2beca0*)t)->FUN_002af2d0() : 0;
}
}
} // namespace fn_002beca0

namespace fn_f43dee86 {

// 0x002bed30 pure3d::SpriteLoader::vfunc_2 (83 B): matches/0x002bed30.cpp
// sym: ?vfunc2@SpriteLoader_2bed30@fn_f43dee86@@QAEPAV12@E@Z
SpriteLoader_2bed30* SpriteLoader_2bed30::vfunc2(unsigned char f) {
    Ref_2bed30* r = (Ref_2bed30*)images;
    vftable = &hulk_at_0042e974;
    r->Rel();
    if (converter)
        ((Ref2*)converter)->Del(1);
    Obj_2bed30* o = (Obj_2bed30*)registry;
    if (o) {
        o->Fini_002ae910();
        Free2_0008d330(o);
    }
    vftable = &hulk_at_003f6098;
    if (f & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f43dee86

// 0x002bed90 pure3d::SpriteLoader::vfunc_5 (828 B): equivalent/0x002bed90.cpp [wrapped: conflict: Reader; content::LoadInventory::DynamicCaster; pure3d::SpriteLoader; pure3d::SpriteObject]
// sym: ?vfunc_5@SpriteLoader@pure3d@fn_002bed90@@UAEHPAPAVSpriteObject@23@PA_KPAUReader@3@PAVCtx_2bed90@3@@Z @455ce4fd0e5e @wde0be347166e @v94cc3696f55b
namespace fn_002bed90 {
// STATUS: equivalent (tools/equiv.py level 3: 183 inputs, branch coverage 26/26)
// pure3d::SpriteLoader::vfunc_5 @ 0x002bed90
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


void* __cdecl FUN_00263ea0(unsigned int size);
void* __cdecl FUN_0008d6d0(int size);

struct Stream {
    void FUN_002647e0(void* dest, unsigned int count, unsigned int size, int flag);
};

struct Reader {
    char pad[0x284];
    Stream* stream;
    HULK_TYPE64(int, bool) FUN_002669f0();
    int FUN_00266a30();   // (x64t15) i32 as defined (natively a hulk_intptr result did not bind)
    void FUN_00266be0();
};

class Image {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Chunks_2bed90 {
    Image* FUN_002c0590(Reader* r, int tag);
};

struct NameField_2bed90 {
    unsigned int keyLo;
    unsigned int keyHi;
    void FUN_0027b040(const char* name);
};

class Shader;
namespace pure3d { class Shader; }

struct Sprite {
    Sprite* FUN_002beb20(Image* image, pure3d::Shader* shader, int one, int a, int b, int c);
    Sprite* FUN_002be440(Image** images, int a, int b, int count, pure3d::Shader* shader, int one, int c, int d, int e);
};

namespace content {
namespace LoadInventory {
template <class T>
class DynamicCaster {
public:
    DynamicCaster() {}
    virtual void v0();
    virtual void v1();
};
}
}

class Ctx_2bed90 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
#if defined(HULK_PTR64)
    virtual pure3d::Shader* v3(::content::LoadInventory::DynamicCaster< ::pure3d::Shader>* caster, unsigned int hash_lo, unsigned int hash_hi);   // (decl1, find2 G4) the slot's definition takes the key as two words; a u64 is one register natively
#else
    virtual pure3d::Shader* v3(::content::LoadInventory::DynamicCaster< ::pure3d::Shader>* caster, unsigned __int64 hash);
#endif
};

// (x64t19) pure3d::SpriteObject's record (decls/drawable_container.h), not polymorphic: the container's constructor
// 0x002a4e10 by its address name, then the game's vftable 0x0042e914 by address (the local polymorphic stand-in got
// clang's own vftable natively, whose setSprite slot had no definition); its slots through a view of the game's
extern "C" char DAT_0042e914[];
class DrawableContainer_2bed90 : public HulkSpriteObject {
public:
    NameField_2bed90 &nameField() { return *(NameField_2bed90 *)name; }
    void FUN_002a4e10(int one);
    DrawableContainer_2bed90(int one) { FUN_002a4e10(one); }
};

namespace pure3d {
class SpriteObject : public DrawableContainer_2bed90 {
public:
    SpriteObject() : DrawableContainer_2bed90(1) { vftable = (void *)DAT_0042e914; }
};
class SpriteObjectSlots {          // the game's vftable 0x0042e914 (never constructed: calls through the object's own)
public:
    virtual void v0_00038290();
    virtual void v1_000382a0();
    virtual void* v2_002bea70(char);
    virtual void v3_002bdf00();
    virtual void v4_002bdf50();
    virtual void v5_002a3e70();
    virtual void v6_002a40d0(int, int);
    virtual void v7_002a4150();
    virtual void v8();
    virtual void v9_002a4350();
    virtual void v10_002a34c0(hulk_intptr);
    virtual void v11();
    virtual void v12_002a4570();
    virtual void v13_002a35a0(void*);
    virtual void v14_002a35d0();
    virtual void v15_002bdf10();
    virtual void v16_002a4410();
    virtual void* v17_002a4440(int, int);
    virtual void* v18_002a44b0(int);
    virtual void v19_002beaa0();
    virtual void v20_002beab0();
    virtual void v21_002be410();
    virtual void setSprite(Sprite* s);
};
}

namespace pure3d {
class SpriteLoader {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int vfunc_5(pure3d::SpriteObject** out, unsigned __int64* outKey, Reader* r, Ctx_2bed90* ctx);
    virtual void v6();
    virtual void v7();
    virtual Image* v8(Reader* r, int tag);
    virtual Image* v9(Reader* r, int tag);
    char pad04[0x14 - 4];
    int f14;
    Chunks_2bed90* f18;
};
}

int pure3d::SpriteLoader::vfunc_5(pure3d::SpriteObject** out, unsigned __int64* outKey, Reader* r, Ctx_2bed90* ctx)
{
    struct Frame {
        char pad10[3];
        char n;
        union {                 // (x64t18) the shader caster is constructed in r6's word: natively it is 8 bytes
            int r6;             // (its vftable), which overlapped `arr`
            void* casterWord;
        };
        Image** arr;
        int r1;
        int r5;
        int r2;
        int r4;
        int r3;
        char nameA[0x100];
        char nameB[0x100];
    } f;
    Image* image = 0;
    f.arr = 0;
    r->stream->FUN_002647e0(&f.n, 1, 1, 1);
    r->stream->FUN_002647e0(f.nameA, (unsigned char)f.n, 1, 1);
    f.nameA[(unsigned char)f.n] = 0;
    r->stream->FUN_002647e0(&f.r1, 1, 4, 1);
    r->stream->FUN_002647e0(&f.r2, 1, 4, 1);
    r->stream->FUN_002647e0(&f.n, 1, 1, 1);
    r->stream->FUN_002647e0(f.nameB, (unsigned char)f.n, 1, 1);
    f.nameB[(unsigned char)f.n] = 0;
    r->stream->FUN_002647e0(&f.r3, 1, 4, 1);
    r->stream->FUN_002647e0(&f.r4, 1, 4, 1);
    r->stream->FUN_002647e0(&f.r5, 1, 4, 1);
    r->stream->FUN_002647e0(&f.r6, 1, 4, 1);
    if (f.r5 > 1 || f.r6 != 0)
        f.arr = (Image **)FUN_0008d6d0(f.r5 * sizeof(Image *));
    int more = r->FUN_002669f0();
    if ((char)more) {
        Image** cursor = f.arr;
        do {
            int id = r->FUN_00266a30();
            if (id == 0x3510) {
                image = f18->FUN_002c0590(r, 0x20);
            } else if (id == 0x19001) {
                if (f.arr != 0) {
                    Image* img = v9(r, 0x20);
                    *cursor = img;
                    img->AddRef();
                    cursor++;
                } else {
                    image = v8(r, 0x20);
                }
            }
            r->FUN_00266be0();
            more = r->FUN_002669f0();
        } while ((char)more);
    }
    Sprite* sprite;
    if (image != 0) {
        unsigned __int64 hash = FUN_0027b020(f.nameB);
        // (x64t18) gen's content::LoadInventory::DynamicCaster<pure3d::Shader>, the game's class: its vftable is the
        // game's 0x003f3e88 (the local stand-in's slot had no definition natively)
        ::content::LoadInventory::DynamicCaster< ::pure3d::Shader>* caster = new (&f.r6) ::content::LoadInventory::DynamicCaster< ::pure3d::Shader>();
#if defined(HULK_PTR64)
        pure3d::Shader* shader = ctx->v3(caster, (unsigned int)(hash), (unsigned int)((hash) >> 32));
#else
        pure3d::Shader* shader = ctx->v3(caster, hash);
#endif
        void* mem = FUN_00263ea0(sizeof(HulkSprite));   // (x64t19) pure3d::Sprite (decls/sprite.h)
        if (mem)
            sprite = ((Sprite*)mem)->FUN_002beb20(image, shader, 1, f.r1, f.r2, f14);
        else
            sprite = 0;
    } else if (f.arr != 0) {
        unsigned __int64 hash = FUN_0027b020(f.nameB);
        // (x64t18) gen's content::LoadInventory::DynamicCaster<pure3d::Shader>, the game's class: its vftable is the
        // game's 0x003f3e88 (the local stand-in's slot had no definition natively)
        ::content::LoadInventory::DynamicCaster< ::pure3d::Shader>* caster = new (&f.r6) ::content::LoadInventory::DynamicCaster< ::pure3d::Shader>();
#if defined(HULK_PTR64)
        pure3d::Shader* shader = ctx->v3(caster, (unsigned int)(hash), (unsigned int)((hash) >> 32));
#else
        pure3d::Shader* shader = ctx->v3(caster, hash);
#endif
        void* mem = FUN_00263ea0(sizeof(HulkSprite));   // (x64t19) pure3d::Sprite (decls/sprite.h)
        if (mem)
            sprite = ((Sprite*)mem)->FUN_002be440(f.arr, f.r3, f.r4, f.r5, shader, 1, f.r1, f.r2, f14);
        else
            sprite = 0;
    } else {
        return more;
    }
    void* omem = FUN_00263ea0(sizeof(HulkSpriteObject));   // (x64t19) natively 0x70
    pure3d::SpriteObject* obj;
    if (omem)
        obj = new (omem) pure3d::SpriteObject();
    else
        obj = 0;
    obj->nameField().FUN_0027b040(f.nameA);
    ((pure3d::SpriteObjectSlots *)obj)->setSprite(sprite);
    if (image != 0)
        image->Release();
    *out = obj;
    unsigned __int64 key = FUN_002672f0(f.nameA, 0, 0);
    *outKey = key;
    return (int)key;
}
} // namespace fn_002bed90
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

