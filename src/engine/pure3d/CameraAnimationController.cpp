// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00292eb0..0x00293b20 (kind game, layer engine, confidence high), dominant class pure3d::CameraAnimationController
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fa983489 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fa983489 {} using namespace fn_fa983489;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fa983489 {
extern "C" char DAT_0042cf7c[];
struct CameraAnimationController {
    unsigned int pad[0x44];
};
extern void __fastcall BaseInit(CameraAnimationController*, void*);
class X_292f20 {
    char pad[0x114];

  public:
    int value;
};
struct Vec3_292f60 {
    float x, y, z;
};
struct Frame_292f60 {
    Vec3_292f60 a;
    Vec3_292f60 b;
};
class Sampler_292f60 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(float coord, float *out);
};
extern void* g_vftable_0042cf7c[];
class Ref_2930d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class BlendFrameController_2930d0 {
  public:
    void* vptr;
    void Fin();
};
class CameraAnimationController_2930d0 : public BlendFrameController_2930d0 {
  public:
    char pad[272];
    Ref_2930d0* m;
    ~CameraAnimationController_2930d0();
};
class Base_293100 {
  public:
    virtual void AddRef();
    virtual void Release();
};
struct TypeInfo_293100 {};
extern TypeInfo_293100 tiSrc;
extern TypeInfo_293100 tiA;
extern TypeInfo_293100 tiB;
class CameraAnimationController_293100 {
  public:
    char pad[0x110];
    int mType;
    Base_293100* mObj;
    void Set(Base_293100* p);
};
extern void* g_vt_293890[];
} // namespace fn_fa983489
void operator delete(void*);
namespace fn_fa983489 {
class Ref_293890 {
  public:
    virtual void F0();
    virtual void Release();
};
class BlendFrameController_293890 {
  public:
    void* vptr;
    void Fin();
};
class CameraAnimationController_293890 : public BlendFrameController_293890 {
  public:
    char pad[276 - 4];
    Ref_293890* m;
    CameraAnimationController_293890* f2(unsigned char flags);
};
typedef unsigned int U_293970;
extern U_293970 __cdecl Query(hulk_uintptr, U_293970, const void*, const void*, U_293970);
extern char EntityRTTI_293970;
struct CameraAnimationController_nv_293970 {
    void Finish(U_293970);
};
struct Triple_293ac0 {
    int a, b, c;
};
struct Object {
    char pad[0xcc];
    unsigned char flag;
    char pad2[0xe8 - 0xcd];
    int x, y, z;
    void Set(Triple_293ac0* p);
};


// 0x00292eb0 FUN_00292eb0 (38 B): matches/0x00292eb0.cpp
// sym: ?FUN_00292eb0@fn_fa983489@@YIPAUCameraAnimationController@1@PAU21@PAX@Z
CameraAnimationController* __fastcall FUN_00292eb0(CameraAnimationController* self, void* edx) {
    BaseInit(self, edx);
    self->pad[0] = ((hulk_intptr)DAT_0042cf7c);
    self->pad[0x44] = 0xffffffff;
    self->pad[0x45] = 0;
    return self;
}

} // namespace fn_fa983489

// 0x00292ee0 pure3d::CameraAnimationController::vfunc_3 (3 B): matches/0x00292ee0.cpp
// sym: ?vfunc_3@CameraAnimationController@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::CameraAnimationController::vfunc_3() {
    return true;
}


// 0x00292ef0 pure3d::CameraAnimationController::vfunc_26 (39 B): matches/0x00292ef0.cpp
// sym: ?vfunc_26@CameraAnimationController@pure3d@@UAE_NPAX@Z
bool pure3d::CameraAnimationController::vfunc_26(void* __p0) { void * p = (void *)__p0;

    if (p != 0) {
        if (*(int*)((char*)p + 0x28) > 0) {
            return *(int*)((char*)p + 0x1c) == ((int)0x4d4143);
        }
    }
    return false;
}

namespace fn_fa983489 {

// 0x00292f20 FUN_00292f20 (7 B): matches/0x00292f20.cpp
// sym: ?target@fn_fa983489@@YIHPAVX_292f20@1@@Z
hulk_intptr __fastcall target(X_292f20* self) {
    return self->value;
}


// 0x00292f60 FUN_00292f60 (354 B): equivalent/0x00292f60.cpp
// sym: _FUN_00292f60
// STATUS: equivalent (tools/equiv.py level 3: 19525 inputs, branch coverage 22/22)
// FUN_00292f60 @ 0x00292f60
// Snap *p to its floor when the two samplers disagree enough; sampler a arrives in esi, b in edi.
// equiv-conv: FUN_00292f60 esi edi stack
extern "C" void FUN_00292f60(void *a, void *b, float *p)
{
    Frame_292f60 f;
    hulk_freg lo = (float)floor((double)*p);
    hulk_freg hi = (float)floor((double)(*p + 1.0f));
    bool bad = false;
    hulk_freg dist = 0.0f;
    hulk_freg dot = 0.0f;

    if (((Sampler_292f60 *)a)) {
        ((Sampler_292f60 *)a)->v4(lo, &f.a.x);
        ((Sampler_292f60 *)a)->v4(hi, &f.b.x);
        f.a.x = f.a.x - f.b.x;
        f.a.y = f.a.y - f.b.y;
        f.a.z = f.a.z - f.b.z;
        dist = (float)sqrt((double)(f.a.z * f.a.z + f.a.y * f.a.y + f.a.x * f.a.x));
        if (dist > 4.0f)
            bad = true;
    }

    if (((Sampler_292f60 *)b) && !bad) {
        ((Sampler_292f60 *)b)->v4(lo, &f.a.x);
        ((Sampler_292f60 *)b)->v4(hi, &f.b.x);
        dot = f.b.z * f.a.z + f.b.y * f.a.y + f.b.x * f.a.x;
        if (dot < 0.0f)
            bad = true;
    }

    if (((Sampler_292f60 *)a) && ((Sampler_292f60 *)b) && !bad) {
        if (dist > 1.0f && dot < 0.866f)
            *p = lo;
    } else if (bad) {
        *p = lo;
    }
}


// 0x002930d0 FUN_002930d0 (42 B): matches/0x002930d0.cpp
// sym: ??1CameraAnimationController_2930d0@fn_fa983489@@QAE@XZ
CameraAnimationController_2930d0::~CameraAnimationController_2930d0() {
    vptr = g_vftable_0042cf7c;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}


// 0x00293100 FUN_00293100 (189 B): matches/0x00293100.cpp
// sym: ?Set@CameraAnimationController_293100@fn_fa983489@@QAEXPAVBase_293100@2@@Z
void CameraAnimationController_293100::Set(Base_293100* p) {
    if (mObj) {
        mObj->Release();
        mObj = 0;
    }
    mType = -1;
    if (!p)
        return;
    if (DynCast(p, 0, &tiSrc, &tiA, 0)) {
        p->AddRef();
        if (mObj)
            mObj->Release();
        mObj = p;
        int* q = &mType;
        *q = 0;
        return;
    }
    if (DynCast(p, 0, &tiSrc, &tiB, 0)) {
        p->AddRef();
        if (mObj)
            mObj->Release();
        mObj = p;
        int* q = &mType;
        *q = 1;
    }
}


// 0x00293890 pure3d::CameraAnimationController::vfunc_2 (63 B): matches/0x00293890.cpp
// sym: ?f2@CameraAnimationController_293890@fn_fa983489@@QAEPAV12@E@Z
CameraAnimationController_293890* CameraAnimationController_293890::f2(unsigned char flags) {
    vptr = g_vt_293890;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_fa983489

// 0x00293910 pure3d::CameraAnimationController::vfunc_4 (81 B): matches/0x00293910.cpp [wrapped: conflict: CameraAnimationController]
// sym: ?f4@CameraAnimationController@fn_00293910@@UAEPAU12@XZ
namespace fn_00293910 {
typedef unsigned int u32_293910;
struct CameraAnimationController {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual CameraAnimationController* f4();
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
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    char pad[0x10c];
    u32_293910 field110;
    u32_293910 field114;
    void init(CameraAnimationController*);
    void finish(u32_293910);
};
extern "C++" __declspec(nothrow) void* __cdecl alloc(hulk_uintptr);
extern u32_293910 camera_vtable_293910;
CameraAnimationController* CameraAnimationController::f4() {
    CameraAnimationController* p = (CameraAnimationController*)alloc(0x118);
    if (p) {
        p->init(this);
        *(hulk_uintptr*)p = (hulk_uintptr)&camera_vtable_293910;
        p->field110 = 0xffffffff;
        p->field114 = 0;
        p->finish(field114);
        return p;
    }
    return 0;
}
} // namespace fn_00293910


// 0x00293970 pure3d::CameraAnimationController::vfunc_5 (42 B): matches/0x00293970.cpp
// sym: ?vfunc_5@CameraAnimationController@pure3d@@UAEXPAX@Z
void pure3d::CameraAnimationController::vfunc_5(void* __p0) { hulk_uintptr arg = (hulk_uintptr)__p0;

    U_293970 x = Query(arg, 0, &EntityRTTI_293970, &CameraRTTI, 0);
    ((CameraAnimationController_nv_293970*)this)->Finish(x);
}


// 0x002939a0 FUN_002939a0 (79 B): equivalent/0x002939a0.cpp [wrapped: conflict: pure3d::VectorCamera]
// sym: ??0VectorCamera@pure3d@fn_002939a0@@QAE@XZ
namespace fn_002939a0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_002939a0 @ 0x002939a0
class __declspec(novtable) Camera_2939a0 {
  public:
    virtual void slot0();
    char pad[0xd0 - 4];
    void FUN_00292d70();
    Camera_2939a0() { FUN_00292d70(); }
};
namespace pure3d {
class VectorCamera : public Camera_2939a0 {
  public:
    VectorCamera();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    int f_d0, f_d4, f_d8, f_dc, f_e0;
    float f_e4;
    int f_e8;
    float f_ec;
    int f_f0;
};
}
pure3d::VectorCamera::VectorCamera() {
    f_d0 = 0;
    f_d4 = 0;
    f_d8 = 0;
    f_dc = 0;
    f_e0 = 0;
    f_e4 = 1.0f;
    f_e8 = 0;
    f_f0 = 0;
    f_ec = 1.0f;
}
} // namespace fn_002939a0


// 0x00293a90 FUN_00293a90 (40 B): matches/0x00293a90.cpp
// sym: ?FUN_00293a90@C_293a90@owners@@QAEXPAH@Z
void owners::C_293a90::FUN_00293a90(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    flag = 0;
}

namespace fn_fa983489 {

// 0x00293ac0 FUN_00293ac0 (40 B): matches/0x00293ac0.cpp
// sym: ?Set@Object@fn_fa983489@@QAEXPAUTriple_293ac0@2@@Z
void Object::Set(Triple_293ac0* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    flag = 0;
}

} // namespace fn_fa983489

// 0x00293af0 FUN_00293af0 (40 B): matches/0x00293af0.cpp
// sym: ?FUN_00293af0@C_293af0@owners@@QAEXPAH@Z
void owners::C_293af0::FUN_00293af0(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    flag = 0;
}

