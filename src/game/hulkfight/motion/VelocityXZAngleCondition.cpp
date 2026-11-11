// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016de30..0x0016dee0 (kind game, layer game, confidence high), dominant class hulkfight::motion::VelocityXZAngleCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fcd8d6f8 {
#define TREE_TU_END }
namespace fn_fcd8d6f8 {} using namespace fn_fcd8d6f8;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fcd8d6f8 {
class TrackFactoryTemplate_16de30 {
  public:
    TrackFactoryTemplate_16de30() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016b9d0();
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int hulk_at_004168b8;
class VelocityXZAngleCondition_16de70 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    int x;
    int y;
    int z;
    float angle;
    void Init_00234590(int);
};
extern int hulk_at_004176d4;
struct ConditionFactoryTemplate_16deb0 {
    void* m_vptr;
    void base1_dtor_00166300();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fcd8d6f8

// 0x0016de30 fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityXZAngleCondition>::vfunc_1 (60 B): matches/0x0016de30.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VVelocityXZAngleCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityXZAngleCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16de30));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16de30* t = new (mem) TrackFactoryTemplate_16de30();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016b9d0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016de70 fight::ConditionFactoryTemplate<hulkfight::motion::VelocityXZAngleCondition>::vfunc_5 (54 B): matches/0x0016de70.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VVelocityXZAngleCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::VelocityXZAngleCondition>::vfunc_5() {
    VelocityXZAngleCondition_16de70* p = (VelocityXZAngleCondition_16de70*)FUN_0008d690((int)sizeof(VelocityXZAngleCondition_16de70));
    if (p) {
        p->Init_00234590(0);
        *(hulk_intptr*)p = (hulk_intptr)&hulk_at_004168b8;
        p->z = 0;
        p->angle = 1.57079637f;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fcd8d6f8 {

// 0x0016deb0 fight::ConditionFactoryTemplate<hulkfight::motion::VelocityXZAngleCondition>::vfunc_2 (43 B): matches/0x0016deb0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16deb0@fn_fcd8d6f8@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16deb0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004176d4;
    base1_dtor_00166300();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fcd8d6f8
