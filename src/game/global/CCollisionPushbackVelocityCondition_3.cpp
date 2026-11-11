// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00057a70..0x00057b20 (kind game, layer game, confidence high), dominant class CCollisionPushbackVelocityCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4159269 {
#define TREE_TU_END }
namespace fn_f4159269 {} using namespace fn_f4159269;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f4159269 {
class TrackFactoryTemplate_57a70 {
  public:
    TrackFactoryTemplate_57a70() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000535f0();
class ConditionFactory_57ab0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
};
class Entity_57ab0 {};
class LoadObject_57ab0 {};
class IRefCount_57ab0 {};
extern int hulk_at_003f707c;
class CCollisionPushbackVelocityCondition_57ab0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    int pad[2];
    int a, b, c;
    void Init_00234590(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003f93d8;
struct ConditionFactoryTemplate_57af0 {
    void* m_vptr;
    void base1_dtor_00048f60();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f4159269

// 0x00057a70 fight::ConditionFactoryCasterTemplate<CCollisionPushbackVelocityCondition>::vfunc_1 (60 B): matches/0x00057a70.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCCollisionPushbackVelocityCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CCollisionPushbackVelocityCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_57a70));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_57a70* t = new (mem) TrackFactoryTemplate_57a70();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000535f0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00057ab0 fight::ConditionFactoryTemplate<CCollisionPushbackVelocityCondition>::vfunc_5 (54 B): matches/0x00057ab0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCCollisionPushbackVelocityCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CCollisionPushbackVelocityCondition>::vfunc_5() {
    CCollisionPushbackVelocityCondition_57ab0* p = (CCollisionPushbackVelocityCondition_57ab0*)FUN_0008d690(0x14);
    if (p) {
        p->Init_00234590(0);
        ((hulk_intptr*)p)[0] = (hulk_intptr)&hulk_at_003f707c;
        p->a = 0;
        p->b = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f4159269 {

// 0x00057af0 fight::ConditionFactoryTemplate<CCollisionPushbackVelocityCondition>::vfunc_2 (43 B): matches/0x00057af0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_57af0@fn_f4159269@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_57af0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f93d8;
    base1_dtor_00048f60();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f4159269
