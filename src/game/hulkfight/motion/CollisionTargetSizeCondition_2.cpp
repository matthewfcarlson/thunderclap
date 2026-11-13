// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001594f0..0x001595a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionTargetSizeCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4c96b13 {
#define TREE_TU_END }
namespace fn_f4c96b13 {} using namespace fn_f4c96b13;
namespace fn_f4c96b13 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f4c96b13 {
class TrackFactoryTemplate_1594f0 {
  public:
    TrackFactoryTemplate_1594f0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001555c0();
extern int hulk_at_00415618;
struct ConditionFactoryTemplate_159570 {
    void* m_vptr;
    void base1_dtor_0014d600();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f4c96b13

// 0x001594f0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_1 (60 B): matches/0x001594f0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCollisionTargetSizeCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1594f0));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_1594f0* t = new (mem) TrackFactoryTemplate_1594f0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001555c0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f4c96b13 {

// 0x00159570 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_2 (43 B): matches/0x00159570.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_159570@fn_f4c96b13@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_159570::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00415618;
    base1_dtor_0014d600();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f4c96b13
