// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006f420..0x0006f4b0 (kind game, layer game, confidence high), dominant class CGrappleAttachTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fdf74c47 {
#define TREE_TU_END }
namespace fn_fdf74c47 {} using namespace fn_fdf74c47;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fdf74c47 {
class TrackFactoryTemplate_6f420 {
  public:
    TrackFactoryTemplate_6f420() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0005ca20();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Dummy_6f460 {
  public:
    hulk_intptr FUN_0005aa00();
};
extern int hulk_at_003fcff0;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0005a9d0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fdf74c47

// 0x0006f420 fight::TrackFactoryCasterTemplate<CGrappleAttachTrack>::vfunc_1 (60 B): matches/0x0006f420.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleAttachTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleAttachTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6f420));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_6f420* t = new (mem) TrackFactoryTemplate_6f420();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0005ca20();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006f460 fight::TrackFactoryTemplate<CGrappleAttachTrack>::vfunc_5 (24 B): matches/0x0006f460.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleAttachTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CGrappleAttachTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x68);
    if (p)
        return (void*)(((Dummy_6f460*)p)->FUN_0005aa00());
    return (void*)(0);
}

namespace fn_fdf74c47 {

// 0x0006f480 fight::TrackFactoryTemplate<CGrappleAttachTrack>::vfunc_2 (43 B): matches/0x0006f480.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fdf74c47@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fcff0;
    base1_dtor_0005a9d0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fdf74c47
