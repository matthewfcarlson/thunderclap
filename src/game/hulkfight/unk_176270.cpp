// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00176270..0x001765f0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fb68229a {
#define TREE_TU_END }
namespace fn_fb68229a {} using namespace fn_fb68229a;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_fb68229a {
class RefObj_176270 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_176270 {
  public:
    Action_176270();
    virtual void Update_00018b30();
    char pad[0x18];
};
class TargetIconDistanceAction_176270 : public Action_176270 {
  public:
    int mTarget;
    RefObj_176270* mObj;
    TargetIconDistanceAction_176270(int target, RefObj_176270* obj);
    virtual void Execute_00018b40();
};
class Obj_1762c0 {
  public:
    virtual void F0();
    virtual void F1();
};
class Action_1762c0 {
  public:
};
class TargetIconDistanceAction : public Action_1762c0 {
  public:
    hulk_intptr vptr;
    char pad04[0x18];
    Obj_1762c0* m1c;
    Obj_1762c0* m20;
    void Clean();
};
extern int hulk_at_00417f9c;
class Ref_176300 {
  public:
    virtual void A();
    virtual void B();
};
class Action_176300 {
  public:
    Action_176300();
    virtual void V0_00018b30();
    char pad[0x18];
};
class MoveJointAction_176300 : public Action_176300 {
  public:
    int f1c;
    Ref_176300* f20;
    int f24, f28, f2c, f30, f34;
    int f38, f3c, f40, f44, f48, f4c;
    char f50;
    char p[3];
    int f54;
    MoveJointAction_176300(int, Ref_176300*);
    virtual void V1_00018b40();
};
extern void* hulk_at_00417fb8[];
class Ref_176370 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_176370 {
  public:
    void* vptr;
};
void Free(void*);
struct Sub_176370 {
    char c;
};
void __fastcall SubFini(Sub_176370*);
void __fastcall SubFini2(Sub_176370*);
class MoveJointAction_176370 : public Action_176370 {
  public:
    char p1c[24];
    void* m1c;
    Ref_176370* m20;
    Ref_176370* m24;
    Ref_176370* m28;
    ~MoveJointAction_176370();
};
struct Vec_1763c0 { unsigned x,y,z; };
struct Matrix { char data[64]; void FUN_0022c2b0(Vec_1763c0*,Vec_1763c0*); };
struct Skeleton { unsigned FUN_0027b200(unsigned,unsigned); };
struct Pose { char pad[8]; Skeleton* skeleton; char pad2[16]; Matrix* matrices; };
struct Actor_1763c0 { char pad[0x120]; Pose* pose; void FUN_000373e0(int); };
struct Intermediate_1763c0 { Actor_1763c0* FUN_00059a30(); };
struct Owner_1763c0 { Intermediate_1763c0* FUN_000592a0(); };
struct Ref_1763c0 { virtual void vfunc_0(); virtual void vfunc_1(); };
extern "C" Ref_1763c0* __cdecl FUN_001817d0(Actor_1763c0*,unsigned);
struct Settings_1763c0 { char pad[0x14]; unsigned selector; unsigned name1a,name1b,name2a,name2b; Vec_1763c0 position; char pad2[0x14]; unsigned value; };
} // namespace fn_fb68229a
namespace hulkfight { namespace motion {
struct MoveJointAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(unsigned,unsigned); virtual void vfunc_4(); virtual void vfunc_5();
 char pad[0x18]; Settings_1763c0* settings; Owner_1763c0* owner; Ref_1763c0* reference; char pad2[4]; Vec_1763c0 position; unsigned joint1,joint2; char pad3[0x10]; unsigned char active; char pad4[3]; unsigned value;
};
} }
namespace fn_fb68229a {
class Ref_1764d0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1764d0 {
  public:
    virtual void FnV_00018b30();
    Action_1764d0();
};
class TargetBreakAction_1764d0 : public Action_1764d0 {
  public:
    virtual void V2_00018b40();
    char pad[0x18];
    Ref_1764d0* mRef;
    TargetBreakAction_1764d0(Ref_1764d0*);
};
extern "C" char DAT_00417fd4[];
class Ref_176510 {
  public:
    virtual void A();
    virtual void B();
};
class Action_176510 {
  public:
};
class TargetBreakAction : public Action_176510 {
  public:
    void Finish();
    char* vptr;
    char pad[0x18];
    Ref_176510* ref;
};
class Ref_176540 {
  public:
    virtual void A();
    virtual void B();
};
class Action_176540 {
  public:
    Action_176540();
    virtual void V0();
    char pad[0x18];
};
class SurfAction_176540 : public Action_176540 {
  public:
    int a;
    Ref_176540* b;
    int c[6];
    float f;
    int d;
    SurfAction_176540(int, Ref_176540*);
    virtual void V0();
};
extern void* hulk_at_00417ff0[];
class Ref_1765a0 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Helper_1765a0 {
  public:
};
class SurfAction_1765a0 {
  public:
    void* vptr;
    char p[0x18];
    int m1c;
    Ref_1765a0* m20;
    Ref_1765a0* m24;
    void f();
};


// 0x00176270 FUN_00176270 (72 B): matches/0x00176270.cpp
// sym: ??0TargetIconDistanceAction_176270@fn_fb68229a@@QAE@HPAVRefObj_176270@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
TargetIconDistanceAction_176270::TargetIconDistanceAction_176270(int target, RefObj_176270* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x001762c0 FUN_001762c0 (50 B): matches/0x001762c0.cpp
// sym: ?Clean@TargetIconDistanceAction@fn_fb68229a@@QAEXXZ
void TargetIconDistanceAction::Clean() {
    vptr = (hulk_intptr)&hulk_at_00417f9c;
    _ReadWriteBarrier();
    Obj_1762c0* p = m20;
    if (p) {
        p->F1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1762c0 *)this)->FUN_002326a0();
}


// 0x00176300 FUN_00176300 (108 B): matches/0x00176300.cpp
// sym: ??0MoveJointAction_176300@fn_fb68229a@@QAE@HPAVRef_176300@1@@Z
MoveJointAction_176300::MoveJointAction_176300(int p, Ref_176300* r) {
    int* q = &f1c;
    *q = 0;
    f20 = 0;
    f24 = 0;
    f28 = 0;
    f38 = 0;
    f3c = 0;
    f40 = 0;
    f50 = 1;
    f54 = 0;
    f1c = p;
    if (r)
        r->A();
    {
        Ref_176300* o = f20;
        if (o)
            o->B();
    }
    Ref_176300** w = &f20;
    *w = r;
    f34 = 0;
    f30 = 0;
    f2c = 0;
    f4c = 0;
    f48 = 0;
    f44 = 0;
}


// 0x00176370 FUN_00176370 (74 B): matches/0x00176370.cpp
// sym: ??1MoveJointAction_176370@fn_fb68229a@@QAE@XZ
MoveJointAction_176370::~MoveJointAction_176370() {
    vptr = hulk_at_00417fb8;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_176370 *)this)->FUN_002326a0();
}

} // namespace fn_fb68229a

// 0x001763c0 hulkfight::motion::MoveJointAction::vfunc_3 (258 B): equivalent/0x001763c0.cpp
// sym: ?vfunc_3@MoveJointAction@motion@hulkfight@@UAE_NII@Z @b3391a34b77a @wf3929c9bc2f2
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::motion::MoveJointAction::vfunc_3 @ 0x001763c0
namespace hulkfight { namespace motion {
bool MoveJointAction::vfunc_3(unsigned,unsigned) {
 Actor_1763c0* actor=owner->FUN_000592a0()->FUN_00059a30();
 Pose* pose=actor->pose;
 Skeleton* skeleton=pose->skeleton;
 unsigned a=settings->name1a,b=settings->name1b;
 if(a|b) { joint1=skeleton->FUN_0027b200(a,b); if(joint1==0xffff) joint1=0; }
 a=settings->name2a; b=settings->name2b;
 if(a|b) { joint2=skeleton->FUN_0027b200(a,b); if(joint2==0xffff) joint2=0; }
 Settings_1763c0* config=settings;
 active=1; value=config->value;
 unsigned index=joint2;
 Matrix* matrices=pose->matrices;
 unsigned x=config->position.x,y=config->position.y,z=config->position.z;
 position.x=x; position.y=y; position.z=z;
 matrices[index].FUN_0022c2b0(&position,&position);
 Ref_1763c0* next=FUN_001817d0(actor,settings->selector);
 if(next) next->vfunc_0();
 if(reference) reference->vfunc_1();
 reference=next;
 actor->FUN_000373e0(0);
 return true;
}
} }

namespace fn_fb68229a {

// 0x001764d0 FUN_001764d0 (58 B): matches/0x001764d0.cpp
// sym: ??0TargetBreakAction_1764d0@fn_fb68229a@@QAE@PAVRef_1764d0@1@@Z
// Same code shape as 0x00018af0 (propagated; names are from that function)
TargetBreakAction_1764d0::TargetBreakAction_1764d0(Ref_1764d0* arg) : Action_1764d0() {
    mRef = 0;
    if (arg)
        arg->AddRef();
    if (mRef)
        mRef->Release();
    mRef = arg;
}


// 0x00176510 FUN_00176510 (36 B): matches/0x00176510.cpp
// sym: ?Finish@TargetBreakAction@fn_fb68229a@@QAEXXZ
void TargetBreakAction::Finish() {
    vptr = (char*)((hulk_intptr)DAT_00417fd4);
    _ReadWriteBarrier();
    if (ref) {
        ref->B();
        ref = 0;
    }
    ((fight::Action *)(Action_176510 *)this)->FUN_002326a0();
}


// 0x00176540 FUN_00176540 (96 B): matches/0x00176540.cpp
// sym: ??0SurfAction_176540@fn_fb68229a@@QAE@HPAVRef_176540@1@@Z
SurfAction_176540::SurfAction_176540(int x, Ref_176540* r) : Action_176540() {
    int* q = &a;
    *q = 0;
    b = 0;
    c[0] = 0;
    c[1] = 0;
    c[2] = 0;
    c[3] = 0;
    c[4] = 0;
    c[5] = 0;
    f = 1.0f;
    d = 0;
    a = x;
    if (r)
        r->A();
    if (b)
        b->B();
    b = r;
}


// 0x001765a0 FUN_001765a0 (69 B): matches/0x001765a0.cpp
// sym: ?f@SurfAction_1765a0@fn_fb68229a@@QAEXXZ
void SurfAction_1765a0::f() {
    vptr = hulk_at_00417ff0;
    _ReadWriteBarrier();
    if (m24) {
        m24->f1();
        m24 = 0;
    }
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(((Helper_1765a0*)this)))->FUN_002326a0();
}

} // namespace fn_fb68229a
