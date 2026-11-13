// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018ca20..0x0018cab0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropSpawnTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff0b2ada {
#define TREE_TU_END }
namespace fn_ff0b2ada {} using namespace fn_ff0b2ada;
namespace fn_ff0b2ada {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ff0b2ada {
class TrackFactoryTemplate_18ca20 {
  public:
    TrackFactoryTemplate_18ca20() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0018b140();
typedef unsigned int u32_18ca60;
struct CGrabTrack_18ca60 {
    hulk_uintptr init_001815d0();
};
extern "C" void* __cdecl operator_new(unsigned int);
extern int hulk_at_0041a9b0;

} // namespace fn_ff0b2ada

// 0x0018ca20 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSpawnTrack>::vfunc_1 (60 B): matches/0x0018ca20.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VPropSpawnTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSpawnTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18ca20));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_18ca20* t = new (mem) TrackFactoryTemplate_18ca20();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0018b140();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018ca60 fight::TrackFactoryTemplate<hulkfight::motion::PropSpawnTrack>::vfunc_5 (24 B): matches/0x0018ca60.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VPropSpawnTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f3d0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropSpawnTrack>::vfunc_5() {
    CGrabTrack_18ca60* p = (CGrabTrack_18ca60*)operator_new(0x50);
    if (p)
        return (void*)(p->init_001815d0());
    return (void*)(0);
}

namespace fn_ff0b2ada {

// 0x0018ca80 fight::TrackFactoryTemplate<hulkfight::motion::PropSpawnTrack>::vfunc_2 (43 B): matches/0x0018ca80.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_ff0b2ada@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a9b0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_ff0b2ada
