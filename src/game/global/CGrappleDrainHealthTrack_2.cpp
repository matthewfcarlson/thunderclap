// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000766c0..0x00076790 (kind game, layer game, confidence high), dominant class CGrappleDrainHealthTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb1ec90b {
#define TREE_TU_END }
namespace fn_fb1ec90b {} using namespace fn_fb1ec90b;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fb1ec90b {
class TrackFactoryTemplate_766c0 {
  public:
    TrackFactoryTemplate_766c0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003fe75c;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00069e70();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_003fe778[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class CGrappleDrainHealthTrack_76730 {
  public:
    void Init_00069ea0();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
extern void* hulk_at_003f98d0[];
class CDrainHealthTrack_76760 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_fb1ec90b
class CGrappleDrainHealthTrack : public CDrainHealthTrack_76760 {
  public:
    CGrappleDrainHealthTrack* vfunc_5(signed char flags);
};


// 0x000766c0 fight::TrackFactoryCasterTemplate<CGrappleDrainHealthTrack>::vfunc_1 (60 B): matches/0x000766c0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleDrainHealthTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleDrainHealthTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_766c0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_766c0* t = new (mem) TrackFactoryTemplate_766c0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000717e0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fb1ec90b {

// 0x00076700 fight::TrackFactoryTemplate<CGrappleDrainHealthTrack>::vfunc_2 (43 B): matches/0x00076700.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fb1ec90b@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fe75c;
    base1_dtor_00069e70();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fb1ec90b

// 0x00076730 fight::TrackFactoryTemplate<CGrappleDrainHealthTrack>::vfunc_5 (38 B): matches/0x00076730.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleDrainHealthTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CGrappleDrainHealthTrack>::vfunc_5() {
    CGrappleDrainHealthTrack_76730* p = (CGrappleDrainHealthTrack_76730*)FUN_0008d690(0x18);
    if (p) {
        p->Init_00069ea0();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003fe778);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00076760 CGrappleDrainHealthTrack::vfunc_5 (36 B): matches/0x00076760.cpp
// sym: ?vfunc_5@CGrappleDrainHealthTrack@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CGrappleDrainHealthTrack* CGrappleDrainHealthTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f98d0;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

