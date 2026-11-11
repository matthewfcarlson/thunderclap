// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018b820..0x0018b8c0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropGrabbableIsThrownCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5384944 {
#define TREE_TU_END }
namespace fn_f5384944 {} using namespace fn_f5384944;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f5384944 {
class TrackFactoryTemplate_18b820 {
  public:
    TrackFactoryTemplate_18b820() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00187960();
extern "C" char DAT_0041918c[];
class Condition_18b860 {
  public:
    Condition_18b860(int);
};
class PropGrabbableIsThrownCondition_18b860 : public Condition_18b860 {
  public:
    PropGrabbableIsThrownCondition_18b860(int);
    char pad[12];
    char flag;
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int g_vftable_18b890;
struct ConditionFactoryTemplate_18b890 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f5384944

// 0x0018b820 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropGrabbableIsThrownCondition>::vfunc_1 (60 B): matches/0x0018b820.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VPropGrabbableIsThrownCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropGrabbableIsThrownCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18b820));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18b820* t = new (mem) TrackFactoryTemplate_18b820();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00187960();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018b860 fight::ConditionFactoryTemplate<hulkfight::motion::PropGrabbableIsThrownCondition>::vfunc_5 (44 B): matches/0x0018b860.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VPropGrabbableIsThrownCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PropGrabbableIsThrownCondition>::vfunc_5() {
    PropGrabbableIsThrownCondition_18b860* p = (PropGrabbableIsThrownCondition_18b860*)FUN_0008d690(16);
    if (p) {
        p->PropGrabbableIsThrownCondition_18b860::PropGrabbableIsThrownCondition_18b860(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0041918c);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f5384944 {

// 0x0018b890 fight::ConditionFactoryTemplate<hulkfight::motion::PropGrabbableIsThrownCondition>::vfunc_2 (43 B): matches/0x0018b890.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_18b890@fn_f5384944@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_18b890::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_18b890;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f5384944
