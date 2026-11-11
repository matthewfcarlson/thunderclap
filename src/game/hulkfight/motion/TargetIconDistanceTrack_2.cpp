// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017e810..0x0017e8d0 (kind game, layer game, confidence high), dominant class hulkfight::motion::TargetIconDistanceTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f838e587 {
#define TREE_TU_END }
namespace fn_f838e587 {} using namespace fn_f838e587;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f838e587 {
class TrackFactoryTemplate_17e810 {
  public:
    TrackFactoryTemplate_17e810() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017a860();
extern "C" void* FUN_0008d690(hulk_uintptr);
class Base_17e850 {
  public:
    Base_17e850();
    virtual void g();
    int x;
};
class Derived_17e850 : public Base_17e850 {
  public:
    Derived_17e850() : Base_17e850() {
        b = 0;
        c = -1.0f;
        d = 0;
        e = 100.0f;
        f = 0;
        a = 1;
    }
    virtual void g();
    int a;
    int b;
    float c;
    int d;
    float e;
    int f;
};
extern int g_vftable_17e8a0;

} // namespace fn_f838e587

// 0x0017e810 fight::TrackFactoryCasterTemplate<hulkfight::motion::TargetIconDistanceTrack>::vfunc_1 (60 B): matches/0x0017e810.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VTargetIconDistanceTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::TargetIconDistanceTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17e810));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17e810* t = new (mem) TrackFactoryTemplate_17e810();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017a860();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017e850 fight::TrackFactoryTemplate<hulkfight::motion::TargetIconDistanceTrack>::vfunc_5 (80 B): matches/0x0017e850.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VTargetIconDistanceTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::TargetIconDistanceTrack>::vfunc_5() {
    Derived_17e850* p = (Derived_17e850*)FUN_0008d690((int)sizeof(Derived_17e850));
    if (p) {
        new (p) Derived_17e850();
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f838e587 {

// 0x0017e8a0 fight::TrackFactoryTemplate<hulkfight::motion::TargetIconDistanceTrack>::vfunc_2 (43 B): matches/0x0017e8a0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f838e587@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_17e8a0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f838e587
