// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00057920..0x000579c0 (kind game, layer game, confidence high), dominant class CCollisionInterruptCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0450c99 {
#define TREE_TU_END }
namespace fn_f0450c99 {} using namespace fn_f0450c99;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f0450c99 {
class TrackFactoryTemplate_57920 {
  public:
    TrackFactoryTemplate_57920() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000534e0();
extern "C" char DAT_003f7034[];
typedef unsigned int u32_57960;
struct CCollisionInterruptCondition_57960 {
    hulk_uintptr vf;
    char pad[8];
    unsigned char flag;
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Initializer_57960 {
    void init_00234590(int);
};
extern int hulk_at_003f93a0;
struct ConditionFactoryTemplate_57990 {
    void* m_vptr;
    void base1_dtor_00048e60();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f0450c99

// 0x00057920 fight::ConditionFactoryCasterTemplate<CCollisionInterruptCondition>::vfunc_1 (60 B): matches/0x00057920.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCCollisionInterruptCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CCollisionInterruptCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_57920));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_57920* t = new (mem) TrackFactoryTemplate_57920();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000534e0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00057960 fight::ConditionFactoryTemplate<CCollisionInterruptCondition>::vfunc_5 (44 B): matches/0x00057960.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCCollisionInterruptCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CCollisionInterruptCondition>::vfunc_5() {
    CCollisionInterruptCondition_57960* p = (CCollisionInterruptCondition_57960*)FUN_0008d690((int)sizeof(CCollisionInterruptCondition_57960));
    if (p) {
        ((Initializer_57960*)p)->init_00234590(0);
        p->vf = ((hulk_intptr)DAT_003f7034);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)((CCollisionInterruptCondition_57960*)0);
}

namespace fn_f0450c99 {

// 0x00057990 fight::ConditionFactoryTemplate<CCollisionInterruptCondition>::vfunc_2 (43 B): matches/0x00057990.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_57990@fn_f0450c99@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_57990::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f93a0;
    base1_dtor_00048e60();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f0450c99
