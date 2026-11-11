// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00164f70..0x00165020 (kind game, layer game, confidence high), dominant class hulkfight::motion::JointPlantedCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f26bd952 {
#define TREE_TU_END }
namespace fn_f26bd952 {} using namespace fn_f26bd952;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f26bd952 {
class TrackFactoryTemplate_164f70 {
  public:
    TrackFactoryTemplate_164f70() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00161c10();
extern "C" char DAT_00415970[];
struct InitBase_164fb0 {
    void init_00234590(int);
};
struct Sub_164fb0 {
    void setup_0027af00();
};
struct Obj_164fb0 {
    hulk_uintptr vptr;
    char pad[12];
    Sub_164fb0 sub;
    char pad2[4];
    int x;
    unsigned char flag;
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int hulk_at_004164e8;
struct ConditionFactoryTemplate_164ff0 {
    void* m_vptr;
    void base1_dtor_0015b7c0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f26bd952

// 0x00164f70 fight::ConditionFactoryCasterTemplate<hulkfight::motion::JointPlantedCondition>::vfunc_1 (60 B): matches/0x00164f70.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VJointPlantedCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::JointPlantedCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_164f70));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_164f70* t = new (mem) TrackFactoryTemplate_164f70();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00161c10();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00164fb0 fight::ConditionFactoryTemplate<hulkfight::motion::JointPlantedCondition>::vfunc_5 (59 B): matches/0x00164fb0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VJointPlantedCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::JointPlantedCondition>::vfunc_5() {
    Obj_164fb0* p = (Obj_164fb0*)FUN_0008d690((int)sizeof(Obj_164fb0));
    if (p) {
        ((InitBase_164fb0*)p)->init_00234590(0);
        p->vptr = ((hulk_intptr)DAT_00415970);
        p->sub.setup_0027af00();
        p->x = 0;
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f26bd952 {

// 0x00164ff0 fight::ConditionFactoryTemplate<hulkfight::motion::JointPlantedCondition>::vfunc_2 (43 B): matches/0x00164ff0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_164ff0@fn_f26bd952@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_164ff0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004164e8;
    base1_dtor_0015b7c0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f26bd952
