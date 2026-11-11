// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016d8d0..0x0016d980 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrappleReactionTypeCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fcd127ab {
#define TREE_TU_END }
namespace fn_fcd127ab {} using namespace fn_fcd127ab;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fcd127ab {
class TrackFactoryTemplate_16d8d0 {
  public:
    TrackFactoryTemplate_16d8d0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016b480();
} // namespace fn_fcd127ab
void* operator new(size_t);
namespace hulkfight { namespace motion {
class BaseCondition {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    BaseCondition(int) throw();
    char pad[8];
};
} }
namespace hulkfight { namespace motion {
class GrappleReactionTypeCondition_16d910 : public BaseCondition {
  public:
    GrappleReactionTypeCondition_16d910() throw() : BaseCondition(0), a(0), b(0) {}
    virtual void f5();
    int a, b;
};
} }
namespace fn_fcd127ab {
extern int hulk_at_004175f4;
struct ConditionFactoryTemplate_16d950 {
    void* m_vptr;
    void base1_dtor_00165ea0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fcd127ab

// 0x0016d8d0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleReactionTypeCondition>::vfunc_1 (60 B): matches/0x0016d8d0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VGrappleReactionTypeCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleReactionTypeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16d8d0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16d8d0* t = new (mem) TrackFactoryTemplate_16d8d0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016b480();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016d910 fight::ConditionFactoryTemplate<hulkfight::motion::GrappleReactionTypeCondition>::vfunc_5 (54 B): matches/0x0016d910.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VGrappleReactionTypeCondition@motion@hulkfight@@@fight@@UAEPAXXZ
 // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::GrappleReactionTypeCondition>::vfunc_5() {
    return (void*)(new hulkfight::motion::GrappleReactionTypeCondition_16d910);
}

namespace fn_fcd127ab {

// 0x0016d950 fight::ConditionFactoryTemplate<hulkfight::motion::GrappleReactionTypeCondition>::vfunc_2 (43 B): matches/0x0016d950.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16d950@fn_fcd127ab@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16d950::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004175f4;
    base1_dtor_00165ea0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fcd127ab
