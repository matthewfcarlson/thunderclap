// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002d2070..0x002d3d80 (kind game, layer engine, confidence high), dominant class pure3d::ParticlePlaneGenerator
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fd7a7bd7 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fd7a7bd7 {} using namespace fn_fd7a7bd7;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fd7a7bd7 {
extern "C" char DAT_0042f074[];
class ParticlePlaneGenerator_2d2070 {
  public:
    void* vftable;
    char pad4[0x0c];
    unsigned char a;
    char pad11[3];
    int b, c, d, e;
    void Init_0027b070();
};
class Entity_2d20a0 {
  public:
    virtual void BV_00038290();
    Entity_2d20a0();
};
class Sub_2d20a0 {
  public:
    char d[8];
    void Init_0027af70(const void*);
};
class ParticleGenerator : public Entity_2d20a0 {
  public:
    virtual void m_vf1_000382a0();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void vfunc_10(float t);
    virtual void m_vf11_002d2100();
    ParticleGenerator(const void* p);
    char _m_pad_4[0x4];
    Sub_2d20a0 sub;
    union { char atKey; char b; };
    char _m_pad_11[0x3];
    union { int a14; float time; };
    union { int a18; float frac; };
    union { int a1c; unsigned count; };
    union { int a20; int index; };
};
extern "C" char DAT_0042f0a8[];
class Entry_2d2130 {
  public:
    int Find_00288960(int, int);
};
class GeneratorBlendState {
  public:
    hulk_intptr vf;
    int a;
    int b;
    int c;
    int d;
    GeneratorBlendState(hulk_intptr x);
};
class ParticleGenerator_2d2510 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual float vfunc_8(int);
    virtual void a9();
    virtual void a10();
    virtual void a11();
};
class Chunk {
  public:
    int Find_00288960(int a, int b);
};
class NonCopyable_2d2570 {
  public:
    NonCopyable_2d2570() : mA(0) {}
    virtual void f0();
    int mA;
};
class GeneratorBlendState_2d2570 : public NonCopyable_2d2570 {
  public:
    GeneratorBlendState_2d2570(Chunk* c);
    virtual void f0();
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
};
struct Vec3_2d2630 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Mat4_2d2630 {
    float m[12];
    Vec3_2d2630 pos;
    float w;
};
struct RandState_2d2630 {
    unsigned int s0;
    unsigned int s1;
};
class Emitter_2d2630 {
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
    virtual bool v14(Vec3_2d2630 *dir, Vec3_2d2630 *pos, float t);
};
extern "C" void __cdecl FUN_00356bf0(float r, float az, float pol, float *x, float *y, float *z);
union FloatBits_2d2630 {
    float f;
    unsigned int u;
};
union MatArg {
    Mat4_2d2630 *mat;
    float f;
    unsigned int u;
};
union EmArg {
    Emitter_2d2630 *em;
    float f;
};
static __forceinline unsigned int NextBits(RandState_2d2630 *r)
{
    r->s0 = (r->s0 & 0xffff) * 0x9069 + (r->s0 >> 16);
    r->s1 = (r->s1 & 0xffff) * 0x4650 + (r->s1 >> 16);
    return (r->s0 << 16) + (r->s1 & 0xffff);
}
static __forceinline float NextSigned(RandState_2d2630 *r)
{
    unsigned int x = NextBits(r);
    FloatBits_2d2630 b;
    b.u = (x & 0x7fffff) | 0x3f800000;
    b.f = b.f - 1.0f;
    b.u |= x & 0x80000000;
    return b.f;
}
static __forceinline float NextRaw(RandState_2d2630 *r)
{
    unsigned int x = NextBits(r);
    FloatBits_2d2630 b;
    b.u = (x & 0x7fffff) | 0x3f800000;
    return b.f;
}
class ParticlePlaneGenerator {
public:
    char pad00[0x38];
    float f38, f3c, f40;
    float f44, f48, f4c;
    float f50, f54, f58, f5c;
    unsigned int vfunc_6(unsigned int count, MatArg from, MatArg to, float step, EmArg em);
};
class ParticleGenerator_2d2b90 {
  public:
    virtual void a();
    virtual void b();
};
extern "C" char DAT_00444152[];
struct Owner_2d2bd0 {
    int pad;
    int Find_00288960(int, int);
};
extern int hulk_at_0042f0c8;
struct GeneratorBlendState_2d2bd0 {
    int* vptr;
    int a, b, c;
    GeneratorBlendState_2d2bd0(Owner_2d2bd0*);
};
struct Vec3_2d2c40 {
    float x, y, z;
    void FUN_0022d260(struct Mat4_2d2c40* m);
    float FUN_0022d110();
};
struct Mat4_2d2c40 {
    float m[12];
    Vec3_2d2c40 pos;
    float w;
};
struct Rng_2d2c40 {
    float FUN_00143100();
};
class Emitter_2d2c40 {
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
    virtual bool v14(Vec3_2d2c40* dir, Vec3_2d2c40* pos, float t);
};
struct Frame_2d2c40 {
    Vec3_2d2c40 tmp;
    Vec3_2d2c40 p;
    Vec3_2d2c40 q1;
    Vec3_2d2c40 w;
    union {
        Vec3_2d2c40 d;
        Vec3_2d2c40 q0;
    };
};
class ParticleSphereGenerator {
public:
    char pad00[0x38];
    float f38, f3c, f40;
    float f44, f48, f4c;
    unsigned int vfunc_6(unsigned int count, Mat4_2d2c40* from, Mat4_2d2c40* to, float step, Emitter_2d2c40* em);
};
extern void* hulk_at_0042f074[];
class Entity_2d31b0 {
  public:
    void Destroy_0027afd0(); // FUN_00236d60, __thiscall, this in ecx
};
class ParticleGenerator_2d31b0 : public Entity_2d31b0 {
  public:
    ParticleGenerator_2d31b0* vfunc_5(signed char flags);
};
struct Curve_2d3340 {
};
struct Elem_2d3340 {
    char pad[8];
    Curve_2d3340* c[3];
};
extern float __cdecl Mix_0028b150(Curve_2d3340*, Curve_2d3340*, float, float);
class ParticlePointGenerator {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f(float);
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    char p4[12];
    unsigned char mode;
    char p11[7];
    float amount;
    unsigned int count;
    int index;
    char p24[8];
    Elem_2d3340** points;
    char p30[8];
    float out[3];
};
class ParticleGenerator_2d3740 {
  public:
    ParticleGenerator_2d3740() throw();
    virtual void a();
    char pad[0xc];
};
struct Init1_2d3740 {
    Init1_2d3740() throw() {
        m10 = 0;
        m14 = 0;
        m18 = 0;
        m1c = 0;
        m20 = 0;
        m28 = 0;
    }
    char m10;
    int m14, m18, m1c, m20, m24, m28;
};
class ParticlePointGenerator_2d3740 : public ParticleGenerator_2d3740, public Init1_2d3740 {
  public:
    ParticlePointGenerator_2d3740() throw();
    virtual void a();
    int m2c, m30, m34, m38, m3c, m40;
    float m44, m48, m4c;
};
extern void* g_vftable_0042f0d8[];
extern void* g_base_2d38a0[];
} // namespace fn_fd7a7bd7
void operator delete(void*);
namespace fn_fd7a7bd7 {
class Ref_2d38a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class ParticleGenerator_2d38a0 {
  public:
    void* vptr;
    void Fin_0027afd0();
};
class ParticlePointGenerator_2d38a0 : public ParticleGenerator_2d38a0 {
  public:
    char pad[0x18];
    unsigned m1c;
    char pad2[0x08];
    Ref_2d38a0* m28;
    Ref_2d38a0** m2c;
    ~ParticlePointGenerator_2d38a0();
};
class Helper_2d3910 {
  public:
    hulk_intptr run_002d3790(pure3d::ParticlePointGenerator*);
};
extern "C" void* __cdecl allocThing_00263ea0(unsigned int);
extern void* hulk_at_0042f10c[];
extern void* g_base_2d3ab0[];
class Ref_2d3ab0 {
  public:
    virtual void F0();
    virtual void Release();
};
class ParticleGenerator_2d3ab0 {
  public:
    void* vptr;
    void Fin_0027afd0();
};
class ParticlePlaneGenerator_2d3ab0 : public ParticleGenerator_2d3ab0 {
  public:
    char pad[0x18];
    unsigned m1c;
    char pad2[0x08];
    Ref_2d3ab0* m28;
    Ref_2d3ab0** m2c;
    ~ParticlePlaneGenerator_2d3ab0();
};
class Other_2d3b20 {
  public:
    hulk_intptr helper_002d3980(pure3d::ParticlePlaneGenerator*);
};
extern void* hulk_at_0042f140[];
extern void* g_vftable_base[];
class Ref_2d3c90 {
  public:
    virtual void F0();
    virtual void Release();
};
class ParticleGenerator_2d3c90 {
  public:
    void* vptr;
    void Fin_0027afd0();
};
class ParticleSphereGenerator_2d3c90 : public ParticleGenerator_2d3c90 {
  public:
    char pad[0x18];
    unsigned n;
    char pad2[8];
    Ref_2d3c90* m28;
    Ref_2d3c90** arr;
    ~ParticleSphereGenerator_2d3c90();
};
class Obj_2d3d00 {
  public:
    hulk_intptr helper_002d3b80(pure3d::ParticleSphereGenerator*);
};
extern Obj_2d3d00* alloc_00263ea0(int);


// 0x002d2070 FUN_002d2070 (35 B): matches/0x002d2070.cpp
// sym: ?FUN_002d2070@fn_fd7a7bd7@@YIPAVParticlePlaneGenerator_2d2070@1@PAV21@@Z
ParticlePlaneGenerator_2d2070* __fastcall FUN_002d2070(ParticlePlaneGenerator_2d2070* p) {
    p->Init_0027b070();
    p->a = 0;
    p->b = 0;
    p->c = 0;
    p->d = 0;
    p->e = 0;
    p->vftable = (void*)((hulk_intptr)DAT_0042f074);
    return p;
}


// 0x002d20a0 FUN_002d20a0 (66 B): matches/0x002d20a0.cpp
// sym: ??0ParticleGenerator@fn_fd7a7bd7@@QAE@PBX@Z
ParticleGenerator::ParticleGenerator(const void* p) : Entity_2d20a0() {
    b = *((const char*)p + 0x10);
    a14 = *(const int*)((const char*)p + 0x14);
    a18 = *(const int*)((const char*)p + 0x18);
    a1c = *(const int*)((const char*)p + 0x1c);
    a20 = *(const int*)((const char*)p + 0x20);
    sub.Init_0027af70((const char*)p + 8);
}

} // namespace fn_fd7a7bd7

// 0x002d2100 pure3d::ParticleGenerator::vfunc_11 (4 B): matches/0x002d2100.cpp
// sym: ?vfunc_11@ParticleGenerator@pure3d@@UAEMXZ
// Same code shape as 0x00069050 (propagated; names are from that function)
hulk_freg pure3d::ParticleGenerator::vfunc_11() {
    return this->f_14;
}

namespace fn_fd7a7bd7 {

// 0x002d2130 FUN_002d2130 (99 B): matches/0x002d2130.cpp
// sym: ??0GeneratorBlendState@fn_fd7a7bd7@@QAE@H@Z
GeneratorBlendState::GeneratorBlendState(hulk_intptr x) {
    a = 0;
    vf = ((hulk_intptr)DAT_0042f0a8);
    b = 0;
    c = 0;
    d = 0;
    if (x != 0) {
        Entry_2d2130* e = (Entry_2d2130*)x;
        b = e->Find_00288960(0x50534f48, 0x31544c46);
        c = e->Find_00288960(0x50534556, 0x31544c46);
        d = e->Find_00288960(0x41564452, 0x31544c46);
    }
}

} // namespace fn_fd7a7bd7

// 0x002d21b0 pure3d::ParticlePointGenerator::vfunc_3 (3 B): matches/0x002d21b0.cpp
// sym: ?vfunc_3@ParticlePointGenerator@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::ParticlePointGenerator::vfunc_3() {
    return true;
}


// 0x002d21c0 pure3d::ParticlePointGenerator::vfunc_6 (791 B): equivalent/0x002d21c0.cpp [wrapped: helper definitions (4 out-of-line function bodies)]
// sym: ?vfunc_6@ParticlePointGenerator@fn_002d21c0@@QAEIIPAUMat4_2d21c0@2@0MPAVEmitter_2d21c0@2@@Z @e1428e558e1e @w9a33d58b3b8b
namespace fn_002d21c0 {
// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 9/10, incomplete)
// pure3d::ParticlePointGenerator::vfunc_6 @ 0x002d21c0

struct Vec3_2d21c0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Mat4_2d21c0 {
    float m[12];
    Vec3_2d21c0 pos;
    float w;
};

struct RngState {
    unsigned int a;
    unsigned int b;
};


union FloatBits_2d21c0 {
    float f;
    unsigned int u;
};

class Emitter_2d21c0 {
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
    virtual bool v14(Vec3_2d21c0* dir, Vec3_2d21c0* pos, float t);
};

extern "C" void __cdecl FUN_00356bf0(float r, float az, float pol, float* x, float* y, float* z);

static unsigned int NextRandom()
{
    (*(RngState*)&DAT_00554bfc).a = ((*(RngState*)&DAT_00554bfc).a & 0xffff) * 0x9069 + ((*(RngState*)&DAT_00554bfc).a >> 16);
    (*(RngState*)&DAT_00554bfc).b = ((*(RngState*)&DAT_00554bfc).b & 0xffff) * 0x4650 + ((*(RngState*)&DAT_00554bfc).b >> 16);
    return ((*(RngState*)&DAT_00554bfc).a << 16) + ((*(RngState*)&DAT_00554bfc).b & 0xffff);
}

static float RandomSigned()
{
    unsigned int r = NextRandom();
    FloatBits_2d21c0 u;
    u.u = (r & 0x7fffff) | 0x3f800000;
    u.f = u.f - 1.0f;
    u.u |= r & 0x80000000;
    return u.f;
}

static float RandomUnsigned()
{
    unsigned int r = NextRandom();
    FloatBits_2d21c0 u;
    u.u = (r & 0x7fffff) | 0x3f800000;
    return u.f - 1.0f;
}

class ParticlePointGenerator {
public:
    char pad00[0x38];
    float f38, f3c, f40;
    float f44, f48, f4c;
    unsigned int vfunc_6(unsigned int count, Mat4_2d21c0* from, Mat4_2d21c0* to, float step, Emitter_2d21c0* em);
};

unsigned int ParticlePointGenerator::vfunc_6(unsigned int count, Mat4_2d21c0* from, Mat4_2d21c0* to, float step, Emitter_2d21c0* em)
{
    if (count == 0)
        return 0;
    float sa = f44 * f38;
    float sb = f48 * f3c;
    float sc = f4c * f40;
    Vec3_2d21c0 p = from->pos;
    float dx = to->pos.x - p.x;
    float dy = to->pos.y - p.y;
    float dz = to->pos.z - p.z;
    volatile float inv = 1.0f / (float)count;
    Vec3_2d21c0 d;
    d.x = dx * inv;
    d.y = dy * inv;
    d.z = dz * inv;
    step = step * inv;
    volatile float t = 0.0f;
    unsigned int n = 0;
    for (unsigned int i = 0; i < count; i++) {
        float v1 = RandomSigned();
        float v2 = RandomSigned();
        float v3 = RandomUnsigned() * sc;
        Vec3_2d21c0 dir;
        FUN_00356bf0(1.0f, v1 * sa + 1.5707964f, v2 * sb + 1.5707964f, &dir.x, &dir.y, &dir.z);
        ((owners::Obj_22d260 *)&dir)->FUN_0022d260((owners::Obj_22d260 *)(struct Mat4_2d21c0 *)from);
        dir.FUN_0022d110();
        Vec3_2d21c0 q;
        q.x = dir.x * v3 + p.x;
        q.y = dir.y * v3 + p.y;
        q.z = dir.z * v3 + p.z;
        if (!em->v14(&dir, &q, t))
            break;
        n++;
        p.x += d.x;
        p.y += d.y;
        p.z += d.z;
        t -= step;
    }
    return n;
}
} // namespace fn_002d21c0


// 0x002d24e0 pure3d::ParticlePointGenerator::vfunc_7 (43 B): matches/0x002d24e0.cpp
// sym: ?vfunc_7@ParticlePointGenerator@pure3d@@UAEXHH@Z
void pure3d::ParticlePointGenerator::vfunc_7(int x, int y) {
    switch (x) {
    case 1:
        (*(int *)&this->f_44) = y;
        break;
    case 2:
        (*(int *)&this->f_48) = y;
        break;
    case 3:
        (*(int *)&this->f_4c) = y;
        break;
    }
}


// 0x002d2510 pure3d::ParticlePointGenerator::vfunc_8 (40 B): matches/0x002d2510.cpp
// sym: ?vfunc_8@ParticlePointGenerator@pure3d@@UAEMH@Z
// data: zero_2d2510 = DAT_003f32e0
hulk_freg pure3d::ParticlePointGenerator::vfunc_8(int n) {
    --n;
    if (n != 0) {
        --n;
        if (n != 0) {
            --n;
            if (n != 0)
                return DAT_003f32e0;
            return this->f_4c;
        }
        return this->f_48;
    }
    return this->f_44;
}


// 0x002d2540 pure3d::ParticlePointGenerator::vfunc_9 (15 B): matches/0x002d2540.cpp
// sym: ?vfunc_9@ParticlePointGenerator@pure3d@@UAEXXZ
void pure3d::ParticlePointGenerator::vfunc_9() {
    this->f_44 = 1.0f;
    this->f_48 = 1.0f;
    this->f_4c = 1.0f;
}

namespace fn_fd7a7bd7 {

// 0x002d2570 FUN_002d2570 (145 B): matches/0x002d2570.cpp
// sym: ??0GeneratorBlendState_2d2570@fn_fd7a7bd7@@QAE@PAVChunk@1@@Z
GeneratorBlendState_2d2570::GeneratorBlendState_2d2570(Chunk* c) {
    m8 = 0;
    mC = 0;
    m10 = 0;
    m14 = 0;
    m18 = 0;
    if (c) {
        m8 = c->Find_00288960(((hulk_intptr)((char*)0x544457)), 0x31544c46);
        mC = c->Find_00288960(((hulk_intptr)((char*)0x544748)), 0x31544c46);
        m10 = c->Find_00288960(0x50534f48, 0x31544c46);
        m14 = c->Find_00288960(0x50534556, 0x31544c46);
        m18 = c->Find_00288960(0x41564452, 0x31544c46);
    }
}

} // namespace fn_fd7a7bd7

// 0x002d2620 pure3d::ParticlePlaneGenerator::vfunc_3 (3 B): matches/0x002d2620.cpp
// sym: ?vfunc_3@ParticlePlaneGenerator@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::ParticlePlaneGenerator::vfunc_3() {
    return true;
}

namespace fn_fd7a7bd7 {

// 0x002d2630 pure3d::ParticlePlaneGenerator::vfunc_6 (1194 B): equivalent/0x002d2630.cpp
// sym: ?vfunc_6@ParticlePlaneGenerator@fn_fd7a7bd7@@QAEIITMatArg@2@0MTEmArg@2@@Z @38ef6898d59e @w4fef05c2bde8
// STATUS: equivalent (tools/equiv.py level 3: 19136 inputs, branch coverage 9/10, incomplete)
// pure3d::ParticlePlaneGenerator::vfunc_6 @ 0x002d2630
unsigned int ParticlePlaneGenerator::vfunc_6(unsigned int count, MatArg from, MatArg to, float step, EmArg em)
{
    if (count == 0)
        return 0;

    struct Frame {
        float t;
        unsigned int n;
        unsigned int i;
        float u3;
        float v3;
        float v2;
        float v1;
        float u5;
        float u4;
        Vec3_2d2630 p;
        Vec3_2d2630 r;
        Vec3_2d2630 w;
        Vec3_2d2630 d;
        float c60;
        float pad64;
        float c68;
        Vec3_2d2630 q;
    } f;

    f.p = from.mat->pos;
    hulk_freg dx = (hulk_freg)f.p.x - to.mat->pos.x;   // x and y stay in registers, z goes through d.z
    hulk_freg dy = (hulk_freg)f.p.y - to.mat->pos.y;
    f.d.z = f.p.z - to.mat->pos.z;
    to.f = 1.0f / (float)count;
    float inv = *(volatile float *)&to.f;   // the original reloads the stored (rounded) reciprocal
    f.d.x = dx * inv;
    f.d.y = dy * inv;
    f.d.z = f.d.z * inv;
    step = inv * step;
    f.t = 0.0f;
    f.n = 0;
    f.i = 0;
    f.v1 = f54 * f40;
    f.v2 = f58 * f44;
    f.v3 = f5c * f48;
    f.c60 = f4c * f38 * -0.5f;
    f.c68 = f50 * f3c * -0.5f;
    Mat4_2d2630 *fromMat = from.mat;
    Emitter_2d2630 *emitter = em.em;
    do {
        float r1 = NextSigned(((RandState_2d2630*)&DAT_00554bfc));
        float r2 = NextSigned(((RandState_2d2630*)&DAT_00554bfc));
        f.u3 = NextRaw(((RandState_2d2630*)&DAT_00554bfc));
        to.f = r1;
        from.f = r2;
        em.f = (f.u3 - 1.0f) * f.v3;
        FUN_00356bf0(1.0f, to.f * f.v1 + 1.5707964f, from.f * f.v2 + 1.5707964f, &f.w.x, &f.w.y, &f.w.z);
        ((owners::Obj_22d260 *)&(f.w))->FUN_0022d260((owners::Obj_22d260 *)(struct Mat4_2d2630 *)fromMat);
        f.w.FUN_0022d110();
        f.u4 = NextRaw(((RandState_2d2630*)&DAT_00554bfc));
        f.u5 = NextRaw(((RandState_2d2630*)&DAT_00554bfc));
        f.q.x = (f.u5 - 1.0f) * f38 + f.c60;
        f.q.y = 0.0f;
        f.q.z = (f.u4 - 1.0f) * f3c + f.c68;
        ((owners::M_22c3b0 *)fromMat)->FUN_0022c3b0((float *)(const Vec3_2d2630 *)(&f.q), (float *)(Vec3_2d2630 *)(&f.r));
        hulk_freg ax = (hulk_freg)f.r.x + f.p.x;
        hulk_freg ay = (hulk_freg)f.r.y + f.p.y;
        f.r.z = f.r.z + f.p.z;
        f.r.x = f.w.x * em.f + ax;
        f.r.y = f.w.y * em.f + ay;
        f.r.z = f.w.z * em.f + *(volatile float *)&f.r.z;   // the original reloads the stored (rounded) sum
        if (!emitter->v14(&f.w, &f.r, f.t))
            break;
        f.n++;
        f.i++;
        f.p.x = f.p.x + f.d.x;
        f.p.y = f.p.y + f.d.y;
        f.p.z = f.p.z + f.d.z;
        f.t = f.t + step;
    } while (f.i < count);
    return f.n;
}

} // namespace fn_fd7a7bd7

// 0x002d2ae0 pure3d::ParticlePlaneGenerator::vfunc_7 (67 B): equivalent/0x002d2ae0.cpp [wrapped: conflict: pure3d::ParticlePlaneGenerator]
// sym: ?vfunc_7@ParticlePlaneGenerator@pure3d@fn_002d2ae0@@QAEXII@Z @e4cc1aa4136e @w9db31a791fb7
namespace fn_002d2ae0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/7)
// pure3d::ParticlePlaneGenerator::vfunc_7 @ 0x002d2ae0
namespace pure3d { struct ParticlePlaneGenerator { char padding[0x4c]; unsigned int field4c, field50, field54, field58, field5c; void vfunc_7(unsigned int index, unsigned int value); }; void ParticlePlaneGenerator::vfunc_7(unsigned int index, unsigned int value) { switch (index) { case 1: field54 = value; break; case 2: field58 = value; break; case 3: field5c = value; break; case 4: field4c = value; break; case 5: field50 = value; break; } } }
} // namespace fn_002d2ae0


// 0x002d2b40 pure3d::ParticlePlaneGenerator::vfunc_8 (56 B): equivalent/0x002d2b40.cpp [wrapped: conflict: pure3d::ParticlePlaneGenerator]
// sym: ?vfunc_8@ParticlePlaneGenerator@pure3d@fn_002d2b40@@QAEMI@Z @1b73419227fd @wbfabf5e4d44b
namespace fn_002d2b40 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/7)
// pure3d::ParticlePlaneGenerator::vfunc_8 @ 0x002d2b40

namespace pure3d { struct ParticlePlaneGenerator { char pad[0x4c]; float a,b,c,d,e; float vfunc_8(unsigned int index); }; }
float pure3d::ParticlePlaneGenerator::vfunc_8(unsigned int index) {
    switch (index) {
    case 1: return c;
    case 2: return d;
    case 3: return e;
    case 4: return a;
    case 5: return b;
    default: return (*(float*)&DAT_003f32e0);
    }
}
} // namespace fn_002d2b40


// 0x002d2b90 pure3d::ParticlePlaneGenerator::vfunc_9 (21 B): matches/0x002d2b90.cpp
// sym: ?vfunc_9@ParticlePlaneGenerator@pure3d@@UAEXXZ
void pure3d::ParticlePlaneGenerator::vfunc_9() {
    *(int*)((char*)this + 0x4c) = 0x3f800000;
    *(int*)((char*)this + 0x50) = 0x3f800000;
    *(int*)((char*)this + 0x54) = 0x3f800000;
    *(int*)((char*)this + 0x58) = 0x3f800000;
    *(int*)((char*)this + 0x5c) = 0x3f800000;
}

namespace fn_fd7a7bd7 {

// 0x002d2bd0 FUN_002d2bd0 (76 B): matches/0x002d2bd0.cpp
// sym: ??0GeneratorBlendState_2d2bd0@fn_fd7a7bd7@@QAE@PAUOwner_2d2bd0@1@@Z
GeneratorBlendState_2d2bd0::GeneratorBlendState_2d2bd0(Owner_2d2bd0* arg) {
    a = 0;
    vptr = &hulk_at_0042f0c8;
    b = 0;
    c = 0;
    if (arg) {
        b = arg->Find_00288960(((int)0x444152), 0x31544c46);
        c = arg->Find_00288960(0x41564452, 0x31544c46);
    }
}

} // namespace fn_fd7a7bd7

// 0x002d2c30 pure3d::ParticleSphereGenerator::vfunc_3 (3 B): matches/0x002d2c30.cpp
// sym: ?vfunc_3@ParticleSphereGenerator@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::ParticleSphereGenerator::vfunc_3() {
    return true;
}

namespace fn_fd7a7bd7 {

// 0x002d2c40 pure3d::ParticleSphereGenerator::vfunc_6 (811 B): equivalent/0x002d2c40.cpp
// sym: ?vfunc_6@ParticleSphereGenerator@fn_fd7a7bd7@@QAEIIPAUMat4_2d2c40@2@0MPAVEmitter_2d2c40@2@@Z @fa17896e4fe3 @w26a5b4ab11b5
// STATUS: equivalent (tools/equiv.py level 3: 105 inputs, branch coverage 16/18, incomplete)
// pure3d::ParticleSphereGenerator::vfunc_6 @ 0x002d2c40
unsigned int ParticleSphereGenerator::vfunc_6(unsigned int count, Mat4_2d2c40* from, Mat4_2d2c40* to, float step, Emitter_2d2c40* em)
{
    if (count == 0)
        return 0;
    float radius = f40 * f38;
    float jitter = f44 * f3c;
    Frame_2d2c40 fr;
    fr.p = from->pos;
    float dx = fr.p.x - to->pos.x;
    float dy = fr.p.y - to->pos.y;
    float dz = fr.p.z - to->pos.z;
    volatile float inv = 1.0f / (float)count;
    fr.d.x = dx * inv;
    fr.d.y = dy * inv;
    fr.d.z = dz * inv;
    step = step * inv;
    unsigned int n = 0;
    if (radius != 0.0f) {
        volatile float t = 0.0f;
        for (unsigned int i = 0; i < count; i++) {
            float ph = (*(Rng_2d2c40*)&DAT_00554bfc).FUN_00143100() * 3.1415927f;
            float th = (*(Rng_2d2c40*)&DAT_00554bfc).FUN_00143100() * 3.1415927f;
            float v = (*(Rng_2d2c40*)&DAT_00554bfc).FUN_00143100() * jitter;
            Vec3_2d2c40& w = fr.w;
            FUN_00356bf0(radius, ph, th, &fr.tmp.x, &fr.tmp.y, &fr.tmp.z);
            w = fr.tmp;
            w.FUN_0022d260(from);
            Vec3_2d2c40& q = fr.q1;
            q = w;
            w.FUN_0022d110();
            q.x = w.x * v + (q.x + fr.p.x);
            q.y = w.y * v + (q.y + fr.p.y);
            q.z = w.z * v + (q.z + fr.p.z);
            if (!em->v14(&w, &q, t))
                break;
            n++;
            fr.p.x += fr.d.x;
            fr.p.y += fr.d.y;
            fr.p.z += fr.d.z;
            t += step;
        }
    } else {
        for (unsigned int i = 0; i < count; i++) {
            float ph = (*(Rng_2d2c40*)&DAT_00554bfc).FUN_00143100() * 3.1415927f;
            float th = (*(Rng_2d2c40*)&DAT_00554bfc).FUN_00143100() * 3.1415927f;
            float v = (*(Rng_2d2c40*)&DAT_00554bfc).FUN_00143100() * jitter;
            Vec3_2d2c40& w = fr.w;
            FUN_00356bf0(1.0f, ph, th, &w.x, &w.y, &w.z);
            w.FUN_0022d260(from);
            w.FUN_0022d110();
            Vec3_2d2c40& q = fr.q0;
            q.x = w.x * v + from->pos.x;
            q.y = w.y * v + from->pos.y;
            q.z = w.z * v + from->pos.z;
            if (!em->v14(&w, &q, 0.0f))
                break;
            n++;
        }
    }
    return n;
}

} // namespace fn_fd7a7bd7

// 0x002d2f70 pure3d::ParticleSphereGenerator::vfunc_7 (34 B): matches/0x002d2f70.cpp [wrapped: conflict: ParticleSphereGenerator]
// sym: ?vfunc_7@ParticleSphereGenerator@fn_002d2f70@@QAEXHI@Z
namespace fn_002d2f70 {
class ParticleSphereGenerator {
  public:
    char pad[0x48];
    void vfunc_7(int, unsigned);
};
void ParticleSphereGenerator::vfunc_7(int which, unsigned value) {
    switch (which) {
    case 3:
        *(unsigned*)(pad + 0x44) = value;
        break;
    case 6:
        *(unsigned*)(pad + 0x40) = value;
        break;
    }
}
} // namespace fn_002d2f70


// 0x002d2fa0 pure3d::ParticleSphereGenerator::vfunc_8 (22 B): matches/0x002d2fa0.cpp
// sym: ?vfunc_8@ParticleSphereGenerator@pure3d@@UAEMH@Z
// data: zero_2d2fa0 = DAT_003f32e0
hulk_freg pure3d::ParticleSphereGenerator::vfunc_8(int arg) {
    if (arg != 6)
        return DAT_003f32e0;
    return this->f_40;
}


// 0x002d2fc0 pure3d::ParticleSphereGenerator::vfunc_9 (12 B): matches/0x002d2fc0.cpp
// sym: ?vfunc_9@ParticleSphereGenerator@pure3d@@UAEXXZ
void pure3d::ParticleSphereGenerator::vfunc_9() {
    this->f_40 = 1.0f;
    this->f_44 = 1.0f;
}

namespace fn_fd7a7bd7 {

// 0x002d31b0 pure3d::ParticleGenerator::vfunc_2 (36 B): matches/0x002d31b0.cpp
// sym: ?vfunc_5@ParticleGenerator_2d31b0@fn_fd7a7bd7@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ParticleGenerator_2d31b0* ParticleGenerator_2d31b0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0042f074;
    Destroy_0027afd0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x002d31e0 pure3d::ParticleGenerator::vfunc_10 (319 B): equivalent/0x002d31e0.cpp
// sym: ?vfunc_10@ParticleGenerator@fn_fd7a7bd7@@UAEXM@Z @dee4acba2914 @w6df609bf45b2
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 13/14, incomplete)
// pure3d::ParticleGenerator::vfunc_10 @ 0x002d31e0
void ParticleGenerator::vfunc_10(float t)
{
    if (t >= 0.0f) {
        if (!(t <= 1.0f))
            t = 1.0f;
    } else {
        t = 0.0f;
    }

    float delta = t - time;
    *(unsigned *)&delta &= 0x7fffffff;
    if (delta <= 1e-05f)
        return;

    if (count <= 1) {
        index = 0;
        time = 0;
        atKey = 1;
        frac = 0;
        return;
    }

    float x = (float)(int)(count - 1) * t;
    int idx = (int)floor(x);
    time = t;
    index = idx;
    float f = x - (float)idx;
    frac = f;

    float rem = f - 1.0f;
    *(unsigned *)&rem &= 0x7fffffff;
    if (rem <= 1e-05f) {
        index = idx + 1;
        atKey = 0;
        frac = 0;
        return;
    }
    float af = f;
    *(unsigned *)&af &= 0x7fffffff;
    if (af <= 1e-05f)
        atKey = 0;
    else
        atKey = 1;
}

} // namespace fn_fd7a7bd7

// 0x002d3320 pure3d::ParticlePointGenerator::GeneratorBlendState::vfunc_2 (31 B): matches/0x002d3320.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002d3320@@UAEPAV123@E@Z
namespace fn_002d3320 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class NonCopyable_2d3320 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public NonCopyable_2d3320 {
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
} // namespace fn_002d3320

namespace fn_fd7a7bd7 {

// 0x002d3340 pure3d::ParticlePointGenerator::vfunc_5 (174 B): matches/0x002d3340.cpp
// sym: ?f@ParticlePointGenerator@fn_fd7a7bd7@@UAEXM@Z
void ParticlePointGenerator::f(float arg) {
    if (!(count > 0))
        return;
    if (mode == 1) {
        Elem_2d3340** p = points + index;
        Elem_2d3340* a = p[0];
        Elem_2d3340* b = p[1];
        out[0] = Mix_0028b150(a->c[0], b->c[0], amount, arg);
        out[1] = Mix_0028b150(a->c[1], b->c[1], amount, arg);
        out[2] = Mix_0028b150(a->c[2], b->c[2], amount, arg);
    } else {
        Elem_2d3340* p = points[index];
        ((owners::Curve_28a1c0 *)(p->c[0]))->FUN_0028a1c0(arg, &out[0]);
        ((owners::Curve_28a1c0 *)(p->c[1]))->FUN_0028a1c0(arg, &out[1]);
        ((owners::Curve_28a1c0 *)(p->c[2]))->FUN_0028a1c0(arg, &out[2]);
    }
}

} // namespace fn_fd7a7bd7

// 0x002d33f0 pure3d::ParticlePlaneGenerator::GeneratorBlendState::vfunc_2 (31 B): matches/0x002d33f0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002d33f0@@UAEPAV123@E@Z
namespace fn_002d33f0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class NonCopyable_2d33f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public NonCopyable_2d33f0 {
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
} // namespace fn_002d33f0


// 0x002d3410 pure3d::ParticlePlaneGenerator::vfunc_5 (249 B): equivalent/0x002d3410.cpp [wrapped: conflict: pure3d::ParticlePlaneGenerator]
// sym: ?vfunc_5@ParticlePlaneGenerator@pure3d@fn_002d3410@@QAEXM@Z @dd84d9a9f05c @w45854849fefd
namespace fn_002d3410 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// pure3d::ParticlePlaneGenerator::vfunc_5 @ 0x002d3410
struct Curve_2d3410 { void FUN_0028a1c0(float time, float* output); };
hulk_freg __cdecl FUN_0028b150(Curve_2d3410*, Curve_2d3410*, float, float);
struct Key_2d3410 { char pad[8]; Curve_2d3410* channels[5]; };
namespace pure3d {
struct ParticlePlaneGenerator {
 char pad0[16];
 unsigned char mode;
 char pad11[7];
 float blend;
 unsigned int count;
 unsigned int index;
 char pad24[8];
 Key_2d3410** keys;
 char pad30[8];
 float values[5];
 void vfunc_5(float time);
};
void ParticlePlaneGenerator::vfunc_5(float time) {
 if (!count) return;
 Key_2d3410* first = keys[index];
 if (mode == 1) {
  Key_2d3410* second = keys[index + 1];
  values[0] = FUN_0028b150(first->channels[0], second->channels[0], blend, time);
  values[1] = FUN_0028b150(first->channels[1], second->channels[1], blend, time);
  values[2] = FUN_0028b150(first->channels[2], second->channels[2], blend, time);
  values[3] = FUN_0028b150(first->channels[3], second->channels[3], blend, time);
  values[4] = FUN_0028b150(first->channels[4], second->channels[4], blend, time);
 } else {
  first->channels[0]->FUN_0028a1c0(time, &values[0]);
  first->channels[1]->FUN_0028a1c0(time, &values[1]);
  first->channels[2]->FUN_0028a1c0(time, &values[2]);
  first->channels[3]->FUN_0028a1c0(time, &values[3]);
  first->channels[4]->FUN_0028a1c0(time, &values[4]);
 }
}
}
} // namespace fn_002d3410


// 0x002d3510 pure3d::ParticleSphereGenerator::GeneratorBlendState::vfunc_2 (31 B): matches/0x002d3510.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002d3510@@UAEPAV123@E@Z
namespace fn_002d3510 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class NonCopyable_2d3510 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public NonCopyable_2d3510 {
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
} // namespace fn_002d3510


// 0x002d3530 pure3d::ParticleSphereGenerator::vfunc_5 (136 B): equivalent/0x002d3530.cpp [wrapped: conflict: pure3d::ParticleSphereGenerator]
// sym: ?vfunc_5@ParticleSphereGenerator@pure3d@fn_002d3530@@QAEXM@Z @a71627fc0f57 @w600ec5ba93ea
namespace fn_002d3530 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// pure3d::ParticleSphereGenerator::vfunc_5 @ 0x002d3530
struct Curve_2d3530 { void FUN_0028a1c0(float time, float *output); };
hulk_freg __cdecl FUN_0028b150(Curve_2d3530 *, Curve_2d3530 *, float, float);
struct Key_2d3530 { char pad[8]; Curve_2d3530 *channels[2]; };
namespace pure3d {
struct ParticleSphereGenerator {
    char pad0[16];
    unsigned char mode;
    char pad11[7];
    float blend;
    unsigned int count;
    unsigned int index;
    char pad24[8];
    Key_2d3530 **keys;
    char pad30[8];
    float values[2];
    void vfunc_5(float time);
};
void ParticleSphereGenerator::vfunc_5(float time)
{
    if (!count)
        return;
    Key_2d3530 *first = keys[index];
    if (mode == 1) {
        Key_2d3530 *second = keys[index + 1];
        values[0] = FUN_0028b150(first->channels[0], second->channels[0], blend, time);
        values[1] = FUN_0028b150(first->channels[1], second->channels[1], blend, time);
    } else {
        first->channels[0]->FUN_0028a1c0(time, &values[0]);
        first->channels[1]->FUN_0028a1c0(time, &values[1]);
    }
}
}
} // namespace fn_002d3530

namespace fn_fd7a7bd7 {

// 0x002d3740 FUN_002d3740 (67 B): matches/0x002d3740.cpp
// sym: ??0ParticlePointGenerator_2d3740@fn_fd7a7bd7@@QAE@XZ
ParticlePointGenerator_2d3740::ParticlePointGenerator_2d3740() throw() {
    _ReadWriteBarrier();
    m2c = 0;
    m30 = 0;
    m38 = 0;
    m3c = 0;
    m40 = 0;
    m44 = 1.0f;
    m48 = 1.0f;
    m4c = 1.0f;
}

} // namespace fn_fd7a7bd7

// 0x002d3790 FUN_002d3790 (267 B): equivalent/0x002d3790.cpp [wrapped: conflict: pure3d::ParticleGenerator; pure3d::ParticlePointGenerator]
// sym: ?copy@ParticlePointGenerator@pure3d@fn_002d3790@@QAEPAU123@ABU123@@Z @e32fe6d01dac @w1b693f82774a
void* __cdecl operator new(size_t,void*);
namespace fn_002d3790 {
// STATUS: equivalent (tools/equiv.py level 3: 37 inputs, branch coverage 16/16)
// FUN_002d3790 @ 0x002d3790
/* size_t: tree_prelude.h */

struct Ref_2d3790 { virtual void AddRef(); virtual void Release(); };
struct Part_2d3790 { unsigned a,b; void FUN_0027af70(const Part_2d3790*); };
namespace pure3d {
struct ParticleGenerator {virtual void slot0(); unsigned field4;Part_2d3790 part;unsigned char flag;char pad11[3];unsigned f14,f18,count,f20,f24;Ref_2d3790* ref;Ref_2d3790** items;Ref_2d3790** end;unsigned f34,f38,f3c,f40,f44,f48,f4c;void FUN_0027b070();};
struct ParticlePointGenerator:ParticleGenerator {virtual void slot0(); ParticlePointGenerator* copy(const ParticlePointGenerator&);};
}
extern "C" void* __cdecl FUN_0008d6d0(unsigned);
pure3d::ParticlePointGenerator* pure3d::ParticlePointGenerator::copy(const ParticlePointGenerator& src) {
 FUN_0027b070();
 this->ParticleGenerator::ParticleGenerator();
 flag=src.flag;f14=src.f14;f18=src.f18;count=src.count;f20=src.f20;part.FUN_0027af70(&src.part);
 this->ParticlePointGenerator::ParticlePointGenerator();
 ref=0;unsigned bytes=src.count*4;
 if(src.count){items=(Ref_2d3790**)FUN_0008d6d0(bytes);if(items)end=(Ref_2d3790**)((char*)items+bytes);else{items=0;end=0;}}else{items=0;end=0;}
 f38=src.f38;f3c=src.f3c;f40=src.f40;f44=src.f44;f48=src.f48;f4c=src.f4c;
 Ref_2d3790* r=src.ref;if(r)r->AddRef();if(ref)ref->Release();ref=r;
 for(unsigned i=0;i<count;++i){items[i]=0;Ref_2d3790** dst=&items[i];Ref_2d3790* r=src.items[i];if(r)r->AddRef();if(*dst)(*dst)->Release();*dst=r;}return this;
}
} // namespace fn_002d3790

namespace fn_fd7a7bd7 {

// 0x002d38a0 FUN_002d38a0 (102 B): matches/0x002d38a0.cpp
// sym: ??1ParticlePointGenerator_2d38a0@fn_fd7a7bd7@@QAE@XZ
ParticlePointGenerator_2d38a0::~ParticlePointGenerator_2d38a0() {
    vptr = g_vftable_0042f0d8;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    for (unsigned i = 0; i < m1c; i++) {
        Ref_2d38a0** p = &m2c[i];
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
    }
    if (m2c)
        operator delete(m2c);
    vptr = g_base_2d38a0;
    Fin_0027afd0();
}

} // namespace fn_fd7a7bd7

// 0x002d3910 pure3d::ParticlePointGenerator::vfunc_4 (31 B): matches/0x002d3910.cpp
// sym: ?vfunc_4@ParticlePointGenerator@pure3d@@UAEPAXXZ
void* pure3d::ParticlePointGenerator::vfunc_4() {
    void* p = allocThing_00263ea0(0x50);
    if (p)
        return (void*)(((Helper_2d3910*)p)->run_002d3790(this));
    return (void*)(0);
}


// 0x002d3930 FUN_002d3930 (79 B): equivalent/0x002d3930.cpp [wrapped: conflict: pure3d::ParticlePlaneGenerator]
// sym: ??0ParticlePlaneGenerator@pure3d@fn_002d3930@@QAE@XZ @13ca534329d3 @webeacc81de34
namespace fn_002d3930 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d3930 @ 0x002d3930
namespace pure3d {
struct FUN_0027b070 {
    FUN_0027b070();
    virtual void virtual0();
    char padding[0x0c];
};
struct ParticlePlaneGenerator : FUN_0027b070 {
    virtual void virtual0();
    unsigned char enabled;
    char pad11[3];
    int a14, a18, a1c, a20;
    char pad24[4];
    int a28, a2c, a30;
    char pad34[4];
    float a38, a3c;
    int a40, a44, a48;
    float a4c, a50, a54, a58, a5c;
    ParticlePlaneGenerator();
};
ParticlePlaneGenerator::ParticlePlaneGenerator() {
    enabled = 0;
    a14 = a18 = a1c = a20 = a28 = 0;
    a2c = a30 = a40 = a44 = a48 = 0;
    a38 = a3c = a4c = a50 = a54 = a58 = a5c = 1.0f;
}
}
} // namespace fn_002d3930


// 0x002d3980 FUN_002d3980 (297 B): equivalent/0x002d3980.cpp [wrapped: conflict: pure3d::ParticleGenerator; pure3d::ParticlePlaneGenerator]
// sym: ?copy@ParticlePlaneGenerator@pure3d@fn_002d3980@@QAEPAU123@ABU123@@Z @7ff0f3cc0571 @w8b93527ed2f8
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_002d3980 {
// STATUS: equivalent (tools/equiv.py level 3: 37 inputs, branch coverage 16/16)
// FUN_002d3980 @ 0x002d3980

struct Ref_2d3980 { virtual void AddRef()=0; virtual void Release()=0; };
struct Small_2d3980 { char data[8]; void FUN_0027af70(const Small_2d3980*); };
namespace pure3d {
struct ParticleGenerator {
 virtual void placeholder();
 unsigned int unknown4; Small_2d3980 data; unsigned char flag; char pad11[3];
 unsigned int a14,a18,count,a20,a24; Ref_2d3980* object; Ref_2d3980** items; Ref_2d3980** end; unsigned int a34; unsigned int fields[10];
 void FUN_0027b070();
};
struct ParticlePlaneGenerator: ParticleGenerator { virtual void placeholder(); ParticlePlaneGenerator* copy(const ParticlePlaneGenerator&); };
}
void* __cdecl FUN_0008d6d0(unsigned int);
pure3d::ParticlePlaneGenerator* pure3d::ParticlePlaneGenerator::copy(const ParticlePlaneGenerator& src) {
 FUN_0027b070(); new(this) ParticleGenerator;
 flag=src.flag; a14=src.a14; a18=src.a18; count=src.count; a20=src.a20;
 data.FUN_0027af70(&src.data);
 new(this) ParticlePlaneGenerator;
 object=0;
 unsigned int bytes=src.count*sizeof(Ref_2d3980*);
 if(src.count>0) { items=(Ref_2d3980**)FUN_0008d6d0(bytes); if(items) end=(Ref_2d3980**)((char*)items+bytes); else {items=0;end=0;} } else {items=0;end=0;}
 for(unsigned int j=0;j<10;++j) fields[j]=src.fields[j];
 Ref_2d3980* r=src.object; if(r) r->AddRef(); if(object) object->Release(); object=r;
 for(unsigned int i=0;i<count;++i) { items[i]=0; Ref_2d3980** slot=items+i; Ref_2d3980* value=src.items[i]; if(value) value->AddRef(); if(*slot) (*slot)->Release(); *slot=value; }
 return this;
}
} // namespace fn_002d3980

namespace fn_fd7a7bd7 {

// 0x002d3ab0 FUN_002d3ab0 (102 B): matches/0x002d3ab0.cpp
// sym: ??1ParticlePlaneGenerator_2d3ab0@fn_fd7a7bd7@@QAE@XZ
ParticlePlaneGenerator_2d3ab0::~ParticlePlaneGenerator_2d3ab0() {
    vptr = hulk_at_0042f10c;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    for (unsigned i = 0; i < m1c; i++) {
        Ref_2d3ab0** p = &m2c[i];
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
    }
    if (m2c)
        operator delete(m2c);
    vptr = g_base_2d3ab0;
    Fin_0027afd0();
}

} // namespace fn_fd7a7bd7

// 0x002d3b20 pure3d::ParticlePlaneGenerator::vfunc_4 (31 B): matches/0x002d3b20.cpp
// sym: ?vfunc_4@ParticlePlaneGenerator@pure3d@@UAEPAXXZ
// Same code shape as 0x002a7540 (propagated; names are from that function)
void* pure3d::ParticlePlaneGenerator::vfunc_4() {
    pure3d::ParticlePlaneGenerator* self = this;
    Other_2d3b20* p = (Other_2d3b20*)allocate(0x60);
    if (p)
        return (void*)(p->helper_002d3980(self));
    return (void*)(0);
}


// 0x002d3b40 FUN_002d3b40 (61 B): matches/0x002d3b40.cpp [wrapped: conflict: ParticleSphereGenerator]
// sym: ??0ParticleSphereGenerator@fn_002d3b40@@QAE@XZ
namespace fn_002d3b40 {
class Base {
  public:
    Base();
    virtual void fn();
    char pad[12];
    unsigned char flag;
    char gap[3];
    int a, b, c, d;
    char gap2[4];
    int e;
};
class ParticleGenerator_2d3b40 : public Base {
  public:
    ParticleGenerator_2d3b40() {
        flag = 0;
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        e = 0;
    }
};
struct Zeros {
    int f, g;
    Zeros() : f(0), g(0) {}
};
struct Floats {
    float h;
    int i;
    float j, k;
    Floats() : h(1.0f), i(0), j(1.0f), k(1.0f) {}
};
class ParticleSphereGenerator : public ParticleGenerator_2d3b40 {
  public:
    ParticleSphereGenerator();
    virtual void fn();
    Zeros z;
    char pad[4];
    Floats values;
};
ParticleSphereGenerator::ParticleSphereGenerator() {}
} // namespace fn_002d3b40


// 0x002d3b80 FUN_002d3b80 (265 B): equivalent/0x002d3b80.cpp [wrapped: conflict: pure3d::ParticleGenerator; pure3d::ParticleSphereGenerator]
// sym: ??0ParticleSphereGenerator@pure3d@fn_002d3b80@@QAE@ABU012@@Z @d018ea310c83 @wf8060fd1029c
namespace fn_002d3b80 {
// STATUS: equivalent (tools/equiv.py level 3: 37 inputs, branch coverage 16/16)
// FUN_002d3b80 @ 0x002d3b80
typedef unsigned int uint;
struct Ref_2d3b80 { virtual void AddRef(); virtual void Release(); };
struct Small_2d3b80 { void FUN_0027af70(const Small_2d3b80*); char data[8]; };
struct FUN_0027b070 { virtual void placeholder(); uint f4; FUN_0027b070(); };
namespace pure3d {
struct ParticleGenerator : FUN_0027b070 {
 virtual void placeholder();
 Small_2d3b80 small;
 unsigned char flag; char pad11[3];
 uint f14,f18,count,f20,f24;
 Ref_2d3b80* object; Ref_2d3b80** entries; Ref_2d3b80** end;
 uint f34,f38,f3c,f40,f44;
 ParticleGenerator(const ParticleGenerator& source) {
 flag=source.flag; f14=source.f14; f18=source.f18; count=source.count; f20=source.f20;
 small.FUN_0027af70(&source.small);
 }
};
struct ParticleSphereGenerator : ParticleGenerator {
 virtual void placeholder();
 ParticleSphereGenerator(const ParticleSphereGenerator& source);
};
}
void* __cdecl FUN_0008d6d0(uint);
pure3d::ParticleSphereGenerator::ParticleSphereGenerator(const ParticleSphereGenerator& source) : ParticleGenerator(source) {
 object=0;
 uint size=source.count*sizeof(Ref_2d3b80*);
 if(source.count) {
 entries=(Ref_2d3b80**)FUN_0008d6d0(size);
 if(entries) end=(Ref_2d3b80**)((char*)entries+size);
 else { entries=0; end=0; }
 } else { entries=0; end=0; }
 f38=source.f38; f3c=source.f3c; f40=source.f40; f44=source.f44;
 Ref_2d3b80* obj=source.object;
 if(obj) obj->AddRef();
 if(object) object->Release();
 object=obj;
 for(uint i=0;i<count;++i) {
 entries[i]=0;
 Ref_2d3b80** slot=&entries[i];
 Ref_2d3b80* item=source.entries[i];
 if(item) item->AddRef();
 if(*slot) (*slot)->Release();
 *slot=item;
 }
}
} // namespace fn_002d3b80

namespace fn_fd7a7bd7 {

// 0x002d3c90 FUN_002d3c90 (102 B): matches/0x002d3c90.cpp
// sym: ??1ParticleSphereGenerator_2d3c90@fn_fd7a7bd7@@QAE@XZ
ParticleSphereGenerator_2d3c90::~ParticleSphereGenerator_2d3c90() {
    vptr = hulk_at_0042f140;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    for (unsigned i = 0; i < n; i++) {
        Ref_2d3c90** p = &arr[i];
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
    }
    if (arr)
        operator delete(arr);
    vptr = g_vftable_base;
    Fin_0027afd0();
}

} // namespace fn_fd7a7bd7

// 0x002d3d00 pure3d::ParticleSphereGenerator::vfunc_4 (31 B): matches/0x002d3d00.cpp
// sym: ?vfunc_4@ParticleSphereGenerator@pure3d@@UAEPAXXZ
// Same code shape as 0x00297130 (propagated; names are from that function)
void* pure3d::ParticleSphereGenerator::vfunc_4() {
    Obj_2d3d00* p = alloc_00263ea0(0x48);
    if (p)
        return (void*)(p->helper_002d3b80(this));
    return (void*)(0);
}


// 0x002d3d20 pure3d::ParticlePointGenerator::vfunc_2 (30 B): matches/0x002d3d20.cpp
// sym: ??_GParticlePointGenerator@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::ParticlePointGenerator::~ParticlePointGenerator() {}


// 0x002d3d40 pure3d::ParticlePlaneGenerator::vfunc_2 (30 B): matches/0x002d3d40.cpp
// sym: ??_GParticlePlaneGenerator@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::ParticlePlaneGenerator::~ParticlePlaneGenerator() {}


// 0x002d3d60 pure3d::ParticleSphereGenerator::vfunc_2 (30 B): matches/0x002d3d60.cpp
// sym: ??_GParticleSphereGenerator@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::ParticleSphereGenerator::~ParticleSphereGenerator() {}

