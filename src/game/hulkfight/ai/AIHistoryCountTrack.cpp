// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00114990..0x00114a30 (kind game, layer game, confidence high), dominant class hulkfight::ai::AIHistoryCountTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f496d4dd {
#define TREE_TU_END }
namespace fn_f496d4dd {} using namespace fn_f496d4dd;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f496d4dd {
class TrackFactoryTemplate_114990 {
  public:
    TrackFactoryTemplate_114990() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00112940();
extern "C" char DAT_0040dbe4[];
extern "C" void* __cdecl Alloc(hulk_uintptr);
class AIHistoryCountTrack_1149d0 {
  public:
    hulk_intptr vptr;
    char pad[8];
    int member;
    AIHistoryCountTrack_1149d0();
};
extern int hulk_at_0040e9bc;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0010d1a0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f496d4dd

// 0x00114990 fight::TrackFactoryCasterTemplate<hulkfight::ai::AIHistoryCountTrack>::vfunc_1 (60 B): matches/0x00114990.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VAIHistoryCountTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::AIHistoryCountTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_114990));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_114990* t = new (mem) TrackFactoryTemplate_114990();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00112940();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001149d0 fight::TrackFactoryTemplate<hulkfight::ai::AIHistoryCountTrack>::vfunc_5 (45 B): matches/0x001149d0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VAIHistoryCountTrack@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::AIHistoryCountTrack>::vfunc_5() {
    AIHistoryCountTrack_1149d0* p = (AIHistoryCountTrack_1149d0*)Alloc(16);
    if (p) {
        p->AIHistoryCountTrack_1149d0::AIHistoryCountTrack_1149d0();
        p->vptr = ((hulk_intptr)DAT_0040dbe4);
        p->member = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f496d4dd {

// 0x00114a00 fight::TrackFactoryTemplate<hulkfight::ai::AIHistoryCountTrack>::vfunc_2 (43 B): matches/0x00114a00.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f496d4dd@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040e9bc;
    base1_dtor_0010d1a0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f496d4dd
