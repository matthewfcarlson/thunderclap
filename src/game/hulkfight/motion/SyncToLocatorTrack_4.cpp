// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017efd0..0x0017f060 (kind game, layer game, confidence high), dominant class hulkfight::motion::SyncToLocatorTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4961c7e {
#define TREE_TU_END }
namespace fn_f4961c7e {} using namespace fn_f4961c7e;
namespace fn_f4961c7e {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f4961c7e {
class TrackFactoryTemplate_17efd0 {
  public:
    TrackFactoryTemplate_17efd0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017ced0();
typedef unsigned int u32_17f010;
struct CGrabTrack_17f010 {
    hulk_uintptr init_00170080();
};
extern "C" void* __cdecl operator_new(unsigned int);
extern int hulk_at_00419048;

} // namespace fn_f4961c7e

// 0x0017efd0 fight::TrackFactoryCasterTemplate<hulkfight::motion::SyncToLocatorTrack>::vfunc_1 (60 B): matches/0x0017efd0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::SyncToLocatorTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17efd0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_17efd0* t = new (mem) TrackFactoryTemplate_17efd0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017ced0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017f010 fight::TrackFactoryTemplate<hulkfight::motion::SyncToLocatorTrack>::vfunc_5 (24 B): matches/0x0017f010.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f3d0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::SyncToLocatorTrack>::vfunc_5() {
    CGrabTrack_17f010* p = (CGrabTrack_17f010*)operator_new(0x50);
    if (p)
        return (void*)(p->init_00170080());
    return (void*)(0);
}

namespace fn_f4961c7e {

// 0x0017f030 fight::TrackFactoryTemplate<hulkfight::motion::SyncToLocatorTrack>::vfunc_2 (43 B): matches/0x0017f030.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f4961c7e@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00419048;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f4961c7e
