// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076520..0x000765f0 (kind game, layer game, confidence high), dominant class CGrappleAutoTargetTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f05850fe {
#define TREE_TU_END }
namespace fn_f05850fe {} using namespace fn_f05850fe;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f05850fe {
class TrackFactoryTemplate_76520 {
  public:
    TrackFactoryTemplate_76520() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003fe6ac;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00069c20();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_003fe6c8[];
typedef unsigned int u32_76590;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Track_76590 {
  public:
    void Init_00069c50();
};
extern void* hulk_at_003f98d0[];
class CAutoTargetTrack_765c0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f05850fe
class CGrappleAutoTargetTrack : public CAutoTargetTrack_765c0 {
  public:
    CGrappleAutoTargetTrack* vfunc_5(signed char flags);
};


// 0x00076520 fight::TrackFactoryCasterTemplate<CGrappleAutoTargetTrack>::vfunc_1 (60 B): matches/0x00076520.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleAutoTargetTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleAutoTargetTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_76520));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_76520* t = new (mem) TrackFactoryTemplate_76520();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00071430();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f05850fe {

// 0x00076560 fight::TrackFactoryTemplate<CGrappleAutoTargetTrack>::vfunc_2 (43 B): matches/0x00076560.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f05850fe@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fe6ac;
    base1_dtor_00069c20();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f05850fe

// 0x00076590 fight::TrackFactoryTemplate<CGrappleAutoTargetTrack>::vfunc_5 (38 B): matches/0x00076590.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleAutoTargetTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CGrappleAutoTargetTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x3c);
    if (p) {
        ((Track_76590*)p)->Init_00069c50();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003fe6c8);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x000765c0 CGrappleAutoTargetTrack::vfunc_5 (36 B): matches/0x000765c0.cpp
// sym: ?vfunc_5@CGrappleAutoTargetTrack@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CGrappleAutoTargetTrack* CGrappleAutoTargetTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f98d0;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

