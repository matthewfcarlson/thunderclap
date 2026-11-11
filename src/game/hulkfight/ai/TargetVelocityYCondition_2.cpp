// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012a890..0x0012a940 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetVelocityYCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f85d66a1 {
#define TREE_TU_END }
namespace fn_f85d66a1 {} using namespace fn_f85d66a1;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f85d66a1 {
class TrackFactoryTemplate_12a890 {
  public:
    TrackFactoryTemplate_12a890() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00128c50();
extern "C" char DAT_0040fe54[];
class TargetVelocityYCondition_12a8d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    TargetVelocityYCondition_12a8d0(int);
    int pad1;
    int pad2;
    int a;
    int b;
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int g_vftable_12a910;
struct ConditionFactoryTemplate_12a910 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f85d66a1

// 0x0012a890 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetVelocityYCondition>::vfunc_1 (60 B): matches/0x0012a890.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetVelocityYCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetVelocityYCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12a890));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12a890* t = new (mem) TrackFactoryTemplate_12a890();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00128c50();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0012a8d0 fight::ConditionFactoryTemplate<hulkfight::ai::TargetVelocityYCondition>::vfunc_5 (54 B): matches/0x0012a8d0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VTargetVelocityYCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetVelocityYCondition>::vfunc_5() {
    TargetVelocityYCondition_12a8d0* p = (TargetVelocityYCondition_12a8d0*)FUN_0008d690((int)sizeof(TargetVelocityYCondition_12a8d0));
    if (p) {
        p->TargetVelocityYCondition_12a8d0::TargetVelocityYCondition_12a8d0(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_0040fe54);
        p->a = 0;
        p->b = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f85d66a1 {

// 0x0012a910 fight::ConditionFactoryTemplate<hulkfight::ai::TargetVelocityYCondition>::vfunc_2 (43 B): matches/0x0012a910.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12a910@fn_f85d66a1@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12a910::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_12a910;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f85d66a1
