// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016e190..0x0016e230 (kind game, layer game, confidence high), dominant class hulkfight::motion::ShoreNearCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fde90977 {
#define TREE_TU_END }
namespace fn_fde90977 {} using namespace fn_fde90977;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fde90977 {
class TrackFactoryTemplate_16e190 {
  public:
    TrackFactoryTemplate_16e190() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016bce0();
} // namespace fn_fde90977
void* __cdecl operator new(size_t);
namespace hulkfight { namespace motion {
class BaseCondition {
  public:
    virtual void f();
    char pad[8];
    BaseCondition(int) throw();
};
} }
namespace hulkfight { namespace motion {
class ShoreNearCondition_16e1d0 : public BaseCondition {
  public:
    virtual void f();
    bool enabled;
    ShoreNearCondition_16e1d0(int x) throw() : BaseCondition(x), enabled(true) {}
};
} }
namespace fn_fde90977 {
extern int g_vftable_16e200;
struct ConditionFactoryTemplate_16e200 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fde90977

// 0x0016e190 fight::ConditionFactoryCasterTemplate<hulkfight::motion::ShoreNearCondition>::vfunc_1 (60 B): matches/0x0016e190.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VShoreNearCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::ShoreNearCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16e190));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16e190* t = new (mem) TrackFactoryTemplate_16e190();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016bce0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016e1d0 fight::ConditionFactoryTemplate<hulkfight::motion::ShoreNearCondition>::vfunc_5 (44 B): matches/0x0016e1d0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VShoreNearCondition@motion@hulkfight@@@fight@@UAEPAXXZ
 // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::ShoreNearCondition>::vfunc_5() {
    return (void*)(new hulkfight::motion::ShoreNearCondition_16e1d0(0));
}

namespace fn_fde90977 {

// 0x0016e200 fight::ConditionFactoryTemplate<hulkfight::motion::ShoreNearCondition>::vfunc_2 (43 B): matches/0x0016e200.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16e200@fn_fde90977@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16e200::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_16e200;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fde90977
