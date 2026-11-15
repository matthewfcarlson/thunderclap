// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178d00..0x0017e1a0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/JointTrackerTrack_3.cpp
// piece 0x00179100..0x001791e0 (kind game, layer game, confidence high, dominant class hulkfight::motion::LocomotionStateTrack); was game/hulkfight/motion/LocomotionStateTrack_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f969746b {
#define TREE_TU_END }
namespace fn_f969746b {} using namespace fn_f969746b;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f969746b {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004ba150;
} // namespace fn_f969746b
namespace fight {
class TrackFactoryCaster_179100 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class SuckTrack_179100;
} }
namespace hulkfight { namespace motion {
class LocomotionStateTrack_179160;
} }
namespace fn_f969746b {
extern char DAT_004ba200;
} // namespace fn_f969746b
namespace fight {
class TrackFactoryCaster_179160 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}


// 0x00179100 fight::TrackFactoryCasterTemplate<hulkfight::motion::SuckTrack>::vfunc_0 (36 B): matches/0x00179100.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VSuckTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::SuckTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004ba150, 0) != 0;
}


// 0x00179160 fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotionStateTrack>::vfunc_0 (36 B): matches/0x00179160.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VLocomotionStateTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotionStateTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004ba200, 0) != 0;
}

