// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017e610..0x0017e6c0 (kind game, layer game, confidence high), dominant class hulkfight::motion::TargetBreakTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff7c7495 {
#define TREE_TU_END }
namespace fn_ff7c7495 {} using namespace fn_ff7c7495;
namespace fn_ff7c7495 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ff7c7495 {
class TrackFactoryTemplate_17e610 {
  public:
    TrackFactoryTemplate_17e610() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017a420();
extern int hulk_at_00418ec0;

} // namespace fn_ff7c7495

// 0x0017e610 fight::TrackFactoryCasterTemplate<hulkfight::motion::TargetBreakTrack>::vfunc_1 (60 B): matches/0x0017e610.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VTargetBreakTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::TargetBreakTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17e610));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_17e610* t = new (mem) TrackFactoryTemplate_17e610();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017a420();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017e650 fight::TrackFactoryTemplate<hulkfight::motion::TargetBreakTrack>::vfunc_5 (52 B): matches/0x0017e650.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_5@TrackFactory@fight@fn_0017e650@@UAEPAXXZ
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace fn_0017e650 {
/* size_t: tree_prelude.h */

namespace fight {
class TrackFactory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* vfunc_5();
};
} // namespace fight
class Track_17e650 {
  public:
    Track_17e650();
    virtual void f();
    char pad[4];
    int one;
    int zero;
};
namespace hulkfight {
namespace motion {
class TargetBreakTrack : public Track_17e650 {
  public:
    TargetBreakTrack();
    virtual void f();
};
} // namespace motion
} // namespace hulkfight
hulkfight::motion::TargetBreakTrack::TargetBreakTrack() : Track_17e650() {
    zero = 0;
    one = 1;
}
void* fight::TrackFactory::vfunc_5() {
    return new hulkfight::motion::TargetBreakTrack;
}
} // namespace fn_0017e650

namespace fn_ff7c7495 {

// 0x0017e690 fight::TrackFactoryTemplate<hulkfight::motion::TargetBreakTrack>::vfunc_2 (43 B): matches/0x0017e690.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_ff7c7495@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00418ec0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_ff7c7495
