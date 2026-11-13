// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017e3e0..0x0017e4a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::DriftToHulkTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff877770 {
#define TREE_TU_END }
namespace fn_ff877770 {} using namespace fn_ff877770;
namespace fn_ff877770 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ff877770 {
class TrackFactoryTemplate_17e3e0 {
  public:
    TrackFactoryTemplate_17e3e0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017a180();
extern "C" char DAT_00417a78[];
class DriftTrack {
  public:
    volatile int a[8];
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class InitObj_17e420 {
  public:
    void Init_00236d40();
};
extern int hulk_at_00418e6c;

} // namespace fn_ff877770

// 0x0017e3e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::DriftToHulkTrack>::vfunc_1 (60 B): matches/0x0017e3e0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VDriftToHulkTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::DriftToHulkTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17e3e0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_17e3e0* t = new (mem) TrackFactoryTemplate_17e3e0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017a180();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017e420 fight::TrackFactoryTemplate<hulkfight::motion::DriftToHulkTrack>::vfunc_5 (69 B): matches/0x0017e420.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VDriftToHulkTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::DriftToHulkTrack>::vfunc_5() {
    DriftTrack* p = (DriftTrack*)FUN_0008d690((int)sizeof(DriftTrack));
    if (p) {
        ((InitObj_17e420*)p)->Init_00236d40();
        p->a[3] = 0;
        p->a[0] = ((hulk_intptr)DAT_00417a78);
        p->a[4] = (int)0xbf800000;
        p->a[5] = 0;
        p->a[6] = 0;
        p->a[7] = 0;
        p->a[2] = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_ff877770 {

// 0x0017e470 fight::TrackFactoryTemplate<hulkfight::motion::DriftToHulkTrack>::vfunc_2 (43 B): matches/0x0017e470.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_ff877770@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00418e6c;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_ff877770
