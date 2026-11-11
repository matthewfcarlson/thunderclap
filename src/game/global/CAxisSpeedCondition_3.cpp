// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00057040..0x000570f0 (kind game, layer game, confidence high), dominant class CAxisSpeedCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f38214e1 {
#define TREE_TU_END }
namespace fn_f38214e1 {} using namespace fn_f38214e1;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f38214e1 {
class TrackFactoryTemplate_57040 {
  public:
    TrackFactoryTemplate_57040() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00052b40();
extern "C" void* __cdecl Allocate(unsigned int);
extern "C" int hulk_at_003f6e7c;
class CAxisSpeedCondition_57080 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    int a, b, c, d, e;
    void Initialize_00234590(int);
};
extern int hulk_at_003f9160;
struct ConditionFactoryTemplate_570c0 {
    void* m_vptr;
    void base1_dtor_000486f0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f38214e1

// 0x00057040 fight::ConditionFactoryCasterTemplate<CAxisSpeedCondition>::vfunc_1 (60 B): matches/0x00057040.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCAxisSpeedCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CAxisSpeedCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_57040));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_57040* t = new (mem) TrackFactoryTemplate_57040();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00052b40();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00057080 fight::ConditionFactoryTemplate<CAxisSpeedCondition>::vfunc_5 (61 B): matches/0x00057080.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCAxisSpeedCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CAxisSpeedCondition>::vfunc_5() {
    CAxisSpeedCondition_57080* p = (CAxisSpeedCondition_57080*)Allocate(0x18);
    if (p) {
        p->Initialize_00234590(0);
        p->c = 0;
        *(hulk_intptr*)p = (hulk_intptr)&hulk_at_003f6e7c;
        p->d = 4;
        p->e = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f38214e1 {

// 0x000570c0 fight::ConditionFactoryTemplate<CAxisSpeedCondition>::vfunc_2 (43 B): matches/0x000570c0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_570c0@fn_f38214e1@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_570c0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9160;
    base1_dtor_000486f0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f38214e1
