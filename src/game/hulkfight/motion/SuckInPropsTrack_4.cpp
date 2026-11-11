// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017e980..0x0017ea40 (kind game, layer game, confidence high), dominant class hulkfight::motion::SuckInPropsTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f047e9f1 {
#define TREE_TU_END }
namespace fn_f047e9f1 {} using namespace fn_f047e9f1;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f047e9f1 {
class TrackFactoryTemplate_17e980 {
  public:
    TrackFactoryTemplate_17e980() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017aa40();
extern "C" char DAT_00417c58[];
extern "C" void* __cdecl alloc(hulk_uintptr);
class S_17e9c0 {
  public:
    void Init_00236d40();
    hulk_intptr vp;
    int unk4;
    int unk8;
    int f0c;
    float f10;
    float f14;
    float f18;
    float f1c;
};
extern int hulk_at_00418f4c;

} // namespace fn_f047e9f1

// 0x0017e980 fight::TrackFactoryCasterTemplate<hulkfight::motion::SuckInPropsTrack>::vfunc_1 (60 B): matches/0x0017e980.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VSuckInPropsTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::SuckInPropsTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17e980));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17e980* t = new (mem) TrackFactoryTemplate_17e980();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017aa40();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f047e9f1 {

// 0x0017e9c0 fight::TrackFactoryTemplate<hulkfight::motion::SuckInPropsTrack>::vfunc_5 (80 B): matches/0x0017e9c0.cpp
// sym: ?target@fn_f047e9f1@@YAPAVS_17e9c0@1@XZ
S_17e9c0* __cdecl target() {
    S_17e9c0* p = (S_17e9c0*)alloc(0x20);
    if (p) {
        p->Init_00236d40();
        p->vp = ((hulk_intptr)DAT_00417c58);
        p->f0c = 0;
        p->f10 = -1.0f;
        p->f14 = 0.0f;
        p->f18 = 0.0f;
        p->f1c = 20.0f;
        p->unk8 = 1;
        return p;
    }
    return 0;
}


// 0x0017ea10 fight::TrackFactoryTemplate<hulkfight::motion::SuckInPropsTrack>::vfunc_2 (43 B): matches/0x0017ea10.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f047e9f1@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00418f4c;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f047e9f1
