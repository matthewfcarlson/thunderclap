// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006e840..0x00075ce0 (kind game, layer game, confidence high), merged by D32: global/CJointTrack_params_06e840.cpp
// piece 0x0006fb10..0x0006fbd0 (kind game, layer game, confidence high, dominant class CHitAnimationTrack); was game/global/CHitAnimationTrack.cpp until D46
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc227ff7 {
#define TREE_TU_END }
namespace fn_fc227ff7 {} using namespace fn_fc227ff7;
namespace fn_fc227ff7 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
namespace fn_fc227ff7 { extern "C" char DAT_003fd230[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fc227ff7 {
class TrackFactoryTemplate_6fb10 {
  public:
    TrackFactoryTemplate_6fb10() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003fd214;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0005dc80();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};
struct CHitAnimationTrack_6fb80 {
    unsigned int* vf;
    void init_0005dcb0();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

} // namespace fn_fc227ff7

// 0x0006fb10 fight::TrackFactoryCasterTemplate<CHitAnimationTrack>::vfunc_1 (60 B): matches/0x0006fb10.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCHitAnimationTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CHitAnimationTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6fb10));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_6fb10* t = new (mem) TrackFactoryTemplate_6fb10();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0005fbe0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fc227ff7 {

// 0x0006fb50 fight::TrackFactoryTemplate<CHitAnimationTrack>::vfunc_2 (43 B): matches/0x0006fb50.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fc227ff7@@QAEPAXE@Z
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd214;
    base1_dtor_0005dc80();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fc227ff7

// 0x0006fb80 fight::TrackFactoryTemplate<CHitAnimationTrack>::vfunc_5 (38 B): matches/0x0006fb80.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCHitAnimationTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CHitAnimationTrack>::vfunc_5() {
    CHitAnimationTrack_6fb80* p = (CHitAnimationTrack_6fb80*)FUN_0008d690((int)sizeof(::CHitAnimationTrack));   // (allocsize1) the size by gen's record
    if (p) {
        p->init_0005dcb0();
        p->vf = (unsigned int*)((int*)DAT_003fd230);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x0006fbb0 CHitAnimationTrack::vfunc_5 (30 B): matches/0x0006fbb0.cpp
// sym: ?vfunc_5@CHitAnimationTrack_6fbb0@fn_0006fbb0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `CHitAnimationTrack::~CHitAnimationTrack() {}` stood for it, which natively
// defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's
// body 0x0005dd40, then (flags & 1) operator delete.
namespace fn_0006fbb0 {
struct CHitAnimationTrack_6fbb0 {
    void FUN_0005dd40();   // the destructor's body
    void* vfunc_5(unsigned int flags);
};
void* CHitAnimationTrack_6fbb0::vfunc_5(unsigned int flags) {
    FUN_0005dd40();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_0006fbb0
// (x64t21) the destructor itself, which other objects' code references:
CHitAnimationTrack::~CHitAnimationTrack() {}

