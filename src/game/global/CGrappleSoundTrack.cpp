// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076a00..0x00076ad0 (kind game, layer game, confidence high), dominant class CGrappleSoundTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f15fc4c0 {
#define TREE_TU_END }
namespace fn_f15fc4c0 {} using namespace fn_f15fc4c0;
namespace fn_f15fc4c0 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f15fc4c0 {
class TrackFactoryTemplate_76a00 {
  public:
    TrackFactoryTemplate_76a00() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003fe8bc;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00069690();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_003fe8d8[];
typedef unsigned int u32_76a70;
extern "C" void* FUN_0008d690(unsigned int);
struct Track_76a70 {
    void Init_000696c0();
};
extern void* hulk_at_003f98d0[];
class CSoundTrack_76aa0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f15fc4c0
class CGrappleSoundTrack : public CSoundTrack_76aa0 {
  public:
    CGrappleSoundTrack* vfunc_5(signed char flags);
};


// 0x00076a00 fight::TrackFactoryCasterTemplate<CGrappleSoundTrack>::vfunc_1 (60 B): matches/0x00076a00.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleSoundTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleSoundTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_76a00));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_76a00* t = new (mem) TrackFactoryTemplate_76a00();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00070d50();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f15fc4c0 {

// 0x00076a40 fight::TrackFactoryTemplate<CGrappleSoundTrack>::vfunc_2 (43 B): matches/0x00076a40.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f15fc4c0@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fe8bc;
    base1_dtor_00069690();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f15fc4c0

// 0x00076a70 fight::TrackFactoryTemplate<CGrappleSoundTrack>::vfunc_5 (38 B): matches/0x00076a70.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleSoundTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CGrappleSoundTrack>::vfunc_5() {
    Track_76a70* p = (Track_76a70*)FUN_0008d690(0x54);
    if (p != 0) {
        p->Init_000696c0();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003fe8d8);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00076aa0 CGrappleSoundTrack::vfunc_5 (36 B): matches/0x00076aa0.cpp
// sym: ?vfunc_5@CGrappleSoundTrack@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CGrappleSoundTrack* CGrappleSoundTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f98d0;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

