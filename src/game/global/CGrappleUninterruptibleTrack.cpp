// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076ad0..0x00076ba0 (kind game, layer game, confidence high), dominant class CGrappleUninterruptibleTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f77f55b0 {
#define TREE_TU_END }
namespace fn_f77f55b0 {} using namespace fn_f77f55b0;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f77f55b0 {
class TrackFactoryTemplate_76ad0 {
  public:
    TrackFactoryTemplate_76ad0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int g_vftable_76b10;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
} // namespace fn_f77f55b0
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_f77f55b0 {
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void v0();
};
class CGrappleUninterruptibleTrack_76b40 : public BaseTrack {
  public:
    CGrappleUninterruptibleTrack_76b40() throw() : BaseTrack() {}
    virtual void v0();
    char padding[0x14];
};
extern void* CUninterruptibleTrack_76b70_vftable[];
class CUninterruptibleTrack_76b70 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f77f55b0
class CGrappleUninterruptibleTrack : public CUninterruptibleTrack_76b70 {
  public:
    CGrappleUninterruptibleTrack* vfunc_5(signed char flags);
};


// 0x00076ad0 fight::TrackFactoryCasterTemplate<CGrappleUninterruptibleTrack>::vfunc_1 (60 B): matches/0x00076ad0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleUninterruptibleTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleUninterruptibleTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_76ad0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_76ad0* t = new (mem) TrackFactoryTemplate_76ad0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00072280();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f77f55b0 {

// 0x00076b10 fight::TrackFactoryTemplate<CGrappleUninterruptibleTrack>::vfunc_2 (43 B): matches/0x00076b10.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f77f55b0@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_76b10;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f77f55b0

// 0x00076b40 fight::TrackFactoryTemplate<CGrappleUninterruptibleTrack>::vfunc_5 (38 B): matches/0x00076b40.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleUninterruptibleTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CGrappleUninterruptibleTrack>::vfunc_5() {
    return (void*)(new CGrappleUninterruptibleTrack_76b40);
}


// 0x00076b70 CGrappleUninterruptibleTrack::vfunc_5 (36 B): matches/0x00076b70.cpp
// sym: ?vfunc_5@CGrappleUninterruptibleTrack@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CGrappleUninterruptibleTrack* CGrappleUninterruptibleTrack::vfunc_5(signed char flags) {
    *(void***)this = CUninterruptibleTrack_76b70_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

