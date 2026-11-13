// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00070080..0x00070110 (kind game, layer game, confidence high), dominant class CSmartPropEventTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3ae5866 {
#define TREE_TU_END }
namespace fn_f3ae5866 {} using namespace fn_f3ae5866;
namespace fn_f3ae5866 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f3ae5866 {
class TrackFactoryTemplate_70080 {
  public:
    TrackFactoryTemplate_70080() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00064660();
class Effect_700c0 {
  public:
    hulk_intptr Init_00062b50();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003fd388;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00062b20();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f3ae5866

// 0x00070080 fight::TrackFactoryCasterTemplate<CSmartPropEventTrack>::vfunc_1 (60 B): matches/0x00070080.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCSmartPropEventTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CSmartPropEventTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_70080));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_70080* t = new (mem) TrackFactoryTemplate_70080();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00064660();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000700c0 fight::TrackFactoryTemplate<CSmartPropEventTrack>::vfunc_5 (24 B): matches/0x000700c0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCSmartPropEventTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f2b0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<CSmartPropEventTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x18);
    if (p)
        return (void*)(((Effect_700c0*)p)->Init_00062b50());
    return (void*)(0);
}

namespace fn_f3ae5866 {

// 0x000700e0 fight::TrackFactoryTemplate<CSmartPropEventTrack>::vfunc_2 (43 B): matches/0x000700e0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f3ae5866@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd388;
    base1_dtor_00062b20();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f3ae5866
