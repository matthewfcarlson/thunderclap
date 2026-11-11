// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00057b20..0x00057bd0 (kind game, layer game, confidence high), dominant class CCollisionPushbackYCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fac59c20 {
#define TREE_TU_END }
namespace fn_fac59c20 {} using namespace fn_fac59c20;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fac59c20 {
class TrackFactoryTemplate_57b20 {
  public:
    TrackFactoryTemplate_57b20() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000536a0();
extern "C" char DAT_003f70a0[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct CCollisionPushbackYCondition_57b60 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    int pad0;
    int pad1;
    int a;
    int b;
};
struct Initializer_57b60 {
    void init_00234590(int);
};
extern int hulk_at_003f93f4;
struct ConditionFactoryTemplate_57ba0 {
    void* m_vptr;
    void base1_dtor_00048fd0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fac59c20

// 0x00057b20 fight::ConditionFactoryCasterTemplate<CCollisionPushbackYCondition>::vfunc_1 (60 B): matches/0x00057b20.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCCollisionPushbackYCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CCollisionPushbackYCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_57b20));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_57b20* t = new (mem) TrackFactoryTemplate_57b20();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000536a0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00057b60 fight::ConditionFactoryTemplate<CCollisionPushbackYCondition>::vfunc_5 (54 B): matches/0x00057b60.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCCollisionPushbackYCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CCollisionPushbackYCondition>::vfunc_5() {
    CCollisionPushbackYCondition_57b60* p = (CCollisionPushbackYCondition_57b60*)FUN_0008d690((int)sizeof(CCollisionPushbackYCondition_57b60));
    if (p) {
        ((Initializer_57b60*)p)->init_00234590(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003f70a0);
        p->a = 3;
        p->b = 0;
    } else
        return (void*)((CCollisionPushbackYCondition_57b60*)0);
    return (void*)(p);
}

namespace fn_fac59c20 {

// 0x00057ba0 fight::ConditionFactoryTemplate<CCollisionPushbackYCondition>::vfunc_2 (43 B): matches/0x00057ba0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_57ba0@fn_fac59c20@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_57ba0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f93f4;
    base1_dtor_00048fd0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fac59c20
