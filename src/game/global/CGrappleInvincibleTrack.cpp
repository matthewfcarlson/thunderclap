// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076860..0x00076930 (kind game, layer game, confidence high), dominant class CGrappleInvincibleTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fcb7e3d9 {
#define TREE_TU_END }
namespace fn_fcb7e3d9 {} using namespace fn_fcb7e3d9;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fcb7e3d9 {
class TrackFactoryTemplate_76860 {
  public:
    TrackFactoryTemplate_76860() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003fe80c;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006a040();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_003fe828[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class CGrappleInvincibleTrack_768d0 {
  public:
    void Init_0006a070();
};
extern void* hulk_at_003f98d0[];
class CInvincibleTrack_76900 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_fcb7e3d9
class CGrappleInvincibleTrack : public CInvincibleTrack_76900 {
  public:
    CGrappleInvincibleTrack* vfunc_5(signed char flags);
};


// 0x00076860 fight::TrackFactoryCasterTemplate<CGrappleInvincibleTrack>::vfunc_1 (60 B): matches/0x00076860.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleInvincibleTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleInvincibleTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_76860));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_76860* t = new (mem) TrackFactoryTemplate_76860();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000719a0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fcb7e3d9 {

// 0x000768a0 fight::TrackFactoryTemplate<CGrappleInvincibleTrack>::vfunc_2 (43 B): matches/0x000768a0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fcb7e3d9@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fe80c;
    base1_dtor_0006a040();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fcb7e3d9

// 0x000768d0 fight::TrackFactoryTemplate<CGrappleInvincibleTrack>::vfunc_5 (38 B): matches/0x000768d0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleInvincibleTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CGrappleInvincibleTrack>::vfunc_5() {
    CGrappleInvincibleTrack_768d0* p = (CGrappleInvincibleTrack_768d0*)FUN_0008d690(0x18);
    if (p) {
        p->Init_0006a070();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_003fe828);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00076900 CGrappleInvincibleTrack::vfunc_5 (36 B): matches/0x00076900.cpp
// sym: ?vfunc_5@CGrappleInvincibleTrack@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CGrappleInvincibleTrack* CGrappleInvincibleTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f98d0;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

