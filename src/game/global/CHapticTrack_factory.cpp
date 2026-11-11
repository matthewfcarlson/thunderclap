// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006fe40..0x0006fed0 (kind game, layer game, confidence high), dominant class CHapticTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb05d217 {
#define TREE_TU_END }
namespace fn_fb05d217 {} using namespace fn_fb05d217;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fb05d217 {
class TrackFactoryTemplate_6fe40 {
  public:
    TrackFactoryTemplate_6fe40() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0005d370();
typedef unsigned int u32_6fe80;
struct Helper_6fe80 {
    hulk_uintptr run_0005d230();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003fd318;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0005d170();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fb05d217

// 0x0006fe40 fight::TrackFactoryCasterTemplate<CHapticTrack>::vfunc_1 (60 B): matches/0x0006fe40.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCHapticTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CHapticTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6fe40));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_6fe40* t = new (mem) TrackFactoryTemplate_6fe40();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0005d370();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006fe80 fight::TrackFactoryTemplate<CHapticTrack>::vfunc_5 (24 B): matches/0x0006fe80.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCHapticTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f340 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<CHapticTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x20);
    if (p)
        return (void*)(((Helper_6fe80*)p)->run_0005d230());
    return (void*)(0);
}

namespace fn_fb05d217 {

// 0x0006fea0 fight::TrackFactoryTemplate<CHapticTrack>::vfunc_2 (43 B): matches/0x0006fea0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fb05d217@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd318;
    base1_dtor_0005d170();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fb05d217
