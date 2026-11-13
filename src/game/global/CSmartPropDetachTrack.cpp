// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006ff60..0x0006fff0 (kind game, layer game, confidence high), dominant class CSmartPropDetachTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f506c233 {
#define TREE_TU_END }
namespace fn_f506c233 {} using namespace fn_f506c233;
namespace fn_f506c233 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f506c233 {
class TrackFactoryTemplate_6ff60 {
  public:
    TrackFactoryTemplate_6ff60() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00064280();
struct Allocated_6ffa0 {
    hulk_intptr Finish_00062800();
};
extern "C" void* FUN_0008d690(unsigned int);
extern int hulk_at_003fd350;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_000627d0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f506c233

// 0x0006ff60 fight::TrackFactoryCasterTemplate<CSmartPropDetachTrack>::vfunc_1 (60 B): matches/0x0006ff60.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCSmartPropDetachTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CSmartPropDetachTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6ff60));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_6ff60* t = new (mem) TrackFactoryTemplate_6ff60();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00064280();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006ffa0 fight::TrackFactoryTemplate<CSmartPropDetachTrack>::vfunc_5 (24 B): matches/0x0006ffa0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCSmartPropDetachTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f100 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<CSmartPropDetachTrack>::vfunc_5() {
    Allocated_6ffa0* p = (Allocated_6ffa0*)FUN_0008d690(0x10);
    if (p)
        return (void*)(p->Finish_00062800());
    return (void*)(0);
}

namespace fn_f506c233 {

// 0x0006ffc0 fight::TrackFactoryTemplate<CSmartPropDetachTrack>::vfunc_2 (43 B): matches/0x0006ffc0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f506c233@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd350;
    base1_dtor_000627d0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f506c233
