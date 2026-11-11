// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000760f0..0x000761b0 (kind game, layer game, confidence high), dominant class CComboTimerTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8ea40da {
#define TREE_TU_END }
namespace fn_f8ea40da {} using namespace fn_f8ea40da;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f8ea40da {
class TrackFactoryTemplate_760f0 {
  public:
    TrackFactoryTemplate_760f0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000718c0();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class CComboTimerTrack_76130 {
  public:
    CComboTimerTrack_76130();
    int a[6];
};
extern int CComboTimerTrack_vftable;
extern int g_vftable_76180;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f8ea40da

// 0x000760f0 fight::TrackFactoryCasterTemplate<CComboTimerTrack>::vfunc_1 (60 B): matches/0x000760f0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCComboTimerTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CComboTimerTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_760f0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_760f0* t = new (mem) TrackFactoryTemplate_760f0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000718c0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00076130 fight::TrackFactoryTemplate<CComboTimerTrack>::vfunc_5 (66 B): matches/0x00076130.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCComboTimerTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CComboTimerTrack>::vfunc_5() {
    CComboTimerTrack_76130* p = (CComboTimerTrack_76130*)FUN_0008d690((int)sizeof(CComboTimerTrack_76130));
    if (p) {
        p->CComboTimerTrack_76130::CComboTimerTrack_76130();
        *(int**)p = &CComboTimerTrack_vftable;
        p->a[3] = 0;
        p->a[4] = (int)0xbf800000;
        p->a[5] = 0;
        p->a[2] = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f8ea40da {

// 0x00076180 fight::TrackFactoryTemplate<CComboTimerTrack>::vfunc_2 (43 B): matches/0x00076180.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f8ea40da@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_76180;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f8ea40da
