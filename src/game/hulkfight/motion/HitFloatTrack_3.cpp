// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00159f60..0x0015a020 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitFloatTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fddba4d1 {
#define TREE_TU_END }
namespace fn_fddba4d1 {} using namespace fn_fddba4d1;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fddba4d1 {
class TrackFactoryTemplate_159f60 {
  public:
    TrackFactoryTemplate_159f60() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00156280();
extern "C" char DAT_00414390[];
struct HitFloatTrack_159fa0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    int x;
};
struct Initializer_159fa0 {
    void Init_00236d40();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_004157bc;

} // namespace fn_fddba4d1

// 0x00159f60 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitFloatTrack>::vfunc_1 (60 B): matches/0x00159f60.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VHitFloatTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::HitFloatTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_159f60));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_159f60* t = new (mem) TrackFactoryTemplate_159f60();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00156280();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00159fa0 fight::TrackFactoryTemplate<hulkfight::motion::HitFloatTrack>::vfunc_5 (72 B): matches/0x00159fa0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VHitFloatTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitFloatTrack>::vfunc_5() {
    HitFloatTrack_159fa0* p = (HitFloatTrack_159fa0*)FUN_0008d690(0x28);
    if (p) {
        ((Initializer_159fa0*)p)->Init_00236d40();
        *(int*)((char*)p + 12) = 0;
        *((char*)p + 20) = 0;
        *(int*)((char*)p + 24) = 0;
        *(int*)((char*)p + 32) = 0;
        *(int*)((char*)p + 36) = 0;
        *(void**)p = (void*)((hulk_intptr)DAT_00414390);
        *(unsigned int*)((char*)p + 16) = 0xbf800000;
        *(int*)((char*)p + 28) = -5;
        return (void*)(p);
    }
    return (void*)((HitFloatTrack_159fa0*)0);
}

namespace fn_fddba4d1 {

// 0x00159ff0 fight::TrackFactoryTemplate<hulkfight::motion::HitFloatTrack>::vfunc_2 (43 B): matches/0x00159ff0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fddba4d1@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004157bc;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fddba4d1
