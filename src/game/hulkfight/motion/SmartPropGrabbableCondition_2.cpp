// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018b760..0x0018b820 (kind game, layer game, confidence high), dominant class hulkfight::motion::SmartPropGrabbableCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe0fc732 {
#define TREE_TU_END }
namespace fn_fe0fc732 {} using namespace fn_fe0fc732;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fe0fc732 {
class TrackFactoryTemplate_18b760 {
  public:
    TrackFactoryTemplate_18b760() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001876f0();
extern "C" char DAT_0041914c[];
class SmartPropGrabbableCondition {
  public:
    void Init(int);
    void* vf;
    char pad0[0xc - 4];
    unsigned char b0c;
    char pad1[3];
    int i10;
    unsigned char b14;
    unsigned char b15;
    unsigned char b16;
    char pad3[1];
    int i18;
    unsigned char b1c;
    char pad4[3];
    int i20;
    unsigned char b24;
    char pad5[3];
    int i28;
};
extern int g_vftable_18b7f0;
struct ConditionFactoryTemplate_18b7f0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fe0fc732

// 0x0018b760 fight::ConditionFactoryCasterTemplate<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_1 (60 B): matches/0x0018b760.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18b760));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18b760* t = new (mem) TrackFactoryTemplate_18b760();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001876f0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fe0fc732 {

// 0x0018b7a0 fight::ConditionFactoryTemplate<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_5 (75 B): matches/0x0018b7a0.cpp
// sym: ?vfunc_5@fn_fe0fc732@@YAPAVSmartPropGrabbableCondition@1@XZ
SmartPropGrabbableCondition* vfunc_5() {
    SmartPropGrabbableCondition* p = (SmartPropGrabbableCondition*)operator new(sizeof(SmartPropGrabbableCondition));
    if (p) {
        p->Init(0);
        p->b0c = 0;
        p->i10 = 0;
        p->b14 = 0;
        p->b16 = 0;
        p->i18 = 0;
        p->b1c = 0;
        p->i20 = 0;
        p->b24 = 0;
        p->i28 = 0;
        p->vf = (void*)((hulk_intptr)DAT_0041914c);
        p->b15 = 1;
        return p;
    }
    return 0;
}


// 0x0018b7f0 fight::ConditionFactoryTemplate<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_2 (43 B): matches/0x0018b7f0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_18b7f0@fn_fe0fc732@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_18b7f0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_18b7f0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fe0fc732
