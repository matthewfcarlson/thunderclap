// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006f390..0x0006f420 (kind game, layer game, confidence high), dominant class CGrabTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb7fd81f {
#define TREE_TU_END }
namespace fn_fb7fd81f {} using namespace fn_fb7fd81f;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fb7fd81f {
class TrackFactoryTemplate_6f390 {
  public:
    TrackFactoryTemplate_6f390() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0005cf20();
typedef unsigned int u32_6f3d0;
struct CGrabTrack_6f3d0 {
    hulk_uintptr init_0005b0e0();
};
extern int hulk_at_003fcfd4;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0005b0b0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fb7fd81f

// 0x0006f390 fight::TrackFactoryCasterTemplate<CGrabTrack>::vfunc_1 (60 B): matches/0x0006f390.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrabTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrabTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6f390));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_6f390* t = new (mem) TrackFactoryTemplate_6f390();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0005cf20();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006f3d0 fight::TrackFactoryTemplate<CGrabTrack>::vfunc_5 (24 B): matches/0x0006f3d0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrabTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CGrabTrack>::vfunc_5() {
    CGrabTrack_6f3d0* p = (CGrabTrack_6f3d0*)operator_new(0x50);
    if (p)
        return (void*)(p->init_0005b0e0());
    return (void*)(0);
}

namespace fn_fb7fd81f {

// 0x0006f3f0 fight::TrackFactoryTemplate<CGrabTrack>::vfunc_2 (43 B): matches/0x0006f3f0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fb7fd81f@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fcfd4;
    base1_dtor_0005b0b0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fb7fd81f
