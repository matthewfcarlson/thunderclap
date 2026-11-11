// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00159a60..0x00159b00 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionInterruptPriorityCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fdffb444 {
#define TREE_TU_END }
namespace fn_fdffb444 {} using namespace fn_fdffb444;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fdffb444 {
class TrackFactoryTemplate_159a60 {
  public:
    TrackFactoryTemplate_159a60() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00155bb0();
} // namespace fn_fdffb444
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_fdffb444 {
class BaseCondition {
  public:
    BaseCondition(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    char pad[8];
    int value;
};
} // namespace fn_fdffb444
namespace hulkfight { namespace motion {
class CollisionInterruptPriorityCondition_159aa0 : public BaseCondition {
  public:
    CollisionInterruptPriorityCondition_159aa0() throw() : BaseCondition(0) { value = 0; }
    virtual void f0();
};
} }
namespace fn_fdffb444 {
extern int hulk_at_004156f8;
struct ConditionFactoryTemplate_159ad0 {
    void* m_vptr;
    void base1_dtor_0014da60();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fdffb444

// 0x00159a60 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionInterruptPriorityCondition>::vfunc_1 (60 B): matches/0x00159a60.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCollisionInterruptPriorityCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionInterruptPriorityCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_159a60));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_159a60* t = new (mem) TrackFactoryTemplate_159a60();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00155bb0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00159aa0 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionInterruptPriorityCondition>::vfunc_5 (47 B): matches/0x00159aa0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCollisionInterruptPriorityCondition@motion@hulkfight@@@fight@@UAEPAXXZ
 // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionInterruptPriorityCondition>::vfunc_5() {
    return (void*)(new hulkfight::motion::CollisionInterruptPriorityCondition_159aa0());
}

namespace fn_fdffb444 {

// 0x00159ad0 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionInterruptPriorityCondition>::vfunc_2 (43 B): matches/0x00159ad0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_159ad0@fn_fdffb444@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_159ad0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004156f8;
    base1_dtor_0014da60();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fdffb444
