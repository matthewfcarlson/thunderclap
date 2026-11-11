// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002d3dc0..0x002d6720 (kind game, layer engine, confidence high), dominant class pure3d::SpriteParticleEmitter
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f0cbe20f {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f0cbe20f {} using namespace fn_f0cbe20f;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f0cbe20f {
class SpriteParticleUpdater {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual unsigned int vfunc_3();
    virtual void f4();
    virtual void f5();
};
struct DrawablePrimitive_2d3de0 {
    DrawablePrimitive_2d3de0();
    virtual void f();
    char p[0x3c];
};
struct Sub_2d3de0 {
    void Init_0022b980();
    char q[0x40];
};
struct ParticleEmitter_2d3de0 : DrawablePrimitive_2d3de0 {
    Sub_2d3de0 s;
    int a[9];
    char b0, b1, b2;
    ParticleEmitter_2d3de0();
    virtual void f();
};
class Base_2d3e60 {
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
};
struct Inner_2d3e80 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h(int, int);
};
class ParticleEmitter {
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
    virtual float f18(float);
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    char pad[0x84];
    struct Other {
        virtual void a();
        virtual void b();
        virtual void c();
        virtual void d();
        virtual void e();
        virtual void g();
        virtual void h();
        virtual void i();
        virtual float f(float);
    }* ptr;
};
class DrawablePrimitive_2d3ec0 {
  public:
    virtual void f0();
};
class IValueChangedReceiver_2d3ec0 {
  public:
    virtual void f1();
};
extern "C" char DAT_00415244[];
extern "C" char DAT_00415247[];
extern "C" char DAT_00445053[];
extern "C" char DAT_0046494c[];
extern "C" char DAT_00495053[];
extern int hulk_at_0042f26c;
class Src_2d4040 {
  public:
    void* Find_00288960(unsigned a, unsigned b) throw();
};
class EmitterBlendState_2d4040 {
  public:
    void* vptr;
    void* v[18];
    EmitterBlendState_2d4040(Src_2d4040* s) throw();
};
typedef unsigned int U_2d4350;
extern U_2d4350 hulk_at_0042f27c;
extern U_2d4350 hulk_at_003f6098;
void drop_0008d340(U_2d4350);
class OverLifeAttributes_2d4350 {
  public:
    hulk_uintptr vptr;
    U_2d4350 x[3];
    U_2d4350 a[8];
    void f();
};
class Ref_2d44e0 {
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
};
typedef unsigned int u32_2d45e0;
struct V {
    char b[64];
    V(const void*, const void*);
};
extern void* hulk_at_0042f1e4[];
class Ref_2d4b50 {
  public:
    virtual void F0();
    virtual void Release();
};
class DrawablePrimitive_2d4b50 {
  public:
    void* vptr;
    void Fin_002a50a0();
};
class ParticleEmitter_2d4b50 : public DrawablePrimitive_2d4b50 {
  public:
    char pad[0x7c];
    Ref_2d4b50* m80;
    Ref_2d4b50* m84;
    Ref_2d4b50* m88;
    Ref_2d4b50* m8c;
    Ref_2d4b50* m90;
    ~ParticleEmitter_2d4b50();
};
} // namespace fn_f0cbe20f
namespace pure3d {
struct Obj_2d4d40 {
    virtual void f0();
    virtual void f1();
};
}
namespace fn_f0cbe20f {
class Obj_2d4d70 {
  public:
    virtual void Release();
    virtual void AddRef();
};
class Obj_2d4db0 {
  public:
    virtual void f();
    virtual void g();
};
} // namespace fn_f0cbe20f
namespace pure3d {
struct Ref_2d4de0 {
    virtual void Release();
    virtual void AddRef();
};
}
namespace pure3d {
class Ref_2d4e20 {
  public:
    virtual void AddRef();
    virtual void Release();
};
}
namespace fn_f0cbe20f {
struct RefObj_2d4e80 {
    virtual void FUN_vf0();
    virtual void FUN_vf1();
};
struct Extra_2d4e80 {
    Extra_2d4e80 *FUN_0022b980();
};
extern "C" void *FUN_0008d690(unsigned int size);
struct Config_2d4e80 {
    RefObj_2d4e80 *ref;
    char pad04[4];
    char blockA[0x40];
    char blockB[0x40];
    int f88;
    int f8c;
    char f90;
    int f94;
    Extra_2d4e80 *extra;
    int f9c;
    int fa0;
    int fa4;
    int fa8;
    int fac;
    int fb0;
    char fb4;
    int tail[22];
    char f110;
    char f111;

    Config_2d4e80 *FUN_002d4e80(const Config_2d4e80 *src);
};
class Thing_2d5090 {
  public:
    virtual void f0();
    virtual void f1();
};
class Obj_2d5090 {
  public:
    Thing_2d5090* p;
    char pad[0x94];
    int x;
};
struct Curve;
struct Key_2d50c0 {
    const Curve *c[0x13];
};
struct Sink88 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(Ctx *ctx, void *out);
};
struct Sink8c {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void v6(Ctx *ctx, void *out);
};
struct Sink94 {
    void FUN_0028ac90(Ctx *ctx, void *out);
};
float __cdecl FUN_0028b150(const Curve *a, const Curve *b, int t, Ctx *ctx);
unsigned int *__cdecl FUN_0028b2f0(unsigned int *out, const Curve *a, const Curve *b, int t, Ctx *ctx);
unsigned char __cdecl FUN_0028b100(const Curve *a, const Curve *b, int t, Ctx *ctx);
struct Vec3_2d53d0 {
    float x, y, z;
};
struct Matrix {
  public:
    char _m_pad_0[0x30];
    Vec3_2d53d0 pos;
    char _m_pad_3c[0x4];
    void FUN_0022b980();
    void FUN_0022ca90(const void *a, const void *b);
};
struct State_2d4200 {
 unsigned int field0; char pad4[4]; Matrix first; Matrix second;
 float f88,f8c; unsigned char enabled; char pad91[3];
 float f94,f98,f9c,fa0,fa4,fa8,fac,fb0;
 unsigned char flagb4; char padb5[3];
 float fb8,fbc,fc0,fc4,fc8,fcc,fd0,fd4,fd8,fdc,fe0,fe4,fe8,fec,ff0,ff4,ff8,ffc,f100,f104,f108;
 int index; unsigned char flag110,flag111;
 State_2d4200* FUN_002d4200();
};
struct MatrixHolder {
    Matrix *FUN_0028faa0();
};
class Blend_2d50c0 {
public:
    char pad0[8];
    Matrix mat;             // 0x08
    char f48[0x30];         // 0x48
    char f78[0x10];         // 0x78
    Sink88 *sink88;         // 0x88
    Sink8c *sink8c;         // 0x8c
    char f90[4];            // 0x90
    Sink94 *sink94;         // 0x94
    char pad98[0xac - 0x98];
    float fac, fb0;         // 0xac, 0xb0
    char padb4[4];
    float fb8, fbc, fc0, fc4, fc8, fcc, fd0, fd4, fd8;
    char paddc[0xe4 - 0xdc];
    float fe4, fe8, fec, ff0, ff4, ff8, ffc, f100, f104, f108;
    unsigned int f10c;
    unsigned char f110, f111;

    void FUN_002d50c0(Ctx *ctx, const Key_2d50c0 *a, const Key_2d50c0 *b, int t, const void *xform);
};
class PositionReader {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReadPosition(Stream* s, Vec3_2d53d0* out);        // slot 4
};
class RotationReader {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void ReadRotation(Stream* s, Matrix* out);      // slot 6
};
struct Curve_2d53d0 {
    void FUN_0028a1c0(Stream* s, float* out);
};
struct ColorCurve {
    void FUN_0028ad20(Stream* s, unsigned int* out);
};
struct ByteCurve {
    void FUN_0028a0b0(Stream* s, unsigned char* out);
};
struct Desc_2d53d0 {
    char pad00[8];
    Curve_2d53d0* c08;
    Curve_2d53d0* c0c;
    Curve_2d53d0* c10;
    Curve_2d53d0* c14;
    Curve_2d53d0* c18;
    Curve_2d53d0* c1c;
    Curve_2d53d0* c20;
    Curve_2d53d0* c24;
    Curve_2d53d0* c28;
    Curve_2d53d0* c2c;
    Curve_2d53d0* c30;
    Curve_2d53d0* c34;
    Curve_2d53d0* c38;
    ColorCurve* c3c;
    ByteCurve* b40;
    ByteCurve* b44;
    ByteCurve* b48;
};
struct Extra_2d53d0 {
    void FUN_0028ac90(Stream* s, int* out);
};
struct Camera {
    Matrix* FUN_0028faa0();
};
struct CameraHolder {
    Camera* camera;
};
class Emitter_2d53d0 {
public:
    void FUN_002d53d0(Stream* s, Desc_2d53d0* d, Matrix* parent);

    char pad0[0x8];
    Matrix local;  // 0x8
    Matrix orient;  // 0x48
    PositionReader* positionReader;  // 0x88
    RotationReader* rotationReader;  // 0x8c
    int f90;  // 0x90
    Extra_2d53d0* extra;  // 0x94
    char pad98[0x14];
    float fac;  // 0xac
    float fb0;  // 0xb0
    char padb4[0x4];
    float fb8;  // 0xb8
    float fbc;  // 0xbc
    float fc0;  // 0xc0
    float fc4;  // 0xc4
    float fc8;  // 0xc8
    float fcc;  // 0xcc
    float fd0;  // 0xd0
    float fd4;  // 0xd4
    float fd8;  // 0xd8
    char paddc[0x8];
    float fe4;  // 0xe4
    float fe8;  // 0xe8
    float fec;  // 0xec
    float ff0;  // 0xf0
    float ff4;  // 0xf4
    float ff8;  // 0xf8
    float ffc;  // 0xfc
    float f100;  // 0x100
    float f104;  // 0x104
    float f108;  // 0x108
    unsigned int color;  // 0x10c
    unsigned char b110;  // 0x110
    unsigned char b111;  // 0x111
};
struct Vec3_2d5a70 {
    float x, y, z;
};
struct Particle_2d5a70 {
    Vec3_2d5a70 pos;
    unsigned int color;
    float f10;
    float f14;
    unsigned char b18;
    unsigned char b19;
    short s1a;
    float f1c;
    Vec3_2d5a70 vel;
    int f2c;
    float f30;
    int f34;
    int f38;
    short s3c;
    unsigned char b3e;
};
struct ParticlePool {
    char pad0[8];
    unsigned int size;
    Particle_2d5a70** data;
};
struct Palette_2d5a70 {
    char pad0[8];
    int count;
};
class SpriteParticleEmitter {
  public:
    virtual V* vfunc_22(V* out);
    char _m_pad_4[0x80];
    ParticlePool* pool;
    char _m_pad_88[0x68];
    char x[64];
    char _m_pad_130[0x1c];
    int count;
    char _m_pad_150[0x10];
    float f160;
    float f164;
    char _m_pad_168[0x4];
    float f16c;
    float f170;
    char _m_pad_174[0x4];
    float f178;
    float f17c;
    char _m_pad_180[0x4];
    float f184;
    float f188;
    float f18c;
    float f190;
    char _m_pad_194[0x4];
    float f198;
    float f19c;
    char _m_pad_1a0[0x14];
    int f1b4;
    signed char c1b8;
    signed char c1b9;
    char _m_pad_1ba[0x2];
    Palette_2d5a70* palette;
    char _m_pad_1c0[0x8];
    Particle_2d5a70** begin;
    Particle_2d5a70** end;
    bool vfunc_14(Vec3_2d5a70* dir, Vec3_2d5a70* pos, int arg2);
};
struct Rng_2d5a70 {
    float FUN_00143100();
    char FUN_002d49c0(int lo, int hi);
    char FUN_00011380(int lo, int hi);
};
unsigned int* FUN_002e6780(unsigned int* out, int a, unsigned int b);
unsigned int* FUN_002e6840(unsigned int* out, unsigned int v, unsigned int b);
struct Buffer_2d5cb0 {
    int a[2];
    int used;
    int* data;
};
class Obj_2d5e00 {
  public:
    virtual void a();
    virtual void b();
    char pad[0x14];
    int kind;
};
class Obj_2d5e70 {
  public:
    virtual void a();
    virtual void b();
};
struct Inner_2d5ec0 {
    void FnA_002d53d0(int, int, void*);
    void FnB_002d50c0(int, int, int, int, void*);
};
struct SpriteParticleEmitter_2d5ec0 {
    char pad0[0x40];
    char field40[0x58];
    int index;
    int value9c;
    char padA0[4];
    unsigned char flag;
    char padA5[3];
    Inner_2d5ec0 inner;
    char padB0[0x128];
    int* items;
    void target(int arg);
};
} // namespace fn_f0cbe20f
extern "C" double __cdecl __floor_default(double);
namespace fn_f0cbe20f {
struct SpriteParticleEmitter_2d5f20;
struct Backend_2d5f20 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void update(int);
    virtual int consume(int, void*, int, int, SpriteParticleEmitter_2d5f20*);
};
struct SpriteParticleEmitter_2d5f20 {
    char pad0[0x88];
    Backend_2d5f20* backend;
    char pad1[0xb0 - 0x8c];
    char data[0x14c - 0xb0];
    int used;
    float credit;
    char pad2[0x1c8 - 0x154];
    int* begin;
    int* end;
    void target(int a, int b, int c);
};
struct Item_2d5fe0 { char pad[0x2c]; volatile float current; volatile float limit; };
struct Pool_2d5fe0 { char pad[8]; volatile unsigned count; Item_2d5fe0* volatile* volatile items; };
struct Updater_2d5fe0 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void update(float, pure3d::SpriteParticleEmitter*); virtual void special(float, pure3d::SpriteParticleEmitter*); };
struct Sub_2d63a0 {
    void Init_002d4200();
    char pad[0x114];
};
struct ParticleEmitter_2d63a0 {
    ParticleEmitter_2d63a0();
    virtual void V1();
};
struct SpriteParticleEmitter_2d63a0 : ParticleEmitter_2d63a0 {
    SpriteParticleEmitter_2d63a0();
    virtual void V1();
    char pad[0xa8 - 4];
    Sub_2d63a0 sub;
    int f1bc, f1c0, f1c4, f1c8, f1cc, f1d0, f1d4, f1d8;
};
class Obj_2d66b0 {
  public:
    hulk_intptr run_002d63f0(pure3d::SpriteParticleEmitter*);
};
extern "C" Obj_2d66b0* alloc(hulk_intptr);


// 0x002d3dc0 FUN_002d3dc0 (6 B): matches/0x002d3dc0.cpp
// sym: ?vfunc_3@SpriteParticleUpdater@fn_f0cbe20f@@UAEIXZ
// Same code shape as 0x002d1230 (propagated; names are from that function)
unsigned int SpriteParticleUpdater::vfunc_3() {
    return 0x54525053;
}


// 0x002d3de0 FUN_002d3de0 (101 B): matches/0x002d3de0.cpp
// sym: ??0ParticleEmitter_2d3de0@fn_f0cbe20f@@QAE@XZ
ParticleEmitter_2d3de0::ParticleEmitter_2d3de0() {
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 0;
    a[6] = 0;
    a[7] = 0;
    a[8] = 0;
    b0 = 0;
    b1 = 1;
    b2 = 0;
    s.Init_0022b980();
}

} // namespace fn_f0cbe20f

// 0x002d3e50 pure3d::ParticleEmitter::vfunc_5 (6 B): matches/0x002d3e50.cpp
// sym: ?vfunc_5@ParticleEmitter@pure3d@@UAEHXZ
// Same code shape as 0x0004e0b0 (propagated; names are from that function)
int pure3d::ParticleEmitter::vfunc_5() {
    return 2;
}


// 0x002d3e60 pure3d::ParticleEmitter::vfunc_16 (18 B): matches/0x002d3e60.cpp
// sym: ?vfunc_16@ParticleEmitter@pure3d@@UAEXXZ
void pure3d::ParticleEmitter::vfunc_16() {
    if ((*(Base_2d3e60 * *)&this->f_88))
        (*(Base_2d3e60 * *)&this->f_88)->f9();
}


// 0x002d3e80 pure3d::ParticleEmitter::vfunc_17 (20 B): matches/0x002d3e80.cpp
// sym: ?vfunc_17@ParticleEmitter@pure3d@@UAEXHH@Z
void pure3d::ParticleEmitter::vfunc_17(int a, int b) {
    if ((*(Inner_2d3e80 * *)&this->f_88))
        (*(Inner_2d3e80 * *)&this->f_88)->h(a, b);
}

namespace fn_f0cbe20f {

// 0x002d3ea0 pure3d::ParticleEmitter::vfunc_18 (26 B): matches/0x002d3ea0.cpp
// sym: ?f18@ParticleEmitter@fn_f0cbe20f@@UAEMM@Z
// data: zero_2d3ea0 = DAT_003f32e0
float ParticleEmitter::f18(float x) {
    if (ptr)
        return ptr->f(x);
    return DAT_003f32e0;
}

} // namespace fn_f0cbe20f

// 0x002d3ec0 pure3d::ParticleEmitter::vfunc_20 (7 B): matches/0x002d3ec0.cpp
// sym: ?vfunc_20@ParticleEmitter@pure3d@@UAEMXZ
// Same code shape as 0x000d7a30 (propagated; names are from that function)
hulk_freg pure3d::ParticleEmitter::vfunc_20() {
    return this->f_a0;
}


// 0x002d3f80 pure3d::ParticleEmitter::vfunc_22 (23 B): matches/0x002d3f80.cpp [wrapped: conflict: pure3d::ParticleEmitter]
// sym: ?vfunc_22@ParticleEmitter@pure3d@fn_002d3f80@@QAE?AUBlock@3@XZ
namespace fn_002d3f80 {
struct Block {
    int a[16];
};
namespace pure3d {
class ParticleEmitter {
    char pad[0x40];
    Block b;

  public:
    Block vfunc_22();
};
Block ParticleEmitter::vfunc_22() {
    return b;
}
} // namespace pure3d
} // namespace fn_002d3f80


// 0x002d3fa0 pure3d::ParticleEmitter::vfunc_24 (7 B): matches/0x002d3fa0.cpp
// sym: ?vfunc_24@ParticleEmitter@pure3d@@UAEIXZ
hulk_uintptr pure3d::ParticleEmitter::vfunc_24() {
    return this->f_80;
}


// 0x002d3fb0 pure3d::ParticleEmitter::vfunc_26 (7 B): matches/0x002d3fb0.cpp
// sym: ?vfunc_26@ParticleEmitter@pure3d@@UAEIXZ
// Same code shape as 0x002b95c0 (propagated; names are from that function)
hulk_uintptr pure3d::ParticleEmitter::vfunc_26() {
    return this->f_84;
}


// 0x002d3fc0 pure3d::ParticleEmitter::vfunc_28 (7 B): matches/0x002d3fc0.cpp
// sym: ?vfunc_28@ParticleEmitter@pure3d@@UAEHXZ
// Same code shape as 0x000cae70 (propagated; names are from that function)
int pure3d::ParticleEmitter::vfunc_28() {
    return (*(int *)&this->f_88);
}


// 0x002d3fd0 pure3d::ParticleEmitter::vfunc_30 (7 B): matches/0x002d3fd0.cpp
// sym: ?vfunc_30@ParticleEmitter@pure3d@@UAEIXZ
 // namespace pure3d
unsigned int pure3d::ParticleEmitter::vfunc_30() {
    return *(unsigned int*)((char*)this + 0x8c);
}


// 0x002d3fe0 pure3d::ParticleEmitter::vfunc_32 (7 B): matches/0x002d3fe0.cpp
// sym: ?vfunc_32@ParticleEmitter@pure3d@@UAEIXZ
// Same code shape as 0x001d4fc0 (propagated; names are from that function)
hulk_uintptr pure3d::ParticleEmitter::vfunc_32() {
    return this->f_90;
}

namespace fn_f0cbe20f {

// 0x002d4040 FUN_002d4040 (425 B): matches/0x002d4040.cpp
// sym: ??0EmitterBlendState_2d4040@fn_f0cbe20f@@QAE@PAVSrc_2d4040@1@@Z
EmitterBlendState_2d4040::EmitterBlendState_2d4040(Src_2d4040* s) throw() {
    v[0] = 0;
    vptr = &hulk_at_0042f26c;
    v[1] = 0;
    v[2] = 0;
    v[3] = 0;
    v[4] = 0;
    v[5] = 0;
    v[6] = 0;
    v[7] = 0;
    v[8] = 0;
    v[9] = 0;
    v[10] = 0;
    v[11] = 0;
    v[12] = 0;
    v[13] = 0;
    v[14] = 0;
    v[15] = 0;
    v[16] = 0;
    v[17] = 0;
    if (s) {
        v[1] = s->Find_00288960(((hulk_intptr)((char*)0x544152)), 0x31544c46);
        v[2] = s->Find_00288960(((int)0x46494c), 0x31544c46);
        v[3] = s->Find_00288960(0x5646494c, 0x31544c46);
        v[4] = s->Find_00288960(((int)0x445053), 0x31544c46);
        v[5] = s->Find_00288960(0x56445053, 0x31544c46);
        v[6] = s->Find_00288960(0x5a4953, 0x31544c46);
        v[7] = s->Find_00288960(0x565a4953, 0x31544c46);
        v[8] = s->Find_00288960(((int)0x495053), 0x31544c46);
        v[9] = s->Find_00288960(0x56495053, 0x31544c46);
        v[10] = s->Find_00288960(((hulk_intptr)((char*)0x544757)), 0x31544c46);
        v[11] = s->Find_00288960(0x56544757, 0x31544c46);
        v[12] = s->Find_00288960(((int)0x415247), 0x31544c46);
        v[13] = s->Find_00288960(((int)0x415244), 0x31544c46);
        v[14] = s->Find_00288960(((hulk_intptr)((char*)0x524c43)), ((hulk_intptr)((char*)0x524c43)));
        v[15] = s->Find_00288960(0x56524c43, ((hulk_intptr)((char*)0x544e49)));
        v[16] = s->Find_00288960(((hulk_intptr)((char*)0x504c41)), ((hulk_intptr)((char*)0x544e49)));
        v[17] = s->Find_00288960(0x56504c41, ((hulk_intptr)((char*)0x544e49)));
    }
}


// 0x002d4200 FUN_002d4200 (261 B): equivalent/0x002d4200.cpp
// sym: ?FUN_002d4200@State_2d4200@fn_f0cbe20f@@QAEPAU12@XZ @48e137c2bf06 @w3f481ec5888b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d4200 @ 0x002d4200
State_2d4200* State_2d4200::FUN_002d4200() {
 fb0=fc0=fc4=fcc=fd0=fd4=fd8=fec=ff0=ff8=f100=f108=1.0f;
 field0=0; f88=0.0f; f8c=0.0f; enabled=1;
 f94=f98=f9c=fa0=fa4=fa8=0.0f;
 fac=10.0f; flagb4=0; fb8=30.0f;
 fbc=fc8=fdc=fe0=fe4=fe8=ff4=ffc=f104=0.0f;
 index=-1; flag110=0; flag111=0;
 first.FUN_0022b980(); second.FUN_0022b980();
 return this;
}


// 0x002d4350 FUN_002d4350 (92 B): matches/0x002d4350.cpp
// sym: ?f@OverLifeAttributes_2d4350@fn_f0cbe20f@@QAEXXZ
void OverLifeAttributes_2d4350::f() {
    vptr = (hulk_uintptr)&hulk_at_0042f27c;
    drop_0008d340(a[0]);
    drop_0008d340(a[1]);
    drop_0008d340(a[2]);
    drop_0008d340(a[3]);
    drop_0008d340(a[4]);
    drop_0008d340(a[5]);
    drop_0008d340(a[6]);
    drop_0008d340(a[7]);
    vptr = (hulk_uintptr)&hulk_at_003f6098;
}

} // namespace fn_f0cbe20f

// 0x002d43b0 pure3d::SpriteParticleEmitter::vfunc_11 (6 B): matches/0x002d43b0.cpp
// sym: ?vfunc_11@SpriteParticleEmitter@pure3d@@UAEIXZ
// Same code shape as 0x002d1230 (propagated; names are from that function)
unsigned int pure3d::SpriteParticleEmitter::vfunc_11() {
    return 0x54525053;
}


// 0x002d43c0 pure3d::SpriteParticleEmitter::vfunc_3 (3 B): matches/0x002d43c0.cpp
// sym: ?vfunc_3@SpriteParticleEmitter@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::SpriteParticleEmitter::vfunc_3() {
    return true;
}


// 0x002d43d0 pure3d::SpriteParticleEmitter::vfunc_6 (241 B): matches/0x002d43d0.cpp [wrapped: conflict: pure3d::SpriteParticleEmitter]
// sym: ?vfunc_6@SpriteParticleEmitter@pure3d@fn_002d43d0@@UAEXXZ
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_002d43d0 {
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

struct StateHook {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void begin();
    virtual void end();
};
namespace pure3d {
struct SpriteParticleEmitter;
}
struct Gfx {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void setMode(int);
    virtual int getMode();
    virtual void setFlag(unsigned char);
    virtual unsigned char getFlag();
};
struct ParticleDrawer {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void draw(pure3d::SpriteParticleEmitter*);
};
namespace pure3d {
struct SpriteParticleEmitter {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad04[0x7c];
    StateHook* hook;
    char pad84[0xc];
    ParticleDrawer* drawer;
    char pad94[0x11];
    unsigned char modeEnabled;
    unsigned char flag;
    char padA7[0x91];
    unsigned char active;
};
void SpriteParticleEmitter::vfunc_6() {
    if (active != 1 || !drawer)
        return;
    if (hook)
        hook->begin();
    unsigned char oldFlag = DAT_0052c2a8->getFlag();
    if (oldFlag != flag)
        DAT_0052c2a8->setFlag(flag);
    int oldMode = DAT_0052c2a8->getMode();
    if (!modeEnabled && oldMode != 1)
        DAT_0052c2a8->setMode(1);
    drawer->draw(this);
    if (!modeEnabled && oldMode != 1)
        DAT_0052c2a8->setMode(oldMode);
    if (oldFlag != flag)
        DAT_0052c2a8->setFlag(oldFlag);
    if (hook)
        hook->end();
}
} // namespace pure3d
} // namespace fn_002d43d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x002d44d0 pure3d::SpriteParticleEmitter::vfunc_13 (7 B): matches/0x002d44d0.cpp
// sym: ?vfunc_13@SpriteParticleEmitter@pure3d@@UAEIXZ
unsigned int pure3d::SpriteParticleEmitter::vfunc_13() {
    return this->f_14c;
}


// 0x002d44e0 pure3d::SpriteParticleEmitter::vfunc_16 (69 B): matches/0x002d44e0.cpp
// sym: ?vfunc_16@SpriteParticleEmitter@pure3d@@UAEXXZ
void pure3d::SpriteParticleEmitter::vfunc_16() {
    *(unsigned int*)(reinterpret_cast<char*>(this) + 0x158) = 0x3f800000;
    *(unsigned int*)(reinterpret_cast<char*>(this) + 0x168) = 0x3f800000;
    *(unsigned int*)(reinterpret_cast<char*>(this) + 0x174) = 0x3f800000;
    *(unsigned int*)(reinterpret_cast<char*>(this) + 0x180) = 0x3f800000;
    *(unsigned int*)(reinterpret_cast<char*>(this) + 0x194) = 0x3f800000;
    *(unsigned int*)(reinterpret_cast<char*>(this) + 0x1a0) = 0x3f800000;
    *(unsigned int*)(reinterpret_cast<char*>(this) + 0x1a8) = 0x3f800000;
    *(unsigned int*)(reinterpret_cast<char*>(this) + 0x1b0) = 0x3f800000;
    if ((*(Ref_2d44e0 * *)&this->f_88))
        (*(Ref_2d44e0 * *)&this->f_88)->j();
}


// 0x002d4530 pure3d::SpriteParticleEmitter::vfunc_18 (118 B): equivalent/0x002d4530.cpp [wrapped: conflict: pure3d::SpriteParticleEmitter]
// sym: ?vfunc_18@SpriteParticleEmitter@pure3d@fn_002d4530@@UAEMH@Z @21dddd51eef6 @w11623ad8cd91
namespace fn_002d4530 {
// STATUS: equivalent (tools/equiv.py level 3: 3049 inputs, branch coverage 18/18)
// pure3d::SpriteParticleEmitter::vfunc_18 @ 0x002d4530
class Source_2d4530 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual float Get(int which);
};

namespace pure3d {
class SpriteParticleEmitter {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual float vfunc_18(int which);
    char pad04[0x88 - 0x4 - 0x0];
    Source_2d4530 *source;
    char pad8c[0x158 - 0x8c];
    float f158;
    char pad15c[0x168 - 0x15c];
    float f168;
    char pad16c[0x174 - 0x16c];
    float f174;
    char pad178[0x180 - 0x178];
    float f180;
    char pad184[0x194 - 0x184];
    float f194;
    char pad198[0x1a0 - 0x198];
    float f1a0;
    char pad1a4[0x1a8 - 0x1a4];
    float f1a8;
    char pad1ac[0x1b0 - 0x1ac];
    float f1b0;
};
}

float pure3d::SpriteParticleEmitter::vfunc_18(int which)
{
    switch (which) {
    case 0:
        return f158;
    case 7:
        return f168;
    case 8:
        return f174;
    case 9:
        return f180;
    case 10:
        return f194;
    case 11:
        return f1a0;
    case 12:
        return f1a8;
    case 13:
        return f1b0;
    }
    if (source != 0)
        return source->Get(which);
    return 0.0f;
}
} // namespace fn_002d4530


// 0x002d45e0 pure3d::SpriteParticleEmitter::vfunc_7 (7 B): matches/0x002d45e0.cpp
// sym: ?vfunc_7@SpriteParticleEmitter@pure3d@@UAEIXZ
// Same code shape as 0x001d4e00 (propagated; names are from that function)
hulk_uintptr pure3d::SpriteParticleEmitter::vfunc_7() {
    return (unsigned int)((*(u32_2d45e0 *)&this->f_a8));
}


// 0x002d45f0 pure3d::SpriteParticleEmitter::vfunc_9 (3 B): matches/0x002d45f0.cpp
// sym: ?vfunc_9@SpriteParticleEmitter@pure3d@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char pure3d::SpriteParticleEmitter::vfunc_9() {
    return 0;
}


// 0x002d4600 pure3d::SpriteParticleEmitter::vfunc_21 (7 B): matches/0x002d4600.cpp
// sym: ?vfunc_21@SpriteParticleEmitter@pure3d@@UAEEXZ
 // namespace pure3d
unsigned char pure3d::SpriteParticleEmitter::vfunc_21() {
    return (*(char (*)[308])&this->f_04)[0x134];
}

namespace fn_f0cbe20f {

// 0x002d4610 pure3d::SpriteParticleEmitter::vfunc_22 (50 B): matches/0x002d4610.cpp
// sym: ?vfunc_22@SpriteParticleEmitter@fn_f0cbe20f@@UAEPAUV@2@PAU32@@Z
V* SpriteParticleEmitter::vfunc_22(V* out) {
    V tmp((char*)this + 0x40, x);
    *out = tmp;
    return out;
}

} // namespace fn_f0cbe20f

// 0x002d4650 pure3d::SpriteParticleEmitter::vfunc_10 (172 B): equivalent/0x002d4650.cpp [wrapped: conflict: pure3d::SpriteParticleEmitter]
// sym: ?vfunc_10@SpriteParticleEmitter@pure3d@fn_002d4650@@UAEXXZ @3a5d709d16f8 @we9733626e8b1
namespace fn_002d4650 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// pure3d::SpriteParticleEmitter::vfunc_10 @ 0x002d4650
namespace pure3d {
struct Matrix { float elements[16]; };
struct SpriteParticleEmitter {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual Matrix* vfunc_22(Matrix*);
 char pad[16];
 float minX,minY,minZ,maxX,maxY,maxZ,centerX,centerY,centerZ,radius;
};
void SpriteParticleEmitter::vfunc_10() {
 Matrix temp;
 Matrix* transform = vfunc_22(&temp);
 float x = transform->elements[12];
 float y = transform->elements[13];
 float z = transform->elements[14];
 maxZ = z + 0.01f;
 maxX = x + 0.01f;
 maxY = y + 0.01f;
 minZ = z - 0.01f;
 minX = x - 0.01f;
 minY = y - 0.01f;
 centerX=x; centerY=y; centerZ=z; radius=0.01f;
}
}
} // namespace fn_002d4650


// 0x002d49c0 FUN_002d49c0 (85 B): equivalent/0x002d49c0.cpp
// sym: ?FUN_002d49c0@Random_2d49c0@owners@@QAEHHH@Z @e5c8b242a819 @w4e8fc7f52f9f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d49c0 @ 0x002d49c0
int owners::Random_2d49c0::FUN_002d49c0(int base, int range) {
    first = (first & 0xffffu) * 0x9069u + (first >> 16);
    second = (second & 0xffffu) * 0x4650u + (second >> 16);
    unsigned int value = (second & 0xffffu) + (first << 16);
    unsigned int divisor = (unsigned int)range * 2u + 1u;
    return (int)(value % divisor - (unsigned int)range + (unsigned int)base);
}


// 0x002d4a20 FUN_002d4a20 (300 B): equivalent/0x002d4a20.cpp [wrapped: conflict: ParticleEmitter]
// sym: ??0ParticleEmitter@fn_002d4a20@@QAE@ABV01@@Z @8e2e03cb4aa4 @w17a55f045ece
namespace fn_002d4a20 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_002d4a20 @ 0x002d4a20
struct RefObj_2d4a20 {
    virtual void addRef();
    virtual void release();
    virtual void v2();
    virtual void v3();
    virtual RefObj_2d4a20 *clone();
};

class __declspec(novtable) DrawablePrimitive_2d4a20 {
  public:
    virtual void f0();
    char pad_04[0x3c];
    void FUN_002a5150(const DrawablePrimitive_2d4a20 &src);
    DrawablePrimitive_2d4a20(const DrawablePrimitive_2d4a20 &src) { FUN_002a5150(src); }
};

class ParticleEmitter : public DrawablePrimitive_2d4a20 {
  public:
    ParticleEmitter(const ParticleEmitter &src);
    virtual void f0();
    virtual void f1_000382a0();
    virtual void f2();
    virtual void f3() HULK_PURE64;
    virtual void f4() HULK_PURE64;
    virtual void f5_002d3e50();
    virtual void f6() HULK_PURE64;
    virtual void f7() HULK_PURE64;
    virtual void f8() HULK_PURE64;
    virtual void f9() HULK_PURE64;
    virtual void f10() HULK_PURE64;
    virtual void f11() HULK_PURE64;
    virtual void f12() HULK_PURE64;
    virtual void f13() HULK_PURE64;
    virtual void f14() HULK_PURE64;
    virtual void f15() HULK_PURE64;
    virtual void f16_002d3e60();
    virtual void f17_002d3e80(int, int);
    virtual float f18_002d3ea0(float);
    virtual void f19_002d4bd0(float);
    virtual void f20_002d3ec0();
    virtual void f21() HULK_PURE64;
    virtual void f22();
    virtual void f23_002d4d40(void*);
    virtual void f24_002d3fa0();
    virtual void f25_002d4d70(void*);
    virtual void f26_002d3fb0();
    virtual void f27_002d4db0(void*);
    virtual void f28_002d3fc0();
    virtual void f29_002d4de0(void*);
    virtual void f30_002d3fd0();
    virtual void f31_002d4e20(void*);
    virtual void f32_002d3fe0();

    unsigned matrix[16];
    int field_80;
    RefObj_2d4a20 *ref_84;
    RefObj_2d4a20 *ref_88;
    RefObj_2d4a20 *ref_8c;
    RefObj_2d4a20 *ref_90;
    int field_94;
    int field_98;
    int field_9c;
    int field_a0;
    char flag_a4;
    char flag_a5;
    char flag_a6;
};

ParticleEmitter::ParticleEmitter(const ParticleEmitter &src) : DrawablePrimitive_2d4a20(src)
{
    field_80 = 0;
    ref_84 = 0;
    ref_88 = 0;
    ref_8c = 0;
    ref_90 = 0;
    field_94 = src.field_94;
    field_98 = src.field_98;
    field_9c = src.field_9c;
    field_a0 = src.field_a0;
    flag_a4 = src.flag_a4;
    flag_a5 = src.flag_a5;
    flag_a6 = src.flag_a6;

    RefObj_2d4a20 *p = src.ref_84;
    if (p)
        p->addRef();
    if (ref_84)
        ref_84->release();
    ref_84 = p;

    RefObj_2d4a20 *q = src.ref_88;
    if (q) {
        RefObj_2d4a20 *c = q->clone();
        ref_88 = c;
        c->addRef();
    }

    p = src.ref_8c;
    if (p)
        p->addRef();
    if (ref_8c)
        ref_8c->release();
    ref_8c = p;

    p = src.ref_90;
    if (p)
        p->addRef();
    if (ref_90)
        ref_90->release();
    ref_90 = p;

    for (int i = 0; i < 16; i++)
        matrix[i] = src.matrix[i];
}
} // namespace fn_002d4a20

namespace fn_f0cbe20f {

// 0x002d4b50 FUN_002d4b50 (126 B): matches/0x002d4b50.cpp
// sym: ??1ParticleEmitter_2d4b50@fn_f0cbe20f@@QAE@XZ
ParticleEmitter_2d4b50::~ParticleEmitter_2d4b50() {
    vptr = hulk_at_0042f1e4;
    _ReadWriteBarrier();
    if (m80) {
        m80->Release();
        m80 = 0;
    }
    if (m84) {
        m84->Release();
        m84 = 0;
    }
    if (m88) {
        m88->Release();
        m88 = 0;
    }
    if (m8c) {
        m8c->Release();
        m8c = 0;
    }
    if (m90) {
        m90->Release();
        m90 = 0;
    }
    Fin_002a50a0();
}

} // namespace fn_f0cbe20f

// 0x002d4bd0 pure3d::ParticleEmitter::vfunc_19 (368 B): equivalent/0x002d4bd0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_19@ParticleEmitter@fn_002d4bd0@@UAEXM@Z @19577e393752 @wfd3b67bfdbb5
namespace fn_002d4bd0 {
// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 15/16, incomplete)
// pure3d::ParticleEmitter::vfunc_19 @ 0x002d4bd0

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double floor(double x);
#endif


class Child_2d4bd0 {
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
    virtual void v10(float t);
};

class ParticleEmitter {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void vfunc_19(float t);
    char pad04[0x88 - 0x04];
    Child_2d4bd0* child;
    char pad8c[0x94 - 0x8c];
    unsigned int frameCount;
    int frame;
    float frac;
    float time;
    bool atEnd;
};

static float absf(float v)
{
    return v < 0.0f ? -v : v;
}

void ParticleEmitter::vfunc_19(float t)
{
    if (!(t >= 0.0f))
        t = 0.0f;
    else if (t > 1.0f)
        t = 1.0f;
    float d = t - time;
    if (!(absf(d) <= 1e-5f)) {
        if (frameCount <= 1) {
            frame = 0;
            time = 0.0f;
            atEnd = true;
            frac = 0.0f;
        } else {
            int n = (int)frameCount - 1;
            float s = n * t;
            int i = (int)floor((double)(n * t));
            time = t;
            frame = i;
            float f = s - (float)i;
            frac = f;
            if (absf(1.0f - f) <= 1e-5f) {
                frame = i + 1;
                atEnd = false;
                frac = 0.0f;
            } else if (absf(f) <= 1e-5f) {
                atEnd = false;
            } else {
                atEnd = true;
            }
        }
    }
    if (child != 0)
        child->v10(time);
}
} // namespace fn_002d4bd0


// 0x002d4d40 pure3d::ParticleEmitter::vfunc_23 (44 B): matches/0x002d4d40.cpp
// sym: ?vfunc_23@ParticleEmitter@pure3d@@UAEXPAX@Z
 // namespace pure3d
void pure3d::ParticleEmitter::vfunc_23(void* __p0) { void * p = (void *)__p0;

    if (p)
        ((Obj_2d4d40*)p)->f0();
    if ((*(Obj_2d4d40 * *)&this->f_80))
        (*(Obj_2d4d40 * *)&this->f_80)->f1();
    (*(Obj_2d4d40 * *)&this->f_80) = (Obj_2d4d40*)p;
}


// 0x002d4d70 pure3d::ParticleEmitter::vfunc_25 (54 B): matches/0x002d4d70.cpp
// sym: ?vfunc_25@ParticleEmitter@pure3d@@UAEXPAX@Z
void pure3d::ParticleEmitter::vfunc_25(void* __p0) { Obj_2d4d70 * param = (Obj_2d4d70 *)__p0;

    if (param != (*(Obj_2d4d70 * *)&this->f_84)) {
        if (param)
            param->Release();
        if ((*(Obj_2d4d70 * *)&this->f_84))
            (*(Obj_2d4d70 * *)&this->f_84)->AddRef();
        (*(Obj_2d4d70 * *)&this->f_84) = param;
    }
}


// 0x002d4db0 pure3d::ParticleEmitter::vfunc_27 (44 B): matches/0x002d4db0.cpp
// sym: ?vfunc_27@ParticleEmitter@pure3d@@UAEXPAX@Z
void pure3d::ParticleEmitter::vfunc_27(void* __p0) { Obj_2d4db0 * p = (Obj_2d4db0 *)__p0;

    if (p)
        p->f();
    if ((*(Obj_2d4db0 * *)&this->f_88))
        (*(Obj_2d4db0 * *)&this->f_88)->g();
    (*(Obj_2d4db0 * *)&this->f_88) = p;
}


// 0x002d4de0 pure3d::ParticleEmitter::vfunc_29 (54 B): matches/0x002d4de0.cpp
// sym: ?vfunc_29@ParticleEmitter@pure3d@@UAEXPAX@Z
 // namespace pure3d
void pure3d::ParticleEmitter::vfunc_29(void* __p0) { Ref_2d4de0 * p = (Ref_2d4de0 *)__p0;

    if (p != (*(Ref_2d4de0 * *)&this->f_8c)) {
        if (p)
            p->Release();
        if ((*(Ref_2d4de0 * *)&this->f_8c))
            (*(Ref_2d4de0 * *)&this->f_8c)->AddRef();
        (*(Ref_2d4de0 * *)&this->f_8c) = p;
    }
}


// 0x002d4e20 pure3d::ParticleEmitter::vfunc_31 (54 B): matches/0x002d4e20.cpp
// sym: ?vfunc_31@ParticleEmitter@pure3d@@UAEXPAX@Z
 // namespace pure3d
void pure3d::ParticleEmitter::vfunc_31(void* __p0) { Ref_2d4e20 * p = (Ref_2d4e20 *)__p0;

    if (p != (*(Ref_2d4e20 * *)&this->f_90)) {
        if (p)
            p->AddRef();
        if ((*(Ref_2d4e20 * *)&this->f_90))
            (*(Ref_2d4e20 * *)&this->f_90)->Release();
        (*(Ref_2d4e20 * *)&this->f_90) = p;
    }
}


// 0x002d4e60 pure3d::SpriteParticleEmitter::EmitterBlendState::vfunc_2 (31 B): matches/0x002d4e60.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002d4e60@@UAEPAV123@E@Z
namespace fn_002d4e60 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class NonCopyable_2d4e60 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public NonCopyable_2d4e60 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002d4e60

namespace fn_f0cbe20f {

// 0x002d4e80 FUN_002d4e80 (522 B): equivalent/0x002d4e80.cpp
// sym: ?FUN_002d4e80@Config_2d4e80@fn_f0cbe20f@@QAEPAU12@PBU12@@Z @e71d20c0f286 @wcf06203768be
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_002d4e80 @ 0x002d4e80
Config_2d4e80 *Config_2d4e80::FUN_002d4e80(const Config_2d4e80 *src)
{
    ref = 0;
    f88 = src->f88;
    f8c = src->f8c;
    f90 = src->f90;
    f94 = src->f94;
    extra = 0;
    f9c = src->f9c;
    fa0 = src->fa0;
    fa4 = 0;
    fa8 = 0;
    fac = src->fac;
    fb0 = src->fb0;
    fb4 = src->fb4;
    for (int i = 0; i < 22; i++)
        tail[i] = src->tail[i];
    f110 = src->f110;
    f111 = src->f111;

    RefObj_2d4e80 *r = src->ref;
    if (r != 0) {
        r->FUN_vf0();
        if (ref != 0)
            ref->FUN_vf1();
    }
    ref = r;
    for (int i = 0; i < 0x40; i++) blockA[i] = src->blockA[i];
    for (int i = 0; i < 0x40; i++) blockB[i] = src->blockB[i];
    if (src->extra != 0) {
        Extra_2d4e80 *e = (Extra_2d4e80 *)FUN_0008d690(0x40);
        extra = e;
        e->FUN_0022b980();
    }
    return this;
}


// 0x002d5090 FUN_002d5090 (37 B): matches/0x002d5090.cpp
// sym: ?target@fn_f0cbe20f@@YIXPAVObj_2d5090@1@@Z
void __fastcall target(Obj_2d5090* self) {
    if (self->p) {
        self->p->f1();
        self->p = 0;
    }
    thunk(self->x);
}


// 0x002d50c0 FUN_002d50c0 (770 B): equivalent/0x002d50c0.cpp
// sym: ?FUN_002d50c0@Blend_2d50c0@fn_f0cbe20f@@QAEXPAUCtx@2@PBUKey_2d50c0@2@1HPBX@Z @8575beb1afea @w930f8a1f1a8a
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_002d50c0 @ 0x002d50c0
void Blend_2d50c0::FUN_002d50c0(Ctx *ctx, const Key_2d50c0 *a, const Key_2d50c0 *b, int t, const void *xform)
{
    sink88->v4(ctx, f78);
    sink8c->v6(ctx, f48);
    if (sink94)
        sink94->FUN_0028ac90(ctx, f90);

    mat.FUN_0022ca90(xform, f48);
    Matrix tmp;
    tmp.FUN_0022ca90(&mat, (*(*(MatrixHolder***)&DAT_0052c2b0))->FUN_0028faa0());
    mat = tmp;

    fac = FUN_0028b150(a->c[2], b->c[2], t, ctx);
    fac = fac * fb0;
    if (fac < 0.0f)
        fac = 0.0f;
    fb8 = FUN_0028b150(a->c[3], b->c[3], t, ctx);
    fb8 = fb8 * fc0;
    if (fb8 < 0.0f)
        fb8 = 0.0f;
    fbc = FUN_0028b150(a->c[4], b->c[4], t, ctx);
    fc4 = FUN_0028b150(a->c[5], b->c[5], t, ctx) * fcc;
    fc8 = FUN_0028b150(a->c[6], b->c[6], t, ctx);
    fd0 = FUN_0028b150(a->c[7], b->c[7], t, ctx);
    fd0 = fd0 * fd8;
    if (fd0 < 0.0f)
        fd0 = 0.0f;
    fd4 = FUN_0028b150(a->c[8], b->c[8], t, ctx);
    if (a->c[9] && b->c[9])
        fe4 = FUN_0028b150(a->c[9], b->c[9], t, ctx) * fec;
    if (a->c[10] && b->c[10])
        fe8 = FUN_0028b150(a->c[10], b->c[10], t, ctx);
    ff0 = FUN_0028b150(a->c[11], b->c[11], t, ctx) * ff8;
    ff4 = FUN_0028b150(a->c[12], b->c[12], t, ctx);
    ffc = FUN_0028b150(a->c[13], b->c[13], t, ctx) * f100;
    f104 = FUN_0028b150(a->c[14], b->c[14], t, ctx) * f108;
    unsigned int col;
    f10c = *FUN_0028b2f0(&col, a->c[15], b->c[15], t, ctx);
    f10c = (f10c & 0xffffff) | ((unsigned int)FUN_0028b100(a->c[17], b->c[17], t, ctx) << 24);
    f110 = FUN_0028b100(a->c[16], b->c[16], t, ctx);
    f111 = FUN_0028b100(a->c[18], b->c[18], t, ctx);
}


// 0x002d53d0 FUN_002d53d0 (589 B): equivalent/0x002d53d0.cpp
// sym: ?FUN_002d53d0@Emitter_2d53d0@fn_f0cbe20f@@QAEXPAUStream@2@PAUDesc_2d53d0@2@PAUMatrix@2@@Z @078df37a71ec @w5e63090fcc0a
// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 12/12)
// FUN_002d53d0 @ 0x002d53d0
void Emitter_2d53d0::FUN_002d53d0(Stream* s, Desc_2d53d0* d, Matrix* parent)
{
    positionReader->ReadPosition(s, &orient.pos);
    rotationReader->ReadRotation(s, &orient);
    if (extra)
        extra->FUN_0028ac90(s, &f90);

    ((owners::Matrix_22ca90 *)&local)->FUN_0022ca90((const owners::Matrix_22ca90 *)(Matrix *)parent, (const owners::Matrix_22ca90 *)(Matrix *)(&orient));
    Matrix combined;
    ((owners::Matrix_22ca90 *)&combined)->FUN_0022ca90((const owners::Matrix_22ca90 *)(Matrix *)(&local), (const owners::Matrix_22ca90 *)(Matrix *)((*(CameraHolder**)&DAT_0052c2b0)->camera->FUN_0028faa0()));
    local = combined;

    d->c08->FUN_0028a1c0(s, &fac);
    hulk_freg p = fb0 * fac;
    fac = (p < 0.0f) ? 0.0f : p;

    d->c0c->FUN_0028a1c0(s, &fb8);
    p = fc0 * fb8;
    fb8 = (p < 0.0f) ? 0.0f : p;

    d->c10->FUN_0028a1c0(s, &fbc);

    d->c14->FUN_0028a1c0(s, &fc4);
    fc4 = fcc * fc4;
    d->c18->FUN_0028a1c0(s, &fc8);

    d->c1c->FUN_0028a1c0(s, &fd0);
    p = fd8 * fd0;
    fd0 = (p < 0.0f) ? 0.0f : p;
    d->c20->FUN_0028a1c0(s, &fd4);

    if (d->c24) {
        d->c24->FUN_0028a1c0(s, &fe4);
        fe4 = fec * fe4;
    }
    if (d->c28)
        d->c28->FUN_0028a1c0(s, &fe8);

    d->c2c->FUN_0028a1c0(s, &ff0);
    ff0 = ff8 * ff0;
    d->c30->FUN_0028a1c0(s, &ff4);

    d->c34->FUN_0028a1c0(s, &ffc);
    ffc = f100 * ffc;

    d->c38->FUN_0028a1c0(s, &f104);
    f104 = f108 * f104;

    d->c3c->FUN_0028ad20(s, &color);

    unsigned char b;
    d->b44->FUN_0028a0b0(s, &b);
    color = (color & 0xffffff) | ((unsigned int)b << 24);
    d->b40->FUN_0028a0b0(s, &b);
    b110 = b;
    d->b48->FUN_0028a0b0(s, &b);
    b111 = b;
}

} // namespace fn_f0cbe20f

// 0x002d5620 pure3d::SpriteParticleEmitter::OverLifeAttributes::vfunc_2 (30 B): matches/0x002d5620.cpp
// sym: ??_GOverLifeAttributes@SpriteParticleEmitter@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::SpriteParticleEmitter::OverLifeAttributes::~OverLifeAttributes() {}


// 0x002d5640 FUN_002d5640 (1063 B): equivalent/0x002d5640.cpp [wrapped: conflict: pure3d::SpriteParticleEmitter]
// sym: ??0OverLifeAttributes@SpriteParticleEmitter@pure3d@fn_002d5640@@QAE@PAVSource_2d5640@3@HH@Z @c4e5abc50aa4 @wa612b6f9b663
namespace fn_002d5640 {
// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 38/38)
// FUN_002d5640 @ 0x002d5640
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);

class Channel {
public:
    void FUN_0028a1c0(float t, float *out);
    void FUN_0028a0b0(float t, float *out);
    void FUN_0028ad20(float t, float *out);
};

class ChannelSet_2d5640 {
public:
    Channel *FUN_00288960(unsigned int tagLo, unsigned int tagHi);
};

class Source_2d5640 {
public:
    char pad0[0x10];
    float length;
    ChannelSet_2d5640 *FUN_00288a10(int index);
};

namespace pure3d {
class SpriteParticleEmitter {
public:
    class OverLifeAttributes {
    public:
        virtual void v0_00018b30();
        int f04;
        int count;                  // 0x08
        int f0c;
        float *times;               // 0x10
        float *tbl14;
        float *tbl18;
        float *tbl1c;
        float *tbl20;
        float *tbl24;
        unsigned char *bytes28;
        unsigned char *bytes2c;
        OverLifeAttributes(Source_2d5640 *src, int n, int arg);
    };
};

SpriteParticleEmitter::OverLifeAttributes::OverLifeAttributes(Source_2d5640 *src, int n, int arg)
{
    f04 = 0;
    count = n;
    f0c = arg;
    times = 0;
    tbl14 = 0;
    tbl18 = 0;
    tbl1c = 0;
    tbl20 = 0;
    tbl24 = 0;
    bytes28 = 0;
    bytes2c = 0;
    times = (float *)FUN_0008d6d0(n * 4 + 4);
    volatile float inv = 1.0f / (float)count;
    volatile int idx = 0;
    while (idx < count + 1) {
        int i = idx;
        idx = i + 1;
        times[i] = (float)i * inv;
    }
    if (src == 0)
        return;

    ChannelSet_2d5640 *cs = src->FUN_00288a10(0);
    int life = (int)(__int64)src->length;
    Channel *ch;

    ch = cs->FUN_00288960(0x4c4f5053, 0x31544c46);
    if (ch != 0) {
        float *a = (float *)FUN_0008d6d0(0x54);
        tbl14 = a;
        volatile float step = (float)life * 0.05f;
        volatile float t = 0.0f;
        for (int k = 0; k < 20; k++) {
            ch->FUN_0028a1c0(t, a + k);
            t = step + t;
        }
        tbl14[20] = tbl14[19];
    }

    ch = cs->FUN_00288960(0x4c4f5a53, 0x31544c46);
    if (ch != 0) {
        float *a = (float *)FUN_0008d6d0(0x54);
        tbl18 = a;
        volatile float step = (float)life * 0.05f;
        volatile float t = 0.0f;
        for (int k = 0; k < 20; k++) {
            ch->FUN_0028a1c0(t, a + k);
            t = step + t;
        }
        tbl18[20] = tbl18[19];
    }

    ch = cs->FUN_00288960(0x4c4f4e53, 0x31544c46);
    if (ch != 0) {
        float *a = (float *)FUN_0008d6d0(0x54);
        tbl1c = a;
        volatile float step = (float)life * 0.05f;
        volatile float t = 0.0f;
        for (int k = 0; k < 20; k++) {
            ch->FUN_0028a1c0(t, a + k);
            t = step + t;
        }
        tbl1c[20] = tbl1c[19];
    }

    ch = cs->FUN_00288960(0x4c4f4557, 0x31544c46);
    if (ch != 0) {
        float *a = (float *)FUN_0008d6d0(0x54);
        tbl20 = a;
        volatile float step = (float)life * 0.05f;
        volatile float t = 0.0f;
        for (int k = 0; k < 20; k++) {
            ch->FUN_0028a1c0(t, a + k);
            t = step + t;
        }
        tbl20[20] = tbl20[19];
    }

    ch = cs->FUN_00288960(0x4c4f4f43, 0x524c43);
    if (ch != 0) {
        float *a = (float *)FUN_0008d6d0(0x54);
        tbl24 = a;
        volatile float step = (float)life * 0.05f;
        volatile float t = 0.0f;
        for (int k = 0; k < 20; k++) {
            ch->FUN_0028ad20(t, a + k);
            t = step + t;
        }
        tbl24[20] = tbl24[19];
    }

    float tmp[21];

    ch = cs->FUN_00288960(0x4c4f4c41, 0x544e49);
    if (ch != 0) {
        volatile float step = (float)life * 0.05f;
        volatile float t = 0.0f;
        for (int k = 0; k < 20; k++) {
            ch->FUN_0028a0b0(t, tmp + k);
            t = step + t;
        }
        bytes28 = (unsigned char *)FUN_0008d6d0(0x15);
        const unsigned char *src8 = (const unsigned char *)tmp;
        unsigned int i = 0;
        do {
            bytes28[i] = src8[i * 4];
            bytes28[i + 1] = src8[(i + 1) * 4];
            bytes28[i + 2] = src8[(i + 2) * 4];
            i += 3;
        } while (i <= 0x14);
    }

    ch = cs->FUN_00288960(0x4c4f4554, 0x544e49);
    if (ch != 0) {
        volatile float step = (float)life * 0.05f;
        volatile float t = 0.0f;
        for (int k = 0; k < 20; k++) {
            ch->FUN_0028a0b0(t, tmp + k);
            t = step + t;
        }
        bytes2c = (unsigned char *)FUN_0008d6d0(0x15);
        const unsigned char *src8 = (const unsigned char *)tmp;
        unsigned int i = 0;
        do {
            bytes2c[i] = src8[i * 4];
            bytes2c[i + 1] = src8[(i + 1) * 4];
            bytes2c[i + 2] = src8[(i + 2) * 4];
            bytes2c[i + 3] = src8[(i + 3) * 4];
            bytes2c[i + 4] = src8[(i + 4) * 4];
            i += 5;
        } while (i < 0x14);
    }
}
}
} // namespace fn_002d5640

namespace fn_f0cbe20f {

// 0x002d5a70 pure3d::SpriteParticleEmitter::vfunc_14 (574 B): equivalent/0x002d5a70.cpp
// sym: ?vfunc_14@SpriteParticleEmitter@fn_f0cbe20f@@QAE_NPAUVec3_2d5a70@2@0H@Z @d428c0c1e982 @w935532213907
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 6/6)
// pure3d::SpriteParticleEmitter::vfunc_14 @ 0x002d5a70
bool SpriteParticleEmitter::vfunc_14(Vec3_2d5a70* dir, Vec3_2d5a70* pos, int arg2)
{
    if ((unsigned int)count >= (unsigned int)(end - begin))
        return false;

    ParticlePool* pl = pool;
    unsigned int n = pl->size;
    if (n == 0)
        return false;
    Particle_2d5a70** items = pl->data;
    n--;
    pl->size = n;
    Particle_2d5a70* p = items[n];
    items[n] = 0;
    if (p == 0)
        return false;

    p->pos = *pos;
    p->f38 = 0;

    // The original spills the range limits into its (dead) argument slots; the slot of "pos" is
    // later handed to the colour helpers as their output cell, so keep the same frame layout.
    float* lo = (float*)&dir;
    float* hi = (float*)&pos;

    float lo4 = f16c;
    *hi = f170;
    float speed = (*(Rng_2d5a70*)&DAT_00554c04).FUN_00143100() * *hi + lo4;
    p->vel.x = speed * dir->x;
    p->vel.y = speed * dir->y;
    p->vel.z = speed * dir->z;

    *hi = f19c;
    *lo = f198;
    float a = (*(Rng_2d5a70*)&DAT_00554c04).FUN_00143100() * *hi + *lo;
    p->s3c = (short)(int)(a * 256.0f);

    *hi = f17c;
    *lo = f178;
    float b = (*(Rng_2d5a70*)&DAT_00554c04).FUN_00143100() * *hi + *lo;
    p->f10 = b;
    p->s1a = (short)(int)(b * 256.0f);

    *hi = f190;
    *lo = f18c;
    p->f1c = (*(Rng_2d5a70*)&DAT_00554c04).FUN_00143100() * *hi + *lo;

    *hi = f188;
    p->f14 = (*(Rng_2d5a70*)&DAT_00554c04).FUN_00143100() * *hi + f184;

    *hi = f164;
    *lo = f160;
    p->f30 = (*(Rng_2d5a70*)&DAT_00554c04).FUN_00143100() * *hi + *lo;

    p->f2c = arg2;
    p->f34 = 0;

    p->b3e = (*(Rng_2d5a70*)&DAT_00554c04).FUN_002d49c0(0, c1b8);
    p->b18 = (*(Rng_2d5a70*)&DAT_00554c04).FUN_002d49c0(0, c1b9);

    unsigned int* tmp = (unsigned int*)&pos;
    p->color = *FUN_002e6780(tmp, f1b4, p->b3e);
    p->color = *FUN_002e6840(tmp, p->color, p->b18);

    p->b19 = (*(Rng_2d5a70*)&DAT_00554c04).FUN_00011380(0, palette->count - 1);

    begin[count] = p;
    count++;
    return true;
}

} // namespace fn_f0cbe20f

// 0x002d5cb0 pure3d::SpriteParticleEmitter::vfunc_15 (93 B): matches/0x002d5cb0.cpp
// sym: ?vfunc_15@SpriteParticleEmitter@pure3d@@UAEXXZ
void pure3d::SpriteParticleEmitter::vfunc_15() {
    unsigned int i = 0;
    Buffer_2d5cb0* b = *(Buffer_2d5cb0**)((char*)this + 0x84);
    while (i < this->f_14c) {
        int* p = (*(int * *)&this->f_1c8) + i;
        int v = *p;
        if (v) {
            b->data[b->used++] = v;
            *p = 0;
        }
        ++i;
    }
    this->f_14c = 0;
}


// 0x002d5d10 pure3d::SpriteParticleEmitter::vfunc_17 (182 B): equivalent/0x002d5d10.cpp [wrapped: conflict: pure3d::SpriteParticleEmitter]
// sym: ?vfunc_17@SpriteParticleEmitter@pure3d@fn_002d5d10@@QAEXIM@Z @e446f9f85307 @w0d1a3c62a0bc
namespace fn_002d5d10 {
// STATUS: equivalent (tools/equiv.py level 3: 3030 inputs, branch coverage 20/20)
// pure3d::SpriteParticleEmitter::vfunc_17 @ 0x002d5d10
struct Delegate_2d5d10 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(unsigned int, float); };
namespace pure3d { struct SpriteParticleEmitter { char pad0[0x88]; Delegate_2d5d10* delegate; char pad1[0xcc]; float f158; char p15c[12]; float f168; char p16c[8]; float f174; char p178[8]; float f180; char p184[16]; float f194; char p198[8]; float f1a0; char p1a4[4]; float f1a8; char p1ac[4]; float f1b0; void vfunc_17(unsigned int, float); }; }
void pure3d::SpriteParticleEmitter::vfunc_17(unsigned int id, float value) { switch(id) { case 0: f158=value; break; case 7: f168=value<0.0f?0.0f:value; break; case 8: f174=value; break; case 9: f180=value; break; case 10: f194=value; break; case 11: f1a0=value; break; case 12: f1a8=value; break; case 13: f1b0=value; break; default: if(delegate) delegate->v7(id,value); break; } }
} // namespace fn_002d5d10


// 0x002d5e00 pure3d::SpriteParticleEmitter::vfunc_8 (105 B): matches/0x002d5e00.cpp
// sym: ?vfunc_8@SpriteParticleEmitter@pure3d@@UAEXPAX@Z
void pure3d::SpriteParticleEmitter::vfunc_8(void* __p0) { Obj_2d5e00 * p = (Obj_2d5e00 *)__p0;

    if (p)
        p->a();
    if ((*(Obj_2d5e00 * *)&this->f_a8))
        (*(Obj_2d5e00 * *)&this->f_a8)->b();
    (*(Obj_2d5e00 * *)&this->f_a8) = p;
    if (p && (p->kind == 1 || p->kind == 3 || p->kind == 7 || p->kind == 2 || p->kind == 4 || p->kind == 5 ||
              p->kind == 6))
        this->f_10 = 1;
    else
        this->f_10 = 0;
}


// 0x002d5e70 pure3d::SpriteParticleEmitter::vfunc_25 (67 B): matches/0x002d5e70.cpp
// sym: ?vfunc_25@SpriteParticleEmitter@pure3d@@UAEXPAX@Z
void pure3d::SpriteParticleEmitter::vfunc_25(void* __p0) { Obj_2d5e70 * p = (Obj_2d5e70 *)__p0;

    if (p != (*(Obj_2d5e70 * *)&this->f_84)) {
        vfunc_15();
        if (p != (*(Obj_2d5e70 * *)&this->f_84)) {
            if (p)
                p->a();
            if ((*(Obj_2d5e70 * *)&this->f_84))
                (*(Obj_2d5e70 * *)&this->f_84)->b();
            (*(Obj_2d5e70 * *)&this->f_84) = p;
        }
    }
}

namespace fn_f0cbe20f {

// 0x002d5ec0 FUN_002d5ec0 (95 B): matches/0x002d5ec0.cpp
// sym: ?target@SpriteParticleEmitter_2d5ec0@fn_f0cbe20f@@QAEXH@Z
void SpriteParticleEmitter_2d5ec0::target(int arg) {
    if (!flag)
        inner.FnA_002d53d0(arg, items[index], (char*)this + 0x40);
    else {
        int* q = items + index;
        inner.FnB_002d50c0(arg, q[0], q[1], value9c, (char*)this + 0x40);
    }
}


// 0x002d5f20 FUN_002d5f20 (187 B): matches/0x002d5f20.cpp
// sym: ?target@SpriteParticleEmitter_2d5f20@fn_f0cbe20f@@QAEXHHH@Z
void SpriteParticleEmitter_2d5f20::target(int a, int b, int c) {
    if (!backend)
        return;
    backend->update(a);
    int available = ((int)((hulk_ulongptr)end - (hulk_ulongptr)begin) >> 2) - used;
    if ((float)available < credit)
        credit = (float)available;
    if (credit >= 1.0f) {
        double count = __floor_default(credit);
        Backend_2d5f20* current = backend;
        int taken = current->consume((int)count, data, c, b, this);
        credit -= (float)taken;
    }
}

} // namespace fn_f0cbe20f

// 0x002d5fe0 FUN_002d5fe0 (200 B): equivalent/0x002d5fe0.cpp
// sym: ?FUN_002d5fe0@SpriteParticleEmitter@pure3d@@QAEXM@Z @cb38ccd3eafe @w712cdf08120b
// STATUS: equivalent (tools/equiv.py level 3: 105 inputs, branch coverage 14/14)
// FUN_002d5fe0 @ 0x002d5fe0
void pure3d::SpriteParticleEmitter::FUN_002d5fe0(float dt) {
 Updater_2d5fe0* handler = (*(Updater_2d5fe0 *volatile *)&this->f_8c);
 if (!handler || !(dt > 0.0f)) return;
 if ((*(volatile unsigned char *)&this->f_15c) == 1) { handler->special(dt, this); return; }
 handler->update(dt, this);
 Pool_2d5fe0* destination = (*(Pool_2d5fe0 *volatile *)&this->f_84);
 unsigned kept = 0;
 for (unsigned i = 0; i < (*(volatile unsigned int *)&this->f_14c); ++i) {
  Item_2d5fe0* volatile* slot = &(*(Item_2d5fe0 *volatile *volatile *)&this->f_1c8)[i];
  Item_2d5fe0* item = *slot;
  Item_2d5fe0* volatile nullableItem = item;
  if (item->current >= item->limit) {
   if (nullableItem) {
    unsigned n = destination->count;
    Item_2d5fe0* volatile* buffer = destination->items;
    buffer[n] = item;
    n = destination->count;
    destination->count = n + 1;
    *slot = 0;
   }
  } else {
   *slot = 0; (*(Item_2d5fe0 *volatile *volatile *)&this->f_1c8)[kept++] = item;
  }
 }
 (*(volatile unsigned int *)&this->f_14c) = kept;
}


// 0x002d60e0 pure3d::ParticleEmitter::vfunc_2 (30 B): matches/0x002d60e0.cpp
// sym: ??_GParticleEmitter@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::ParticleEmitter::~ParticleEmitter() {}

namespace fn_f0cbe20f {

// 0x002d63a0 FUN_002d63a0 (73 B): matches/0x002d63a0.cpp
// sym: ??0SpriteParticleEmitter_2d63a0@fn_f0cbe20f@@QAE@XZ
SpriteParticleEmitter_2d63a0::SpriteParticleEmitter_2d63a0() {
    sub.Init_002d4200();
    f1bc = 0;
    f1c0 = 0;
    f1c4 = 0;
    f1c8 = 0;
    f1cc = 0;
    f1d4 = 0;
    f1d8 = 0;
}

} // namespace fn_f0cbe20f

// 0x002d63f0 FUN_002d63f0 (413 B): equivalent/0x002d63f0.cpp [wrapped: conflict: SpriteParticleEmitter]
// sym: ??0SpriteParticleEmitter@fn_002d63f0@@QAE@ABV01@@Z @81bad6605a30 @w3ece43f4e219
namespace fn_002d63f0 {
// STATUS: equivalent (tools/equiv.py level 3: 35 inputs, branch coverage 28/28)
// FUN_002d63f0 @ 0x002d63f0
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);

class RefCounted_2d63f0 {
public:
    virtual void addRef();
    virtual void release();
};

class __declspec(novtable) ParticleEmitter_2d63f0 {
public:
    virtual void b0_00038290();
    char pad04[0x94 - 4];
    unsigned int count;      // 0x94
    char pad98[0xa8 - 0x98];
    void FUN_002d4a20(const ParticleEmitter_2d63f0 *other);
    ParticleEmitter_2d63f0(const ParticleEmitter_2d63f0 &other) { FUN_002d4a20(&other); }
};

class EmitterState {
public:
    char data[0x1bc - 0xa8];
    void FUN_002d4e80(const EmitterState *other);
    EmitterState(const EmitterState &other) { FUN_002d4e80(&other); }
};

class SpriteParticleEmitter : public ParticleEmitter_2d63f0 {
public:
    virtual void f1_000382a0();
    EmitterState state;      // 0xa8
    RefCounted_2d63f0 *ref1bc;
    RefCounted_2d63f0 *ref1c0;
    RefCounted_2d63f0 *ref1c4;
    int *vec1c8;
    int *vec1cc;
    char pad1d0[4];
    RefCounted_2d63f0 **vec1d4;
    RefCounted_2d63f0 **vec1d8;

    static void Assign(RefCounted_2d63f0 **slot, RefCounted_2d63f0 *p) {
        if (p)
            p->addRef();
        RefCounted_2d63f0 *old = *slot;
        if (old)
            old->release();
        *slot = p;
    }

    SpriteParticleEmitter(const SpriteParticleEmitter &other);
};

SpriteParticleEmitter::SpriteParticleEmitter(const SpriteParticleEmitter &other)
    : ParticleEmitter_2d63f0(other), state(other.state)
{
    ref1bc = 0;
    ref1c0 = 0;
    ref1c4 = 0;

    hulk_uintptr n = other.vec1cc - other.vec1c8;
    if (n != 0) {
        int *p = (int *)FUN_0008d6d0(n * 4);
        vec1c8 = p;
        if (p) {
            vec1cc = (int *)((char *)p + n * 4);
        } else {
            vec1c8 = 0;
            vec1cc = 0;
        }
    } else {
        vec1c8 = 0;
        vec1cc = 0;
    }

    hulk_uintptr m = other.vec1d8 - other.vec1d4;
    if (m != 0) {
        RefCounted_2d63f0 **p = (RefCounted_2d63f0 **)FUN_0008d6d0(m * sizeof(RefCounted_2d63f0 *));
        vec1d4 = p;
        if (p) {
            vec1d8 = (RefCounted_2d63f0 **)((char *)p + m * 4);
        } else {
            vec1d4 = 0;
            vec1d8 = 0;
        }
    } else {
        vec1d4 = 0;
        vec1d8 = 0;
    }

    Assign(&ref1bc, other.ref1bc);
    for (unsigned int i = 0; i < count; i++) {
        vec1d4[i] = 0;
        Assign(&vec1d4[i], other.vec1d4[i]);
    }
    Assign(&ref1c0, other.ref1c0);
    Assign(&ref1c4, other.ref1c4);
}
} // namespace fn_002d63f0


// 0x002d6590 FUN_002d6590 (274 B): matches/0x002d6590.cpp [wrapped: conflict: pure3d::SpriteParticleEmitter]
// sym: ??1SpriteParticleEmitter@pure3d@fn_002d6590@@QAE@XZ
namespace fn_002d6590 {
struct Resource_2d6590 {
    virtual void slot0();
    virtual void release();
};
struct Pool_2d6590 {
    char pad[8];
    unsigned count;
    void** items;
};
void __cdecl FUN_0008d340(void*);
void __cdecl FUN_0008d330(void*);
namespace pure3d {
struct SpriteParticleEmitter {
    virtual void slot0_00038290();
    char pad04[0x80];
    Pool_2d6590* pool;
    char pad88[0xc];
    unsigned resourceCount;
    char pad98[0x10];
    Resource_2d6590* resourceA8;
    char padAC[0x94];
    void* buffer;
    char pad144[8];
    unsigned itemCount;
    char pad150[0x6c];
    Resource_2d6590* resource1BC;
    Resource_2d6590* resource1C0;
    Resource_2d6590* resource1C4;
    void** items;
    char pad1CC[8];
    Resource_2d6590** resources;
    void FUN_002d4b50();
    ~SpriteParticleEmitter();
};
SpriteParticleEmitter::~SpriteParticleEmitter() {
    Pool_2d6590* p = pool;
    for (unsigned i = 0; i < itemCount; ++i) {
        void** entry = &items[i];
        if (*entry) {
            p->items[p->count] = *entry;
            ++p->count;
            *entry = 0;
        }
    }
    if (resource1BC) {
        resource1BC->release();
        resource1BC = 0;
    }
    for (unsigned i = 0; i < resourceCount; ++i) {
        Resource_2d6590** entry = &resources[i];
        if (*entry) {
            (*entry)->release();
            *entry = 0;
        }
    }
    if (resource1C0) {
        resource1C0->release();
        resource1C0 = 0;
    }
    if (resource1C4) {
        resource1C4->release();
        resource1C4 = 0;
    }
    if (resources)
        FUN_0008d340(resources);
    if (items)
        FUN_0008d340(items);
    if (resourceA8) {
        resourceA8->release();
        resourceA8 = 0;
    }
    FUN_0008d330(buffer);
    FUN_002d4b50();
}
} // namespace pure3d
} // namespace fn_002d6590


// 0x002d66b0 pure3d::SpriteParticleEmitter::vfunc_4 (34 B): matches/0x002d66b0.cpp
// sym: ?vfunc_4@SpriteParticleEmitter@pure3d@@UAEPAXXZ
void* pure3d::SpriteParticleEmitter::vfunc_4() {
    Obj_2d66b0* p = alloc(0x1e0);
    if (p)
        return (void*)(p->run_002d63f0(this));
    return (void*)(0);
}

