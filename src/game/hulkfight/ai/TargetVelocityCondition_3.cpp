// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012a940..0x0012a9f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetVelocityCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fcb2a3af {
#define TREE_TU_END }
namespace fn_fcb2a3af {} using namespace fn_fcb2a3af;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fcb2a3af {
class TrackFactoryTemplate_12a940 {
  public:
    TrackFactoryTemplate_12a940() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00128d00();
extern "C" char DAT_0040fe74[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Init_12a980 {
  public:
    void Start(int);
};
struct Obj_12a980 {
    hulk_uintptr vt;
    int a;
    int b;
    int c;
    int d;
};
extern int g_vftable_12a9c0;
struct ConditionFactoryTemplate_12a9c0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fcb2a3af

// 0x0012a940 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetVelocityCondition>::vfunc_1 (60 B): matches/0x0012a940.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetVelocityCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetVelocityCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12a940));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12a940* t = new (mem) TrackFactoryTemplate_12a940();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00128d00();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0012a980 fight::ConditionFactoryTemplate<hulkfight::ai::TargetVelocityCondition>::vfunc_5 (54 B): matches/0x0012a980.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VTargetVelocityCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetVelocityCondition>::vfunc_5() {
    Obj_12a980* p = (Obj_12a980*)FUN_0008d690((int)sizeof(Obj_12a980));
    if (p) {
        ((Init_12a980*)p)->Start(0);
        p->vt = ((hulk_intptr)DAT_0040fe74);
        p->c = 0;
        p->d = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fcb2a3af {

// 0x0012a9c0 fight::ConditionFactoryTemplate<hulkfight::ai::TargetVelocityCondition>::vfunc_2 (43 B): matches/0x0012a9c0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12a9c0@fn_fcb2a3af@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12a9c0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_12a9c0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fcb2a3af
