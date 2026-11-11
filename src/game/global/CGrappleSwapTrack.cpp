// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006f9f0..0x0006fa80 (kind game, layer game, confidence high), dominant class CGrappleSwapTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd4eb0af {
#define TREE_TU_END }
namespace fn_fd4eb0af {} using namespace fn_fd4eb0af;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fd4eb0af {
class TrackFactoryTemplate_6f9f0 {
  public:
    TrackFactoryTemplate_6f9f0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0005cd20();
typedef unsigned int u32_6fa30;
struct Grapple_6fa30 {
    hulk_uintptr BuildTrack_0005ab30();
};
extern int hulk_at_003fd1dc;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0005ab00();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fd4eb0af

// 0x0006f9f0 fight::TrackFactoryCasterTemplate<CGrappleSwapTrack>::vfunc_1 (60 B): matches/0x0006f9f0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleSwapTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleSwapTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6f9f0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_6f9f0* t = new (mem) TrackFactoryTemplate_6f9f0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0005cd20();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006fa30 fight::TrackFactoryTemplate<CGrappleSwapTrack>::vfunc_5 (24 B): matches/0x0006fa30.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleSwapTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CGrappleSwapTrack>::vfunc_5() {
    Grapple_6fa30* p = (Grapple_6fa30*)operator new(0x40);
    if (p)
        return (void*)(p->BuildTrack_0005ab30());
    return (void*)(0);
}

namespace fn_fd4eb0af {

// 0x0006fa50 fight::TrackFactoryTemplate<CGrappleSwapTrack>::vfunc_2 (43 B): matches/0x0006fa50.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fd4eb0af@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd1dc;
    base1_dtor_0005ab00();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fd4eb0af
