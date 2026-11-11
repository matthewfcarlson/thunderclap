// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00075e30..0x00075ee0 (kind game, layer game, confidence high), dominant class CCameraShakeTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd0ccaa0 {
#define TREE_TU_END }
namespace fn_fd0ccaa0 {} using namespace fn_fd0ccaa0;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fd0ccaa0 {
class TrackFactoryTemplate_75e30 {
  public:
    TrackFactoryTemplate_75e30() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00071bc0();
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
class CCameraShakeTrack_75e70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[4];
    int flag;
    int x;
    int y;
    int z;
    int w;
    void Init();
};
extern int g_vftable_75eb0;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fd0ccaa0

// 0x00075e30 fight::TrackFactoryCasterTemplate<CCameraShakeTrack>::vfunc_1 (60 B): matches/0x00075e30.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCCameraShakeTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CCameraShakeTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_75e30));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_75e30* t = new (mem) TrackFactoryTemplate_75e30();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00071bc0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00075e70 fight::TrackFactoryTemplate<CCameraShakeTrack>::vfunc_5 (62 B): matches/0x00075e70.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCCameraShakeTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CCameraShakeTrack>::vfunc_5() {
    CCameraShakeTrack_75e70* p = (CCameraShakeTrack_75e70*)FUN_0008d690((int)sizeof(CCameraShakeTrack_75e70));
    if (p) {
        p->Init();
        p->x = 0;
        p->y = 0;
        p->z = 0;
        p->w = 0;
        *(hulk_ulongptr*)p = (hulk_ulongptr)&shakeVtable;
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fd0ccaa0 {

// 0x00075eb0 fight::TrackFactoryTemplate<CCameraShakeTrack>::vfunc_2 (43 B): matches/0x00075eb0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fd0ccaa0@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_75eb0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fd0ccaa0
