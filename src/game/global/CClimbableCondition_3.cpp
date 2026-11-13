// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000575b0..0x00057660 (kind game, layer game, confidence high), dominant class CClimbableCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbcd4bc2 {
#define TREE_TU_END }
namespace fn_fbcd4bc2 {} using namespace fn_fbcd4bc2;
namespace fn_fbcd4bc2 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fbcd4bc2 {
class TrackFactoryTemplate_575b0 {
  public:
    TrackFactoryTemplate_575b0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00054160();
class CClimbableCondition_575f0 {
  public:
    hulk_intptr vt;
    void Init_00234590(int);
    int a;
    int b;
    int c;
    int d;
    char e;
};
extern int hulk_at_003f73e0;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003f9314;
struct ConditionFactoryTemplate_57630 {
    void* m_vptr;
    void base1_dtor_0004a400();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fbcd4bc2

// 0x000575b0 fight::ConditionFactoryCasterTemplate<CClimbableCondition>::vfunc_1 (60 B): matches/0x000575b0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCClimbableCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CClimbableCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_575b0));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_575b0* t = new (mem) TrackFactoryTemplate_575b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00054160();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000575f0 fight::ConditionFactoryTemplate<CClimbableCondition>::vfunc_5 (58 B): matches/0x000575f0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCClimbableCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CClimbableCondition>::vfunc_5() {
    CClimbableCondition_575f0* p = (CClimbableCondition_575f0*)FUN_0008d690((int)sizeof(CClimbableCondition_575f0));
    if (p) {
        p->Init_00234590(0);
        p->vt = (hulk_intptr)&hulk_at_003f73e0;
        p->c = 0;
        p->d = 0x3e860a92;
        p->e = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fbcd4bc2 {

// 0x00057630 fight::ConditionFactoryTemplate<CClimbableCondition>::vfunc_2 (43 B): matches/0x00057630.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_57630@fn_fbcd4bc2@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_57630::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9314;
    base1_dtor_0004a400();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fbcd4bc2
