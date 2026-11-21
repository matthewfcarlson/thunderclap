// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178d00..0x0017e1a0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/JointTrackerTrack_3.cpp
// piece 0x00179020..0x00179100 (kind game, layer game, confidence high, dominant class hulkfight::motion::SyncToLocatorTrack); was game/hulkfight/motion/SyncToLocatorTrack_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f2aa30a1 {
#define TREE_TU_END }
namespace fn_f2aa30a1 {} using namespace fn_f2aa30a1;
#include "game/hulkfight/motion.h"
// (gfx2) __RTDynamicCast's own name (CRT, C linkage): the stand-ins below bound nothing natively
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f2aa30a1 {
extern int hulk_at_0049850c, hulk_at_004ba0a8;
} // namespace fn_f2aa30a1
namespace fight {
class TrackFactoryCaster_179020 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class SyncToLocatorTrack_179020;
} }


// 0x00179020 fight::TrackFactoryCasterTemplate<hulkfight::motion::SyncToLocatorTrack>::vfunc_0 (36 B): matches/0x00179020.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::SyncToLocatorTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast((void*)(hulk_uintptr)(p), 0, (void*)(hulk_uintptr)(&hulk_at_0049850c), (void*)(hulk_uintptr)(&hulk_at_004ba0a8), 0)) != 0;
}

