// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018c2d0..0x0018c390 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAddToMissileCountTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8452970 {
#define TREE_TU_END }
namespace fn_f8452970 {} using namespace fn_f8452970;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f8452970 {
class TrackFactoryTemplate_18c2d0 {
  public:
    TrackFactoryTemplate_18c2d0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00188570();
extern "C" void* __cdecl alloc(hulk_uintptr);
extern int hulk_at_0041953c;
class Prop_18c310 {
  public:
    hulk_intptr vptr;
    int pad;
    int x;
    int a;
    int b;
    int c;
    void Init_00236d40();
};
extern int hulk_at_0041a87c;

} // namespace fn_f8452970

// 0x0018c2d0 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_1 (60 B): matches/0x0018c2d0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VPropAddToMissileCountTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18c2d0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18c2d0* t = new (mem) TrackFactoryTemplate_18c2d0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00188570();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018c310 fight::TrackFactoryTemplate<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_5 (66 B): matches/0x0018c310.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VPropAddToMissileCountTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_5() {
    Prop_18c310* p = (Prop_18c310*)alloc(0x18);
    if (p) {
        p->Init_00236d40();
        p->vptr = (hulk_intptr)&hulk_at_0041953c;
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->x = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f8452970 {

// 0x0018c360 fight::TrackFactoryTemplate<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_2 (43 B): matches/0x0018c360.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f8452970@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a87c;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f8452970
