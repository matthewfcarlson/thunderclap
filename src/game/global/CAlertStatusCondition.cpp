// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004a2d0..0x0004a560 (kind game, layer game, confidence high), dominant class CAlertStatusCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4b9a9e9 {
#define TREE_TU_END }
namespace fn_f4b9a9e9 {} using namespace fn_f4b9a9e9;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f4b9a9e9 {
struct Obj_4a2d0 {
    char pad[0x330];
    int a;
    int b;
    int c;
};
struct Helper_4a2d0 {
};
struct ObjHelper_4a2d0 {
    Obj_4a2d0* Second();
};
extern int* gTable_4a330;
class CCondition_4a330 {
  public:
    virtual int vfunc_0(int);
};
struct Fighter_4a380 {
    char pad0[0x144];
    unsigned int hits;
};
struct Anchor_4a380 {
    Fighter_4a380 *FUN_00059a30();
};
struct FightHandle_4a380 {
};
extern int* gTable_4a420;
class CCondition_4a420 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_4a490;
class CCondition_4a490 {
  public:
    virtual int vfunc_0(int);
};
class CAlertStatusCondition_4a4a0 {
  public:
    hulk_intptr vptr;
    int pad4;
    int pad8;
    int mC;
    int m10;
};
struct CAlertStatusCondition_nv_4a4a0 {
    void Init(int);
};
class CCondition_4a4e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(void*);
};
struct H {
    void second();
};

} // namespace fn_f4b9a9e9

// 0x0004a2d0 CGrappleMotionStateCondition::vfunc_8 (56 B): matches/0x0004a2d0.cpp
// sym: ?vfunc_8@CGrappleMotionStateCondition@@UAEHH@Z
int CGrappleMotionStateCondition::vfunc_8(hulk_intptr p) {
    if (!p)
        return 0;
    Helper_4a2d0* h = (Helper_4a2d0*)p;
    Obj_4a2d0* x = ((Obj_4a2d0 *)((owners::Object_592a0 *)h)->FUN_000592a0());
    x = ((ObjHelper_4a2d0*)x)->Second();
    if (x->b)
        return x->b;
    if (x->a)
        return x->a;
    return x->c;
}

namespace fn_f4b9a9e9 {

// 0x0004a310 FUN_0004a310 (19 B): matches/0x0004a310.cpp
// sym: ?FUN_0004a310@fn_f4b9a9e9@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0004a310() {
    FUN_00234810(((char*)&DAT_004dc528), ((char*)&DAT_004dc52c));
}

} // namespace fn_f4b9a9e9

// 0x0004a330 CMotionHitCondition::vfunc_0 (16 B): matches/0x0004a330.cpp
// sym: ?vfunc_0@CMotionHitCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CMotionHitCondition::vfunc_0(int index) {
    int* p = gTable_4a330;
    return p[index];
}


// 0x0004a380 CMotionHitCondition::vfunc_7 (117 B): equivalent/0x0004a380.cpp
// sym: ?vfunc_7@CMotionHitCondition@@UAE_NPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CMotionHitCondition::vfunc_7 @ 0x0004a380
bool CMotionHitCondition::vfunc_7(void* __p0) { FightHandle_4a380 * h = (FightHandle_4a380 *)__p0;

    Fighter_4a380 *f = ((Anchor_4a380 *)((owners::Object_592a0 *)h)->FUN_000592a0())->FUN_00059a30();
    unsigned int mask = 0;
    if ((*(unsigned int *)&this->motionHit) != 0)
        mask = 1u << ((*(unsigned int *)&this->motionHit) - 1);
    unsigned int hits = f->hits;
    if (mask == 0) {
        if (this->compare == 0)
            return hits == 0;
        if (this->compare == 1)
            return hits != 0;
        return false;
    }
    if (this->compare == 0)
        return (hits & mask) != 0;
    if (this->compare == 1)
        return (hits & mask) == 0;
    return false;
}

namespace fn_f4b9a9e9 {

// 0x0004a400 FUN_0004a400 (19 B): matches/0x0004a400.cpp
// sym: ?FUN_0004a400@fn_f4b9a9e9@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0004a400() {
    FUN_00234810(((char*)&DAT_004dc530), ((char*)&DAT_004dc534));
}

} // namespace fn_f4b9a9e9

// 0x0004a420 CClimbableCondition::vfunc_0 (16 B): matches/0x0004a420.cpp
// sym: ?vfunc_0@CClimbableCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CClimbableCondition::vfunc_0(int index) {
    int* p = gTable_4a420;
    return p[index];
}

namespace fn_f4b9a9e9 {

// 0x0004a470 FUN_0004a470 (19 B): matches/0x0004a470.cpp
// sym: ?FUN_0004a470@fn_f4b9a9e9@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0004a470() {
    FUN_00234810(((char*)&DAT_004dc538), ((char*)&DAT_004dc53c));
}

} // namespace fn_f4b9a9e9

// 0x0004a490 CAlertStatusCondition::vfunc_0 (16 B): matches/0x0004a490.cpp
// sym: ?vfunc_0@CAlertStatusCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CAlertStatusCondition::vfunc_0(int index) {
    int* p = gTable_4a490;
    return p[index];
}

namespace fn_f4b9a9e9 {

// 0x0004a4a0 FUN_0004a4a0 (34 B): matches/0x0004a4a0.cpp
// sym: ?FUN_0004a4a0@fn_f4b9a9e9@@YIPAVCAlertStatusCondition_4a4a0@1@PAV21@PAX@Z
CAlertStatusCondition_4a4a0* __fastcall FUN_0004a4a0(CAlertStatusCondition_4a4a0* self, void*) {
    ((CAlertStatusCondition_nv_4a4a0*)(((CAlertStatusCondition*)(self))))->Init(0);
    self->vptr = ((hulk_intptr)DAT_003f7404);
    self->mC = 0;
    self->m10 = 0;
    return self;
}

} // namespace fn_f4b9a9e9

// 0x0004a4e0 CAlertStatusCondition::vfunc_8 (19 B): matches/0x0004a4e0.cpp
// sym: ?vfunc_8@CAlertStatusCondition@@UAEXPAX@Z
// Same code shape as 0x0004a260 (propagated; names are from that function)
void CAlertStatusCondition::vfunc_8(void* __p0) { void * p = (void *)__p0;

    ((H *)((owners::Object_592a0 *)(((H*)p)))->FUN_000592a0())->second();
}


// 0x0004a500 CAlertStatusCondition::vfunc_7 (83 B): matches/0x0004a500.cpp [wrapped: conflict: CAlertStatusCondition]
// sym: ?v7@CAlertStatusCondition@fn_0004a500@@UAE_NPAX@Z
namespace fn_0004a500 {
struct Status_4a500 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual int get();
};
struct Entity {
    char pad[0x1ca0];
    Status_4a500* status;
};
class CAlertStatusCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual bool v7(void*);
    virtual Entity* v8(void*);
    int pad[2];
    int mode;
    int value;
};
bool CAlertStatusCondition::v7(void* arg) {
    Entity* obj = v8(arg);
    if (obj == 0)
        return false;
    if (obj->status == 0)
        return false;
    int x = obj->status->get();
    switch (mode) {
    case 0:
        return x == value;
    case 1:
        return x != value;
    }
    return false;
}
} // namespace fn_0004a500

