// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001148d0..0x00114990 (kind game, layer game, confidence high), dominant class hulkfight::ai::TokenSupressTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f25bec20 {
#define TREE_TU_END }
namespace fn_f25bec20 {} using namespace fn_f25bec20;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f25bec20 {
class TrackFactoryTemplate_1148d0 {
  public:
    TrackFactoryTemplate_1148d0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001127d0();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
} // namespace fn_f25bec20
namespace hulkfight { namespace ai {
struct TokenSupressTrack_114910 {
    virtual void vfunc_0();
    char pad4[4];
    int count;
    int valueC;
    float value10;
    unsigned char active;
    char pad15[3];
    float value18;
    unsigned char flag1c;
    unsigned char flag1d;
    char pad1e[2];
    void FUN_00236d40();
};
} }
namespace fn_f25bec20 {
extern int g_vftable_114960;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f25bec20

// 0x001148d0 fight::TrackFactoryCasterTemplate<hulkfight::ai::TokenSupressTrack>::vfunc_1 (60 B): matches/0x001148d0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VTokenSupressTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::TokenSupressTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1148d0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1148d0* t = new (mem) TrackFactoryTemplate_1148d0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001127d0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00114910 fight::TrackFactoryTemplate<hulkfight::ai::TokenSupressTrack>::vfunc_5 (75 B): equivalent/0x00114910.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VTokenSupressTrack@ai@hulkfight@@@fight@@UAEPAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 19941 inputs, branch coverage 2/2)
// fight::TrackFactoryTemplate<hulkfight::ai::TokenSupressTrack>::vfunc_5 @ 0x00114910
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::TokenSupressTrack>::vfunc_5() {
    hulkfight::ai::TokenSupressTrack_114910* track = (hulkfight::ai::TokenSupressTrack_114910*)FUN_0008d690((int)sizeof(hulkfight::ai::TokenSupressTrack_114910));
    if (track) {
        track->FUN_00236d40();
        new(track) hulkfight::ai::TokenSupressTrack_114910;
        track->active = 1;
        track->count = 1;
        track->valueC = 0;
        track->value10 = -1.0f;
        track->value18 = -1.0f;
        track->flag1c = 0;
        track->flag1d = 0;
    }
    return (void*)(track);
}

namespace fn_f25bec20 {

// 0x00114960 fight::TrackFactoryTemplate<hulkfight::ai::TokenSupressTrack>::vfunc_2 (43 B): matches/0x00114960.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f25bec20@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_114960;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f25bec20
