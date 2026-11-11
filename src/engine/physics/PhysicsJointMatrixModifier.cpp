// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002fbf20..0x002fc420 (kind game, layer engine, confidence high), dominant class physics::PhysicsJointMatrixModifier
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f55081c6 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f55081c6 {} using namespace fn_f55081c6;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f55081c6 {
extern "C" char DAT_00431840[];
class PoseDriver_2fc0d0 {
  public:
    char pad[0x18];
    PoseDriver_2fc0d0();
};
class PhysicsJointMatrixModifier : public PoseDriver_2fc0d0 {
  public:
    void* member;
    PhysicsJointMatrixModifier(void*);
};
struct Small_2fc130 {
    unsigned int x[0x10];
};
struct Big_2fc130 {
    unsigned int x[0x15];
    Small_2fc130* f100();
    void f120(Small_2fc130*);
};
struct Joint2 {
    char pad[8];
    void* item;
    void b980(Small_2fc130*);
};
struct Obj_2fc130 {
    Big_2fc130* edf0();
    void ee40(Big_2fc130*);
};
struct Arg_2fc130 {
    Obj_2fc130* f490(void*);
};
extern "C" char DAT_0043186c[];
class RootMatrixDriver {
  public:
    hulk_intptr vf;
    char pad[0x14];
    int value;
    RootMatrixDriver(int);
};
class PhysicsJointMatrixModifier_2fc1d0 {
  public:
    void Init();
};
class Item_2fc320 {
  public:
    virtual void Add();
    virtual void Release();
};
class Holder_2fc320 {
  public:
    Item_2fc320* mItem;
    Item_2fc320* Set(Item_2fc320* item);
};
class Ref_2fc350 {
  public:
    virtual void F();
};
class Owner_2fc350 {
  public:
    Ref_2fc350* mRef;
    Owner_2fc350* Set(Ref_2fc350* r);
};
class Item_2fc3a0 {
  public:
    virtual void Add();
    virtual void Release();
};
class Holder_2fc3a0 {
  public:
    Item_2fc3a0* mItem;
    Item_2fc3a0* Set(Item_2fc3a0* item);
};

} // namespace fn_f55081c6

// 0x002fbf20 FUN_002fbf20 (431 B): equivalent/0x002fbf20.cpp
// sym: ?FUN_002fbf20@AxisRemap_2fbf20@owners@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 24/24)
// FUN_002fbf20 @ 0x002fbf20
void owners::AxisRemap_2fbf20::FUN_002fbf20()
{
    int pickA = 0;
    int pickB = 0;

    if (fabs(m[0][0]) > DAT_004d2fb8) {
        pickA = 1;
    } else if (fabs(m[1][0]) > DAT_004d2fb8) {
        pickB = 1;
    } else if (!(fabs(m[2][0]) > DAT_004d2fb8)) {
        return;
    }

    if (fabs(m[0][1]) > DAT_004d2fb8) {
        pickA = 2;
    } else if (fabs(m[1][1]) > DAT_004d2fb8) {
        pickB = 2;
    } else if (!(fabs(m[2][1]) > DAT_004d2fb8)) {
        return;
    }

    if (fabs(m[0][2]) > DAT_004d2fb8) {
        pickA = 3;
    } else if (fabs(m[1][2]) > DAT_004d2fb8) {
        pickB = 3;
    } else if (!(fabs(m[2][2]) > DAT_004d2fb8)) {
        return;
    }

    snapped = 1;
    if (pickA != 1) {
        float t = scale[0];
        if (pickB == 1) {
            scale[0] = scale[1];
            scale[1] = t;
            pickB = pickA;
        } else {
            scale[0] = scale[2];
            scale[2] = t;
        }
    }
    if (pickB != 2) {
        float t = scale[2];
        scale[2] = scale[1];
        scale[1] = t;
    }
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[0][0] = 1.0f;
    m[1][0] = 0.0f;
    m[1][1] = 1.0f;
    m[1][2] = 0.0f;
    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = 1.0f;
}

namespace fn_f55081c6 {

// 0x002fc0d0 FUN_002fc0d0 (27 B): matches/0x002fc0d0.cpp
// sym: ??0PhysicsJointMatrixModifier@fn_f55081c6@@QAE@PAX@Z
PhysicsJointMatrixModifier::PhysicsJointMatrixModifier(void* arg) {
    member = arg;
    *(void**)this = (void*)((hulk_intptr)DAT_00431840);
}

} // namespace fn_f55081c6

// 0x002fc0f0 physics::PoseDriver::vfunc_7 (10 B): matches/0x002fc0f0.cpp
// sym: ?vfunc_7@PoseDriver@physics@@UAEXE@Z
// Same code shape as 0x00284ad0 (propagated; names are from that function)
void physics::PoseDriver::vfunc_7(unsigned char x) {
    this->f_10 = x;
}


// 0x002fc100 physics::PhysicsJointMatrixModifier::vfunc_5 (7 B): matches/0x002fc100.cpp
// sym: ?vfunc_5@PhysicsJointMatrixModifier@physics@@UAEHXZ
int physics::PhysicsJointMatrixModifier::vfunc_5() {
    return *(int*)((char*)(*(void * *)&this->f_18) + 8);
}


// 0x002fc110 physics::PhysicsJointMatrixModifier::vfunc_6 (6 B): matches/0x002fc110.cpp
// sym: ?vfunc_6@PhysicsJointMatrixModifier@physics@@UAEHXZ
// Same code shape as 0x00050230 (propagated; names are from that function)
int physics::PhysicsJointMatrixModifier::vfunc_6() {
    return 10;
}


// 0x002fc120 physics::PhysicsJointMatrixModifier::vfunc_8 (3 B): matches/0x002fc120.cpp
// sym: ?vfunc_8@PhysicsJointMatrixModifier@physics@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void physics::PhysicsJointMatrixModifier::vfunc_8(int a) {
    (void)a;
}


// 0x002fc130 physics::PhysicsJointMatrixModifier::vfunc_9 (134 B): matches/0x002fc130.cpp
// sym: ?vfunc_9@PhysicsJointMatrixModifier@physics@@UAEXH@Z
void physics::PhysicsJointMatrixModifier::vfunc_9(hulk_intptr __p0) { Arg_2fc130 * arg = (Arg_2fc130 *)__p0;

    if (!this->f_10)
        return;
    void* it = (*(Joint2 * *)&this->f_18)->item;
    Obj_2fc130* obj = arg->f490(it);
    Big_2fc130* bp = obj->edf0();
    Big_2fc130 big = *bp;
    Small_2fc130* sp = big.f100();
    Small_2fc130 small = *sp;
    (*(Joint2 * *)&this->f_18)->b980(&small);
    big.f120(&small);
    obj->ee40(&big);
}

namespace fn_f55081c6 {

// 0x002fc1d0 FUN_002fc1d0 (27 B): matches/0x002fc1d0.cpp
// sym: ??0RootMatrixDriver@fn_f55081c6@@QAE@H@Z
RootMatrixDriver::RootMatrixDriver(int x) {
    ((PhysicsJointMatrixModifier_2fc1d0*)this)->Init();
    value = x;
    vf = ((hulk_intptr)DAT_0043186c);
}


// 0x002fc1f0 physics::RootMatrixDriver::vfunc_5 (3 B): matches/0x002fc1f0.cpp
// sym: ?GetZero@fn_f55081c6@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_f55081c6

// 0x002fc200 physics::RootMatrixDriver::vfunc_6 (3 B): matches/0x002fc200.cpp [wrapped: same definition as 0x002fc1f0 in this TU]
// sym: ?GetZero@fn_002fc200@@YAIXZ
namespace fn_002fc200 {
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}
} // namespace fn_002fc200


// 0x002fc210 physics::RootMatrixDriver::vfunc_8 (3 B): matches/0x002fc210.cpp
// sym: ?vfunc_8@RootMatrixDriver@physics@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void physics::RootMatrixDriver::vfunc_8(int a) {
    (void)a;
}


// 0x002fc220 physics::RootMatrixDriver::vfunc_9 (113 B): matches/0x002fc220.cpp [wrapped: conflict: RootMatrixDriver]
// sym: ?vfunc_9@RootMatrixDriver@fn_002fc220@@UAEXPAUSkeleton@2@@Z
namespace fn_002fc220 {
// physics::RootMatrixDriver::vfunc_9 @ 0x002fc220
struct Mat4_2fc220 {
    float m[16];
};

struct Joint_2fc220 {
    Mat4_2fc220* FUN_0030f100();
};

struct Link_2fc220 {
    Joint_2fc220* FUN_0030ef30();
};

struct Skeleton {
    Link_2fc220* FUN_0030f490(int index);
};

class RootMatrixDriver {
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
    virtual void vfunc_9(Skeleton* skeleton);
    char pad04[0x18 - 4];
    Mat4_2fc220* root;     // 0x18
};

struct Frame_2fc220 {
    Mat4_2fc220 cur;
    Mat4_2fc220 out;
};

// Multiplies the root joint's matrix by the driver's root matrix and writes it back.
void RootMatrixDriver::vfunc_9(Skeleton* skeleton)
{
    Frame_2fc220 f;
    Link_2fc220* link = skeleton->FUN_0030f490(0);
    f.cur = *link->FUN_0030ef30()->FUN_0030f100();
    ((owners::Matrix_22ca90 *)&(f.out))->FUN_0022ca90((const owners::Matrix_22ca90 *)(Mat4_2fc220 *)(&f.cur), (const owners::Matrix_22ca90 *)(Mat4_2fc220 *)root);
    f.cur = f.out;
    ((owners::A_30ee70 *)link)->FUN_0030ee70((hulk_intptr)(Mat4_2fc220 *)(&f.cur));
}
} // namespace fn_002fc220

namespace fn_f55081c6 {

// 0x002fc2d0 FUN_002fc2d0 (4 B): matches/0x002fc2d0.cpp
// sym: ?FUN_002fc2d0@fn_f55081c6@@YIHPAX@Z
// Same code shape as 0x00086320 (propagated; names are from that function)
hulk_intptr __fastcall FUN_002fc2d0(void* p) {
    return *(int*)((char*)p + 8);
}


// 0x002fc320 FUN_002fc320 (42 B): matches/0x002fc320.cpp
// sym: ?Set@Holder_2fc320@fn_f55081c6@@QAEPAVItem_2fc320@2@PAV32@@Z
// Same code shape as 0x001b7620 (propagated; names are from that function)
Item_2fc320* Holder_2fc320::Set(Item_2fc320* item) {
    Item_2fc320* old = mItem;
    if (old != item) {
        mItem = item;
        if (item)
            item->Add();
        if (old)
            old->Release();
    }
    return mItem;
}


// 0x002fc350 FUN_002fc350 (23 B): matches/0x002fc350.cpp
// sym: ?Set@Owner_2fc350@fn_f55081c6@@QAEPAV12@PAVRef_2fc350@2@@Z
// Same code shape as 0x001b75d0 (propagated; names are from that function)
Owner_2fc350* Owner_2fc350::Set(Ref_2fc350* r) {
    mRef = r;
    if (r)
        r->F();
    return this;
}


// 0x002fc3a0 FUN_002fc3a0 (42 B): matches/0x002fc3a0.cpp
// sym: ?Set@Holder_2fc3a0@fn_f55081c6@@QAEPAVItem_2fc3a0@2@PAV32@@Z
// Same code shape as 0x001b7620 (propagated; names are from that function)
Item_2fc3a0* Holder_2fc3a0::Set(Item_2fc3a0* item) {
    Item_2fc3a0* old = mItem;
    if (old != item) {
        mItem = item;
        if (item)
            item->Add();
        if (old)
            old->Release();
    }
    return mItem;
}

} // namespace fn_f55081c6

// 0x002fc3e0 physics::PhysicsJointMatrixModifier::vfunc_2 (30 B): matches/0x002fc3e0.cpp
// sym: ??_GPhysicsJointMatrixModifier@physics@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
physics::PhysicsJointMatrixModifier::~PhysicsJointMatrixModifier() {}


// 0x002fc400 physics::RootMatrixDriver::vfunc_2 (30 B): matches/0x002fc400.cpp
// sym: ??_GRootMatrixDriver@physics@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
physics::RootMatrixDriver::~RootMatrixDriver() {}

