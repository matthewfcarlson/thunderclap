// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006fa80..0x0006fb10 (kind game, layer game, confidence high), dominant class CHeliDeathSpiralTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f834f864 {
#define TREE_TU_END }
namespace fn_f834f864 {} using namespace fn_f834f864;
namespace fn_f834f864 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f834f864 {
class TrackFactoryTemplate_6fa80 {
  public:
    TrackFactoryTemplate_6fa80() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000783a0();
class Track_6fac0 {
  public:
    hulk_intptr method_00078080();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003fd1f8;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00077f10();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f834f864

// 0x0006fa80 fight::TrackFactoryCasterTemplate<CHeliDeathSpiralTrack>::vfunc_1 (60 B): matches/0x0006fa80.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCHeliDeathSpiralTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CHeliDeathSpiralTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6fa80));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_6fa80* t = new (mem) TrackFactoryTemplate_6fa80();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000783a0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006fac0 fight::TrackFactoryTemplate<CHeliDeathSpiralTrack>::vfunc_5 (24 B): matches/0x0006fac0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCHeliDeathSpiralTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CHeliDeathSpiralTrack>::vfunc_5() {
    Track_6fac0* p = (Track_6fac0*)FUN_0008d690(0x38);
    if (p)
        return (void*)(p->method_00078080());
    return (void*)(0);
}

namespace fn_f834f864 {

// 0x0006fae0 fight::TrackFactoryTemplate<CHeliDeathSpiralTrack>::vfunc_2 (43 B): matches/0x0006fae0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f834f864@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd1f8;
    base1_dtor_00077f10();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f834f864
