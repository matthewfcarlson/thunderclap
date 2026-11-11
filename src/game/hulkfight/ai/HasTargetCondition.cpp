// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012a7f0..0x0012a890 (kind game, layer game, confidence high), dominant class hulkfight::ai::HasTargetCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f56221d5 {
#define TREE_TU_END }
namespace fn_f56221d5 {} using namespace fn_f56221d5;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f56221d5 {
class TrackFactoryTemplate_12a7f0 {
  public:
    TrackFactoryTemplate_12a7f0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00128bf0();
extern int hulk_at_00410a30;
struct ConditionFactoryTemplate_12a860 {
    void* m_vptr;
    void base1_dtor_00123ec0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f56221d5

// 0x0012a7f0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::HasTargetCondition>::vfunc_1 (60 B): matches/0x0012a7f0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VHasTargetCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::HasTargetCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12a7f0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12a7f0* t = new (mem) TrackFactoryTemplate_12a7f0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00128bf0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0012a830 fight::ConditionFactoryTemplate<hulkfight::ai::HasTargetCondition>::vfunc_5 (44 B): matches/0x0012a830.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_5@HasTargetFactory@fight@fn_0012a830@@UAEPAXXZ
void* operator new(size_t);
namespace fn_0012a830 {
/* size_t: tree_prelude.h */

namespace hulkfight {
namespace ai {
class BaseCondition {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    char pad[8];
    BaseCondition(int) throw();
};
class HasTargetCondition : public BaseCondition {
  public:
    HasTargetCondition(int) throw();
    char flag;
};
HasTargetCondition::HasTargetCondition(int n) throw() : BaseCondition(n) {
    flag = 1;
}
} // namespace ai
} // namespace hulkfight
namespace fight {
class ConditionFactory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* vfunc_5();
};
class HasTargetFactory : public ConditionFactory {
  public:
    virtual void* vfunc_5();
};
void* HasTargetFactory::vfunc_5() {
    return new hulkfight::ai::HasTargetCondition(0);
}
} // namespace fight
} // namespace fn_0012a830

namespace fn_f56221d5 {

// 0x0012a860 fight::ConditionFactoryTemplate<hulkfight::ai::HasTargetCondition>::vfunc_2 (43 B): matches/0x0012a860.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12a860@fn_f56221d5@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12a860::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00410a30;
    base1_dtor_00123ec0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f56221d5
