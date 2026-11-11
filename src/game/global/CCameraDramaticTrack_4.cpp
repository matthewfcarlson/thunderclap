// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00077a50..0x00077ae0 (kind game, layer game, confidence high), dominant class CCameraDramaticTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f22fcc84 {
#define TREE_TU_END }
namespace fn_f22fcc84 {} using namespace fn_f22fcc84;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f22fcc84 {
class TrackFactoryTemplate_77a50 {
  public:
    TrackFactoryTemplate_77a50() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00075230();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003febd8;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006a370();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f22fcc84

// 0x00077a50 fight::TrackFactoryCasterTemplate<CCameraDramaticTrack>::vfunc_1 (60 B): matches/0x00077a50.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCCameraDramaticTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CCameraDramaticTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_77a50));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_77a50* t = new (mem) TrackFactoryTemplate_77a50();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00075230();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00077a90 fight::TrackFactoryTemplate<CCameraDramaticTrack>::vfunc_5 (27 B): matches/0x00077a90.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCCameraDramaticTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CCameraDramaticTrack>::vfunc_5() {
    void* p = FUN_0008d690(0xa0);
    if (p)
        return (void*)(construct_camera(p));
    return (void*)(0);
}

namespace fn_f22fcc84 {

// 0x00077ab0 fight::TrackFactoryTemplate<CCameraDramaticTrack>::vfunc_2 (43 B): matches/0x00077ab0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f22fcc84@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003febd8;
    base1_dtor_0006a370();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f22fcc84
