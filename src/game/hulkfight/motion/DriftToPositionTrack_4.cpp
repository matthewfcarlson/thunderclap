// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017e310..0x0017e3e0 (kind game, layer game, confidence high), dominant class hulkfight::motion::DriftToPositionTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6d45618 {
#define TREE_TU_END }
namespace fn_f6d45618 {} using namespace fn_f6d45618;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f6d45618 {
class TrackFactoryTemplate_17e310 {
  public:
    TrackFactoryTemplate_17e310() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00179fe0();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct DriftToPositionTrack_17e350 {
    virtual hulk_intptr vfunc_0_001703f0(int);
    char pad04[4];
    int count;
    int field0c;
    float field10;
    unsigned char field14;
    char pad15[3];
    int field18;
    int field1c;
    int field20;
    unsigned char field24;
    unsigned char field25;
    char pad26[2];
    int field28;
    void FUN_00236d40();
};
extern int hulk_at_00418e50;

} // namespace fn_f6d45618

// 0x0017e310 fight::TrackFactoryCasterTemplate<hulkfight::motion::DriftToPositionTrack>::vfunc_1 (60 B): matches/0x0017e310.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::DriftToPositionTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17e310));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17e310* t = new (mem) TrackFactoryTemplate_17e310();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00179fe0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017e350 fight::TrackFactoryTemplate<hulkfight::motion::DriftToPositionTrack>::vfunc_5 (82 B): equivalent/0x0017e350.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAEPAXXZ @2015bdd55785 @w1ed29ddce8af
// STATUS: equivalent (tools/equiv.py level 3: 19942 inputs, branch coverage 2/2)
// fight::TrackFactoryTemplate<hulkfight::motion::DriftToPositionTrack>::vfunc_5 @ 0x0017e350
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::DriftToPositionTrack>::vfunc_5() {
    DriftToPositionTrack_17e350* track = (DriftToPositionTrack_17e350*)FUN_0008d690((int)sizeof(DriftToPositionTrack_17e350));
    if (track) {
        track->FUN_00236d40();
        new(track) DriftToPositionTrack_17e350;
        track->field0c = 0;
        track->field14 = 0;
        track->field10 = -1.0f;
        track->field18 = 0;
        track->field1c = 0;
        track->field20 = 0;
        track->field24 = 1;
        track->count = 1;
        track->field25 = 0;
        track->field28 = 0;
    }
    return (void*)(track);
}

namespace fn_f6d45618 {

// 0x0017e3b0 fight::TrackFactoryTemplate<hulkfight::motion::DriftToPositionTrack>::vfunc_2 (43 B): matches/0x0017e3b0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f6d45618@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00418e50;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f6d45618
