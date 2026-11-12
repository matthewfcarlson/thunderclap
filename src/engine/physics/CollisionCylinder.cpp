// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002f2e70..0x002f32b0 (kind game, layer engine, confidence high), dominant class physics::CollisionCylinder
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/physics_world.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f419e76e {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f419e76e {} using namespace fn_f419e76e;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f419e76e {
extern "C" char DAT_004313cc[];
struct Part_2f2e70 {
    void Init_00306e00();
};
struct CollisionCylinder_nv_2f2e70 {
    void Finish_00306ac0();
};
struct CollisionCylinder_2f2e70 {
    void* vptr;
    char pad[0x60];
    void Target();
};
class C_2f2eb0 {
  public:
    char pad[0x38];
};
class C_2f2ec0 {
  public:
    char pad[0x38];
};
struct V {
    int a, b, c;
};
class CollisionVolume {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual V* f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14(CollisionVolume*);
    char pad[0x40];
};
class Vec_2f2f60 {
  public:
    void normalize_0022d180();
    float x, y, z;
};
class CollisionCylinder : public CollisionVolume {
  public:
    virtual void vfunc14(CollisionCylinder*);
    char _m_pad_44[0xc];
    float x50;
    float x54;
    char _m_pad_58[0x18];
    Vec_2f2f60 v;
    float x7c;
    float x80;
    void base_00306560(float);
    void vfunc_7(float);
    void f() { f5(); }
    void j() { f9(); }
};
typedef unsigned int u32_2f2ff0;
struct Obj_2f2ff0 {
    virtual void a();
    virtual void b();
    virtual u32_2f2ff0 c();
    virtual void d();
    virtual u32_2f2ff0 e();
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
};
struct Helper_2f2ff0 {
};


// 0x002f2e70 FUN_002f2e70 (33 B): matches/0x002f2e70.cpp
// sym: ?Target@CollisionCylinder_2f2e70@fn_f419e76e@@QAEXXZ
void CollisionCylinder_2f2e70::Target() {
    vptr = (void*)((hulk_intptr)DAT_004313cc);
    ((Part_2f2e70*)((char*)this + 0x64))->Init_00306e00();
    ((Part_2f2e70*)((char*)this + 0x38))->Init_00306e00();
    ((CollisionCylinder_nv_2f2e70*)(((physics::CollisionCylinder*)(((physics::CollisionCylinder*)this)))))->Finish_00306ac0();
}

} // namespace fn_f419e76e

// 0x002f2ea0 physics::CollisionCylinder::vfunc_6 (6 B): matches/0x002f2ea0.cpp
// sym: ?vfunc_6@CollisionCylinder@physics@@UAEHXZ
// Same code shape as 0x0004e0b0 (propagated; names are from that function)
int physics::CollisionCylinder::vfunc_6() {
    return 2;
}

namespace fn_f419e76e {

// 0x002f2eb0 physics::CollisionCylinder::vfunc_4 (4 B): matches/0x002f2eb0.cpp
// sym: ?FUN_002f2eb0@fn_f419e76e@@YIPAVC_2f2eb0@1@PAV21@@Z
// Same code shape as 0x00092050 (propagated; names are from that function)
C_2f2eb0* __fastcall FUN_002f2eb0(C_2f2eb0* p) {
    return (C_2f2eb0*)((char*)p + 0x38);
}


// 0x002f2ec0 physics::CollisionCylinder::vfunc_3 (4 B): matches/0x002f2ec0.cpp
// sym: ?FUN_002f2ec0@fn_f419e76e@@YIPAVC_2f2ec0@1@PAV21@@Z
// Same code shape as 0x00092050 (propagated; names are from that function)
C_2f2ec0* __fastcall FUN_002f2ec0(C_2f2ec0* p) {
    return (C_2f2ec0*)((char*)p + 0x38);
}


// 0x002f2ed0 physics::CollisionCylinder::vfunc_14 (131 B): matches/0x002f2ed0.cpp
// sym: ?vfunc14@CollisionCylinder@fn_f419e76e@@UAEXPAV12@@Z
void CollisionCylinder::vfunc14(CollisionCylinder* p) {
    CollisionVolume::f14((CollisionVolume*)p);
    V* a = f4();
    V* b = p->f4();
    *b = *a;
    char* s = (char*)this;
    char* d = (char*)p;
    *(int*)(d + 0x44) = *(int*)(s + 0x44);
    *(int*)(d + 0x48) = *(int*)(s + 0x48);
    *(int*)(d + 0x4c) = *(int*)(s + 0x4c);
    *(int*)(d + 0x50) = *(int*)(s + 0x50);
    *(int*)(d + 0x54) = *(int*)(s + 0x54);
    d[0x58] = s[0x58];
    *(int*)(d + 0x70) = *(int*)(s + 0x70);
    *(int*)(d + 0x74) = *(int*)(s + 0x74);
    *(int*)(d + 0x78) = *(int*)(s + 0x78);
    *(int*)(d + 0x7c) = *(int*)(s + 0x7c);
    *(int*)(d + 0x80) = *(int*)(s + 0x80);
    *(int*)(d + 0x60) = *(int*)(s + 0x60);
}


// 0x002f2f60 physics::CollisionCylinder::vfunc_7 (91 B): matches/0x002f2f60.cpp
// sym: ?vfunc_7@CollisionCylinder@fn_f419e76e@@QAEXM@Z
// data: one = DAT_003f32dc
void CollisionCylinder::vfunc_7(float p) {
    x50 = p * x7c;
    x54 = p * x80;
    Vec_2f2f60* q = &v;
    q->normalize_0022d180();
    hulk_freg f = DAT_003f32dc / p;
    q->x = f * q->x;
    q->y = f * q->y;
    q->z = f * q->z;
    j();
    base_00306560(p);
}

} // namespace fn_f419e76e

// 0x002f2fc0 physics::CollisionCylinder::vfunc_13 (39 B): equivalent/0x002f2fc0.cpp [wrapped: conflict: physics::CollisionCylinder]
// sym: ?vfunc_13@CollisionCylinder@physics@fn_002f2fc0@@UAEXXZ @d1d158d4a7ea @w42949e13a7b8
namespace fn_002f2fc0 {
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 0/0)
// physics::CollisionCylinder::vfunc_13 @ 0x002f2fc0
namespace physics {
struct CallbackResult { void FUN_0022c3b0(void*, void*); };
struct Callback {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
 virtual CallbackResult* vfunc_4(hulk_intptr);   // (x64t6) the id (was void*: natively 8 bytes over the id and the next word)
};
struct Owner { char pad[HULK_CO_OWNER]; Callback* callback; };   // (x64t6) the CollisionObject's owner (decls/physics_world.h)
struct CollisionCylinder {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
 virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
 virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
 virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
 // (x64t6) the volume's words by decls/physics_world.h (HULK_CV): the id an int, the owner at 0x10, c19 at 0x19
 char pad04[HULK_CV(8) - sizeof(void*)]; int field08; char pad0c[HULK_CV(0x10) - HULK_CV(0xc)]; Owner* owner; char pad14[HULK_CV(0x19) - HULK_CV(0x14)]; unsigned char dirty; char pad1a[HULK_CV(0x44) - HULK_CV(0x1a)]; char position[0x2c]; char pad70[4];
};
void CollisionCylinder::vfunc_13() {
 dirty = 1;
 owner->callback->vfunc_4(field08)->FUN_0022c3b0(pad70, position);
}
}
} // namespace fn_002f2fc0


// 0x002f2ff0 physics::CollisionCylinder::vfunc_11 (48 B): matches/0x002f2ff0.cpp
// sym: ?vfunc_11@CollisionCylinder@physics@@UAEXPAX@Z
void physics::CollisionCylinder::vfunc_11(void* __p0) { void * p = (void *)__p0;

    Helper_2f2ff0* h = (Helper_2f2ff0*)p;
    ((owners::M_22c3b0 *)h)->FUN_0022c3b0((float *)(&this->f_44), (float *)(&this->f_44));
    hulk_uintptr a = vfunc_4();
    ((owners::Mat_22c2b0 *)h)->FUN_0022c2b0((float *)(hulk_uintptr)(hulk_uintptr)(vfunc_4()), (float *)(hulk_uintptr)(hulk_uintptr)a);
}


// 0x002f3020 physics::CollisionCylinder::vfunc_5 (3 B): matches/0x002f3020.cpp
// sym: ?vfunc_5@CollisionCylinder@physics@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void physics::CollisionCylinder::vfunc_5(int a, int b) {}


// 0x002f3030 physics::CollisionCylinder::vfunc_2 (54 B): matches/0x002f3030.cpp [wrapped: conflict: physics::CollisionCylinder]
// sym: ?vfunc_2@CollisionCylinder@physics@fn_002f3030@@QAEPAU123@E@Z
namespace fn_002f3030 {
typedef unsigned char u8_2f3030;
extern int hulk_at_004313cc;
struct Part_2f3030 {
    void init_00306e00();
};
namespace physics {
struct CollisionCylinder {
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
    char pad[0x64 - 4];
    CollisionCylinder* vfunc_2(u8_2f3030);
    void base_00306ac0();
};
} // namespace physics
void cleanup_0008d330(physics::CollisionCylinder*);
physics::CollisionCylinder* physics::CollisionCylinder::vfunc_2(u8_2f3030 flag) {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_004313cc;
    ((Part_2f3030*)((char*)this + 0x64))->init_00306e00();
    ((Part_2f3030*)((char*)this + 0x38))->init_00306e00();
    base_00306ac0();
    if (flag & 1)
        cleanup_0008d330(this);
    return this;
}
} // namespace fn_002f3030


// 0x002f3070 FUN_002f3070 (179 B): equivalent/0x002f3070.cpp [wrapped: conflict: physics::CollisionCylinder]
// sym: ??0CollisionCylinder@physics@fn_002f3070@@QAE@PAUVector3_2f3070@2@IIII@Z @521299292e19 @wc18a2c653e6f
namespace fn_002f3070 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002f3070 @ 0x002f3070

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif

struct Vector3_2f3070 { unsigned int x,y,z; };
struct ShapePart {
 char pad[24]; float radius; float height; unsigned char round; char tail[11];
 void FUN_00306e70();
 void FUN_00306e10(Vector3_2f3070*,unsigned int,unsigned int,unsigned int,unsigned int,int);
};
struct FUN_003060a0 {
 FUN_003060a0();
 virtual void slot0();
 char pad04[24]; Vector3_2f3070 position; char pad28[12]; float extent;
};
namespace physics {
struct CollisionCylinder : FUN_003060a0 {
 virtual void slot0();
 ShapePart first; ShapePart second;
 CollisionCylinder(Vector3_2f3070*,hulk_uintptr,unsigned int,unsigned int,unsigned int);
};
}
physics::CollisionCylinder::CollisionCylinder(Vector3_2f3070* p,hulk_uintptr a,unsigned int b,unsigned int c,unsigned int d) {
 first.FUN_00306e70(); second.FUN_00306e70();
 position.x=p->x; position.y=p->y; position.z=p->z;
 first.tail[7]=0; first.tail[8]=0; first.tail[9]=0; first.tail[10]=0;
 first.FUN_00306e10(p,a,b,c,d,0);
 second.FUN_00306e10(p,a,b,c,d,0);
 if(first.round) extent=(float)sqrt((double)first.radius*first.radius+(double)first.height*first.height);
 else extent=first.height+first.radius;
}
} // namespace fn_002f3070


// 0x002f3160 physics::CollisionCylinder::vfunc_8 (270 B): equivalent/0x002f3160.cpp
// sym: ?vfunc_8@CollisionCylinder@physics@@UAEXXZ @77372ebe9ba7 @wc94a37943e11
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// physics::CollisionCylinder::vfunc_8 @ 0x002f3160
void physics::CollisionCylinder::vfunc_8() {
 for (int i=0;i<3;++i) {
 union { float f; unsigned int u; } a;
 a.f=(*(float (*)[3])&this->f_44)[i]; a.u &= 0x7fffffff;
 if((*(unsigned char *)&this->f_58)) {
 double square=(double)a.f*a.f;
 (*(float (*)[3])&this->f_28)[i]=(float)(((1.0-0.5*square)+square*square*0.125)*this->f_54+(double)a.f*this->f_50);
 } else (*(float (*)[3])&this->f_28)[i]=(float)((double)a.f*this->f_50+this->f_54);
 }
}


// 0x002f3270 physics::CollisionCylinder::vfunc_9 (51 B): equivalent/0x002f3270.cpp [wrapped: conflict: physics::CollisionCylinder; physics::CollisionVolume]
// sym: ?vfunc_9@CollisionCylinder@physics@fn_002f3270@@QAEXXZ @53342f59eb3d @wde717e935bb5
namespace fn_002f3270 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// physics::CollisionCylinder::vfunc_9 @ 0x002f3270

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif

namespace physics {
struct CollisionVolume {
    char padding[0x34];
    float extent;
    void vfunc_9_00306450();
};
struct CollisionCylinder : CollisionVolume {
    char padding2[0x50 - 0x38];
    float radius;
    float halfHeight;
    unsigned char roundEnds;
    void vfunc_9();
};
void CollisionCylinder::vfunc_9() {
    if (roundEnds) {
        float r = radius;
        float h = halfHeight;
        extent = (float)sqrt(r*r + h*h);
    } else {
        extent = halfHeight + radius;
    }
    CollisionVolume::vfunc_9_00306450();
}
}
} // namespace fn_002f3270

