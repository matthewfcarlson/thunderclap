// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017ee70..0x0017ef40 (kind game, layer game, confidence high), dominant class hulkfight::motion::RestPoseTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fdd67982 {
#define TREE_TU_END }
namespace fn_fdd67982 {} using namespace fn_fdd67982;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fdd67982 {
class TrackFactoryTemplate_17ee70 {
  public:
    TrackFactoryTemplate_17ee70() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017ca60();
extern "C" char DAT_004178f8[];
class Sub_17eeb0 {
  public:
    void Init();
};
class RestPoseTrack_17eeb0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    int a;
    int b;
    int c;
    float d;
    char pad[4];
    Sub_17eeb0 sub;
    int x;
    int y;
    int z;
    int q;
    void Init();
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int g_vftable_17ef10;

} // namespace fn_fdd67982

// 0x0017ee70 fight::TrackFactoryCasterTemplate<hulkfight::motion::RestPoseTrack>::vfunc_1 (60 B): matches/0x0017ee70.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VRestPoseTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::RestPoseTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17ee70));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17ee70* t = new (mem) TrackFactoryTemplate_17ee70();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017ca60();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017eeb0 fight::TrackFactoryTemplate<hulkfight::motion::RestPoseTrack>::vfunc_5 (81 B): matches/0x0017eeb0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VRestPoseTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::RestPoseTrack>::vfunc_5() {
    RestPoseTrack_17eeb0* p = (RestPoseTrack_17eeb0*)FUN_0008d690(0x30);
    if (p) {
        p->Init();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_004178f8);
        p->c = 0;
        p->d = -1.0f;
        p->sub.Init();
        p->y = -5;
        p->z = 0;
        p->q = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fdd67982 {

// 0x0017ef10 fight::TrackFactoryTemplate<hulkfight::motion::RestPoseTrack>::vfunc_2 (43 B): matches/0x0017ef10.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fdd67982@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_17ef10;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fdd67982
