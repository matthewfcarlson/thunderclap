// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00159640..0x001596f0 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitPushbackVelocityCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3d41fac {
#define TREE_TU_END }
namespace fn_f3d41fac {} using namespace fn_f3d41fac;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f3d41fac {
class TrackFactoryTemplate_159640 {
  public:
    TrackFactoryTemplate_159640() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001556e0();
extern int g_vftable_1596c0;
struct ConditionFactoryTemplate_1596c0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f3d41fac

// 0x00159640 fight::ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_1 (60 B): matches/0x00159640.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VHitPushbackVelocityCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_159640));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_159640* t = new (mem) TrackFactoryTemplate_159640();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001556e0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f3d41fac {

// 0x001596c0 fight::ConditionFactoryTemplate<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_2 (43 B): matches/0x001596c0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1596c0@fn_f3d41fac@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1596c0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_1596c0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f3d41fac
