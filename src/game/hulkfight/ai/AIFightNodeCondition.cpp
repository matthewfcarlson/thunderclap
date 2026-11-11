// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00113e00..0x00113ea0 (kind game, layer game, confidence high), dominant class hulkfight::ai::AIFightNodeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0666ec3 {
#define TREE_TU_END }
namespace fn_f0666ec3 {} using namespace fn_f0666ec3;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f0666ec3 {
class TrackFactoryTemplate_113e00 {
  public:
    TrackFactoryTemplate_113e00() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00111c40();
struct AIFightNodeCondition_113e40 {
    int v;
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct InitObj_113e40 {
    void InitCondition(int);
};
struct EntityObj {
    void InitEntity();
};
extern int g_vftable_113e70;
struct ConditionFactoryTemplate_113e70 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f0666ec3

// 0x00113e00 fight::ConditionFactoryCasterTemplate<hulkfight::ai::AIFightNodeCondition>::vfunc_1 (60 B): matches/0x00113e00.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VAIFightNodeCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::AIFightNodeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_113e00));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_113e00* t = new (mem) TrackFactoryTemplate_113e00();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00111c40();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00113e40 fight::ConditionFactoryTemplate<hulkfight::ai::AIFightNodeCondition>::vfunc_5 (48 B): matches/0x00113e40.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VAIFightNodeCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::AIFightNodeCondition>::vfunc_5() {
    AIFightNodeCondition_113e40* p = (AIFightNodeCondition_113e40*)FUN_0008d690(0x18);
    if (p) {
        ((InitObj_113e40*)p)->InitCondition(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_0040d9a4);
        ((EntityObj*)((char*)p + 0xc))->InitEntity();
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f0666ec3 {

// 0x00113e70 fight::ConditionFactoryTemplate<hulkfight::ai::AIFightNodeCondition>::vfunc_2 (43 B): matches/0x00113e70.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_113e70@fn_f0666ec3@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_113e70::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_113e70;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f0666ec3
