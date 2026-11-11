// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012ab50..0x0012ac00 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetVelocityXZCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5ed8d52 {
#define TREE_TU_END }
namespace fn_f5ed8d52 {} using namespace fn_f5ed8d52;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f5ed8d52 {
class TrackFactoryTemplate_12ab50 {
  public:
    TrackFactoryTemplate_12ab50() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00128fb0();
extern int hulk_at_00410abc;
struct ConditionFactoryTemplate_12abd0 {
    void* m_vptr;
    void base1_dtor_001240e0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f5ed8d52

// 0x0012ab50 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetVelocityXZCondition>::vfunc_1 (60 B): matches/0x0012ab50.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetVelocityXZCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetVelocityXZCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12ab50));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12ab50* t = new (mem) TrackFactoryTemplate_12ab50();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00128fb0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f5ed8d52 {

// 0x0012abd0 fight::ConditionFactoryTemplate<hulkfight::ai::TargetVelocityXZCondition>::vfunc_2 (43 B): matches/0x0012abd0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12abd0@fn_f5ed8d52@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12abd0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00410abc;
    base1_dtor_001240e0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f5ed8d52
