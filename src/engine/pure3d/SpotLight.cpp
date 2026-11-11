// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c4020..0x002c6a80 (kind game, layer engine, confidence high), dominant class pure3d::SpotLight
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/engine/pure3d/prop.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_faaafd8b {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_faaafd8b {} using namespace fn_faaafd8b;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_faaafd8b {
class Target_2c4130 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    virtual void G();
    virtual void H();
    virtual void I();
    virtual void J(int);
    char pad[0x58 - 4];
    int a;
    int b;
    int c;
    void Run(int x, int y, int z);
};
class Obj {
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
    virtual void f9(int);
    char pad[0x6c];
    int value;
    void Func(int x);
};
struct T_2c41a0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(int);
    char pad[0x64 - 4];
    int f1, f2, f3;
    void Set(int x, int y, int z);
};
class C_2c41e0 {
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
    virtual void f9(int);
    int pad[28];
    int a, b, c;
    void target(int, int, int);
};
extern void* hulk_at_0042ef00[];
class Light_2c4220 {
  public:
    void Destroy_002a0720(); // FUN_00236d60, __thiscall, this in ecx
};
class SpotLight_2c4220 : public Light_2c4220 {
  public:
    SpotLight_2c4220* vfunc_5(signed char flags);
};
struct Arg_2c4250 {
    int a;
    float b;
    float c;
};
struct Obj_2c4250 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void next(int);
    char pad[0x54];
    int x;
    float y;
    float z;
    void run(Arg_2c4250* p);
};
struct Desc_2c4280 {
    unsigned char flag;
    char pad[3];
    int a, b;
    float c, d, e, f, g, h, i, j, k, l, m, n, o;
    void FUN_0029c240(int, void*, void*, float, float, float, float, float, float);
};
} // namespace fn_faaafd8b
struct Gfx {
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
    virtual void v37(int, Desc_2c4280*, int);
};
namespace fn_faaafd8b {
class A_2c50a0 {
  public:
    virtual void f();
    virtual void g();
};
class B_2c50a0 {
  public:
    A_2c50a0* p;
    void run();
};
struct Vec3_2c50c0 {
    float x, y, z;
    void FUN_0022d180();
};
struct Matrix {
    float m[16];
};
extern "C" void __fastcall FUN_0022b980(Matrix *m);
struct Src_2c5c90 {
    char pad00[0x14];
    int f14;
    float p[3];
};
void FUN_002c5260(float width, float* from, float w2, float* to, int a, int b, int c, int d);
struct Obj_2c5c90 {
    int w0, w4, w8, wc;
    void FUN_002c5c90(Src_2c5c90* s, float f);
};
struct Input {
    char pad[20];
    int v;
    float f;
};
extern void __cdecl work_002c4cb0(float, float*, int, int, int, int);
struct Thing {
    int a, b, c, d;
    void fn(Input*, float);
};
typedef unsigned int U_2c5ed0;
void __cdecl FUN_002c4cb0(float f, void* p, U_2c5ed0 a, U_2c5ed0 b, U_2c5ed0 c, U_2c5ed0 d);
class Obj_2c5ed0 {
  public:
    U_2c5ed0 a, b, c, d;
    void FUN_002c5ed0(void*, U_2c5ed0);
};
class A_2c6630 {
  public:
    virtual void f();
    virtual void g();
};
class B_2c6630 {
  public:
    A_2c6630* p;
    void run();
};
struct Resource { virtual void FUN_00000000(); virtual void FUN_00000001(); virtual void FUN_00000002(); virtual void FUN_00000003(); virtual void FUN_00000004(); virtual void FUN_00000005(); virtual void FUN_00000006(void*, int); };
struct Manager { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual Resource* slot11(const char*, int); };
struct Object { Resource* resource; int value; float a,b; Object* FUN_002c6840(); };
struct Src_2c6900 {
    char pad00[0x14];
    int f14;
    float p[3];
    char pad24[0x58 - 0x24];
    float v[3];
};
struct Obj_2c6900 {
    int w0, w4, w8, wc;
    void FUN_002c6900(Src_2c6900* s, float f);
};

} // namespace fn_faaafd8b

// 0x002c4020 FUN_002c4020 (70 B): equivalent/0x002c4020.cpp [wrapped: conflict: pure3d::SpotLight]
// sym: ??0SpotLight@pure3d@fn_002c4020@@QAE@XZ
namespace fn_002c4020 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002c4020 @ 0x002c4020
namespace pure3d {
class FUN_002a0a70 {
public:
    char data[0x50];
    FUN_002a0a70();
    virtual void method();
};
class SpotLight : public FUN_002a0a70 {
public:
    int type;
    float x, y, z, w;
    float a, b, c;
    float angle, halfAngle, intensity;
    SpotLight();
    virtual void method();
};
SpotLight::SpotLight() {
    x = 0.0f;
    y = 0.0f;
    z = 1.0f;
    a = 0.0f;
    b = 0.0f;
    c = 0.0f;
    w = 1.0f;
    angle = 1.57079637f;
    halfAngle = 0.785398185f;
    intensity = 1.0f;
    type = 3;
}
}
} // namespace fn_002c4020


// 0x002c40f0 pure3d::SpotLight::vfunc_8 (25 B): matches/0x002c40f0.cpp
// sym: ?vfunc_8@SpotLight@pure3d@@UAEXPAX@Z
// Same code shape as 0x002a07c0 (propagated; names are from that function)
void pure3d::SpotLight::vfunc_8(void* __p0) { int * p = (int *)__p0;

    vfunc_7(p[0], p[1], p[2]);
}


// 0x002c4110 pure3d::SpotLight::vfunc_7 (31 B): matches/0x002c4110.cpp
// sym: ?vfunc_7@SpotLight@pure3d@@UAEXHHH@Z
// Same code shape as 0x002c3cc0 (propagated; names are from that function)
void pure3d::SpotLight::vfunc_7(int x, int y, int z) {
    this->f_18 = x;
    this->f_1c = y;
    this->f_20 = z;
    vfunc_9(1);
}

namespace fn_faaafd8b {

// 0x002c4130 FUN_002c4130 (31 B): matches/0x002c4130.cpp
// sym: ?Run@Target_2c4130@fn_faaafd8b@@QAEXHHH@Z
void Target_2c4130::Run(int x, int y, int z) {
    a = x;
    b = y;
    c = z;
    J(1);
}

} // namespace fn_faaafd8b

// 0x002c4150 FUN_002c4150 (30 B): matches/0x002c4150.cpp
// sym: ?FUN_002c4150@C_2c4150@owners@@QAEXPAH00@Z
// Same code shape as 0x002a2f20 (propagated; names are from that function)
void owners::C_2c4150::FUN_002c4150(int* x, int* y, int* z) {
    *x = a;
    *y = b;
    *z = c;
}

namespace fn_faaafd8b {

// 0x002c4170 FUN_002c4170 (20 B): matches/0x002c4170.cpp
// sym: ?Func@Obj@fn_faaafd8b@@QAEXH@Z
void Obj::Func(int x) {
    value = x;
    f9(0);
}


// 0x002c41a0 FUN_002c41a0 (31 B): matches/0x002c41a0.cpp
// sym: ?Set@T_2c41a0@fn_faaafd8b@@QAEXHHH@Z
void T_2c41a0::Set(int x, int y, int z) {
    f1 = x;
    f2 = y;
    f3 = z;
    v9(0);
}

} // namespace fn_faaafd8b

// 0x002c41c0 FUN_002c41c0 (30 B): matches/0x002c41c0.cpp
// sym: ?FUN_002c41c0@C_2c41c0@owners@@QAEXPAH00@Z
void owners::C_2c41c0::FUN_002c41c0(int* x, int* y, int* z) {
    *x = a;
    *y = b;
    *z = c;
}

namespace fn_faaafd8b {

// 0x002c41e0 FUN_002c41e0 (31 B): matches/0x002c41e0.cpp
// sym: ?target@C_2c41e0@fn_faaafd8b@@QAEXHHH@Z
void C_2c41e0::target(int x, int y, int z) {
    a = x;
    b = y;
    c = z;
    f9(0);
}

} // namespace fn_faaafd8b

// 0x002c4200 FUN_002c4200 (30 B): matches/0x002c4200.cpp
// sym: ?FUN_002c4200@Thing_2c4200@owners@@QAEXPAH00@Z
void owners::Thing_2c4200::FUN_002c4200(int* x, int* y, int* z) {
    *x = a;
    *y = b;
    *z = c;
}

namespace fn_faaafd8b {

// 0x002c4220 pure3d::SpotLight::vfunc_2 (36 B): matches/0x002c4220.cpp
// sym: ?vfunc_5@SpotLight_2c4220@fn_faaafd8b@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
SpotLight_2c4220* SpotLight_2c4220::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0042ef00;
    Destroy_002a0720();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x002c4250 FUN_002c4250 (34 B): matches/0x002c4250.cpp
// sym: ?run@Obj_2c4250@fn_faaafd8b@@QAEXPAUArg_2c4250@2@@Z
void Obj_2c4250::run(Arg_2c4250* p) {
    float c = p->c;
    float b = p->b;
    x = p->a;
    y = b;
    z = c;
    next(1);
}

} // namespace fn_faaafd8b

// 0x002c4280 pure3d::SpotLight::vfunc_9 (224 B): matches/0x002c4280.cpp
// sym: ?vfunc_9@SpotLight@pure3d@@UAEXH@Z
 // namespace pure3d
void pure3d::SpotLight::vfunc_9(int arg) {
    if (this->f_10) {
        Desc_2c4280 desc;
        desc.flag = (*(unsigned char *)&this->f_11);
        desc.a = 0;
        desc.b = -1;
        desc.c = 0;
        desc.d = 0;
        desc.e = 0;
        desc.f = 0;
        desc.g = 0;
        desc.h = 1.0f;
        desc.i = 1.0f;
        desc.j = 0;
        desc.k = 0;
        desc.l = 0;
        desc.m = 0;
        desc.n = 0;
        desc.o = 10000000.0f;
        desc.FUN_0029c240(this->f_14, (*(char (*)[12])&this->f_18), (*(float (*)[3])&this->f_58), this->f_74, this->f_78, this->f_7c, this->f_64, this->f_68, this->f_6c);
        DAT_0052c2a8->v37(this->f_24, &desc, arg);
    }
}


// 0x002c4360 FUN_002c4360 (1713 B): equivalent/0x002c4360.cpp [wrapped: macros]
// sym: ?FUN_002c4360@fn_002c4360@@YAXPAUV3@1@0PAXID@Z
namespace fn_002c4360 {
// STATUS: equivalent (tools/equiv.py level 3: 552 inputs, branch coverage 4/4)
// FUN_002c4360 @ 0x002c4360
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

struct V3 { float x, y, z; };

struct VBuf {
    char pad0[8];
    V3 *pos;
    char padc[4];
    unsigned int *color;
    void FUN_0008ef00();
};

struct Gfx {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29();
    virtual VBuf *v30(void *tex, int prim, int fmt, int count, int z);
    virtual void v31(VBuf *vb);
};

struct Frame {
    V3 P;                            // S+0x10
    V3 Q;                            // S+0x1c
};

#define EMIT(X, Y, Z) { float x_ = (X); float y_ = (Y); float z_ = (Z); V3 *pp_ = vb->pos; pp_->x = x_; pp_->y = y_; pp_->z = z_; unsigned int *cp_ = vb->color; *cp_ = color; vb->FUN_0008ef00(); }
#define EMITP() { float x_ = f.P.x; float y_ = f.P.y; float z_ = f.P.z; V3 *pp_ = vb->pos; pp_->x = x_; pp_->z = z_; pp_->y = y_; unsigned int *cp_ = vb->color; *cp_ = color; vb->FUN_0008ef00(); }

void __cdecl FUN_002c4360(V3 *a, V3 *b, void *tex, unsigned int color, char wire2)
{
    Frame f;
    f.Q = *a;
    f.P = *a;
    VBuf *vb = DAT_0052c2a8->v30(tex, 2, 0x2020, wire2 ? 0x24 : 0x18, 0);

    f.P.x = b->x;
    EMIT(f.Q.x, f.Q.y, f.Q.z);
    EMITP();

    f.Q.z = b->z;
    f.P.z = b->z;
    EMIT(f.Q.x, f.Q.y, f.Q.z);
    EMITP();

    f.Q.y = b->y;
    f.P.y = b->y;
    EMIT(f.Q.x, f.Q.y, f.Q.z);
    EMITP();

    f.P.z = a->z;
    EMIT(f.Q.x, f.Q.y, a->z);
    EMITP();

    f.Q.y = a->y;
    f.Q.z = a->z;
    f.P.z = b->z;
    f.P.x = a->x;
    f.P.y = a->y;
    EMIT(a->x, a->y, a->z);
    EMITP();

    f.Q.x = b->x;
    f.P.x = b->x;
    EMIT(f.Q.x, f.Q.y, f.Q.z);
    EMITP();

    f.Q.y = b->y;
    f.P.y = b->y;
    EMIT(f.Q.x, f.Q.y, f.Q.z);
    EMITP();

    f.P.x = a->x;
    EMIT(a->x, f.Q.y, f.Q.z);
    EMITP();

    f.Q.y = a->y;
    f.Q.z = a->z;
    f.P.y = b->y;
    f.P.x = a->x;
    f.P.z = a->z;
    EMIT(a->x, a->y, a->z);
    EMITP();

    f.Q.x = b->x;
    f.P.x = b->x;
    EMIT(f.Q.x, f.Q.y, f.Q.z);
    EMITP();

    f.Q.z = b->z;
    f.P.z = b->z;
    EMIT(f.Q.x, f.Q.y, f.Q.z);
    EMITP();

    f.P.x = a->x;
    EMIT(a->x, f.Q.y, f.Q.z);
    EMITP();

    if (wire2) {
        f.Q.z = a->z;
        f.P.z = a->z;
        f.P.x = b->x;
        f.P.y = b->y;
        EMIT(a->x, a->y, a->z);
        EMITP();

        float ox = f.P.x, oy = f.P.y, oz = f.P.z;
        f.Q.z = oz;
        f.P.y = a->y;
        f.P.x = b->x;
        f.P.z = b->z;
        EMIT(ox, oy, oz);
        EMITP();

        ox = f.P.x; oy = f.P.y; oz = f.P.z;
        f.Q.z = oz;
        f.P.x = a->x;
        f.P.y = b->y;
        f.P.z = b->z;
        EMIT(ox, oy, oz);
        EMITP();

        ox = f.P.x; oy = f.P.y; oz = f.P.z;
        f.Q.z = oz;
        f.P.z = a->z;
        f.P.x = a->x;
        f.P.y = a->y;
        EMIT(ox, oy, oz);
        EMITP();

        ox = f.P.x; oy = f.P.y; oz = f.P.z;
        f.Q.z = oz;
        f.P.y = a->y;
        f.P.x = b->x;
        f.P.z = b->z;
        EMIT(ox, oy, oz);
        EMITP();

        f.P.y = b->y;
        f.P.z = b->z;
        f.Q.z = a->z;
        f.P.x = a->x;
        EMIT(b->x, b->y, a->z);
        EMITP();
    }
    DAT_0052c2a8->v31(vb);
}
} // namespace fn_002c4360
#undef EMIT
#undef EMITP
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x002c4a20 FUN_002c4a20 (649 B): equivalent/0x002c4a20.cpp [wrapped: conflict: Gfx]
// sym: ?FUN_002c4a20@fn_002c4a20@@YAXPAXHHIMM@Z
namespace fn_002c4a20 {
// STATUS: equivalent (tools/equiv.py level 3: 30 inputs, branch coverage 8/8)
// FUN_002c4a20 @ 0x002c4a20
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

struct Vec3_2c4a20 {
    float x, y, z;
};

class Renderer_2c4a20 {
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
    virtual void v16(int arg);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23(int a, int b);
};

class Mesh_2c4a20 {
public:
    char pad0[8];
    Vec3_2c4a20 *vtx;
    char pad1[4];
    unsigned *color;
    void FUN_0008ef00();
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
    virtual Mesh_2c4a20 *v30(int a, int b, int c, int d, int e);
    virtual void v31(Mesh_2c4a20 *m);
};

void __cdecl FUN_00356bf0(void *a1, float a, float b, float *x, float *y, float *z);

struct Frame_2c4a20 {
    float v10;
    float stepX;
    Vec3_2c4a20 V;
    Vec3_2c4a20 V2;
};

void FUN_002c4a20(void *a1, int a2, int a3, unsigned color, float nx, float ny)
{
    Frame_2c4a20 fr;
    (*(*(Renderer_2c4a20***)&DAT_0052c2ac))->v23(0, a2);
    Mesh_2c4a20 *m = DAT_0052c2a8->v30(a3, 2, 0x2020, (int)((nx + 1.0f) * (ny + 1.0f) * 4.0f), 0);
    FUN_00356bf0(a1, 0.0f, 0.0f, &fr.V.x, &fr.V.y, &fr.V.z);
    fr.stepX = 3.14159274f / nx;
    fr.v10 = 0.0f;
    ny = 3.14159274f / ny;
    do {
        float outer = fr.v10;
        nx = 0.0f;
        do {
            fr.V2 = fr.V;
            FUN_00356bf0(a1, outer, nx, &fr.V.x, &fr.V.y, &fr.V.z);
            Vec3_2c4a20 *p = m->vtx;
            p->x = fr.V2.x;
            p->z = fr.V2.z;
            p->y = fr.V2.y;
            *m->color = color;
            m->FUN_0008ef00();
            p = m->vtx;
            p->x = fr.V.x;
            p->y = fr.V.y;
            p->z = fr.V.z;
            *m->color = color;
            m->FUN_0008ef00();
            nx = fr.stepX + nx;
        } while (nx <= 3.14159274f);
        fr.v10 = ny + fr.v10;
    } while (fr.v10 <= 3.14159274f);

    FUN_00356bf0(a1, 0.0f, 0.0f, &fr.V.x, &fr.V.y, &fr.V.z);
    nx = 0.0f;
    do {
        float outer = nx;
        fr.v10 = 0.0f;
        do {
            fr.V2 = fr.V;
            FUN_00356bf0(a1, fr.v10, outer, &fr.V.x, &fr.V.y, &fr.V.z);
            Vec3_2c4a20 *p = m->vtx;
            p->x = fr.V2.x;
            p->z = fr.V2.z;
            p->y = fr.V2.y;
            *m->color = color;
            m->FUN_0008ef00();
            p = m->vtx;
            p->x = fr.V.x;
            p->y = fr.V.y;
            p->z = fr.V.z;
            *m->color = color;
            m->FUN_0008ef00();
            fr.v10 = fr.stepX + fr.v10;
        } while (fr.v10 <= 3.14159274f);
        nx = ny + nx;
    } while (nx <= 3.14159274f);

    DAT_0052c2a8->v31(m);
    (*(*(Renderer_2c4a20***)&DAT_0052c2ac))->v16(0);
}
} // namespace fn_002c4a20
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x002c4cb0 FUN_002c4cb0 (706 B): equivalent/0x002c4cb0.cpp [wrapped: conflict: Gfx; Matrix]
// sym: ?FUN_002c4cb0@fn_002c4cb0@@YAXMPAUV3_2c4cb0@1@HHMM@Z
namespace fn_002c4cb0 {
// STATUS: equivalent (tools/equiv.py level 3: 27 inputs, branch coverage 8/8)
// FUN_002c4cb0 @ 0x002c4cb0
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

   // pi
   // 2 * pi

struct V3_2c4cb0 {
    float x, y, z;
};

struct Matrix {
    float m[16];
    Matrix() {}
    void FUN_0022b980();
    void FUN_0022be40(const V3_2c4cb0 *pos);
};

class Device_2c4cb0 {
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
    virtual void v16(int a);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23(int state, Matrix *m);
};

struct VertexBuf_2c4cb0 {
    char pad0[8];
    V3_2c4cb0 *cursor;         // 8
    char padc[4];
    int *tag;           // 0x10
    void FUN_0008ef00();
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
    virtual VertexBuf_2c4cb0 *v30(int a, int b, int c, int n, int z);
    virtual void v31(VertexBuf_2c4cb0 *b);
};


void __cdecl FUN_00356bf0(float r, float az, float pol, float *x, float *y, float *z);

void __cdecl FUN_002c4cb0(float a1, V3_2c4cb0 *a2, int a3, int a4, float a5, float a6)
{
    Matrix m;
    m.FUN_0022b980();
    m.FUN_0022be40(a2);
    (*(*(Device_2c4cb0***)&DAT_0052c2ac))->v23(0, &m);
    Gfx *rend = DAT_0052c2a8;
    VertexBuf_2c4cb0 *vb = rend->v30(a3, 2, 0x2020, (int)((a6 + a6 + 1.0f) * (a5 + 1.0f) * 4.0f), 0);
    V3_2c4cb0 v;
    FUN_00356bf0(a1, 0, 0, &v.x, &v.y, &v.z);
    volatile float dphi = (*(float*)&DAT_0042ef28) / a5;
    volatile float outerA = 0;
    volatile float innerB;
    volatile float dtheta = (*(float*)&DAT_0042ef28) / a6;
    do {
        float ph = outerA;
        innerB = 0;
        double x;
        do {
            V3_2c4cb0 a = v;
            FUN_00356bf0(a1, ph, innerB, &v.x, &v.y, &v.z);
            V3_2c4cb0 *c = vb->cursor;
            c->x = a.x;
            c->z = a.z;
            c->y = a.y;
            int *t = vb->tag;
            *t = a4;
            vb->FUN_0008ef00();
            c = vb->cursor;
            c->x = v.x;
            c->y = v.y;
            c->z = v.z;
            t = vb->tag;
            *t = a4;
            vb->FUN_0008ef00();
            x = dphi + innerB;
            innerB = (float)x;
        } while (x <= (*(float*)&DAT_0042ef28));
        double y = dtheta + outerA;
        outerA = (float)y;
        if (!(y <= (*(float*)&DAT_0042ef48)))
            break;
    } while (true);
    FUN_00356bf0(a1, 0, 0, &v.x, &v.y, &v.z);
    innerB = 0;
    do {
        float ph = innerB;
        outerA = 0;
        double x;
        do {
            V3_2c4cb0 a = v;
            FUN_00356bf0(a1, outerA, ph, &v.x, &v.y, &v.z);
            V3_2c4cb0 *c = vb->cursor;
            c->x = a.x;
            c->z = a.z;
            c->y = a.y;
            int *t = vb->tag;
            *t = a4;
            vb->FUN_0008ef00();
            c = vb->cursor;
            c->x = v.x;
            c->y = v.y;
            c->z = v.z;
            t = vb->tag;
            *t = a4;
            vb->FUN_0008ef00();
            x = dphi + outerA;
            outerA = (float)x;
        } while (x <= (*(float*)&DAT_0042ef48));
        double y = dtheta + innerB;
        innerB = (float)y;
        if (!(y <= (*(float*)&DAT_0042ef28)))
            break;
    } while (true);
    DAT_0052c2a8->v31(vb);
    (*(*(Device_2c4cb0***)&DAT_0052c2ac))->v16(0);
}
} // namespace fn_002c4cb0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_faaafd8b {

// 0x002c50a0 FUN_002c50a0 (22 B): matches/0x002c50a0.cpp
// sym: ?run@B_2c50a0@fn_faaafd8b@@QAEXXZ
// Same code shape as 0x001c3d20 (propagated; names are from that function)
void B_2c50a0::run() {
    if (p)
        p->g();
    p = 0;
}


// 0x002c50c0 FUN_002c50c0 (406 B): equivalent/0x002c50c0.cpp
// sym: ?FUN_002c50c0@fn_faaafd8b@@YAPAUMatrix@1@PAU21@MMMMMM@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002c50c0 @ 0x002c50c0
// equiv-conv: FUN_002c50c0 ebx stack stack stack stack stack stack
Matrix *FUN_002c50c0(Matrix *out, float fromX, float fromY, float fromZ,
                     float toX, float toY, float toZ)
{
    Matrix mat;
    FUN_0022b980(&mat);
    Vec3_2c50c0 *dir = (Vec3_2c50c0 *)&mat.m[0];
    Vec3_2c50c0 *up = (Vec3_2c50c0 *)&mat.m[4];
    Vec3_2c50c0 *right = (Vec3_2c50c0 *)&mat.m[8];

    dir->x = toX - fromX;
    dir->y = toY - fromY;
    dir->z = toZ - fromZ;
    mat.m[12] = fromX;
    mat.m[13] = fromY;
    mat.m[14] = fromZ;
    dir->FUN_0022d180();

    float dz0 = dir->z * 0.0f;
    float ady = dir->y < 0.0f ? -dir->y : dir->y;
    if (ady > 0.95f) {
        up->x = dz0 - dir->y;
        up->y = dir->x - dz0;
        up->z = dir->y * 0.0f - dir->x * 0.0f;
        up->FUN_0022d180();
        right->x = up->z * dir->y - up->y * dir->z;
        right->y = up->x * dir->z - up->z * dir->x;
        right->z = up->y * dir->x - up->x * dir->y;
    } else {
        float dy0 = dir->y * 0.0f;
        right->x = dy0 - dir->z;
        right->y = dz0 - dir->x * 0.0f;
        right->z = dir->x - dy0;
        right->FUN_0022d180();
        up->x = right->y * dir->z - right->z * dir->y;
        up->y = right->z * dir->x - right->x * dir->z;
        up->z = right->x * dir->y - right->y * dir->x;
    }
    *out = mat;
    return out;
}

} // namespace fn_faaafd8b

// 0x002c5260 FUN_002c5260 (1007 B): equivalent/0x002c5260.cpp [wrapped: conflict: Gfx]
// sym: ?FUN_002c5260@fn_002c5260@@YAXMPAUV3_2c5260@1@M0HHM@Z
namespace fn_002c5260 {
// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 14/14)
// FUN_002c5260 @ 0x002c5260
// equiv-conv: FUN_002c50c0 ebx stack stack stack stack stack stack
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


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double cos(double);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sin(double);
#endif



struct V3_2c5260 {
    float x, y, z;
    void FUN_0022d180();
};

struct Matrix {
    float m[16];
};

class Layer_2c5260 {
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
    virtual void v16(int a);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23(int state, Matrix *m);
};

struct VertexBuf_2c5260 {
    char pad0[8];
    V3_2c5260 *cursor;
    char padc[4];
    int *tag;
    void FUN_0008ef00();
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
    virtual VertexBuf_2c5260* v30(int a, int b, int c, int n, int z);
    virtual void v31(VertexBuf_2c5260 *b);
};


Matrix *FUN_002c50c0(Matrix *out, V3_2c5260 mid, V3_2c5260 end);

void __cdecl FUN_002c5260(float r1, V3_2c5260 *a, float r2, V3_2c5260 *b, int handle, int tag, float n)
{
    struct Frame {
        volatile float theta;
        volatile float sinv;
        V3_2c5260 d;
        volatile float nh;
        volatile float y;
        volatile float z;
        Matrix m;
    } fr;

    fr.theta = 0.0f;
    fr.d.x = b->x - a->x;
    fr.d.y = b->y - a->y;
    double dzx = b->z - a->z;
    fr.d.z = (float)dzx;
    double len2 = dzx * fr.d.z + fr.d.y * fr.d.y + fr.d.x * fr.d.x;
    volatile float h = (float)(sqrt(len2) * 0.5f);
    fr.d.FUN_0022d180();
    volatile float hz = fr.d.z * h;
    V3_2c5260 mid;
    mid.x = fr.d.x * h + a->x;
    mid.y = fr.d.y * h + a->y;
    mid.z = hz + a->z;
    FUN_002c50c0(&fr.m, mid, *b);
    (*(*(Layer_2c5260***)&DAT_0052c2ac))->v23(0, &fr.m);

    int e1 = (r1 != 0.0f) ? 2 : 0;
    int e2 = (r2 != 0.0f) ? 2 : 0;
    VertexBuf_2c5260 *vb = DAT_0052c2a8->v30(handle, 2, 0x2020, (2 * (int)n + 1) * (e2 + e1 + 2), 0);

    volatile float step;
    if (r1 != 0.0f) {
        fr.theta = 0.0f;
        fr.nh = -h;
        fr.y = (float)(cos(0.0) * r1);
        fr.z = (float)(sin(0.0) * r1);
        step = (*(float*)&DAT_0042ef28) / n;
        double t;
        do {
            float yp = fr.y;
            float zp = fr.z;
            fr.y = (float)(cos((double)fr.theta) * r1);
            fr.z = (float)(sin((double)fr.theta) * r1);
            V3_2c5260 *c = vb->cursor;
            c->x = fr.nh;
            c->y = yp;
            c->z = zp;
            *vb->tag = tag;
            vb->FUN_0008ef00();
            c = vb->cursor;
            c->x = fr.nh;
            c->y = fr.y;
            c->z = fr.z;
            *vb->tag = tag;
            vb->FUN_0008ef00();
            t = step + fr.theta;
            fr.theta = (float)t;
        } while (t <= (*(float*)&DAT_0042ef48));
    }
    if (r2 != 0.0f) {
        fr.y = (float)(cos((double)fr.theta) * r2);
        fr.z = (float)(sin((double)fr.theta) * r2);
        fr.theta = 0.0f;
        step = (*(float*)&DAT_0042ef28) / n;
        double t;
        do {
            float yp = fr.y;
            float zp = fr.z;
            fr.y = (float)(cos((double)fr.theta) * r2);
            fr.z = (float)(sin((double)fr.theta) * r2);
            V3_2c5260 *c = vb->cursor;
            c->x = h;
            c->y = yp;
            c->z = zp;
            *vb->tag = tag;
            vb->FUN_0008ef00();
            c = vb->cursor;
            c->x = h;
            c->y = fr.y;
            c->z = fr.z;
            *vb->tag = tag;
            vb->FUN_0008ef00();
            t = step + fr.theta;
            fr.theta = (float)t;
        } while (t <= (*(float*)&DAT_0042ef48));
    }
    fr.theta = 0.0f;
    fr.nh = -h;
    step = (*(float*)&DAT_0042ef28) / n;
    double t;
    do {
        double cx = cos((double)fr.theta);
        volatile float cf = (float)cx;
        double sx = sin((double)fr.theta);
        fr.sinv = (float)sx;
        V3_2c5260 *c = vb->cursor;
        c->x = fr.nh;
        c->y = (float)(cx * r1);
        c->z = (float)(sx * r1);
        *vb->tag = tag;
        vb->FUN_0008ef00();
        c = vb->cursor;
        c->x = h;
        c->y = cf * r2;
        c->z = fr.sinv * r2;
        *vb->tag = tag;
        vb->FUN_0008ef00();
        t = step + fr.theta;
        fr.theta = (float)t;
    } while (t <= (*(float*)&DAT_0042ef48));
    DAT_0052c2a8->v31(vb);
    (*(*(Layer_2c5260***)&DAT_0052c2ac))->v16(0);
}
} // namespace fn_002c5260
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x002c5820 FUN_002c5820 (318 B): equivalent/0x002c5820.cpp [wrapped: conflict: Gfx]
// sym: ?FUN_002c5820@CubeDrawer@fn_002c5820@@QAEXPAUVec3_2c5820@2@M@Z
namespace fn_002c5820 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_002c5820 @ 0x002c5820
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

struct Vec3_2c5820 {
    float x, y, z;
};

struct Prim_2c5820 {
    char pad0[8];
    Vec3_2c5820 *pos;
    char pad0c[4];
    int *tag;
    void FUN_0008ef00();
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
    virtual Prim_2c5820 *Begin(int shape, int a, int flags, int b, int c);
    virtual void End(Prim_2c5820 *p);
};


class CubeDrawer {
public:
    int f0;
    int f4;
    void FUN_002c5820(Vec3_2c5820 *c, float s);
};

void CubeDrawer::FUN_002c5820(Vec3_2c5820 *c, float s)
{
    Prim_2c5820 *p = DAT_0052c2a8->Begin(f0, 2, 0x2020, 6, 0);
    Vec3_2c5820 t;

    *p->tag = f4;
    t = *c;
    p->pos->x = t.x - s;
    p->pos->y = t.y;
    p->pos->z = t.z;
    p->FUN_0008ef00();

    *p->tag = f4;
    t = *c;
    p->pos->x = s + t.x;
    p->pos->y = t.y;
    p->pos->z = t.z;
    p->FUN_0008ef00();

    *p->tag = f4;
    t = *c;
    p->pos->x = t.x;
    p->pos->y = t.y - s;
    p->pos->z = t.z;
    p->FUN_0008ef00();

    *p->tag = f4;
    t = *c;
    p->pos->x = t.x;
    p->pos->y = s + t.y;
    p->pos->z = t.z;
    p->FUN_0008ef00();

    *p->tag = f4;
    t = *c;
    p->pos->x = t.x;
    p->pos->y = t.y;
    p->pos->z = t.z - s;
    p->FUN_0008ef00();

    *p->tag = f4;
    t = *c;
    p->pos->x = t.x;
    p->pos->y = t.y;
    p->pos->z = s + t.z;
    p->FUN_0008ef00();

    DAT_0052c2a8->End(p);
}
} // namespace fn_002c5820
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x002c59f0 FUN_002c59f0 (213 B): equivalent/0x002c59f0.cpp [wrapped: conflict: Gfx]
// sym: ?FUN_002c59f0@LineDrawer@fn_002c59f0@@QAEXHPBUVec3_2c59f0@2@0PBI@Z
namespace fn_002c59f0 {
// STATUS: equivalent (tools/equiv.py level 3: 1479 inputs, branch coverage 6/6)
// FUN_002c59f0 @ 0x002c59f0
// Immediate-mode line list: draws n lines from a[i] to b[i], optionally colouring each from colors[i].
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

struct Vec3_2c59f0 {
    float x, y, z;
};

struct Buffer_2c59f0 {
    char pad00[8];
    Vec3_2c59f0 *position;                 // 8: write cursor for the next vertex
    char pad0c[4];
    unsigned int *colour;           // 0x10
    void FUN_0008ef00();            // emit the vertex written at the cursors
};

class Shader;

class Gfx {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29();
    virtual Buffer_2c59f0 *Begin(Shader *shader, int primitive, int flags, int vertices, int zero);   // slot 30
    virtual void End(Buffer_2c59f0 *buffer);                                                          // slot 31
};


struct LineDrawer {
    Shader *shader;                 // 0
    unsigned int colour;            // 4
    void FUN_002c59f0(int count, const Vec3_2c59f0 *a, const Vec3_2c59f0 *b, const unsigned int *colours);
};

void LineDrawer::FUN_002c59f0(int count, const Vec3_2c59f0 *a, const Vec3_2c59f0 *b, const unsigned int *colours)
{
    Buffer_2c59f0 *buf = DAT_0052c2a8->Begin(shader, 2, 0x2020, count * 2, 0);
    for (int i = 0; i < count; i++) {
        if (colours)
            colour = colours[i];
        Vec3_2c59f0 *p = buf->position;
        unsigned int c = colour;
        p->x = a[i].x;
        p->y = a[i].y;
        p->z = a[i].z;
        *buf->colour = c;
        buf->FUN_0008ef00();
        p = buf->position;
        c = colour;
        p->x = b[i].x;
        p->y = b[i].y;
        p->z = b[i].z;
        *buf->colour = c;
        buf->FUN_0008ef00();
    }
    DAT_0052c2a8->End(buf);
}
} // namespace fn_002c59f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x002c5ad0 FUN_002c5ad0 (216 B): equivalent/0x002c5ad0.cpp [wrapped: conflict: Gfx]
// sym: ?FUN_002c5ad0@Object@fn_002c5ad0@@QAEXPAUVec_2c5ad0@2@@Z
namespace fn_002c5ad0 {
// STATUS: equivalent (tools/equiv.py level 3: 2173 inputs, branch coverage 0/0)
// FUN_002c5ad0 @ 0x002c5ad0
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

struct Vec_2c5ad0 { unsigned int x; float y,z; };
struct Buffer_2c5ad0 { char pad0[8]; Vec_2c5ad0* position; char pad1[4]; unsigned int* color; void FUN_0008ef00(); };
struct Gfx { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual Buffer_2c5ad0* create(unsigned int,int,int,int,int); virtual void finish(Buffer_2c5ad0*); };
struct Object { unsigned int type,color; void FUN_002c5ad0(Vec_2c5ad0* vertices); };
void Object::FUN_002c5ad0(Vec_2c5ad0* vertices) {
 Buffer_2c5ad0* b=DAT_0052c2a8->create(type,3,0x2020,4,0);
 for(int i=0;i<4;++i) {
  *b->color=color;
  Vec_2c5ad0* v=vertices+(i==3?0:i);
  float z=v->z; float y=v->y; unsigned int x=v->x;
  b->position->x=x;
  b->position->y=y;
  b->position->z=z;
  b->FUN_0008ef00();
 }
 DAT_0052c2a8->finish(b);
}
} // namespace fn_002c5ad0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_faaafd8b {

// 0x002c5c90 FUN_002c5c90 (503 B): equivalent/0x002c5c90.cpp
// sym: ?FUN_002c5c90@Obj_2c5c90@fn_faaafd8b@@QAEXPAUSrc_2c5c90@2@M@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002c5c90 @ 0x002c5c90
void Obj_2c5c90::FUN_002c5c90(Src_2c5c90* s, float f)
{
    struct Frame {
        float p0copy;
        float p1copy;
        float neg;
        int oldw8;
        int oldwc;
        float X[3];
        float T[3];
    } fr;
    fr.oldw8 = w8;
    fr.oldwc = wc;
    w4 = s->f14;
    w8 = 0x40000000;
    wc = 0x40000000;
    fr.X[0] = s->p[0];
    fr.X[1] = s->p[1];
    fr.X[2] = s->p[2];
    fr.p1copy = fr.X[1];
    fr.T[0] = fr.X[0] + (f * 0.25f);
    fr.T[1] = fr.p1copy;
    fr.T[2] = fr.X[2];
    FUN_002c5260(0.0f, fr.X, (f * 0.175f), fr.T, w0, w4, w8, wc);

    fr.neg = -(f * 0.25f);
    fr.T[0] = fr.neg + fr.X[0];
    fr.T[1] = fr.p1copy;
    fr.T[2] = fr.X[2];
    FUN_002c5260(0.0f, fr.X, (f * 0.175f), fr.T, w0, w4, w8, wc);

    fr.p0copy = fr.X[0];
    fr.T[0] = fr.X[0];
    fr.T[1] = fr.X[1] + (f * 0.25f);
    fr.T[2] = fr.X[2];
    FUN_002c5260(0.0f, fr.X, (f * 0.175f), fr.T, w0, w4, w8, wc);

    fr.T[0] = fr.p0copy;
    fr.T[1] = fr.neg + fr.X[1];
    fr.T[2] = fr.X[2];
    FUN_002c5260(0.0f, fr.X, (f * 0.175f), fr.T, w0, w4, w8, wc);

    fr.T[0] = fr.p0copy;
    fr.T[1] = fr.p1copy;
    fr.T[2] = fr.X[2] + (f * 0.25f);
    FUN_002c5260(0.0f, fr.X, (f * 0.175f), fr.T, w0, w4, w8, wc);

    fr.T[0] = fr.p0copy;
    fr.T[1] = fr.p1copy;
    fr.T[2] = fr.neg + fr.X[2];
    FUN_002c5260(0.0f, fr.X, (f * 0.175f), fr.T, w0, w4, w8, wc);

    w8 = fr.oldw8;
    wc = fr.oldwc;
}


// 0x002c5e90 FUN_002c5e90 (53 B): matches/0x002c5e90.cpp
// sym: ?fn@Thing@fn_faaafd8b@@QAEXPAUInput@2@M@Z
void Thing::fn(Input* in, float x) {
    work_002c4cb0(x * 0.25f, &in->f, a, (b = in->v), c, d);
}


// 0x002c5ed0 FUN_002c5ed0 (74 B): matches/0x002c5ed0.cpp
// sym: ?FUN_002c5ed0@Obj_2c5ed0@fn_faaafd8b@@QAEXPAXI@Z
void Obj_2c5ed0::FUN_002c5ed0(void* arg, U_2c5ed0 unused) {
    U_2c5ed0 x = *(U_2c5ed0*)((char*)arg + 0x14);
    b = x;
    FUN_002c4cb0(0.2f, (char*)arg + 0x18, a, x, c, d);
    FUN_002c4cb0(0.3f, (char*)arg + 0x18, a, b, c, d);
}


// 0x002c6630 FUN_002c6630 (22 B): matches/0x002c6630.cpp
// sym: ?run@B_2c6630@fn_faaafd8b@@QAEXXZ
// Same code shape as 0x001c3d20 (propagated; names are from that function)
void B_2c6630::run() {
    if (p)
        p->g();
    p = 0;
}

} // namespace fn_faaafd8b

// 0x002c66b0 FUN_002c66b0 (395 B): equivalent/0x002c66b0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_002c66b0@fn_002c66b0@@YAXMPBUVec3_2c66b0@1@0HHHH@Z
namespace fn_002c66b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 4/4)
// FUN_002c66b0 @ 0x002c66b0
struct Vec3_2c66b0 {
    float x, y, z;
    void FUN_0022d180();
};

struct Mat_2c66b0 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(const Vec3_2c66b0 *axis, float angle);
};

hulk_freg __cdecl FUN_00018a20(float v);
void __cdecl FUN_002c4a20(float width, Mat_2c66b0 *m, int a, int b, int c, int d);
void __cdecl FUN_002c5260(float w0, const Vec3_2c66b0 *from, float w1, const Vec3_2c66b0 *to, int a, int b, int c, int d);

struct Frame_2c66b0 {
    Vec3_2c66b0 axis;
    Vec3_2c66b0 dir;
    Mat_2c66b0 m;
};

static float Abs(float v)
{
    return v < 0.0f ? -v : v;
}

void FUN_002c66b0(float width, const Vec3_2c66b0 *p1, const Vec3_2c66b0 *p2, int a, int b, int c, int d)
{
    Frame_2c66b0 f;
    float angle;
    f.dir.x = p1->x - p2->x;
    f.dir.y = p1->y - p2->y;
    f.dir.z = p1->z - p2->z;
    f.dir.FUN_0022d180();
    f.axis.x = f.dir.z;
    f.axis.y = 0.0f;
    f.axis.z = -f.dir.x;
    if (Abs(f.axis.x) <= 1e-05f && Abs(f.axis.z) <= 1e-05f) {
        f.axis.x = 1.0f;
        f.axis.y = 0.0f;
        f.axis.z = 0.0f;
        angle = 3.1415927f;
    } else {
        angle = -FUN_00018a20(f.dir.y);
    }
    f.m.FUN_0022b980();
    f.m.FUN_0022baf0(&f.axis, angle);
    ((owners::Target_22be40 *)&(f.m))->FUN_0022be40((const int *)(const Vec3_2c66b0 *)p1);
    FUN_002c4a20(width, &f.m, a, b, c, d);
    f.m.FUN_0022baf0(&f.axis, angle + 3.1415927f);
    ((owners::Target_22be40 *)&(f.m))->FUN_0022be40((const int *)(const Vec3_2c66b0 *)p2);
    FUN_002c4a20(width, &f.m, a, b, c, d);
    FUN_002c5260(width, p1, width, p2, a, b, c, d);
}
} // namespace fn_002c66b0

namespace fn_faaafd8b {

// 0x002c6840 FUN_002c6840 (90 B): equivalent/0x002c6840.cpp
// sym: ?FUN_002c6840@Object@fn_faaafd8b@@QAEPAU12@XZ
// STATUS: equivalent (tools/equiv.py level 3: 20014 inputs, branch coverage 4/4)
// FUN_002c6840 @ 0x002c6840
Object* Object::FUN_002c6840() { resource=0; value=-1; a=4.0f; b=4.0f; Resource* r=(*(Manager**)&DAT_0052c2a0)->slot11("simple",0); if(r) r->FUN_00000000(); if(resource) resource->FUN_00000001(); resource=r; r->FUN_00000006(((char*)0x54494c),0); return this; }


// 0x002c6900 FUN_002c6900 (374 B): equivalent/0x002c6900.cpp
// sym: ?FUN_002c6900@Obj_2c6900@fn_faaafd8b@@QAEXPAUSrc_2c6900@2@M@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_002c6900 @ 0x002c6900
void Obj_2c6900::FUN_002c6900(Src_2c6900* s, float f)
{
    double k = f * -0.65f; // kept in a register, unrounded
    w4 = s->f14;
    float sx = s->v[0], sy = s->v[1], sz = s->v[2];
    struct Frame { float A[3]; float t[3]; float S[3]; float B[3]; } fr;
    float* t = fr.t;
    float* A = fr.A;
    float* B = fr.B;
    fr.S[0] = sx; fr.S[1] = sy; fr.S[2] = sz;
    t[0] = sx * k + s->p[0];
    t[1] = sy * k + s->p[1];
    t[2] = sz * k + s->p[2];
    A[0] = t[0];
    A[1] = t[1];
    A[2] = t[2];
    A[0] = sx * f + A[0];
    A[1] = sy * f + A[1];
    A[2] = sz * f + A[2];
    B[0] = A[0];
    B[1] = A[1];
    B[2] = A[2];
    double m = f * 0.3f;
    B[0] = sx * m + B[0];
    B[1] = sy * m + B[1];
    B[2] = sz * m + B[2];
    float g = f * 0.05f;
    FUN_002c5260(g, t, g, A, w0, s->f14, w8, wc);
    FUN_002c5260(f * 0.15f, A, 0.0f, B, w0, w4, w8, wc);
}

} // namespace fn_faaafd8b
