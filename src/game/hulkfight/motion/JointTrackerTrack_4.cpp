// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017ede0..0x0017ee70 (kind game, layer game, confidence high), dominant class hulkfight::motion::JointTrackerTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe97ef7f {
#define TREE_TU_END }
namespace fn_fe97ef7f {} using namespace fn_fe97ef7f;
namespace fn_fe97ef7f {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fe97ef7f {
class TrackFactoryTemplate_17ede0 {
  public:
    TrackFactoryTemplate_17ede0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017c650();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Dummy_17ee20 {
  public:
    hulk_intptr FUN_0016fce0();
};
extern int hulk_at_00418ff4;

} // namespace fn_fe97ef7f

// 0x0017ede0 fight::TrackFactoryCasterTemplate<hulkfight::motion::JointTrackerTrack>::vfunc_1 (60 B): matches/0x0017ede0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VJointTrackerTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::JointTrackerTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17ede0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_17ede0* t = new (mem) TrackFactoryTemplate_17ede0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017c650();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017ee20 fight::TrackFactoryTemplate<hulkfight::motion::JointTrackerTrack>::vfunc_5 (24 B): matches/0x0017ee20.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VJointTrackerTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f460 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::JointTrackerTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x68);
    if (p)
        return (void*)(((Dummy_17ee20*)p)->FUN_0016fce0());
    return (void*)(0);
}

namespace fn_fe97ef7f {

// 0x0017ee40 fight::TrackFactoryTemplate<hulkfight::motion::JointTrackerTrack>::vfunc_2 (43 B): matches/0x0017ee40.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fe97ef7f@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00418ff4;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fe97ef7f
