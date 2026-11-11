// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00070590..0x00070620 (kind game, layer game, confidence high), dominant class CWeaponCollisionTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f263f977 {
#define TREE_TU_END }
namespace fn_f263f977 {} using namespace fn_f263f977;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f263f977 {
class TrackFactoryTemplate_70590 {
  public:
    TrackFactoryTemplate_70590() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00064a70();
typedef unsigned int u32_705d0;
extern "C" void* __cdecl alloc(hulk_uintptr);
class CWeaponCollisionTrack_705d0 {
  public:
    hulk_uintptr Init();
};
extern int g_vftable_705f0;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f263f977

// 0x00070590 fight::TrackFactoryCasterTemplate<CWeaponCollisionTrack>::vfunc_1 (60 B): matches/0x00070590.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCWeaponCollisionTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CWeaponCollisionTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_70590));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_70590* t = new (mem) TrackFactoryTemplate_70590();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00064a70();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000705d0 fight::TrackFactoryTemplate<CWeaponCollisionTrack>::vfunc_5 (27 B): matches/0x000705d0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCWeaponCollisionTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CWeaponCollisionTrack>::vfunc_5() {
    CWeaponCollisionTrack_705d0* p = (CWeaponCollisionTrack_705d0*)alloc(0x100);
    if (p)
        return (void*)(p->Init());
    return (void*)(0);
}

namespace fn_f263f977 {

// 0x000705f0 fight::TrackFactoryTemplate<CWeaponCollisionTrack>::vfunc_2 (43 B): matches/0x000705f0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f263f977@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_705f0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f263f977
