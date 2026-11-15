// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00179640..0x00179720 (kind game, layer game, confidence high), dominant class hulkfight::motion::JointPivotTrackerTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f7fdf59c {
#define TREE_TU_END }
namespace fn_f7fdf59c {} using namespace fn_f7fdf59c;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f7fdf59c {
extern char DAT_0049850c;
extern char DAT_004ba810;
} // namespace fn_f7fdf59c
namespace hulkfight { namespace motion {
class JointPivotTrackerTrack_179640;
} }
namespace fight {
class TrackFactoryCaster_179640 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}


// 0x00179640 fight::TrackFactoryCasterTemplate<hulkfight::motion::JointPivotTrackerTrack>::vfunc_0 (36 B): matches/0x00179640.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::JointPivotTrackerTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)(&DAT_0049850c), (void*)(&DAT_004ba810), 0)) != 0;
}

