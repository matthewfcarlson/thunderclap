// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076930..0x00076a00 (kind game, layer game, confidence high), dominant class CGrappleInvulnerableTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd060a0f {
#define TREE_TU_END }
namespace fn_fd060a0f {} using namespace fn_fd060a0f;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fd060a0f {
class TrackFactoryTemplate_76930 {
  public:
    TrackFactoryTemplate_76930() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int g_vftable_76970;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
class CGrappleInvulnerableTrack_769a0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    CGrappleInvulnerableTrack_769a0();
};
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern int vtable_769a0;
extern void* CInvulnerableTrack_769d0_vftable[];
class CInvulnerableTrack_769d0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_fd060a0f
class CGrappleInvulnerableTrack : public CInvulnerableTrack_769d0 {
  public:
    CGrappleInvulnerableTrack* vfunc_5(signed char flags);
};


// 0x00076930 fight::TrackFactoryCasterTemplate<CGrappleInvulnerableTrack>::vfunc_1 (60 B): matches/0x00076930.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleInvulnerableTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleInvulnerableTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_76930));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_76930* t = new (mem) TrackFactoryTemplate_76930();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00072360();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fd060a0f {

// 0x00076970 fight::TrackFactoryTemplate<CGrappleInvulnerableTrack>::vfunc_2 (43 B): matches/0x00076970.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fd060a0f@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_76970;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fd060a0f

// 0x000769a0 fight::TrackFactoryTemplate<CGrappleInvulnerableTrack>::vfunc_5 (38 B): matches/0x000769a0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleInvulnerableTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CGrappleInvulnerableTrack>::vfunc_5() {
    CGrappleInvulnerableTrack_769a0* p = (CGrappleInvulnerableTrack_769a0*)Alloc(0x18);
    if (p) {
        p->CGrappleInvulnerableTrack_769a0::CGrappleInvulnerableTrack_769a0();
        *(hulk_intptr*)p = (hulk_intptr)&vtable_769a0;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x000769d0 CGrappleInvulnerableTrack::vfunc_5 (36 B): matches/0x000769d0.cpp
// sym: ?vfunc_5@CGrappleInvulnerableTrack@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CGrappleInvulnerableTrack* CGrappleInvulnerableTrack::vfunc_5(signed char flags) {
    *(void***)this = CInvulnerableTrack_769d0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

