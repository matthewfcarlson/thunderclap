// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001593b0..0x00159450 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitPushbackCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb077a52 {
#define TREE_TU_END }
namespace fn_fb077a52 {} using namespace fn_fb077a52;
namespace fn_fb077a52 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fb077a52 {
class TrackFactoryTemplate_1593b0 {
  public:
    TrackFactoryTemplate_1593b0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00155500();
class HitPushbackCondition_1593f0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    int pad[2];
    unsigned char flag;
    void Init_00234590(int);
};
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern int hulk_at_00414050;
extern int hulk_at_004155e0;
struct ConditionFactoryTemplate_159420 {
    void* m_vptr;
    void base1_dtor_0014d540();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fb077a52

// 0x001593b0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackCondition>::vfunc_1 (60 B): matches/0x001593b0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VHitPushbackCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1593b0));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_1593b0* t = new (mem) TrackFactoryTemplate_1593b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00155500();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001593f0 fight::ConditionFactoryTemplate<hulkfight::motion::HitPushbackCondition>::vfunc_5 (44 B): matches/0x001593f0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VHitPushbackCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::HitPushbackCondition>::vfunc_5() {
    HitPushbackCondition_1593f0* p = (HitPushbackCondition_1593f0*)Alloc(0x10);
    if (p) {
        p->Init_00234590(0);
        *(hulk_intptr*)p = (hulk_intptr)&hulk_at_00414050;
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fb077a52 {

// 0x00159420 fight::ConditionFactoryTemplate<hulkfight::motion::HitPushbackCondition>::vfunc_2 (43 B): matches/0x00159420.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_159420@fn_fb077a52@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_159420::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004155e0;
    base1_dtor_0014d540();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fb077a52
