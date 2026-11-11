// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001140a0..0x00114150 (kind game, layer game, confidence high), dominant class hulkfight::ai::PropsToChuckCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f1f98e59 {
#define TREE_TU_END }
namespace fn_f1f98e59 {} using namespace fn_f1f98e59;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f1f98e59 {
class TrackFactoryTemplate_1140a0 {
  public:
    TrackFactoryTemplate_1140a0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00111ea0();
extern int hulk_at_0040e850;
struct ConditionFactoryTemplate_114120 {
    void* m_vptr;
    void base1_dtor_0010ca10();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f1f98e59

// 0x001140a0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToChuckCondition>::vfunc_1 (60 B): matches/0x001140a0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VPropsToChuckCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToChuckCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1140a0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1140a0* t = new (mem) TrackFactoryTemplate_1140a0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00111ea0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001140e0 fight::ConditionFactoryTemplate<hulkfight::ai::PropsToChuckCondition>::vfunc_5 (54 B): matches/0x001140e0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VPropsToChuckCondition@ai@hulkfight@fn_001140e0@@@fight@fn_001140e0@@UAEPAVBaseCondition@ai@hulkfight@3@XZ
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace fn_001140e0 {

namespace hulkfight {
namespace ai {
class BaseCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    char pad[8];
    BaseCondition(int) throw();
};
class PropsToChuckCondition : public BaseCondition {
  public:
    PropsToChuckCondition() throw();
    int fieldC;
    int field10;
};
PropsToChuckCondition::PropsToChuckCondition() throw() : BaseCondition(0) {
    fieldC = 0;
    field10 = -1;
}
} // namespace ai
} // namespace hulkfight
namespace fight {
template <class T> class ConditionFactoryTemplate {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual hulkfight::ai::BaseCondition* vfunc_5();
};
template <>
hulkfight::ai::BaseCondition* ConditionFactoryTemplate<hulkfight::ai::PropsToChuckCondition>::vfunc_5() {
    return new hulkfight::ai::PropsToChuckCondition;
}
} // namespace fight
} // namespace fn_001140e0

namespace fn_f1f98e59 {

// 0x00114120 fight::ConditionFactoryTemplate<hulkfight::ai::PropsToChuckCondition>::vfunc_2 (43 B): matches/0x00114120.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_114120@fn_f1f98e59@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_114120::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040e850;
    base1_dtor_0010ca10();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f1f98e59
