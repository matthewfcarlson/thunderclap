// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017e560..0x0017e610 (kind game, layer game, confidence high), dominant class hulkfight::motion::MomentumXZAddTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ffaa2cfd {
#define TREE_TU_END }
namespace fn_ffaa2cfd {} using namespace fn_ffaa2cfd;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ffaa2cfd {
class TrackFactoryTemplate_17e560 {
  public:
    TrackFactoryTemplate_17e560() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017a340();
extern "C" char DAT_00417ad8[];
class MomentumXZAddTrack_17e5a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    int pad;
    int c;
    int d;
    float x;
    float y;
    void Init_00236d40();
};
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern int hulk_at_00418ea4;

} // namespace fn_ffaa2cfd

// 0x0017e560 fight::TrackFactoryCasterTemplate<hulkfight::motion::MomentumXZAddTrack>::vfunc_1 (60 B): matches/0x0017e560.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VMomentumXZAddTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::MomentumXZAddTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17e560));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17e560* t = new (mem) TrackFactoryTemplate_17e560();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017a340();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017e5a0 fight::TrackFactoryTemplate<hulkfight::motion::MomentumXZAddTrack>::vfunc_5 (63 B): matches/0x0017e5a0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VMomentumXZAddTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::MomentumXZAddTrack>::vfunc_5() {
    MomentumXZAddTrack_17e5a0* p = (MomentumXZAddTrack_17e5a0*)Alloc(0x18);
    if (p) {
        p->Init_00236d40();
        p->x = -1.0f;
        p->y = -1.0f;
        *(volatile hulk_intptr*)p = ((hulk_intptr)DAT_00417ad8);
        p->d = 0;
        p->c = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_ffaa2cfd {

// 0x0017e5e0 fight::TrackFactoryTemplate<hulkfight::motion::MomentumXZAddTrack>::vfunc_2 (43 B): matches/0x0017e5e0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_ffaa2cfd@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00418ea4;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ffaa2cfd
