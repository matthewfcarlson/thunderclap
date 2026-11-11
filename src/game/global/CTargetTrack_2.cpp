// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00077750..0x00077800 (kind game, layer game, confidence high), dominant class CTargetTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f92c8711 {
#define TREE_TU_END }
namespace fn_f92c8711 {} using namespace fn_f92c8711;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f92c8711 {
class TrackFactoryTemplate_77750 {
  public:
    TrackFactoryTemplate_77750() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00072a20();
class CTargetTrack_77790 {
  public:
    int a, b, c, d, e;
    void Init_00236d40();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003fc274;
extern int hulk_at_003feb68;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006b220();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f92c8711

// 0x00077750 fight::TrackFactoryCasterTemplate<CTargetTrack>::vfunc_1 (60 B): matches/0x00077750.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCTargetTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CTargetTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_77750));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_77750* t = new (mem) TrackFactoryTemplate_77750();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00072a20();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00077790 fight::TrackFactoryTemplate<CTargetTrack>::vfunc_5 (59 B): matches/0x00077790.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCTargetTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CTargetTrack>::vfunc_5() {
    CTargetTrack_77790* p = (CTargetTrack_77790*)FUN_0008d690((int)sizeof(CTargetTrack_77790));
    if (p) {
        p->Init_00236d40();
        *(hulk_ulongptr*)p = (hulk_ulongptr)&hulk_at_003fc274;
        p->d = 0;
        p->e = (int)0xbf800000;
        p->c = 1;
        return (void*)(p);
    }
    return (void*)((CTargetTrack_77790*)0);
}

namespace fn_f92c8711 {

// 0x000777d0 fight::TrackFactoryTemplate<CTargetTrack>::vfunc_2 (43 B): matches/0x000777d0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f92c8711@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003feb68;
    base1_dtor_0006b220();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f92c8711
