// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000591b0..0x00059260 (kind game, layer game, confidence high), dominant class CSmartPropNameCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f941d5f2 {
#define TREE_TU_END }
namespace fn_f941d5f2 {} using namespace fn_f941d5f2;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f941d5f2 {
class TrackFactoryTemplate_591b0 {
  public:
    TrackFactoryTemplate_591b0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00056620();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Base_591f0 {
  public:
    Base_591f0(int);
    virtual void a();
    virtual void b();
    virtual void c();
    char pad[0x8];
};
class Inner_591f0 {
  public:
    void Init_0027af00();
    int x;
};
class Derived : public Base_591f0 {
  public:
    Derived() : Base_591f0(0) {
        m0 = 0;
        m1 = -1;
        ((Inner_591f0*)((char*)this + 0x18))->Init_0027af00();
    }
    virtual void a();
    virtual void b();
    virtual void c();
    int m0;
    int m1;
    char pad2[4];
};
extern int hulk_at_003f980c;
struct ConditionFactoryTemplate_59230 {
    void* m_vptr;
    void base1_dtor_00049550();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f941d5f2

// 0x000591b0 fight::ConditionFactoryCasterTemplate<CSmartPropNameCondition>::vfunc_1 (60 B): matches/0x000591b0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCSmartPropNameCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CSmartPropNameCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_591b0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_591b0* t = new (mem) TrackFactoryTemplate_591b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00056620();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000591f0 fight::ConditionFactoryTemplate<CSmartPropNameCondition>::vfunc_5 (62 B): matches/0x000591f0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCSmartPropNameCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CSmartPropNameCondition>::vfunc_5() {
    Derived* p = (Derived*)FUN_0008d690(0x20);
    if (p) {
        p->Derived::Derived();
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f941d5f2 {

// 0x00059230 fight::ConditionFactoryTemplate<CSmartPropNameCondition>::vfunc_2 (43 B): matches/0x00059230.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_59230@fn_f941d5f2@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_59230::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f980c;
    base1_dtor_00049550();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f941d5f2
