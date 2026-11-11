// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c26d0..0x002c31b0 (kind game, layer engine, confidence high), dominant class pure3d::GeometryLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/content.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_ff9773df {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_ff9773df {} using namespace fn_ff9773df;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ff9773df {
class pddiObject_2c26d0 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_2c26d0 : public pddiObject_2c26d0 {};
class pddiBaseShader_2c26d0 : public pddiShader_2c26d0 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_2c26d0 : public pddiBaseShader_2c26d0 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
struct Pair {
    int x, y;
};
class Child {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
};
class DrawableContainer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void vfunc_6(int, int);
};
class Geometry : public DrawableContainer {
  public:
    char pad[0x5c];
    Child* a;
    Child* b;
    virtual void vfunc_6(Pair);
};
class Part_2c2730 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
};
struct Geometry_nv_2c2730 {
    void helper_002a41e0(hulk_intptr, int);
};
class Obj_2c2770 {
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
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
};
class DrawableContainer_2c2770 {
  public:
    void vfunc_9_002a4350();
};
extern int hulk_at_0042ec7c;
class Ref_2c28d0 {
  public:
    virtual void f0();
    virtual void Release();
};
class DrawableContainer_2c28d0 {
  public:
    void* vptr;
    ~DrawableContainer_2c28d0() throw();
};
class Geometry_2c28d0 : public DrawableContainer_2c28d0 {
  public:
    char p58[84];
    Ref_2c28d0* a58;
    Ref_2c28d0* a5c;
    Ref_2c28d0* a60;
    Ref_2c28d0* a64;
    ~Geometry_2c28d0() throw();
};
extern void* hulk_at_0042eccc[];
} // namespace fn_ff9773df
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_ff9773df {
class Ref_2c29b0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class PrimGroupLoader_2c29b0 : public Ref_2c29b0 {
  public:
    PrimGroupLoader_2c29b0() throw();
    char pad[0x2c - 4];
};
class OldPrimGroupLoader_2c29b0 : public Ref_2c29b0 {
  public:
    OldPrimGroupLoader_2c29b0() throw();
    char pad[0x24 - 4];
};
struct RP_2c29b0 {
    Ref_2c29b0* p;
    void Set(Ref_2c29b0* r) {
        if (r)
            r->AddRef();
        if (p)
            p->Release();
        p = r;
    }
};
struct Pad_2c29b0 {
    unsigned char b24, b25, b26, b27, b28, b29, b2a;
    void Set() {
        b27 = 0x20;
        b26 = 0x20;
        b25 = 0x20;
        b24 = 0x20;
        b28 = 0x20;
        b29 = 0x20;
        b2a = 0x20;
    }
};
class GeometryLoader_2c29b0 {
  public:
    void* vptr;
    int m4;
    int m8;
    int mc;
    int m10;
    char m14;
    int m18;
    RP_2c29b0 m1c;
    RP_2c29b0 m20;
    Pad_2c29b0 pd;
    GeometryLoader_2c29b0();
};
extern void* g_vftable_2c2a70[];
class Ref_2c2a70 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleChunkHandler_2c2a70 {
  public:
    void* vptr;
    void Fin();
};
class GeometryLoader_2c2a70 : public SimpleChunkHandler_2c2a70 {
  public:
    char pad[0x1c - 4];
    Ref_2c2a70* m1c;
    Ref_2c2a70* m20;
    ~GeometryLoader_2c2a70() throw();
};
extern void* g_a_2c3160[];
extern void* hulk_at_003f6098[];
} // namespace fn_ff9773df
void operator delete(void*);
namespace fn_ff9773df {
class Ref_2c3160 {
  public:
    virtual void F0();
    virtual void Release();
};
class GeometryLoader_2c3160 {
  public:
    void* vptr;
    char pad[0x18];
    Ref_2c3160* m1c;
    Ref_2c3160* m20;
    GeometryLoader_2c3160* f2(unsigned char flags);
};

} // namespace fn_ff9773df

// 0x002c26d0 pure3d::Geometry::vfunc_15 (6 B): matches/0x002c26d0.cpp
// sym: ?vfunc_15@Geometry@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::Geometry::vfunc_15() {
    return 1;
}


// 0x002c26e0 pure3d::Geometry::vfunc_3 (3 B): matches/0x002c26e0.cpp
// sym: ?vfunc_3@Geometry@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::Geometry::vfunc_3() {
    return true;
}

namespace fn_ff9773df {

// 0x002c26f0 pure3d::Geometry::vfunc_6 (60 B): matches/0x002c26f0.cpp
// sym: ?vfunc_6@Geometry@fn_ff9773df@@UAEXUPair@2@@Z
void Geometry::vfunc_6(Pair p) {
    if (a)
        a->f6(p.x, p.y);
    if (b)
        b->f6(p.x, p.y);
    DrawableContainer::vfunc_6(p.x, p.y);
}

} // namespace fn_ff9773df

// 0x002c2730 pure3d::Geometry::vfunc_8 (60 B): matches/0x002c2730.cpp
// sym: ?vfunc_8@Geometry@pure3d@@UAEXHH@Z
void pure3d::Geometry::vfunc_8(hulk_intptr a, int b) {
    if ((*(Part_2c2730 * *)&this->f_60))
        (*(Part_2c2730 * *)&this->f_60)->f6(0, 1);
    if ((*(Part_2c2730 * *)&this->f_64))
        (*(Part_2c2730 * *)&this->f_64)->f6(0, 1);
    ((Geometry_nv_2c2730*)this)->helper_002a41e0(a, b);
}


// 0x002c2770 pure3d::Geometry::vfunc_9 (39 B): matches/0x002c2770.cpp
// sym: ?vfunc_9@Geometry@pure3d@@UAEXXZ
void pure3d::Geometry::vfunc_9() {
    if ((*(Obj_2c2770 * *)&this->f_60))
        (*(Obj_2c2770 * *)&this->f_60)->f23();
    if ((*(Obj_2c2770 * *)&this->f_64))
        (*(Obj_2c2770 * *)&this->f_64)->f23();
    ((DrawableContainer_2c2770*)this)->vfunc_9_002a4350();
}


// 0x002c27a0 pure3d::Geometry::vfunc_16 (26 B): matches/0x002c27a0.cpp [wrapped: conflict: Geometry]
// sym: ?vfunc_16@Geometry@fn_002c27a0@@UAEHXZ
namespace fn_002c27a0 {
class DrawableContainer {
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
    virtual int vfunc_16();
};
class Geometry : public DrawableContainer {
  public:
    char pad[0x60 - 4];
    int a;
    int b;
    int vfunc_16();
};
int Geometry::vfunc_16() {
    int r = DrawableContainer::vfunc_16();
    if (a)
        ++r;
    if (b)
        ++r;
    return r;
}
} // namespace fn_002c27a0


// 0x002c27c0 pure3d::Geometry::vfunc_17 (64 B): equivalent/0x002c27c0.cpp [wrapped: conflict: pure3d::DrawableContainer; pure3d::Geometry]
// sym: ?vfunc_17@Geometry@pure3d@fn_002c27c0@@QAEXHH@Z @7bcd4413e014 @w9f83ea832d5f
namespace fn_002c27c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// pure3d::Geometry::vfunc_17 @ 0x002c27c0
namespace pure3d { struct Item { char pad[8]; int x; int y; }; struct DrawableContainer { void vfunc_17_002a4440(int, int); }; struct Geometry : DrawableContainer { char pad[0x60 - sizeof(DrawableContainer)]; Item* first; Item* second; void vfunc_17(int, int); }; void Geometry::vfunc_17(int x, int y) { if (first && first->x == x && first->y == y) return; if (second && second->x == x && second->y == y) return; DrawableContainer::vfunc_17_002a4440(x, y); } }
} // namespace fn_002c27c0


// 0x002c2800 pure3d::Geometry::vfunc_18 (54 B): matches/0x002c2800.cpp [wrapped: conflict: Geometry]
// sym: ?vfunc_18@Geometry@fn_002c2800@@UAEHH@Z
namespace fn_002c2800 {
class DrawableContainer {
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
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual int vfunc_18(int);
};
class Geometry : public DrawableContainer {
  public:
    char pad[0x60 - 4];
    int a;
    int b;
    int vfunc_18(int);
};
int Geometry::vfunc_18(int param) {
    int i = a;
    if (i != 0) {
        if (param == 0)
            return i;
        --param;
    }
    if (b != 0) {
        if (param == 0)
            return b;
        if (param == 1 && i != 0)
            return b;
        --param;
    }
    return DrawableContainer::vfunc_18(param);
}
} // namespace fn_002c2800

namespace fn_ff9773df {

// 0x002c28d0 FUN_002c28d0 (81 B): matches/0x002c28d0.cpp
// sym: ??1Geometry_2c28d0@fn_ff9773df@@QAE@XZ
Geometry_2c28d0::~Geometry_2c28d0() throw() {
    vptr = &hulk_at_0042ec7c;
    _ReadWriteBarrier();
    if (a58) {
        a58->Release();
        a58 = 0;
    }
    if (a5c) {
        a5c->Release();
        a5c = 0;
    }
    if (a60) {
        a60->Release();
        a60 = 0;
    }
    if (a64) {
        a64->Release();
        a64 = 0;
    }
}


// 0x002c29b0 FUN_002c29b0 (179 B): matches/0x002c29b0.cpp
// sym: ??0GeometryLoader_2c29b0@fn_ff9773df@@QAE@XZ
GeometryLoader_2c29b0::GeometryLoader_2c29b0() {
    m8 = 0x10000;
    vptr = hulk_at_0042eccc;
    m14 = 1;
    m18 = -1;
    m4 = 0;
    mc = 0;
    m10 = 0;
    m1c.p = 0;
    m20.p = 0;
    pd.Set();
    m1c.Set(new PrimGroupLoader_2c29b0);
    m20.Set(new OldPrimGroupLoader_2c29b0);
}


// 0x002c2a70 FUN_002c2a70 (55 B): matches/0x002c2a70.cpp
// sym: ??1GeometryLoader_2c2a70@fn_ff9773df@@QAE@XZ
GeometryLoader_2c2a70::~GeometryLoader_2c2a70() throw() {
    vptr = g_vftable_2c2a70;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    vptr = g_vftable2;
}

} // namespace fn_ff9773df

// 0x002c2ab0 pure3d::GeometryLoader::vfunc_5 (1359 B): equivalent/0x002c2ab0.cpp [wrapped: conflict: Geometry; content::ObjectLoader; pure3d::FrameController; pure3d::FrameControllerLoader (+3)]
// sym: ?vfunc_5@GeometryLoader@pure3d@fn_002c2ab0@@UAE_KPAPAVGeometry@3@PA_KPAULoader_2c2ab0@3@PAUCtx@3@@Z @ba99255f0ba4 @wfc4f56b26af7
inline void operator delete(void*, void*) throw() {}
inline void* operator new(size_t, void* p) throw() { return p; }
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_002c2ab0 {
// STATUS: equivalent (tools/equiv.py level 3: 15869 inputs, branch coverage 56/61, incomplete)
// pure3d::GeometryLoader::vfunc_5 @ 0x002c2ab0
// pure3d::GeometryLoader::vfunc_5 @ 0x002c2ab0
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



void* thunk_FUN_0008d690(unsigned int size) throw();
void* FUN_0008d690(unsigned int size) throw();
typedef unsigned long long u64_2c2ab0;
struct Words64_2c2ab0 { unsigned int lo, hi; };    // 4-aligned stand-in for a 64-bit out value

class RefObj_2c2ab0 {
public:
    virtual void AddRef() throw();
    virtual void Release() throw();
};

namespace content {
class ObjectLoader : public RefObj_2c2ab0 {
public:
    virtual void v2() throw();
};
}

struct Ctx;
struct Loader_2c2ab0;
class Geometry;

namespace pure3d {
class FrameController : public RefObj_2c2ab0 {
public:
    virtual void v2() throw();
};
class VertexAnimController : public FrameController {
public:
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5(Geometry* g) throw();
};
class ProceduralVertexAnimController : public FrameController {
public:
    virtual void v3() throw();
    void FUN_002a6930(Geometry* g) throw();
};
class FrameControllerLoader : public content::ObjectLoader {
public:
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5(FrameController** out, Words64_2c2ab0* res, Loader_2c2ab0* ld, Ctx* ctx) throw();
};
}

struct Stream {
    void FUN_002647e0(void* dst, int a, int b, int c) throw();
};

struct Loader_2c2ab0 {
    char pad000[0x284];
    Stream* stream;
    bool FUN_002669f0() throw();
    unsigned int FUN_00266a30() throw();
    void FUN_00266be0() throw();
};

struct Mgr_2c2ab0 {
    content::ObjectLoader* FUN_00265310(unsigned int id) throw();
};

struct Holder_2c2ab0 {
    void* p;
    void FUN_002e4e90() throw();
    RefObj_2c2ab0* FUN_002e6340(Loader_2c2ab0* ld, Ctx* ctx) throw();
    void FUN_002e4ea0() throw();
};

struct Pair_2c2ab0 {
    unsigned int w16;
    unsigned int w20;
};

struct VertexAnimObject_2c2ab0 : public RefObj_2c2ab0 {
    VertexAnimObject_2c2ab0* FUN_002d1090(Geometry* g) throw();
};

struct NameObj_2c2ab0 {
    char data[0xc];
    void FUN_0027b040(const char* s) throw();
};

class __declspec(novtable) DrawableContainer_2c2ab0 {
public:
    virtual void g0() throw();
    virtual void g1() throw();
    char pad04[4];
    NameObj_2c2ab0 name;
    float v14[3];
    float v20[3];
    float v2c[3];
    unsigned int f38;
    char pad3c[4];
    float f40;
    char pad44[4];
    char* buf48;
    char pad4c[0xc];
    void FUN_002a4e10(unsigned int n) throw();
    DrawableContainer_2c2ab0(unsigned int n) { FUN_002a4e10(n); }
};

class Geometry : public DrawableContainer_2c2ab0 {
public:
    Geometry(unsigned int n) : DrawableContainer_2c2ab0(n) { p58 = 0; p5c = 0; p60 = 0; p64 = 0; }
    virtual void g0() throw();
    virtual void g1() throw();
    RefObj_2c2ab0* p58;
    RefObj_2c2ab0* p5c;
    pure3d::VertexAnimController* p60;
    pure3d::ProceduralVertexAnimController* p64;
};

struct SubA_2c2ab0 {
    void FUN_002df840(unsigned int a) throw();
    void FUN_002e4d70(char* dst, Loader_2c2ab0* ld, Ctx* ctx, int z, int f, Pair_2c2ab0* p) throw();
};
struct SubB_2c2ab0 {
    void FUN_002df890(unsigned int a) throw();
    void FUN_002e4e00(char* dst, Loader_2c2ab0* ld, Ctx* ctx, int z, bool f) throw();
};


namespace pure3d {
class GeometryLoader {
public:
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual u64_2c2ab0 vfunc_5(Geometry** out, u64_2c2ab0* hashOut, Loader_2c2ab0* ld, Ctx* ctx) throw();
    char pad04[0x10];
    unsigned char f14;
    char pad15[3];
    unsigned int f18;
    SubA_2c2ab0* f1c;
    SubB_2c2ab0* f20;
    unsigned int f24;
    unsigned int f28;
};

u64_2c2ab0 GeometryLoader::vfunc_5(Geometry** out, u64_2c2ab0* hashOut, Loader_2c2ab0* ld, Ctx* ctx)
{
    struct Frame {
        char pad0[3];
        unsigned char lenFlag;      // S+3
        union {
            unsigned int version;   // S+4
            Holder_2c2ab0 holder;
        };
        FrameController* ctl;       // S+8
        GeometryLoader* self;       // S+12
        union {                     // S+16
            Pair_2c2ab0 pair;
            unsigned char b[8];
        };
        int offset;                 // S+24
        unsigned int r5;            // S+28
        float clampv;               // S+32
        unsigned int r3;            // S+36
        ProceduralVertexAnimController* proc;  // S+40
        unsigned int vtxAttr;       // S+44
        unsigned int r4;            // S+48
        unsigned int r2;            // S+52
        unsigned int r6;            // S+56
        unsigned int r8;            // S+60
        unsigned int r7;            // S+64
        unsigned int r1;            // S+68
        unsigned int skip;          // S+72
        Words64_2c2ab0 res;         // S+76
        char name[256];             // S+84
    } fr;

    fr.pair.w20 = f28;
    fr.self = this;
    fr.pair.w16 = f24;
    ld->stream->FUN_002647e0(&fr.lenFlag, 1, 1, 1);
    ld->stream->FUN_002647e0(fr.name, fr.lenFlag, 1, 1);
    fr.name[fr.lenFlag] = 0;
    ld->stream->FUN_002647e0(&fr.version, 1, 4, 1);
    fr.lenFlag = (fr.version != 1);
    Geometry* g;
    void* mem = thunk_FUN_0008d690((int)sizeof(Geometry));
    if (mem) {
        ld->stream->FUN_002647e0(&fr.version, 1, 4, 1);
        g = new (mem) Geometry(fr.version);
    } else {
        g = 0;
    }
    g->name.FUN_0027b040(fr.name);
    if (ld->FUN_002669f0()) {
        fr.offset = 0;
        do {
            switch (ld->FUN_00266a30()) {
            case 0x10020:
                f1c->FUN_002df840(f18);
                f1c->FUN_002e4d70(g->buf48 + fr.offset, ld, ctx, 0, f14, &fr.pair);
                fr.offset += 0x10;
                break;
            case 0x10002:
                f20->FUN_002df890(f18);
                f20->FUN_002e4e00(g->buf48 + fr.offset, ld, ctx, 0, f14 && fr.lenFlag);
                fr.offset += 0x10;
                break;
            case 0x10003:
                ld->stream->FUN_002647e0(g->v14, 3, 4, 1);
                ld->stream->FUN_002647e0(g->v20, 3, 4, 1);
                break;
            case 0x10004:
                ld->stream->FUN_002647e0(g->v2c, 3, 4, 1);
                ld->stream->FUN_002647e0(&fr.vtxAttr, 1, 4, 1);
                g->f38 = fr.vtxAttr;
                break;
            case 0x10021:
                ld->stream->FUN_002647e0(&fr.r1, 1, 4, 1);
                ld->stream->FUN_002647e0(&fr.r2, 1, 4, 1);
                fr.b[0] = (unsigned char)fr.r2;
                ld->stream->FUN_002647e0(&fr.r3, 1, 4, 1);
                fr.b[1] = (unsigned char)fr.r3;
                ld->stream->FUN_002647e0(&fr.r4, 1, 4, 1);
                fr.b[2] = (unsigned char)fr.r4;
                ld->stream->FUN_002647e0(&fr.r5, 1, 4, 1);
                fr.b[3] = (unsigned char)fr.r5;
                ld->stream->FUN_002647e0(&fr.r6, 1, 4, 1);
                fr.b[4] = (unsigned char)fr.r6;
                ld->stream->FUN_002647e0(&fr.r7, 1, 4, 1);
                fr.b[5] = (unsigned char)fr.r7;
                ld->stream->FUN_002647e0(&fr.r8, 1, 4, 1);
                fr.b[6] = (unsigned char)fr.r8;
                break;
            case 0x122000:
                ld->stream->FUN_002647e0(&fr.skip, 1, 4, 1);
                ld->stream->FUN_002647e0(&fr.clampv, 1, 4, 1);
                if (!(fr.clampv >= 0.0f))
                    g->f40 = 0.0f;
                else if (fr.clampv > 1.0f)
                    g->f40 = 1.0f;
                else
                    g->f40 = fr.clampv;
                break;
            case 0x121305: {
                fr.holder.FUN_002e4e90();
                RefObj_2c2ab0* a = fr.holder.FUN_002e6340(ld, ctx);
                if (a)
                    a->AddRef();
                if (g->p58)
                    g->p58->Release();
                g->p58 = a;
                void* m = FUN_0008d690(0x18);
                VertexAnimObject_2c2ab0* o;
                if (m)
                    o = ((VertexAnimObject_2c2ab0*)m)->FUN_002d1090(g);
                else
                    o = 0;
                if (o)
                    o->AddRef();
                if (g->p5c)
                    g->p5c->Release();
                g->p5c = o;
                fr.holder.FUN_002e4ea0();
                break;
            }
            case 0x121201: {
                FrameControllerLoader* fl = dynamic_cast<FrameControllerLoader*>((*(Mgr_2c2ab0**)&DAT_00527c58)->FUN_00265310(0x121201));
                fl->AddRef();
                fr.ctl = 0;
                fl->v5(&fr.ctl, &fr.res, ld, ctx);
                if (fr.ctl) {
                    VertexAnimController* va = dynamic_cast<VertexAnimController*>(fr.ctl);
                    fr.proc = dynamic_cast<ProceduralVertexAnimController*>(fr.ctl);
                    if (va) {
                        va->AddRef();
                        if (g->p60)
                            g->p60->Release();
                        g->p60 = va;
                        if (va)
                            va->v5(g);
                    } else if (fr.proc) {
                        fr.proc->AddRef();
                        if (g->p64)
                            g->p64->Release();
                        g->p64 = fr.proc;
                        if (fr.proc)
                            fr.proc->FUN_002a6930(g);
                    } else {
                        fr.ctl->Release();
                        fr.ctl = 0;
                    }
                }
                fl->Release();
                break;
            }
            default:
                break;
            }
            ld->FUN_00266be0();
        } while (ld->FUN_002669f0());
    }
    *out = g;
    u64_2c2ab0 r = FUN_002672f0(fr.name, 0, 0);
    *hashOut = r;
    return r;
}
}
} // namespace fn_002c2ab0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x002c3040 pure3d::Geometry::vfunc_2 (30 B): matches/0x002c3040.cpp
// sym: ??_GGeometry@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::Geometry::~Geometry() {}


// 0x002c3060 FUN_002c3060 (219 B): equivalent/0x002c3060.cpp [wrapped: conflict: FUN_0008d690; pure3d::Geometry]
// sym: ??0Geometry@pure3d@fn_002c3060@@QAE@PAU012@@Z @66ce960358e4 @w88f94542e8f3
namespace fn_002c3060 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// FUN_002c3060 @ 0x002c3060
namespace pure3d { struct Geometry; }
struct Ref_2c3060 {
 virtual void AddRef();
 virtual void Release();
 virtual void slot2();
 virtual void slot3();
 virtual Ref_2c3060* Clone();
 virtual void SetOwner(pure3d::Geometry*);
 void FUN_002a6930(pure3d::Geometry*);
};
struct VertexAnimObject_2c3060 : Ref_2c3060 { VertexAnimObject_2c3060* FUN_002d1090(pure3d::Geometry*); };
void* __cdecl FUN_0008d690(unsigned int);
struct DrawableContainer_2c3060 {
 virtual void slot0();
 char padding[0x54];
 DrawableContainer_2c3060(pure3d::Geometry*);
};
namespace pure3d {
struct Geometry : DrawableContainer_2c3060 {
 Ref_2c3060* resource;
 VertexAnimObject_2c3060* helper;
 Ref_2c3060* first;
 Ref_2c3060* second;
 virtual void slot0();
 Geometry(Geometry* source);
};
Geometry::Geometry(Geometry* source) : DrawableContainer_2c3060(source) {
 resource=0; helper=0; first=0; second=0;
 Ref_2c3060* r=source->resource;
 if(r) r->AddRef();
 if(resource) resource->Release();
 resource=r;
 if(source->helper) {
  VertexAnimObject_2c3060* h=(VertexAnimObject_2c3060*)FUN_0008d690(0x18);
  if(h) h=h->FUN_002d1090(this);
  helper=h;
  h->AddRef();
 }
 if(source->first) {
  r=source->first->Clone();
  if(r) r->AddRef();
  if(first) first->Release();
  first=r;
  if(r) r->SetOwner(this);
 }
 if(source->second) {
  r=source->second->Clone();
  if(r) r->AddRef();
  if(second) second->Release();
  second=r;
  if(r) r->FUN_002a6930(this);
 }
}
}
} // namespace fn_002c3060

namespace fn_ff9773df {

// 0x002c3160 pure3d::GeometryLoader::vfunc_2 (75 B): matches/0x002c3160.cpp
// sym: ?f2@GeometryLoader_2c3160@fn_ff9773df@@QAEPAV12@E@Z
GeometryLoader_2c3160* GeometryLoader_2c3160::f2(unsigned char flags) {
    vptr = g_a_2c3160;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    vptr = hulk_at_003f6098;
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_ff9773df
