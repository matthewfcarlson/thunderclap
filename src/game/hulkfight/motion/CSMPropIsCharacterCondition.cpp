// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018bcc0..0x0018bd60 (kind game, layer game, confidence high), dominant class hulkfight::motion::CSMPropIsCharacterCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff307066 {
#define TREE_TU_END }
namespace fn_ff307066 {} using namespace fn_ff307066;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ff307066 {
class TrackFactoryTemplate_18bcc0 {
  public:
    TrackFactoryTemplate_18bcc0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00187da0();
extern "C" void* __cdecl alloc(hulk_uintptr);
extern int hulk_at_004192ac;
class Obj_18bd00 {
  public:
    virtual void* a();
    virtual void* b();
    virtual void* c();
    virtual void* d();
    virtual void* e();
    virtual void* f();
    char x[8];
    char flag;
    void init_00234590(int);
};
extern int hulk_at_0041a780;
struct ConditionFactoryTemplate_18bd30 {
    void* m_vptr;
    void base1_dtor_00180ae0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_ff307066

// 0x0018bcc0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CSMPropIsCharacterCondition>::vfunc_1 (60 B): matches/0x0018bcc0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCSMPropIsCharacterCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CSMPropIsCharacterCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18bcc0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18bcc0* t = new (mem) TrackFactoryTemplate_18bcc0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00187da0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018bd00 fight::ConditionFactoryTemplate<hulkfight::motion::CSMPropIsCharacterCondition>::vfunc_5 (44 B): matches/0x0018bd00.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCSMPropIsCharacterCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CSMPropIsCharacterCondition>::vfunc_5() {
    Obj_18bd00* p = (Obj_18bd00*)alloc(16);
    if (p) {
        p->init_00234590(0);
        *(hulk_intptr*)p = (hulk_intptr)&hulk_at_004192ac;
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_ff307066 {

// 0x0018bd30 fight::ConditionFactoryTemplate<hulkfight::motion::CSMPropIsCharacterCondition>::vfunc_2 (43 B): matches/0x0018bd30.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_18bd30@fn_ff307066@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_18bd30::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a780;
    base1_dtor_00180ae0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ff307066
