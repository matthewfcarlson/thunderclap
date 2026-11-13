// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00139940..0x001399d0 (kind game, layer game, confidence high), dominant class hulkfight::motion::FlyingAttackTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe990455 {
#define TREE_TU_END }
namespace fn_fe990455 {} using namespace fn_fe990455;
namespace fn_fe990455 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fe990455 {
class TrackFactoryTemplate_139940 {
  public:
    TrackFactoryTemplate_139940() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00138910();
typedef unsigned int u32_139980;
struct Grapple_139980 {
    hulk_uintptr BuildTrack_00133ef0();
};
extern int hulk_at_0041233c;

} // namespace fn_fe990455

// 0x00139940 fight::TrackFactoryCasterTemplate<hulkfight::motion::FlyingAttackTrack>::vfunc_1 (60 B): matches/0x00139940.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VFlyingAttackTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::FlyingAttackTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_139940));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_139940* t = new (mem) TrackFactoryTemplate_139940();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00138910();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00139980 fight::TrackFactoryTemplate<hulkfight::motion::FlyingAttackTrack>::vfunc_5 (24 B): matches/0x00139980.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VFlyingAttackTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006fa30 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::FlyingAttackTrack>::vfunc_5() {
    Grapple_139980* p = (Grapple_139980*)operator new(0x40);
    if (p)
        return (void*)(p->BuildTrack_00133ef0());
    return (void*)(0);
}

namespace fn_fe990455 {

// 0x001399a0 fight::TrackFactoryTemplate<hulkfight::motion::FlyingAttackTrack>::vfunc_2 (43 B): matches/0x001399a0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fe990455@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041233c;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fe990455
