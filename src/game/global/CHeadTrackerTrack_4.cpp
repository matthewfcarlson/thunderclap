// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00077ba0..0x00077c30 (kind game, layer game, confidence high), dominant class CHeadTrackerTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff9c64fd {
#define TREE_TU_END }
namespace fn_ff9c64fd {} using namespace fn_ff9c64fd;
namespace fn_ff9c64fd {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ff9c64fd {
class TrackFactoryTemplate_77ba0 {
  public:
    TrackFactoryTemplate_77ba0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00075810();
typedef unsigned int u32_77be0;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct InitObj_77be0 {
    hulk_uintptr Init_0006ac20();
};
extern int hulk_at_003fec4c;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006abf0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_ff9c64fd

// 0x00077ba0 fight::TrackFactoryCasterTemplate<CHeadTrackerTrack>::vfunc_1 (60 B): matches/0x00077ba0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCHeadTrackerTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CHeadTrackerTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_77ba0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_77ba0* t = new (mem) TrackFactoryTemplate_77ba0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00075810();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00077be0 fight::TrackFactoryTemplate<CHeadTrackerTrack>::vfunc_5 (24 B): matches/0x00077be0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCHeadTrackerTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f220 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<CHeadTrackerTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x60);
    if (p)
        return (void*)(((InitObj_77be0*)p)->Init_0006ac20());
    return (void*)(0);
}

namespace fn_ff9c64fd {

// 0x00077c00 fight::TrackFactoryTemplate<CHeadTrackerTrack>::vfunc_2 (43 B): matches/0x00077c00.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_ff9c64fd@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fec4c;
    base1_dtor_0006abf0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_ff9c64fd
