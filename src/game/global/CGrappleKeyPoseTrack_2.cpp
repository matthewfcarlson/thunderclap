// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00077ae0..0x00077ba0 (kind game, layer game, confidence high), dominant class CGrappleKeyPoseTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_feba9267 {
#define TREE_TU_END }
namespace fn_feba9267 {} using namespace fn_feba9267;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_feba9267 {
class TrackFactoryTemplate_77ae0 {
  public:
    TrackFactoryTemplate_77ae0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003febf4;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_000694f0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};
typedef unsigned int u32_77b50;
extern "C" void* __cdecl alloc(hulk_uintptr);
extern u32_77b50 hulk_at_003fec10;
struct CGrappleKeyPoseTrack_77b50 {
    hulk_uintptr vf;
    void init_00069520();
};

} // namespace fn_feba9267

// 0x00077ae0 fight::TrackFactoryCasterTemplate<CGrappleKeyPoseTrack>::vfunc_1 (60 B): matches/0x00077ae0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleKeyPoseTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleKeyPoseTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_77ae0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_77ae0* t = new (mem) TrackFactoryTemplate_77ae0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00074d90();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_feba9267 {

// 0x00077b20 fight::TrackFactoryTemplate<CGrappleKeyPoseTrack>::vfunc_2 (43 B): matches/0x00077b20.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_feba9267@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003febf4;
    base1_dtor_000694f0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_feba9267

// 0x00077b50 fight::TrackFactoryTemplate<CGrappleKeyPoseTrack>::vfunc_5 (38 B): matches/0x00077b50.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleKeyPoseTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CGrappleKeyPoseTrack>::vfunc_5() {
    CGrappleKeyPoseTrack_77b50* p = (CGrappleKeyPoseTrack_77b50*)alloc(0x78);
    if (p) {
        p->init_00069520();
        p->vf = (hulk_uintptr)&hulk_at_003fec10;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00077b80 CGrappleKeyPoseTrack::vfunc_5 (30 B): matches/0x00077b80.cpp
// sym: ??_GCGrappleKeyPoseTrack@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CGrappleKeyPoseTrack::~CGrappleKeyPoseTrack() {}

