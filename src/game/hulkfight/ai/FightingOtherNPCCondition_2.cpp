// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00114770..0x00114810 (kind game, layer game, confidence high), dominant class hulkfight::ai::FightingOtherNPCCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4f2cc84 {
#define TREE_TU_END }
namespace fn_f4f2cc84 {} using namespace fn_f4f2cc84;
namespace fn_f4f2cc84 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f4f2cc84 {
class TrackFactoryTemplate_114770 {
  public:
    TrackFactoryTemplate_114770() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00112610();
extern "C" char DAT_0040db64[];
class Condition_1147b0 {
  public:
    hulk_intptr vt;
    char pad[8];
    int m;
    void Init_00234590(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_0040e968;
struct ConditionFactoryTemplate_1147e0 {
    void* m_vptr;
    void base1_dtor_0010d000();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f4f2cc84

// 0x00114770 fight::ConditionFactoryCasterTemplate<hulkfight::ai::FightingOtherNPCCondition>::vfunc_1 (60 B): matches/0x00114770.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VFightingOtherNPCCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::FightingOtherNPCCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_114770));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_114770* t = new (mem) TrackFactoryTemplate_114770();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00112610();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001147b0 fight::ConditionFactoryTemplate<hulkfight::ai::FightingOtherNPCCondition>::vfunc_5 (47 B): matches/0x001147b0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VFightingOtherNPCCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::FightingOtherNPCCondition>::vfunc_5() {
    Condition_1147b0* p = (Condition_1147b0*)FUN_0008d690((int)sizeof(Condition_1147b0));
    if (p) {
        p->Init_00234590(0);
        p->vt = ((hulk_intptr)DAT_0040db64);
        p->m = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f4f2cc84 {

// 0x001147e0 fight::ConditionFactoryTemplate<hulkfight::ai::FightingOtherNPCCondition>::vfunc_2 (43 B): matches/0x001147e0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1147e0@fn_f4f2cc84@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1147e0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040e968;
    base1_dtor_0010d000();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f4f2cc84
