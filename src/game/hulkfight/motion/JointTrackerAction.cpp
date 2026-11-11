// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00171010..0x001712c0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::JointTrackerAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fafe1619 {
#define TREE_TU_END }
namespace fn_fafe1619 {} using namespace fn_fafe1619;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fafe1619 {
struct Tail_171010 {
    void Init_0027af50();
};
struct FootPivotTrack_171010 {
    void* vptr;
    char pad[0x14];
    void Finish_00236d60();
    void Run();
};
extern void* hulk_at_00417d78;
struct Thing_171060 {
    int pad[4];
    int value;
};
struct ObjC_171060 {
    void run_00035930(int);
};
struct ObjB_171060 {
    ObjC_171060* run_00059a30();
};
struct ObjA_171060 {
    ObjB_171060* run_000592a0();
};
class A_1710a0 {
  public:
};
class B_1710a0 {
  public:
    void* Fng_00059a30();
};
class C_1710a0 {
  public:
};
struct V3_1710d0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Mat4_1710d0 {
    V3_1710d0 r0;
    float w0;
    V3_1710d0 r1;
    float w1;
    V3_1710d0 r2;
    float w2;
    float t[4];
    void FUN_0022b980();
};
struct Name_1710d0 {
    char data[8];
};
class JointDriver {
public:
    virtual void v0();
    char pad04[4];
    Name_1710d0 name;
    int f10;
    int f14;
    char pad18[0x70 - 0x18];
    JointDriver *FUN_002248a0();
};
struct JointFinder_1710d0 {
    unsigned int FUN_0027b200(int a, int b);
};
struct SceneCtl_1710d0 {
    char pad0[8];
    JointFinder_1710d0 *finder;
};
struct Stats_1710d0 {
    char pad0[0x120];
    SceneCtl_1710d0 *scene;
};
struct Fighter_1710d0 { char pad[4]; };
Fighter_1710d0 *__fastcall FUN_000592a0(void *owner);
extern "C" Stats_1710d0 *__fastcall FUN_00059a30(Fighter_1710d0 *f);
struct TrackerData_1710d0 {
    char pad0[0x18];
    int jointA;
    int jointB;
    V3_1710d0 axisSrc;
    V3_1710d0 refSrc;
};
class JointTrackerAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    TrackerData_1710d0 *data;
    void *owner;
    JointDriver *driver;
    V3_1710d0 axis;
    Mat4_1710d0 mat;
};
struct Two_171290 {
    void* Fnf_00059a40();
};


// 0x00171010 FUN_00171010 (25 B): matches/0x00171010.cpp
// sym: ?Run@FootPivotTrack_171010@fn_fafe1619@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void FootPivotTrack_171010::Run() {
    vptr = &hulk_at_00417d78;
    ((Tail_171010*)((char*)this + 0x18))->Init_0027af50();
    Finish_00236d60();
}

} // namespace fn_fafe1619

// 0x00171060 hulkfight::motion::LocomotionStateAction::vfunc_5 (52 B): matches/0x00171060.cpp
// sym: ?vfunc_5@LocomotionStateAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::LocomotionStateAction::vfunc_5(hulk_intptr param, int unused) {
    if (param)
        return true;
    ObjB_171060* b = (*(ObjA_171060 * *)&this->f_20)->run_000592a0();
    ObjC_171060* c = b->run_00059a30();
    c->run_00035930((*(Thing_171060 * *)&this->f_1c)->value);
    return false;
}


// 0x001710a0 hulkfight::motion::MotionStateAction::vfunc_5 (46 B): matches/0x001710a0.cpp
// sym: ?vfunc_5@MotionStateAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::MotionStateAction::vfunc_5(hulk_intptr arg, int unused) {
    if (arg == 0) {
        void* a = ((void *)((owners::Object_592a0 *)((*(A_1710a0 * *)&this->f_20)))->FUN_000592a0());
        void* b = ((B_1710a0*)a)->Fng_00059a30();
        ((owners::C_359c0 *)(((C_1710a0*)b)))->FUN_000359c0(*(int*)((char*)(*(void * *)&this->f_1c) + 0x14));
    }
    return true;
}

namespace fn_fafe1619 {

// 0x001710d0 hulkfight::motion::JointTrackerAction::vfunc_3 (439 B): equivalent/0x001710d0.cpp
// sym: ?vfunc_3@JointTrackerAction@fn_fafe1619@@UAE_NHH@Z @5e4e816dc21a @w24fb03002d72
// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 6/6)
// hulkfight::motion::JointTrackerAction::vfunc_3 @ 0x001710d0
bool JointTrackerAction::vfunc_3(int a, int b)
{
    Stats_1710d0 *stats = FUN_00059a30(FUN_000592a0(owner));
    SceneCtl_1710d0 *scene = stats->scene;
    int ja = data->jointA;
    int jb = data->jointB;
    unsigned int id = 0;
    if ((ja | jb) != 0) {
        id = scene->finder->FUN_0027b200(ja, jb);
        if (id == 0xffff)
            id = 0;
    }

    JointDriver *d = (JointDriver *)FUN_00263ea0(0x70);
    if (d)
        d = d->FUN_002248a0();
    driver = d;
    ((owners::Target_27b040 *)&(driver->name))->FUN_0027b040((hulk_uintptr)"jointTracker");
    driver->v0();
    driver->f14 = 2;
    driver->f10 = id;

    V3_1710d0 src = data->axisSrc;
    axis = src;
    axis.FUN_0022d110();

    V3_1710d0 ref = data->refSrc;
    ref.FUN_0022d110();

    V3_1710d0 c;
    c.x = ref.z * axis.y - ref.y * axis.z;
    c.y = ref.x * axis.z - ref.z * axis.x;
    c.z = ref.y * axis.x - ref.x * axis.y;
    c.FUN_0022d110();

    V3_1710d0 e;
    e.x = c.y * axis.z - c.z * axis.y;
    e.y = c.z * axis.x - c.x * axis.z;
    e.z = c.x * axis.y - c.y * axis.x;
    e.FUN_0022d110();

    mat.FUN_0022b980();
    mat.r0 = e;
    mat.r1 = c;
    mat.r2 = axis;
    ((owners::M_22c0b0 *)&mat)->FUN_0022c0b0();
    return true;
}

} // namespace fn_fafe1619

// 0x00171290 hulkfight::motion::JointTrackerAction::vfunc_4 (37 B): matches/0x00171290.cpp
// sym: ?vfunc_4@JointTrackerAction@motion@hulkfight@@UAEXXZ
// Same code shape as 0x00134160 (propagated; names are from that function)
void hulkfight::motion::JointTrackerAction::vfunc_4() {
    void* x = (*(One * *)&this->f_20)->f();
    void* y = ((Two_171290*)x)->Fnf_00059a40();
    if (y)
        ((Three*)y)->f((*(void * *)&this->f_24), 0);
}

