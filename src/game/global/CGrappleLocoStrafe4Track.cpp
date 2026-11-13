// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006f6c0..0x0006f750 (kind game, layer game, confidence high), dominant class CGrappleLocoStrafe4Track
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe18d459 {
#define TREE_TU_END }
namespace fn_fe18d459 {} using namespace fn_fe18d459;
namespace fn_fe18d459 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fe18d459 {
class TrackFactoryTemplate_6f6c0 {
  public:
    TrackFactoryTemplate_6f6c0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0005c6b0();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Grapple_6f700 {
    hulk_intptr Build_0005b6f0();
};
extern int hulk_at_003fd0d0;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0005a800();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fe18d459

// 0x0006f6c0 fight::TrackFactoryCasterTemplate<CGrappleLocoStrafe4Track>::vfunc_1 (60 B): matches/0x0006f6c0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleLocoStrafe4Track@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleLocoStrafe4Track>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6f6c0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_6f6c0* t = new (mem) TrackFactoryTemplate_6f6c0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0005c6b0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006f700 fight::TrackFactoryTemplate<CGrappleLocoStrafe4Track>::vfunc_5 (27 B): matches/0x0006f700.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleLocoStrafe4Track@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CGrappleLocoStrafe4Track>::vfunc_5() {
    Grapple_6f700* p = (Grapple_6f700*)FUN_0008d690(0x80);
    if (p)
        return (void*)(p->Build_0005b6f0());
    return (void*)(0);
}

namespace fn_fe18d459 {

// 0x0006f720 fight::TrackFactoryTemplate<CGrappleLocoStrafe4Track>::vfunc_2 (43 B): matches/0x0006f720.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fe18d459@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd0d0;
    base1_dtor_0005a800();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fe18d459
