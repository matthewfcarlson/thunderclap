// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00070080..0x00070110 (kind game, layer game, confidence high), dominant class CSmartPropEventTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3ae5866 {
#define TREE_TU_END }
namespace fn_f3ae5866 {} using namespace fn_f3ae5866;
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
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00064660();
class Effect_700c0 {
  public:
    hulk_intptr Init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int g_vftable_700e0;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f3ae5866

// 0x00070080 fight::TrackFactoryCasterTemplate<CSmartPropEventTrack>::vfunc_1 (60 B): matches/0x00070080.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCSmartPropEventTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CSmartPropEventTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_70080));
    if (mem) {
        ((InitHelper*)mem)->init();
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
        return (void*)(((Effect_700c0*)p)->Init());
    return (void*)(0);
}

namespace fn_f3ae5866 {

// 0x000700e0 fight::TrackFactoryTemplate<CSmartPropEventTrack>::vfunc_2 (43 B): matches/0x000700e0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f3ae5866@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_700e0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f3ae5866
