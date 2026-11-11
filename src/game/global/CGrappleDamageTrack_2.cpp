// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000765f0..0x000766c0 (kind game, layer game, confidence high), dominant class CGrappleDamageTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f40a0ef6 {
#define TREE_TU_END }
namespace fn_f40a0ef6 {} using namespace fn_f40a0ef6;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f40a0ef6 {
class TrackFactoryTemplate_765f0 {
  public:
    TrackFactoryTemplate_765f0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int g_vftable_76630;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
extern "C" void* __cdecl FUN_0008d690(int);
extern void* GrappleVftable;
class CGrappleDamageTrack_76660 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    CGrappleDamageTrack_76660();
};
extern void* CDamageTrack_76690_vftable[];
class CDamageTrack_76690 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f40a0ef6
class CGrappleDamageTrack : public CDamageTrack_76690 {
  public:
    CGrappleDamageTrack* vfunc_5(signed char flags);
};


// 0x000765f0 fight::TrackFactoryCasterTemplate<CGrappleDamageTrack>::vfunc_1 (60 B): matches/0x000765f0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleDamageTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleDamageTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_765f0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_765f0* t = new (mem) TrackFactoryTemplate_765f0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00071700();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f40a0ef6 {

// 0x00076630 fight::TrackFactoryTemplate<CGrappleDamageTrack>::vfunc_2 (43 B): matches/0x00076630.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f40a0ef6@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_76630;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f40a0ef6

// 0x00076660 fight::TrackFactoryTemplate<CGrappleDamageTrack>::vfunc_5 (38 B): matches/0x00076660.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleDamageTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CGrappleDamageTrack>::vfunc_5() {
    CGrappleDamageTrack_76660* p = (CGrappleDamageTrack_76660*)FUN_0008d690(0x18);
    if (p) {
        p->CGrappleDamageTrack_76660::CGrappleDamageTrack_76660();
        *(void**)p = &GrappleVftable;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00076690 CGrappleDamageTrack::vfunc_5 (36 B): matches/0x00076690.cpp
// sym: ?vfunc_5@CGrappleDamageTrack@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CGrappleDamageTrack* CGrappleDamageTrack::vfunc_5(signed char flags) {
    *(void***)this = CDamageTrack_76690_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

