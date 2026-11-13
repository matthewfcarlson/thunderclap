// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006f8a0..0x0006f930 (kind game, layer game, confidence high), dominant class CGrappleSequenceTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f23caa2f {
#define TREE_TU_END }
namespace fn_f23caa2f {} using namespace fn_f23caa2f;
namespace fn_f23caa2f {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f23caa2f {
class TrackFactoryTemplate_6f8a0 {
  public:
    TrackFactoryTemplate_6f8a0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0005c490();
typedef unsigned int u32_6f8e0;
struct Helper_6f8e0 {
    hulk_uintptr run_0005af30();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003fd160;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0005af00();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f23caa2f

// 0x0006f8a0 fight::TrackFactoryCasterTemplate<CGrappleSequenceTrack>::vfunc_1 (60 B): matches/0x0006f8a0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleSequenceTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleSequenceTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6f8a0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_6f8a0* t = new (mem) TrackFactoryTemplate_6f8a0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0005c490();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006f8e0 fight::TrackFactoryTemplate<CGrappleSequenceTrack>::vfunc_5 (24 B): matches/0x0006f8e0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleSequenceTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f340 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<CGrappleSequenceTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x20);
    if (p)
        return (void*)(((Helper_6f8e0*)p)->run_0005af30());
    return (void*)(0);
}

namespace fn_f23caa2f {

// 0x0006f900 fight::TrackFactoryTemplate<CGrappleSequenceTrack>::vfunc_2 (43 B): matches/0x0006f900.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f23caa2f@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd160;
    base1_dtor_0005af00();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f23caa2f
