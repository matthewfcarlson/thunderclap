// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000571c0..0x00057290 (kind game, layer game, confidence high), dominant class CButtonDownCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f35c6cc2 {
#define TREE_TU_END }
namespace fn_f35c6cc2 {} using namespace fn_f35c6cc2;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f35c6cc2 {
class TrackFactoryTemplate_571c0 {
  public:
    TrackFactoryTemplate_571c0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003f91c8;
struct ConditionFactoryTemplate_57200 {
    void* m_vptr;
    void base1_dtor_000484f0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class CButtonDownCondition_57230 {
  public:
    CButtonDownCondition_57230();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003f91e4;
extern void* hulk_at_003f6d50[];
class CButtonValueCondition_57260 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f35c6cc2
class CButtonDownCondition : public CButtonValueCondition_57260 {
  public:
    CButtonDownCondition* vfunc_5(signed char flags);
};


// 0x000571c0 fight::ConditionFactoryCasterTemplate<CButtonDownCondition>::vfunc_1 (60 B): matches/0x000571c0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCButtonDownCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CButtonDownCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_571c0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_571c0* t = new (mem) TrackFactoryTemplate_571c0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000528d0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f35c6cc2 {

// 0x00057200 fight::ConditionFactoryTemplate<CButtonDownCondition>::vfunc_2 (43 B): matches/0x00057200.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_57200@fn_f35c6cc2@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_57200::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f91c8;
    base1_dtor_000484f0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f35c6cc2

// 0x00057230 fight::ConditionFactoryTemplate<CButtonDownCondition>::vfunc_5 (38 B): matches/0x00057230.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCButtonDownCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CButtonDownCondition>::vfunc_5() {
    CButtonDownCondition_57230* p = (CButtonDownCondition_57230*)FUN_0008d690(0x20);
    if (p) {
        p->CButtonDownCondition_57230::CButtonDownCondition_57230();
        *(hulk_intptr*)p = (hulk_intptr)&hulk_at_003f91e4;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00057260 CButtonDownCondition::vfunc_5 (36 B): matches/0x00057260.cpp
// sym: ?vfunc_5@CButtonDownCondition@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CButtonDownCondition* CButtonDownCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

