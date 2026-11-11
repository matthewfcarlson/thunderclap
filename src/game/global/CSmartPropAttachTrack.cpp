// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006fed0..0x0006ff60 (kind game, layer game, confidence high), dominant class CSmartPropAttachTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbe82a3f {
#define TREE_TU_END }
namespace fn_fbe82a3f {} using namespace fn_fbe82a3f;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fbe82a3f {
class TrackFactoryTemplate_6fed0 {
  public:
    TrackFactoryTemplate_6fed0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00065190();
typedef unsigned int u32_6ff10;
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
struct InitObj_6ff10 {
    hulk_uintptr Init_00062db0();
};
extern int hulk_at_003fd334;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_000621f0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fbe82a3f

// 0x0006fed0 fight::TrackFactoryCasterTemplate<CSmartPropAttachTrack>::vfunc_1 (60 B): matches/0x0006fed0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCSmartPropAttachTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CSmartPropAttachTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6fed0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_6fed0* t = new (mem) TrackFactoryTemplate_6fed0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00065190();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006ff10 fight::TrackFactoryTemplate<CSmartPropAttachTrack>::vfunc_5 (24 B): matches/0x0006ff10.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCSmartPropAttachTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f220 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<CSmartPropAttachTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x60);
    if (p)
        return (void*)(((InitObj_6ff10*)p)->Init_00062db0());
    return (void*)(0);
}

namespace fn_fbe82a3f {

// 0x0006ff30 fight::TrackFactoryTemplate<CSmartPropAttachTrack>::vfunc_2 (43 B): matches/0x0006ff30.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fbe82a3f@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd334;
    base1_dtor_000621f0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fbe82a3f
