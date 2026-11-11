// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015a230..0x0015a2e0 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitDamageTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f59a8991 {
#define TREE_TU_END }
namespace fn_f59a8991 {} using namespace fn_f59a8991;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f59a8991 {
class TrackFactoryTemplate_15a230 {
  public:
    TrackFactoryTemplate_15a230() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00156660();
extern "C" char DAT_00414450[];
class HitDamageTrack_15a270 {
  public:
    virtual void f0();
    char pad[8];
    int x;
    float y;
    void init();
};
extern int g_vftable_15a2b0;

} // namespace fn_f59a8991

// 0x0015a230 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitDamageTrack>::vfunc_1 (60 B): matches/0x0015a230.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VHitDamageTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::HitDamageTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_15a230));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_15a230* t = new (mem) TrackFactoryTemplate_15a230();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00156660();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0015a270 fight::TrackFactoryTemplate<hulkfight::motion::HitDamageTrack>::vfunc_5 (52 B): matches/0x0015a270.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VHitDamageTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitDamageTrack>::vfunc_5() {
    HitDamageTrack_15a270* p = (HitDamageTrack_15a270*)operator new(sizeof(HitDamageTrack_15a270));
    if (p) {
        p->init();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00414450);
        p->x = 0;
        p->y = 1.0f;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f59a8991 {

// 0x0015a2b0 fight::TrackFactoryTemplate<hulkfight::motion::HitDamageTrack>::vfunc_2 (43 B): matches/0x0015a2b0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f59a8991@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_15a2b0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f59a8991
