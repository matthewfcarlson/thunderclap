// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0032c270..0x0032ca50 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dReflShader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fd5404cd {
#define TREE_TU_END }
namespace fn_fd5404cd {} using namespace fn_fd5404cd;
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fd5404cd {
extern "C" char DAT_00433a04[];
class Base_32c270 {
  public:
    virtual void f();
    virtual void Release();
};
struct d3dReflShader_nv_32c270 {
    void Tail();
};
class pddiObject_32c2f0 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_32c2f0 : public pddiObject_32c2f0 {};
class pddiBaseShader_32c2f0 : public pddiShader_32c2f0 {
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
class d3dShader_32c2f0 : public pddiBaseShader_32c2f0 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class Thing_32c300 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14(int, void*);
    virtual void a15(int);
};
struct Mat_32c300 {
    float x[16];
};
extern unsigned int gState_32c3b0, gState1, gState2;
extern void __stdcall SetTextureState(int, int);
class Device_32c3b0 {
  public:
    char pad0[0x1c];
    int texCoord;
    char pad1[0xc4];
    int stateE4;
    char pad2[0x10];
    int stateF8;
};
class DevVirtual {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q(int);
};
class Obj {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Holder {
    char pad[0x80];
    Obj* p;

  public:
    void Set(Obj* q);
};
class Owner {
    char pad[0x84];
    Ref* p;

  public:
    void Set(Ref* q);
};
class Obj_32c480 {
  public:
    char pad[0x88];
    void Set(void* p);
};
typedef unsigned int u32_32c490;
class d3dShader_32c490 {
  public:
    d3dShader_32c490(u32_32c490 x);
    virtual void Base0();
    char pad[0x7c];
};
class d3dReflShader_32c490 : public d3dShader_32c490 {
  public:
    d3dReflShader_32c490(u32_32c490 x);
    virtual void Run();
    u32_32c490 a;
    u32_32c490 b;
    u32_32c490 c;
};
class Ref_32c4d0 {
  public:
    virtual void f0();
    virtual void f1();
};
extern int vtable_32c4d0;
class d3dReflShader_32c4d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual d3dReflShader_32c4d0* vfunc_3(unsigned int);
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
    virtual void f24();
    void cleanup();
    char pad[0x80 - 4];
    Ref_32c4d0* a;
    Ref_32c4d0* b;
};
void __cdecl destroy(d3dReflShader_32c4d0*);
extern unsigned int DAT_0039db08;
extern TexSlot DAT_0039db10[];
extern unsigned int DAT_0039dc40;
extern unsigned int DAT_0039dc48;
extern unsigned int DAT_0039dc50;
extern unsigned int DAT_0039dc58;
extern unsigned int DAT_0039dc5c;
struct StageCache_32c520 {
    void FUN_0032a920(int a, int b, int c, int d, int e);
    void FUN_00329f70(int a, int b, const void* p);
    char pad0[0x18];
    int texCoordIndex[4];
    int modes[4];
    char pad38[0x48 - 0x38];
    int f48;
    char pad4c[0x6c - 0x4c];
    int f6c;
    char pad70[0x7c - 0x70];
    int f7c;
    char pad80[0x8c - 0x80];
    int f8c;
    char pad90[0x9c - 0x90];
    int f9c;
    char padA0[0xbc - 0xa0];
    int fbc;
    char padC0[0xcc - 0xc0];
    int fcc;
    char padD0[0xe4 - 0xd0];
    int fe4;
    char padE8[0xf4 - 0xe8];
    int dirty[4];
    char pad104[0x108 - 0x104];
    unsigned int textureFactor;
};
class d3dReflShader_32c520 {
  public:
    void FUN_0032a320(int a, int b);
    void FUN_0032a260();
    char pad0[0x14];
    StageCache_32c520* cache;
    char pad18[0x38 - 0x18];
    int alpha;
    char pad3c[0x44 - 0x3c];
    int f44;
    unsigned char b48;
    char pad49[0x4c - 0x49];
    int f4c;
    char f50[0x7c - 0x50];
    unsigned char b7c;
    char pad7d[0x80 - 0x7d];
    int f80;
    int f84;
    unsigned int color;
    void vfunc_14(int unused);
};

} // namespace fn_fd5404cd

// 0x0032c270 FUN_0032c270 (47 B): matches/0x0032c270.cpp
// sym: ?FUN_0032c270@d3dReflShader@pure3d@@QAEXXZ
void pure3d::d3dReflShader::FUN_0032c270() {
    Base_32c270* p = (*(Base_32c270 * *)&this->f_80);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00433a04);
    if (p)
        p->Release();
    p = (*(Base_32c270 * *)&this->f_84);
    if (p)
        p->Release();
    ((d3dReflShader_nv_32c270*)this)->Tail();
}

namespace fn_fd5404cd {

// 0x0032c2a0 pure3d::d3dReflShader::vfunc_15 (6 B): matches/0x0032c2a0.cpp
// sym: _FUN_0032c2a0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032c2a0() {
    return &(*(int*)&DAT_004d7f50);
}


// 0x0032c2b0 pure3d::d3dReflShader::vfunc_16 (6 B): matches/0x0032c2b0.cpp
// sym: _FUN_0032c2b0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032c2b0() {
    return &(*(int*)&DAT_004d7f98);
}


// 0x0032c2c0 pure3d::d3dReflShader::vfunc_17 (6 B): matches/0x0032c2c0.cpp
// sym: _FUN_0032c2c0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032c2c0() {
    return &(*(int*)&DAT_004d7e60);
}


// 0x0032c2d0 pure3d::d3dReflShader::vfunc_18 (6 B): matches/0x0032c2d0.cpp
// sym: _FUN_0032c2d0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032c2d0() {
    return &(*(int*)&DAT_004d7ec0);
}


// 0x0032c2e0 pure3d::d3dReflShader::vfunc_4 (6 B): matches/0x0032c2e0.cpp
// sym: _FUN_0032c2e0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032c2e0() {
    return &(*(int*)&DAT_004d7e44);
}

} // namespace fn_fd5404cd

// 0x0032c2f0 pure3d::d3dReflShader::vfunc_11 (6 B): matches/0x0032c2f0.cpp
// sym: ?vfunc_11@d3dReflShader@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::d3dReflShader::vfunc_11() {
    return 1;
}


// 0x0032c300 pure3d::d3dReflShader::vfunc_12 (164 B): matches/0x0032c300.cpp
// sym: ?vfunc_12@d3dReflShader@pure3d@@UAEXXZ
void pure3d::d3dReflShader::vfunc_12() {
    (*(Thing_32c300 * *)&this->f_10)->a15(2);
    Mat_32c300 m;
    m.x[0] = 0.5f;
    m.x[1] = 0;
    m.x[2] = 0;
    m.x[3] = 0;
    m.x[4] = 0;
    m.x[5] = 0.5f;
    m.x[6] = 0;
    m.x[7] = 0;
    m.x[8] = 0;
    m.x[9] = 0;
    m.x[10] = 1.0f;
    m.x[11] = 0;
    m.x[12] = 0.5f;
    m.x[13] = 0.5f;
    m.x[14] = 0;
    m.x[15] = 1.0f;
    (*(Thing_32c300 * *)&this->f_10)->a14(2, &m);
}


// 0x0032c3b0 pure3d::d3dReflShader::vfunc_13 (110 B): matches/0x0032c3b0.cpp
// sym: ?vfunc_13@d3dReflShader@pure3d@@UAEXXZ
void pure3d::d3dReflShader::vfunc_13() {
    Device_32c3b0* d = (*(Device_32c3b0 * *)&this->f_14);
    if (d->stateE4 != 1) {
        d->stateE4 = 1;
        gState_32c3b0 |= 0x800;
        gState1 = 1;
    }
    d = (*(Device_32c3b0 * *)&this->f_14);
    if (d->texCoord != 1) {
        d->texCoord = 1;
        SetTextureState(1, 1);
    }
    d = (*(Device_32c3b0 * *)&this->f_14);
    if (d->stateF8 != 0) {
        d->stateF8 = 0;
        gState_32c3b0 |= 0x400;
        gState2 = 0;
    }
    (*(DevVirtual * *)&this->f_10)->q(2);
}

namespace fn_fd5404cd {

// 0x0032c420 FUN_0032c420 (44 B): matches/0x0032c420.cpp
// sym: ?Set@Holder@fn_fd5404cd@@QAEXPAVObj@2@@Z
void Holder::Set(Obj* q) {
    if (q)
        q->AddRef();
    if (p)
        p->Release();
    p = q;
}


// 0x0032c450 FUN_0032c450 (44 B): matches/0x0032c450.cpp
// sym: ?Set@Owner@fn_fd5404cd@@QAEXPAVRef@2@@Z
void Owner::Set(Ref* q) {
    if (q)
        q->AddRef();
    if (p)
        p->Release();
    p = q;
}


// 0x0032c480 FUN_0032c480 (13 B): matches/0x0032c480.cpp
// sym: ?Set@Obj_32c480@fn_fd5404cd@@QAEXPAX@Z
void Obj_32c480::Set(void* p) {
    *(void**)((char*)this + 0x88) = p;
}


// 0x0032c490 FUN_0032c490 (49 B): matches/0x0032c490.cpp
// sym: ??0d3dReflShader_32c490@fn_fd5404cd@@QAE@I@Z
d3dReflShader_32c490::d3dReflShader_32c490(u32_32c490 x) : d3dShader_32c490(x) {
    a = 0;
    b = 0;
    c = 0x80808080;
}


// 0x0032c4d0 pure3d::d3dReflShader::vfunc_3 (68 B): matches/0x0032c4d0.cpp
// sym: ?vfunc_3@d3dReflShader_32c4d0@fn_fd5404cd@@UAEPAV12@I@Z
// Same code shape as 0x0032ba70 (propagated; names are from that function)
d3dReflShader_32c4d0* d3dReflShader_32c4d0::vfunc_3(unsigned int x) {
    *(hulk_intptr*)this = (hulk_intptr)&vtable_32c4d0;
    if (a)
        a->f1();
    if (b)
        b->f1();
    cleanup();
    if (x & 1)
        destroy(this);
    return this;
}


// 0x0032c520 pure3d::d3dReflShader::vfunc_14 (568 B): equivalent/0x0032c520.cpp
// sym: ?vfunc_14@d3dReflShader_32c520@fn_fd5404cd@@QAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 152 inputs, branch coverage 24/24)
// pure3d::d3dReflShader::vfunc_14 @ 0x0032c520
void d3dReflShader_32c520::vfunc_14(int) {
    unsigned int c = color;
    unsigned int t1 = (0xff - alpha) * ((c >> 8) & 0xffff0000);
    unsigned int t2 = (0xff - alpha) * ((c >> 8) & 0xff0000);
    unsigned int factor = (((t1 ^ c) & 0xffffff) ^ t2);
    if (factor != cache->textureFactor) {
        cache->textureFactor = factor;
        D3D8::D3DDevice_SetRenderState_TextureFactor(factor);
    }
    ((owners::Obj_329e50 *)cache)->FUN_00329e50(0, 4, 0, 2);
    if (cache->fe4 != 5) {
        cache->fe4 = 5;
        DAT_0039db08 |= 0x800;
        DAT_0039db60 = 5;
    }
    FUN_0032a320(0, 0);
    ((owners::Obj_329e50 *)cache)->FUN_00329e50(1, 4, 3, 2);
    if (cache->texCoordIndex[1] != 0x30000) {
        cache->texCoordIndex[1] = 0x30000;
        D3D8::D3DDevice_SetTextureState_TexCoordIndex(1, 0x30000);
    }
    if (cache->dirty[1] != 2) {
        cache->dirty[1] = 2;
        DAT_0039db08 |= 0x400;
        DAT_0039db10[1].v54 = 2;
    }
    if (cache->modes[1] != 1) {
        cache->modes[1] = 1;
        unsigned int t = ((unsigned int*)&DAT_004d4efc)[1];
        DAT_0039db08 |= 1u << 1;
        DAT_0039db10[1].v0 = t;
        DAT_0039db10[1].v4 = t;
        DAT_0039db10[1].v8 = t;
    }
    ((owners::Obj_329c90 *)cache)->FUN_00329c90(1, f44);
    if (cache->f6c != 0x12) {
        cache->f6c = 0x12;
        DAT_0039db08 |= 0x800;
        DAT_0039dc40 = 0x12;
    }
    if (cache->f8c != 5) {
        cache->f8c = 5;
        DAT_0039db08 |= 0x800;
        DAT_0039dc48 = 5;
    }
    if (cache->f9c != 1) {
        cache->f9c = 1;
        DAT_0039db08 |= 0x800;
        DAT_0039dc4c = 1;
    }
    if (cache->f7c != 3) {
        cache->f7c = 3;
        DAT_0039db08 |= 0x800;
        DAT_0039dc50 = 3;
    }
    if (cache->fbc != 1) {
        cache->fbc = 1;
        DAT_0039db08 |= 0x800;
        DAT_0039dc58 = 1;
    }
    if (cache->fcc != 3) {
        cache->fcc = 3;
        DAT_0039db08 |= 0x800;
        DAT_0039dc5c = 3;
    }
    cache->FUN_0032a920(3, f80, f84, 0, 0);
    if (f4c != cache->f48) {
        cache->f48 = f4c;
        unsigned int v = ((unsigned int*)&DAT_004d4f24)[f4c];
        D3D8::D3DDevice_SetRenderState_Simple(0x4037c, v);
        DAT_0039de18 = v;
    }
    cache->FUN_00329f70(b48, b7c, f50);
    FUN_0032a260();
}

} // namespace fn_fd5404cd
