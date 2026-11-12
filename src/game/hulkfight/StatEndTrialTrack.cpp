// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00132e00..0x00132eb0 (kind game, layer game, confidence high), dominant class hulkfight::StatEndTrialTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd12af91 {
#define TREE_TU_END }
namespace fn_fd12af91 {} using namespace fn_fd12af91;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fd12af91 {
class TrackFactoryTemplate_132e00 {
  public:
    TrackFactoryTemplate_132e00() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00131c90();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern char hulk_at_004113a4[];
class TrackFactory_132e40 {
  public:
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
};
class StatEndTrialTrack_132e40 {
  public:
    int pad[3];
    int a;
    int b;
    StatEndTrialTrack_132e40();
};
extern int hulk_at_00411b38;

} // namespace fn_fd12af91

// 0x00132e00 fight::TrackFactoryCasterTemplate<hulkfight::StatEndTrialTrack>::vfunc_1 (60 B): matches/0x00132e00.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VStatEndTrialTrack@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::StatEndTrialTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_132e00));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_132e00* t = new (mem) TrackFactoryTemplate_132e00();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00131c90();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00132e40 fight::TrackFactoryTemplate<hulkfight::StatEndTrialTrack>::vfunc_5 (52 B): matches/0x00132e40.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VStatEndTrialTrack@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::StatEndTrialTrack>::vfunc_5() {
    StatEndTrialTrack_132e40* p = (StatEndTrialTrack_132e40*)FUN_0008d690((int)sizeof(StatEndTrialTrack_132e40));
    if (p) {
        p->StatEndTrialTrack_132e40::StatEndTrialTrack_132e40();
        *(hulk_intptr*)p = (hulk_intptr)hulk_at_004113a4;
        p->a = 0;
        p->b = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fd12af91 {

// 0x00132e80 fight::TrackFactoryTemplate<hulkfight::StatEndTrialTrack>::vfunc_2 (43 B): matches/0x00132e80.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fd12af91@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00411b38;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fd12af91
