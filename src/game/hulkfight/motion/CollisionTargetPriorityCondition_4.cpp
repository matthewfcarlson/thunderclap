// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00159260..0x00159310 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionTargetPriorityCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc322d89 {
#define TREE_TU_END }
namespace fn_fc322d89 {} using namespace fn_fc322d89;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fc322d89 {
class TrackFactoryTemplate_159260 {
  public:
    TrackFactoryTemplate_159260() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001553f0();
extern "C" char DAT_00414010[];
struct CollisionTargetPriorityCondition {
    int* vptr;
    int pad4;
    int pad8;
    int mC;
    int m10;
    void Init(int);
};
extern "C" void* __cdecl FUN_0008d690(int);
extern int g_vftable_1592e0;
struct ConditionFactoryTemplate_1592e0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fc322d89

// 0x00159260 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_1 (60 B): matches/0x00159260.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCollisionTargetPriorityCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_159260));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_159260* t = new (mem) TrackFactoryTemplate_159260();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001553f0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fc322d89 {

// 0x001592a0 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_5 (54 B): matches/0x001592a0.cpp
// sym: ?Factory_vfunc5@fn_fc322d89@@YAPAXXZ
void* __cdecl Factory_vfunc5() {
    CollisionTargetPriorityCondition* p = (CollisionTargetPriorityCondition*)FUN_0008d690((int)sizeof(CollisionTargetPriorityCondition));
    if (p) {
        p->Init(0);
        p->vptr = (int*)((hulk_intptr)DAT_00414010);
        p->mC = 0;
        p->m10 = 0;
        return p;
    }
    return 0;
}


// 0x001592e0 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_2 (43 B): matches/0x001592e0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1592e0@fn_fc322d89@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1592e0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_1592e0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc322d89
