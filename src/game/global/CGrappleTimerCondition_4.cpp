// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058030..0x000580f0 (kind game, layer game, confidence high), dominant class CGrappleTimerCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa6d491a {
#define TREE_TU_END }
namespace fn_fa6d491a {} using namespace fn_fa6d491a;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fa6d491a {
class TrackFactoryTemplate_58030 {
  public:
    TrackFactoryTemplate_58030() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00054360();
} // namespace fn_fa6d491a
class CGrappleTimerCondition {
  public:
    void* vfptr;        // +0x00
    int base0;          // +0x04
    int base1;          // +0x08
    int type;           // +0x0c
    int unk10;          // +0x10
    unsigned char flag; // +0x14
    int unk18;          // +0x18

    void Ctor(int flags);
};
namespace fn_fa6d491a {
extern char CGrappleTimerCondition_vftable[];
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
extern int g_vftable_580c0;
struct ConditionFactoryTemplate_580c0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fa6d491a

// 0x00058030 fight::ConditionFactoryCasterTemplate<CGrappleTimerCondition>::vfunc_1 (60 B): matches/0x00058030.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCGrappleTimerCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CGrappleTimerCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_58030));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_58030* t = new (mem) TrackFactoryTemplate_58030();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00054360();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fa6d491a {

// 0x00058070 fight::ConditionFactoryTemplate<CGrappleTimerCondition>::vfunc_5 (65 B): matches/0x00058070.cpp
// sym: ?vfunc_5@fn_fa6d491a@@YAPAXXZ
void* vfunc_5() {
    CGrappleTimerCondition* p = (CGrappleTimerCondition*)FUN_0008d690((int)sizeof(CGrappleTimerCondition));
    if (p != 0) {
        p->Ctor(0);
        p->vfptr = CGrappleTimerCondition_vftable;
        p->type = 5;
        p->unk10 = 0;
        p->flag = 0;
        p->unk18 = 0;
        return p;
    }
    return 0;
}


// 0x000580c0 fight::ConditionFactoryTemplate<CGrappleTimerCondition>::vfunc_2 (43 B): matches/0x000580c0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_580c0@fn_fa6d491a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_580c0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_580c0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fa6d491a
