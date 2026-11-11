// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00114350..0x00114400 (kind game, layer game, confidence high), dominant class hulkfight::ai::FormationReadyCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc50ae1d {
#define TREE_TU_END }
namespace fn_fc50ae1d {} using namespace fn_fc50ae1d;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fc50ae1d {
class TrackFactoryTemplate_114350 {
  public:
    TrackFactoryTemplate_114350() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00112150();
extern "C" char DAT_0040daa4[];
extern "C" void* __cdecl FUN_0008d690(int);
class FormationReadyCondition {
  public:
    void Init_00234590(int);
};
extern int hulk_at_0040e8c0;
struct ConditionFactoryTemplate_1143d0 {
    void* m_vptr;
    void base1_dtor_0010cca0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fc50ae1d

// 0x00114350 fight::ConditionFactoryCasterTemplate<hulkfight::ai::FormationReadyCondition>::vfunc_1 (60 B): matches/0x00114350.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VFormationReadyCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::FormationReadyCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_114350));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_114350* t = new (mem) TrackFactoryTemplate_114350();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00112150();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fc50ae1d {

// 0x00114390 fight::ConditionFactoryTemplate<hulkfight::ai::FormationReadyCondition>::vfunc_5 (54 B): matches/0x00114390.cpp
// sym: ?ConditionFactory_vfunc5@fn_fc50ae1d@@YAPAXXZ
void* ConditionFactory_vfunc5() {
    FormationReadyCondition* p = (FormationReadyCondition*)FUN_0008d690(0x14);
    if (p) {
        p->Init_00234590(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_0040daa4);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}


// 0x001143d0 fight::ConditionFactoryTemplate<hulkfight::ai::FormationReadyCondition>::vfunc_2 (43 B): matches/0x001143d0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1143d0@fn_fc50ae1d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1143d0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040e8c0;
    base1_dtor_0010cca0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc50ae1d
