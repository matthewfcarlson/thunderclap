// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076930..0x00076a00 (kind game, layer game, confidence high), dominant class CGrappleInvulnerableTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd060a0f {
#define TREE_TU_END }
namespace fn_fd060a0f {} using namespace fn_fd060a0f;
namespace fn_fd060a0f {
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
namespace fn_fd060a0f {
class TrackFactoryTemplate_76930 {
  public:
    TrackFactoryTemplate_76930() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003fe864;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006a970();
    void base2_dtor_00236ab0();
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
extern int hulk_at_003fe880;
extern void* hulk_at_003f98d0[];
class CInvulnerableTrack_769d0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
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
        ((FactoryCtor*)mem)->init_00236a90();
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
    m_vptr = (void*)&hulk_at_003fe864;
    base1_dtor_0006a970();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fd060a0f

// 0x000769a0 fight::TrackFactoryTemplate<CGrappleInvulnerableTrack>::vfunc_5 (38 B): matches/0x000769a0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleInvulnerableTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CGrappleInvulnerableTrack>::vfunc_5() {
    CGrappleInvulnerableTrack_769a0* p = (CGrappleInvulnerableTrack_769a0*)Alloc(0x18);
    if (p) {
        p->CGrappleInvulnerableTrack_769a0::CGrappleInvulnerableTrack_769a0();
        *(hulk_intptr*)p = (hulk_intptr)&hulk_at_003fe880;
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
    *(void***)this = hulk_at_003f98d0;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

