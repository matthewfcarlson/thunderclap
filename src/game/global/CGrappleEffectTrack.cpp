// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006f540..0x0006f600 (kind game, layer game, confidence high), dominant class CGrappleEffectTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f922f661 {
#define TREE_TU_END }
namespace fn_f922f661 {} using namespace fn_f922f661;
namespace fn_f922f661 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f922f661 {
class TrackFactoryTemplate_6f540 {
  public:
    TrackFactoryTemplate_6f540() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003fd028;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00060630();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_003fd044[];
typedef unsigned int u32_6f5b0;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct CGrappleEffectTrack_6f5b0 {
    virtual void a();
    void Init_00060660();
};

} // namespace fn_f922f661

// 0x0006f540 fight::TrackFactoryCasterTemplate<CGrappleEffectTrack>::vfunc_1 (60 B): matches/0x0006f540.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleEffectTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleEffectTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6f540));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_6f540* t = new (mem) TrackFactoryTemplate_6f540();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00061850();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f922f661 {

// 0x0006f580 fight::TrackFactoryTemplate<CGrappleEffectTrack>::vfunc_2 (43 B): matches/0x0006f580.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f922f661@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd028;
    base1_dtor_00060630();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f922f661

// 0x0006f5b0 fight::TrackFactoryTemplate<CGrappleEffectTrack>::vfunc_5 (38 B): matches/0x0006f5b0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleEffectTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CGrappleEffectTrack>::vfunc_5() {
    CGrappleEffectTrack_6f5b0* p = (CGrappleEffectTrack_6f5b0*)FUN_0008d690(0x60);
    if (p != 0) {
        p->Init_00060660();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003fd044);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x0006f5e0 CGrappleEffectTrack::vfunc_5 (30 B): matches/0x0006f5e0.cpp
// sym: ??_GCGrappleEffectTrack@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CGrappleEffectTrack::~CGrappleEffectTrack() {}

