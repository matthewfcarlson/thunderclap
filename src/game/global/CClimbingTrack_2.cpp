// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00075f90..0x00076040 (kind game, layer game, confidence high), dominant class CClimbingTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f674bded {
#define TREE_TU_END }
namespace fn_f674bded {} using namespace fn_f674bded;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f674bded {
class TrackFactoryTemplate_75f90 {
  public:
    TrackFactoryTemplate_75f90() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00070620();
extern "C" char DAT_003fba38[];
extern "C" void* __cdecl Allocate(unsigned int);
class Init_75fd0 {
  public:
    void InitFn_00236d40();
};
extern int hulk_at_003fe5cc;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00068ed0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f674bded

// 0x00075f90 fight::TrackFactoryCasterTemplate<CClimbingTrack>::vfunc_1 (60 B): matches/0x00075f90.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCClimbingTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CClimbingTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_75f90));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_75f90* t = new (mem) TrackFactoryTemplate_75f90();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00070620();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00075fd0 fight::TrackFactoryTemplate<CClimbingTrack>::vfunc_5 (59 B): matches/0x00075fd0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCClimbingTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CClimbingTrack>::vfunc_5() {
    void* p = Allocate(0x14);
    if (p) {
        ((Init_75fd0*)p)->InitFn_00236d40();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003fba38);
        *(unsigned int*)((char*)p + 0xc) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0xbf800000;
        *(unsigned int*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f674bded {

// 0x00076010 fight::TrackFactoryTemplate<CClimbingTrack>::vfunc_2 (43 B): matches/0x00076010.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f674bded@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fe5cc;
    base1_dtor_00068ed0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f674bded
