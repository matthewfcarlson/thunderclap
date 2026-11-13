// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000778c0..0x00077990 (kind game, layer game, confidence high), dominant class CWallSlideTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0c0ad92 {
#define TREE_TU_END }
namespace fn_f0c0ad92 {} using namespace fn_f0c0ad92;
namespace fn_f0c0ad92 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f0c0ad92 {
class TrackFactoryTemplate_778c0 {
  public:
    TrackFactoryTemplate_778c0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00072820();
extern "C" char DAT_003fc238[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Track_77900 {
  public:
    Track_77900();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class CWallSlideTrack_77900 : public Track_77900 {
  public:
    char pad[8];
    int x0c;
    float x10;
    float x14;
    int x18;
    float x1c;
    float x20;
    int x24;
    int x28;
    int x2c;
};
extern int hulk_at_003feba0;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006b140();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f0c0ad92

// 0x000778c0 fight::TrackFactoryCasterTemplate<CWallSlideTrack>::vfunc_1 (60 B): matches/0x000778c0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCWallSlideTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CWallSlideTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_778c0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_778c0* t = new (mem) TrackFactoryTemplate_778c0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00072820();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00077900 fight::TrackFactoryTemplate<CWallSlideTrack>::vfunc_5 (83 B): matches/0x00077900.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCWallSlideTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CWallSlideTrack>::vfunc_5() {
    CWallSlideTrack_77900* p = (CWallSlideTrack_77900*)FUN_0008d690((int)sizeof(CWallSlideTrack_77900));
    if (p) {
        p->Track_77900::Track_77900();
        p->x0c = 0;
        p->x18 = 0;
        p->x24 = 0;
        p->x28 = 0;
        p->x2c = 0;
        p->x14 = 20.0f;
        p->x1c = 20.0f;
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003fc238);
        p->x10 = -1.0f;
        p->x20 = 1.0f;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f0c0ad92 {

// 0x00077960 fight::TrackFactoryTemplate<CWallSlideTrack>::vfunc_2 (43 B): matches/0x00077960.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f0c0ad92@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003feba0;
    base1_dtor_0006b140();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f0c0ad92
