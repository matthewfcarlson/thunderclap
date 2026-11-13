// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017f060..0x0017f0f0 (kind game, layer game, confidence high), dominant class hulkfight::motion::MoveJointTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f435d195 {
#define TREE_TU_END }
namespace fn_f435d195 {} using namespace fn_f435d195;
namespace fn_f435d195 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f435d195 {
class TrackFactoryTemplate_17f060 {
  public:
    TrackFactoryTemplate_17f060() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017d210();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Dummy_17f0a0 {
  public:
    hulk_intptr FUN_00170300();
};
extern int hulk_at_00419064;

} // namespace fn_f435d195

// 0x0017f060 fight::TrackFactoryCasterTemplate<hulkfight::motion::MoveJointTrack>::vfunc_1 (60 B): matches/0x0017f060.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VMoveJointTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::MoveJointTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17f060));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_17f060* t = new (mem) TrackFactoryTemplate_17f060();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017d210();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017f0a0 fight::TrackFactoryTemplate<hulkfight::motion::MoveJointTrack>::vfunc_5 (24 B): matches/0x0017f0a0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VMoveJointTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f460 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::MoveJointTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x68);
    if (p)
        return (void*)(((Dummy_17f0a0*)p)->FUN_00170300());
    return (void*)(0);
}

namespace fn_f435d195 {

// 0x0017f0c0 fight::TrackFactoryTemplate<hulkfight::motion::MoveJointTrack>::vfunc_2 (43 B): matches/0x0017f0c0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f435d195@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00419064;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f435d195
