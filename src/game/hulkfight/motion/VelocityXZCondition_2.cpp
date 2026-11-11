// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016df80..0x0016e030 (kind game, layer game, confidence high), dominant class hulkfight::motion::VelocityXZCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0d3a50f {
#define TREE_TU_END }
namespace fn_f0d3a50f {} using namespace fn_f0d3a50f;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f0d3a50f {
class TrackFactoryTemplate_16df80 {
  public:
    TrackFactoryTemplate_16df80() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016bad0();
extern "C" char DAT_00416918[];
struct Obj_16dfc0 {
    hulk_uintptr vt;
    int a;
    int b;
    int c;
    int d;
    void Init(int);
};
extern "C" Obj_16dfc0* __cdecl FUN_0008d690(unsigned int);
extern int g_vftable_16e000;
struct ConditionFactoryTemplate_16e000 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f0d3a50f

// 0x0016df80 fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityXZCondition>::vfunc_1 (60 B): matches/0x0016df80.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VVelocityXZCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityXZCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16df80));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16df80* t = new (mem) TrackFactoryTemplate_16df80();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016bad0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016dfc0 fight::ConditionFactoryTemplate<hulkfight::motion::VelocityXZCondition>::vfunc_5 (54 B): matches/0x0016dfc0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VVelocityXZCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::VelocityXZCondition>::vfunc_5() {
    Obj_16dfc0* p = FUN_0008d690((int)sizeof(Obj_16dfc0));
    if (p) {
        p->Init(0);
        p->vt = ((hulk_intptr)DAT_00416918);
        p->c = 0;
        p->d = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f0d3a50f {

// 0x0016e000 fight::ConditionFactoryTemplate<hulkfight::motion::VelocityXZCondition>::vfunc_2 (43 B): matches/0x0016e000.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16e000@fn_f0d3a50f@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16e000::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_16e000;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f0d3a50f
