// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001599b0..0x00159a60 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionTargetTypeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4dd8c50 {
#define TREE_TU_END }
namespace fn_f4dd8c50 {} using namespace fn_f4dd8c50;
namespace fn_f4dd8c50 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f4dd8c50 {
class TrackFactoryTemplate_1599b0 {
  public:
    TrackFactoryTemplate_1599b0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00155af0();
extern "C" char DAT_004141b0[];
extern "C" void* __cdecl Alloc(hulk_uintptr);
class Cond {
  public:
    Cond(int);
};
extern int hulk_at_004156dc;
struct ConditionFactoryTemplate_159a30 {
    void* m_vptr;
    void base1_dtor_0014d9f0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f4dd8c50

// 0x001599b0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetTypeCondition>::vfunc_1 (60 B): matches/0x001599b0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCollisionTargetTypeCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetTypeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1599b0));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_1599b0* t = new (mem) TrackFactoryTemplate_1599b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00155af0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001599f0 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionTargetTypeCondition>::vfunc_5 (54 B): matches/0x001599f0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCollisionTargetTypeCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionTargetTypeCondition>::vfunc_5() {
    Cond* p = (Cond*)Alloc(20);
    if (p) {
        p->Cond::Cond(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_004141b0);
        *(unsigned int*)((char*)p + 12) = 0;
        *(unsigned int*)((char*)p + 16) = 0;
        return (void*)(p);
    }
    return (void*)((Cond*)0);
}

namespace fn_f4dd8c50 {

// 0x00159a30 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionTargetTypeCondition>::vfunc_2 (43 B): matches/0x00159a30.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_159a30@fn_f4dd8c50@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_159a30::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004156dc;
    base1_dtor_0014d9f0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f4dd8c50
