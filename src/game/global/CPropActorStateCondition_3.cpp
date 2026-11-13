// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000585c0..0x00058670 (kind game, layer game, confidence high), dominant class CPropActorStateCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f1eed91f {
#define TREE_TU_END }
namespace fn_f1eed91f {} using namespace fn_f1eed91f;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f1eed91f {
class TrackFactoryTemplate_585c0 {
  public:
    TrackFactoryTemplate_585c0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00053d80();
extern "C" char DAT_003f7274[];
typedef unsigned int U_58600;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct CPropActorStateCondition_58600 {
    virtual void v0();
    U_58600 x[4];
    void setup_00234590(int);
};
extern int hulk_at_003f95e8;
struct ConditionFactoryTemplate_58640 {
    void* m_vptr;
    void base1_dtor_00049b40();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f1eed91f

// 0x000585c0 fight::ConditionFactoryCasterTemplate<CPropActorStateCondition>::vfunc_1 (60 B): matches/0x000585c0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCPropActorStateCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CPropActorStateCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_585c0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_585c0* t = new (mem) TrackFactoryTemplate_585c0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00053d80();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00058600 fight::ConditionFactoryTemplate<CPropActorStateCondition>::vfunc_5 (54 B): matches/0x00058600.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCPropActorStateCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CPropActorStateCondition>::vfunc_5() {
    CPropActorStateCondition_58600* p = (CPropActorStateCondition_58600*)FUN_0008d690((int)sizeof(CPropActorStateCondition_58600));
    if (p) {
        p->setup_00234590(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003f7274);
        *(U_58600*)((char*)&p->x[2]) = 2;
        *(U_58600*)((char*)&p->x[3]) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f1eed91f {

// 0x00058640 fight::ConditionFactoryTemplate<CPropActorStateCondition>::vfunc_2 (43 B): matches/0x00058640.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58640@fn_f1eed91f@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58640::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f95e8;
    base1_dtor_00049b40();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f1eed91f
