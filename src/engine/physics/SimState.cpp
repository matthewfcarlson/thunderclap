// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002ef300..0x002efb70 (kind game, layer engine, confidence high), dominant class physics::SimState
#include "tree_prelude.h"
#include "decls/physics_world.h"   // (x64t5) the CollisionObject words
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f89b78b9 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f89b78b9 {} using namespace fn_f89b78b9;
#include "engine/physics.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f89b78b9 {
class Obj_2ef3d0 {
  public:
    virtual void Run();
    virtual void Release();
};
class Obj_2ef3f0 {
  public:
    virtual void f();
};
class Old_2ef3f0 {
  public:
    void cleanup_00263e90();
};
// (x64t6) the state's CollisionObject (HULK_SS(0x74)), its shape (HULK_CO_AT(f20)) and the shape's f34 (HULK_CV(0x34)):
// decls/physics_world.h's offsets (were 32-bit pads)
struct Inner_2ef420 {
    char pad[HULK_CV(0x34)];
    float value;
};
struct Holder_2ef420 {
    char pad[HULK_CO_AT(f20)];
    Inner_2ef420* inner;
};
struct Obj_2ef420 {
    char pad[HULK_SS(0x74)];
    Holder_2ef420* holder;
};
struct Helper_2ef440 {
};
class SimulatedObject {
  public:
    virtual void v0();
};
class PhysicsObject : public SimulatedObject {
  public:
    virtual void v1();
    void Finish_002fe6a0(int);
};
struct Obj_2ef440 {
    char pad70[HULK_SS(0x70)];   // (x64t6) decls/physics_world.h's SimState offsets
    SimulatedObject* m70;
    Helper_2ef440* m74;
    void Target(int);
};
typedef unsigned int u32_2ef4a0;
struct Obj18_2ef4a0 {
    char pad[0x18];
    u32_2ef4a0 val;
};
struct Obj1c {
    char pad[HULK_CO_AT(f1c)];   // (x64t6) the CollisionObject's flags (decls/physics_world.h)
    u32_2ef4a0 val;
};
extern int hulk_at_004c60bc;
extern int hulk_at_004c60e4;
class C_2ef4a0 {
  public:
    char pad[HULK_SS(0x70)];   // (x64t6) decls/physics_world.h's SimState offsets
    void* source;
    Obj1c* cached;
};
struct Vec3_2ef530 {
    float x, y, z;
};
struct Vec_2ef5b0 {
    float x, y, z;
};
struct Matrix_2ef5b0 {
    float m[16];
};
struct Position_2ef5b0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec_2ef5b0* slot4();
    char pad[HULK_CV(0x19) - sizeof(void*)];   // (x64t6) the volume's c19 (decls/physics_world.h)
    unsigned char dirty;
};
struct Node_2ef5b0 {   // (x64t6) the CollisionObject's shape (f20) and b68 at the record's offsets
    char pad0[HULK_CO_AT(f20)];
    Position_2ef5b0* position;
    char pad1[HULK_CO_AT(b68) - HULK_CO_AT(f20) - sizeof(void*)];
    unsigned char dirty;
};
} // namespace fn_f89b78b9
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif
namespace fn_f89b78b9 {
struct SimState_nv_2ef670 {
};
struct Vec3_2ef760 {
    float x, y, z;
};
struct Pose {
    char pad00[0x30];
    Vec3_2ef760 pos;                // 0x30
};
struct Motion_2ef760 {
    Vec3_2ef760 delta;              // 0x00
    Vec3_2ef760 aux;                // 0x0c
};
extern "C" void __cdecl FUN_00305630(Vec3_2ef760 *out, Pose *a, Pose *b, float dt);
struct Sub_2ef7f0 {
    char pad[0x40];
    void Init_0022b980() throw();
};
class SimState_2ef7f0 {
  public:
    void* vptr;
    hulk_intptr m4;   // (x64t6) decls/physics_world.h HulkSimState: NonCopyable's word and the two pointers pointer-sized
    int m8, mc;
    Sub_2ef7f0 sub;
    int m50, m54, m58, m5c, m60, m64;
    float f68;
    int m6c;
    void* m70;
    void* m74;
    char c78;
    int m7c, m80;
    char c84, c85;
    SimState_2ef7f0(int a) throw();
};
typedef char hulk_size_2ef7f0[(sizeof(SimState_2ef7f0) == sizeof(HulkSimState)) ? 1 : -1];   // (x64t6) the record's size on every build
extern "C" char DAT_003f6098[];
extern "C" char DAT_00431214[];
void freeit_0008d330(void*);
class Obj_2ef850 {
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
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual void w();
    virtual void x();
    virtual void y();
    virtual void z();
    virtual void aa();
    virtual void ab();
    virtual void ac();
    virtual void ad(int);
};
class Obj_2ef8b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int);
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
    virtual float f21();
};
class State_2ef8b0 {
  public:
    char pad[0x6c];
    int state;
    Obj_2ef8b0* obj;
    void set(int x);
};
struct Mat_2ef900 {
    float m[16];
};
struct Vec3_2ef900 {
    float x, y, z;
};
struct Flags_2ef900 {
    char pad0[0x19];
    unsigned char b19;
};
class Controller_2ef900 {
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
    virtual void vfunc_9();
    virtual void vfunc_10();
};
struct Target_2ef900 {
    char pad0[0x20];
    Flags_2ef900 *flags;
    char pad24[0x68 - 0x24];
    unsigned char on;
    unsigned char dirty;
};
class SimState {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual SimState* f2(unsigned char);
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void vfunc_6(Mat_2ef900 *mat, float dt);
    virtual void vfunc_7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual void _m_vf14();
    hulk_intptr _m_4;   // (x64t6) NonCopyable's word, pointer-sized (decls/physics_world.h HulkSimState)
    char _m_pad_8[8];
    Mat_2ef900 current;
    Vec3_2ef900 delta;
    char _m_pad_5c[0xc];
    int mode;
    int f6c;
    Obj_2ef850* m70;
    union { Obj_2ef850* m74; Target_2ef900 *target; };
    unsigned char changed;
    char _m_pad_79[0x7];
    float radius;
    unsigned char locked;
    char _m_pad_85[0x3];
};
class Sim;
char __cdecl FUN_00306060(Mat_2ef900 *a, Mat_2ef900 *b, float eps);
void __cdecl FUN_002ef760(Mat_2ef900 *cur, Mat_2ef900 *next, int mode, float dt, Vec3_2ef900 *out);
struct SimState_2efa90;
struct Source_2efa90;
struct Parent_2efa90;
struct Service_2efa90 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
};
struct Parent_2efa90 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual Parent_2efa90* v28(SimState_2efa90*); virtual void v29(SimState_2efa90*);
 char pad[12]; int attached; char pad2[4]; void* data;
};
struct Source_2efa90 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual Source_2efa90* v5(SimState_2efa90*);
 // (x64t5) a CollisionObject: decls/physics_world.h's words (Entity's, the name, the owner and shape pointers)
 HULK_ENTITY_WORDS char name[8]; SimState_2efa90* owner; int f1c; Service_2efa90* service; int f24;
 struct { int f28, f2c; void* f30; char b34, b35; };
 struct { int f38; void* f3c; struct { int f40, f44; unsigned char* f48; char b4c, b4d; }; };
 char b50, b51; int f54, f58, f5c, f60, f64; unsigned char flag1; unsigned char flag2;
};
struct SimState_2efa90 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(Parent_2efa90*); virtual void v14(Source_2efa90*);
 SimState_2efa90* FUN_002ef7f0(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

} // namespace fn_f89b78b9

// 0x002ef300 physics::SimState::vfunc_4 (6 B): matches/0x002ef300.cpp
// sym: ?vfunc_4@SimState@physics@@UAEPAXPAX@Z
 // namespace physics
void* physics::SimState::vfunc_4(void* __p0) {
    return (void*)((physics::SimState*)((char*)this + 0x10));
}


// 0x002ef310 physics::SimState::vfunc_5 (6 B): matches/0x002ef310.cpp
// sym: ?vfunc_5@SimState@physics@@UAEPAXH@Z
void* physics::SimState::vfunc_5(int ) {
    return (void*)((physics::SimState*)((char*)this + 0x40));
}


// 0x002ef320 physics::SimState::vfunc_7 (27 B): matches/0x002ef320.cpp
// sym: ?vfunc_7@SimState@physics@@UAEXXZ
void physics::SimState::vfunc_7() {
    *(int*)((*(char (*)[64])&this->f_50) + 0x08) = 0;
    *(int*)((*(char (*)[64])&this->f_50) + 0x04) = 0;
    *(int*)((*(char (*)[64])&this->f_50) + 0x00) = 0;
    *(int*)((*(char (*)[64])&this->f_50) + 0x14) = 0;
    *(int*)((*(char (*)[64])&this->f_50) + 0x10) = 0;
    *(int*)((*(char (*)[64])&this->f_50) + 0x0c) = 0;
    *(int*)((*(char (*)[64])&this->f_50) + 0x30) = 0;
}


// 0x002ef340 physics::SimState::vfunc_9 (6 B): matches/0x002ef340.cpp
// sym: ?vfunc_9@SimState@physics@@UAEII@Z
unsigned int physics::SimState::vfunc_9(unsigned int unused) {
    return (*(unsigned int *)&this->f_70);
}


// 0x002ef350 physics::SimState::vfunc_11 (3 B): matches/0x002ef350.cpp
// sym: ?vfunc_11@SimState@physics@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool physics::SimState::vfunc_11() {
    return true;
}


// 0x002ef3b0 physics::SimState::vfunc_3 (28 B): matches/0x002ef3b0.cpp
// sym: ?vfunc_3@SimState@physics@@UAEXD@Z
void physics::SimState::vfunc_3(char param) {
    char* x = (char*)(*(void * *)&this->f_74);
    if (x) {
        x[0x68] = param;
        if (param)
            *(char*)((char*)*(void**)(x + 0x20) + 0x19) = 0;
    }
}


// 0x002ef3d0 physics::SimState::vfunc_13 (30 B): matches/0x002ef3d0.cpp
// sym: ?vfunc_13@SimState@physics@@UAEXPAX@Z
void physics::SimState::vfunc_13(void* __p0) { void * p = (void *)__p0;

    if ((*(Obj_2ef3d0 * *)&this->f_70))
        (*(Obj_2ef3d0 * *)&this->f_70)->Release();
    (*(Obj_2ef3d0 * *)&this->f_70) = (Obj_2ef3d0*)p;
    (*(Obj_2ef3d0 * *)&this->f_70)->Run();
}


// 0x002ef3f0 physics::SimState::vfunc_14 (38 B): matches/0x002ef3f0.cpp
// sym: ?vfunc_14@SimState@physics@@UAEXPAX@Z
void physics::SimState::vfunc_14(void* __p0) { Obj_2ef3f0 * p = (Obj_2ef3f0 *)__p0;

    if (p)
        p->f();
    if ((*(Obj_2ef3f0 * *)&this->f_74))
        ((Old_2ef3f0*)(*(Obj_2ef3f0 * *)&this->f_74))->cleanup_00263e90();
    (*(Obj_2ef3f0 * *)&this->f_74) = p;
}

namespace fn_f89b78b9 {

// 0x002ef420 FUN_002ef420 (21 B): matches/0x002ef420.cpp
// sym: ?FUN_002ef420@fn_f89b78b9@@YIMPAUObj_2ef420@1@@Z
float __fastcall FUN_002ef420(Obj_2ef420* self) {
    if (self->holder)
        return self->holder->inner->value;
    return DAT_003f32dc;
}


// 0x002ef440 FUN_002ef440 (94 B): matches/0x002ef440.cpp
// sym: ?Target@Obj_2ef440@fn_f89b78b9@@QAEXH@Z
void Obj_2ef440::Target(int arg) {
    if (m74)
        ((owners::C_304740 *)m74)->FUN_00304740((hulk_intptr)arg);
    if (m70) {
        if (dynamic_cast<PhysicsObject*>(m70)) {
            dynamic_cast<PhysicsObject*>(m70)->Finish_002fe6a0(arg);
        }
    }
}


// 0x002ef4a0 FUN_002ef4a0 (84 B): matches/0x002ef4a0.cpp
// sym: ?Target@fn_f89b78b9@@YIIPAVC_2ef4a0@1@@Z
u32_2ef4a0 __fastcall Target(C_2ef4a0* self) {
    if (self->cached)
        return self->cached->val;
    if (self->source) {
        if (__RTDynamicCast(self->source, 0, (void*)(&hulk_at_004c60bc), (void*)(&hulk_at_004c60e4), 0)) {
            return ((Obj18_2ef4a0*)__RTDynamicCast(self->source, 0, (void*)(&hulk_at_004c60bc), (void*)(&hulk_at_004c60e4), 0))->val;
        }
    }
    return 0;
}

} // namespace fn_f89b78b9

// 0x002ef530 physics::SimState::vfunc_8 (116 B): equivalent/0x002ef530.cpp
// sym: ?vfunc_8@SimState@physics@@UAEXHHH@Z @153a8f7283be @wb85210fe96ea
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 0/0)
// physics::SimState::vfunc_8 @ 0x002ef530
void physics::SimState::vfunc_8(hulk_intptr __p0, hulk_intptr __p1, int unused) { const Vec3_2ef530 * p = (const Vec3_2ef530 *)__p0; Vec3_2ef530 * out = (Vec3_2ef530 *)__p1;

    double dx = p->x - (*(Vec3_2ef530 *)&this->f_40).x;
    double dy = p->y - (*(Vec3_2ef530 *)&this->f_40).y;
    double dz = p->z - (*(Vec3_2ef530 *)&this->f_40).z;
    // ny and nz are rounded frame copies in the original; nx stays in a register
    volatile float ny = dx * (*(Vec3_2ef530 *)&this->f_5c).z - dz * (*(Vec3_2ef530 *)&this->f_5c).x;
    volatile float nz = dy * (*(Vec3_2ef530 *)&this->f_5c).x - dx * (*(Vec3_2ef530 *)&this->f_5c).y;
    double nx = dz * (*(Vec3_2ef530 *)&this->f_5c).y - dy * (*(Vec3_2ef530 *)&this->f_5c).z;
    volatile float *o = &out->x;
    o[1] = ny;
    o[2] = nz;
    o[0] = nx;
    o[0] = o[0] + (*(Vec3_2ef530 *)&this->f_50).x;
    o[1] = ny + (*(Vec3_2ef530 *)&this->f_50).y;
    o[2] = nz + (*(Vec3_2ef530 *)&this->f_50).z;
}


// 0x002ef5b0 FUN_002ef5b0 (179 B): matches/0x002ef5b0.cpp
// sym: ?FUN_002ef5b0@SimState@physics@@QAEXPAX0@Z
void physics::SimState::FUN_002ef5b0(void* __p0, void* __p1) { const Matrix_2ef5b0 * first = (const Matrix_2ef5b0 *)__p0; Matrix_2ef5b0 * second = (Matrix_2ef5b0 *)__p1;

    Matrix_2ef5b0 inverse = *first;
    ((owners::Matrix_22cdb0 *)&inverse)->FUN_0022cdb0();
    Vec_2ef5b0 intermediate, delta;
    ((owners::Mat_22c2b0 *)&inverse)->FUN_0022c2b0((float *)(const Vec_2ef5b0 *)((*(Node_2ef5b0 * *)&this->f_74)->position->slot4()), (float *)(Vec_2ef5b0 *)(&intermediate));
    ((owners::Mat_22c2b0 *)second)->FUN_0022c2b0((float *)(const Vec_2ef5b0 *)(&intermediate), (float *)(Vec_2ef5b0 *)(&delta));
    Vec_2ef5b0* original = (*(Node_2ef5b0 * *)&this->f_74)->position->slot4();
    Node_2ef5b0* current = (*(Node_2ef5b0 * *)&this->f_74);
    delta.x = delta.x - original->x;
    delta.y = delta.y - original->y;
    delta.z = delta.z - original->z;
    current->dirty = 1;
    Vec_2ef5b0* result = current->position->slot4();
    result->x = delta.x + result->x;
    result->y = delta.y + result->y;
    result->z = delta.z + result->z;
    current->position->dirty = 0;
}


// 0x002ef670 physics::SimState::vfunc_12 (137 B): matches/0x002ef670.cpp
// sym: ?vfunc_12@SimState@physics@@UAEXPAXM_N@Z
void physics::SimState::vfunc_12(void* __p0, float dt, bool apply) { float * delta = (float *)__p0;

    if (!(*(void * *)&this->f_70) || this->f_6c != 1)
        return;
    float temp[16];
    memcpy(temp, (char*)this + 0x10, 64);
    this->f_40 += delta[0];
    this->f_44 += delta[1];
    this->f_48 += delta[2];
    ((physics::SimState *)(((SimState_nv_2ef670*)this)))->FUN_002ef5b0(temp, (char*)this + 0x10);
    if (apply) {
        hulk_freg s = 1.0f / dt;
        *(float*)((char*)this + 0x50) += s * delta[0];
        *(float*)((char*)this + 0x54) += s * delta[1];
        *(float*)((char*)this + 0x58) += s * delta[2];
    }
}


// 0x002ef700 physics::SimState::vfunc_10 (3 B): matches/0x002ef700.cpp
// sym: ?vfunc_10@SimState@physics@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void physics::SimState::vfunc_10(int a) {
    (void)a;
}

namespace fn_f89b78b9 {

// 0x002ef760 FUN_002ef760 (143 B): equivalent/0x002ef760.cpp
// sym: ?FUN_002ef760@fn_f89b78b9@@YAXPAUPose@1@0MMPAUMotion_2ef760@1@@Z @9c3b1efd31cb @w7775b0d7286e
// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 2/2)
// FUN_002ef760 @ 0x002ef760
void __cdecl FUN_002ef760(Pose *from, Pose *to, float scale, float dt, Motion_2ef760 *out) {
    out->delta.x = to->pos.x - from->pos.x;
    out->delta.y = to->pos.y - from->pos.y;
    out->delta.z = to->pos.z - from->pos.z;
    hulk_freg inv = 1.0f / dt;
    out->delta.x = inv * out->delta.x;
    out->delta.y = inv * out->delta.y;
    out->delta.z = inv * out->delta.z;
    FUN_00305630(&out->aux, from, to, dt);
    if (scale != 1.0f) {
        hulk_freg k = 1.0f / (scale * scale);
        out->aux.x = k * out->aux.x;
        out->aux.y = k * out->aux.y;
        out->aux.z = k * out->aux.z;
    }
}


// 0x002ef7f0 FUN_002ef7f0 (96 B): matches/0x002ef7f0.cpp
// sym: ??0SimState_2ef7f0@fn_f89b78b9@@QAE@H@Z
SimState_2ef7f0::SimState_2ef7f0(int a) throw() {
    int t = *(volatile int*)&a;
    m4 = 0;
    vptr = (void*)DAT_00431214;   // (x64t5) physics::SimState's vftable by address (common.h's `vA` is a zero stub natively)
    m8 = 0;
    mc = 0;
    m50 = 0;
    m54 = 0;
    m58 = 0;
    m5c = 0;
    m60 = 0;
    m64 = 0;
    _ReadWriteBarrier();
    m6c = t;
    f68 = 1.0f;
    m70 = 0;
    m74 = 0;
    c78 = 0;
    m7c = 0;
    m80 = 0;
    c84 = 0;
    c85 = 0;
    sub.Init_0022b980();
}


// 0x002ef850 physics::SimState::vfunc_2 (81 B): matches/0x002ef850.cpp
// sym: ?f2@SimState@fn_f89b78b9@@UAEPAV12@E@Z
SimState* SimState::f2(unsigned char flag) {
    Obj_2ef850* a = m74;
    if (a) {
        *(void**)this = (void*)((hulk_intptr)DAT_00431214);
        *(void**)((char*)a + HULK_CO_OWNER) = 0;   // (x64t6) the CollisionObject's owner (was an int at 0x18)
        m74->b();
    } else {
        *(void**)this = (void*)((hulk_intptr)DAT_00431214);
    }
    if (m70) {
        m70->ad(0);
        m70->b();
    }
    *(void**)this = (void*)((hulk_intptr)DAT_003f6098);
    if (flag & 1)
        freeit_0008d330(this);
    return this;
}


// 0x002ef8b0 FUN_002ef8b0 (80 B): matches/0x002ef8b0.cpp
// sym: ?set@State_2ef8b0@fn_f89b78b9@@QAEXH@Z
void State_2ef8b0::set(int x) {
    if (state != x) {
        state = x;
        if (x == 1) {
            if (obj != 0 && obj->f21() != 0.0f) {
                obj->f6(0);
                obj->f13();
                return;
            }
            state = 0;
        }
    }
}


// 0x002ef900 physics::SimState::vfunc_6 (330 B): equivalent/0x002ef900.cpp
// sym: ?vfunc_6@SimState@fn_f89b78b9@@UAEXPAUMat_2ef900@2@M@Z @66a949132582 @w90c5a277a95b
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 21/24, incomplete)
// physics::SimState::vfunc_6 @ 0x002ef900
void SimState::vfunc_6(Mat_2ef900 *mat, float dt)
{
    Mat_2ef900 *cur = &current;
    changed = (FUN_00306060(cur, mat, 1e-6f) == 0);
    if (f6c == 0) {
        if (changed) {
            if (dt != 0.0f) {
                FUN_002ef760(cur, mat, mode, dt, &delta);
            } else {
                vfunc_7();
                if (target != 0) {
                    target->flags->b19 = 0;
                    target->on = 1;
                    target->dirty = 1;
                    Target_2ef900 *t = target;
                    if (t->on != 0 || t->dirty != 0)
                        ((Controller_2ef900 *)t->flags)->vfunc_10();
                }
            }
        } else {
            vfunc_7();
        }
    }
    if (target != 0 && changed)
        ((physics::SimState *)this)->FUN_002ef5b0((Mat_2ef900 *)cur, (Mat_2ef900 *)mat);

    unsigned char lockedNow = locked;
    *cur = *mat;
    if (lockedNow != 0)
        return;

    hulk_freg lenSq = delta.z * delta.z + delta.y * delta.y + delta.x * delta.x;
    hulk_freg limit = 2.0f * radius;
    if (lenSq > limit * limit) {
        radius = (float)sqrt((double)lenSq);
        Target_2ef900 *t = target;
        if (t != 0) {
            t->flags->b19 = 0;
            t->on = 1;
            t->dirty = 1;
        }
    } else if (lenSq < radius / 2.0f) {
        radius = (float)sqrt((double)lenSq);
    }
}


// 0x002efa90 FUN_002efa90 (192 B): equivalent/0x002efa90.cpp
// sym: _FUN_002efa90 @bee551f84037 @wc45417a8875b
// STATUS: equivalent (tools/equiv.py level 3: 20020 inputs, branch coverage 23/24, incomplete)
// FUN_002efa90 @ 0x002efa90
extern "C" SimState_2efa90* __cdecl FUN_002efa90(Source_2efa90* source, Parent_2efa90* parent, SimState_2efa90* storage) {
 // (x64t4) the state allocated by its constructor's layout (0x002ef7f0: 0x88 bytes on the 32-bit builds, 4 more
 // than that natively, which its constructor overran)
 if (!storage) storage = (SimState_2efa90*)FUN_0008d690((unsigned)sizeof(SimState_2ef7f0));
 if (!storage) return 0;
 SimState_2efa90* result = storage->FUN_002ef7f0(0);
 if (!result) return 0;
 if (parent) {
  if (parent->attached) parent = parent->v28(result);
  else parent->v29(result);
  result->v13(parent);
 }
 if (source) {
  bool cloned = false;
  if (source->owner) { source = source->v5(result); cloned = true; }
  else source->owner = result;
  result->v14(source);
  if (!cloned) {
   if (source->flag1 || source->flag2) source->service->v10();
   source->service->v8();
  }
  if (parent && source) ((owners::C_304740 *)source)->FUN_00304740((hulk_intptr)(parent->data));
 }
 return result;
}

} // namespace fn_f89b78b9
