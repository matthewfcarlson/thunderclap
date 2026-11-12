// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018bd60..0x0018be10 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropActorToPropTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f85ca3d7 {
#define TREE_TU_END }
namespace fn_f85ca3d7 {} using namespace fn_f85ca3d7;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f85ca3d7 {
class TrackFactoryTemplate_18bd60 {
  public:
    TrackFactoryTemplate_18bd60() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00187e00();
extern int hulk_at_0041a79c;

} // namespace fn_f85ca3d7

// 0x0018bd60 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropActorToPropTrack>::vfunc_1 (60 B): matches/0x0018bd60.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VPropActorToPropTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::PropActorToPropTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18bd60));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18bd60* t = new (mem) TrackFactoryTemplate_18bd60();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00187e00();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018bda0 fight::TrackFactoryTemplate<hulkfight::motion::PropActorToPropTrack>::vfunc_5 (60 B): matches/0x0018bda0.cpp [wrapped: helper definitions (6 out-of-line function bodies)]
// sym: ?f5@Factory_18bda0@fn_0018bda0@@UAEPAVPropTrack@2@XZ
namespace fn_0018bda0 {
extern "C" char DAT_004192cc[];
typedef unsigned int u32_18bda0;
typedef unsigned char u8;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class PropTrack {
  public:
    hulk_uintptr v;
    u32_18bda0 pad[2];
    u32_18bda0 a;
    u32_18bda0 b;
    u8 c;
    u8 d;
    PropTrack();
};
class Factory_18bda0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual PropTrack* f5();
};
void Factory_18bda0::f0() {}
void Factory_18bda0::f1() {}
void Factory_18bda0::f2() {}
void Factory_18bda0::f3() {}
void Factory_18bda0::f4() {}
PropTrack* Factory_18bda0::f5() {
    PropTrack* p = (PropTrack*)FUN_0008d690((int)sizeof(PropTrack));
    if (p) {
        p->PropTrack::PropTrack();
        p->v = ((hulk_intptr)DAT_004192cc);
        p->a = 0;
        p->b = 0xffffffff;
        p->c = 0;
        p->d = 0;
        return p;
    }
    return (PropTrack*)0;
}
} // namespace fn_0018bda0

namespace fn_f85ca3d7 {

// 0x0018bde0 fight::TrackFactoryTemplate<hulkfight::motion::PropActorToPropTrack>::vfunc_2 (43 B): matches/0x0018bde0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f85ca3d7@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a79c;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f85ca3d7
