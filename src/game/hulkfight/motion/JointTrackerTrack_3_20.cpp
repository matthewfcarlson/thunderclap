// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178d00..0x0017e1a0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/JointTrackerTrack_3.cpp
// piece 0x00179b60..0x00179c10 (kind game, layer game, confidence high, dominant class hulkfight::motion::FootPivotTrack); was game/hulkfight/motion/FootPivotTrack_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0d3ef45 {
#define TREE_TU_END }
namespace fn_f0d3ef45 {} using namespace fn_f0d3ef45;
#include "game/hulkfight/motion.h"
// (gfx2) __RTDynamicCast's own name (CRT, C linkage): the stand-ins below bound nothing natively
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f0d3ef45 {
extern char DAT_0049850c;
extern char DAT_004baef0;
} // namespace fn_f0d3ef45
namespace fight {
class TrackFactoryCaster_179b60 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class FootPivotTrack_179b60;
} }


// 0x00179b60 fight::TrackFactoryCasterTemplate<hulkfight::motion::FootPivotTrack>::vfunc_0 (36 B): matches/0x00179b60.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VFootPivotTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FootPivotTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast((void*)(hulk_uintptr)(p), 0, (void*)(hulk_uintptr)(&DAT_0049850c), (void*)(hulk_uintptr)(&DAT_004baef0), 0)) != 0;
}

