// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006fbd0..0x0006fc60 (kind game, layer game, confidence high), dominant class CMotionTrailTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff5cc2a1 {
#define TREE_TU_END }
namespace fn_ff5cc2a1 {} using namespace fn_ff5cc2a1;
namespace fn_ff5cc2a1 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ff5cc2a1 {
class TrackFactoryTemplate_6fbd0 {
  public:
    TrackFactoryTemplate_6fbd0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
typedef unsigned int u32_6fc10;
extern "C" void* __cdecl Allocate(unsigned int);
class Created_6fc10 {
  public:
    hulk_uintptr Initialize_00060a00();
};
extern int hulk_at_003fd26c;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00060500();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_ff5cc2a1

// 0x0006fbd0 fight::TrackFactoryCasterTemplate<CMotionTrailTrack>::vfunc_1 (60 B): matches/0x0006fbd0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCMotionTrailTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CMotionTrailTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6fbd0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_6fbd0* t = new (mem) TrackFactoryTemplate_6fbd0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000612e0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006fc10 fight::TrackFactoryTemplate<CMotionTrailTrack>::vfunc_5 (27 B): matches/0x0006fc10.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCMotionTrailTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CMotionTrailTrack>::vfunc_5() {
    Created_6fc10* p = (Created_6fc10*)Allocate(0xd0);
    if (p)
        return (void*)(p->Initialize_00060a00());
    return (void*)(0);
}

namespace fn_ff5cc2a1 {

// 0x0006fc30 fight::TrackFactoryTemplate<CMotionTrailTrack>::vfunc_2 (43 B): matches/0x0006fc30.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_ff5cc2a1@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd26c;
    base1_dtor_00060500();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_ff5cc2a1
