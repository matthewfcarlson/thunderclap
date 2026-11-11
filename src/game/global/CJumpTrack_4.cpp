// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076e80..0x00076f10 (kind game, layer game, confidence high), dominant class CJumpTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f96b6f0d {
#define TREE_TU_END }
namespace fn_f96b6f0d {} using namespace fn_f96b6f0d;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f96b6f0d {
class TrackFactoryTemplate_76e80 {
  public:
    TrackFactoryTemplate_76e80() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000706c0();
extern int hulk_at_003fe9dc;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00068f90();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f96b6f0d

// 0x00076e80 fight::TrackFactoryCasterTemplate<CJumpTrack>::vfunc_1 (60 B): matches/0x00076e80.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCJumpTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CJumpTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_76e80));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_76e80* t = new (mem) TrackFactoryTemplate_76e80();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000706c0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00076ec0 fight::TrackFactoryTemplate<CJumpTrack>::vfunc_5 (24 B): matches/0x00076ec0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCJumpTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CJumpTrack>::vfunc_5() {
    Jump* p = (Jump*)alloc_54(0x54);
    if (p)
        return (void*)(p->construct());
    return (void*)(0);
}

namespace fn_f96b6f0d {

// 0x00076ee0 fight::TrackFactoryTemplate<CJumpTrack>::vfunc_2 (43 B): matches/0x00076ee0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f96b6f0d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fe9dc;
    base1_dtor_00068f90();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f96b6f0d
