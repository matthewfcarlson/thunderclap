// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178d00..0x0017e1a0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/JointTrackerTrack_3.cpp
// piece 0x00179960..0x00179a60 (kind game, layer game, confidence high, dominant class hulkfight::motion::TeleportToLocatorTrack); was game/hulkfight/motion/TeleportToLocatorTrack_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f7e413dc {
#define TREE_TU_END }
namespace fn_f7e413dc {} using namespace fn_f7e413dc;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f7e413dc {
extern char DAT_0049850c;
extern char DAT_004bac38;
} // namespace fn_f7e413dc
namespace fight {
class TrackFactoryCaster_179960 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class IntentionClearTrack_179960 {};
} }
namespace hulkfight { namespace motion {
class TeleportToLocatorTrack_1799c0;
} }
namespace fn_f7e413dc {
extern int hulk_at_0049850c, hulk_at_004bacf0;
} // namespace fn_f7e413dc
namespace fight {
class TrackFactoryCaster_1799c0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}


// 0x00179960 fight::TrackFactoryCasterTemplate<hulkfight::motion::IntentionClearTrack>::vfunc_0 (36 B): matches/0x00179960.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VIntentionClearTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::IntentionClearTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, &DAT_0049850c, &DAT_004bac38, 0) != 0;
}


// 0x001799c0 fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportToLocatorTrack>::vfunc_0 (36 B): matches/0x001799c0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VTeleportToLocatorTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportToLocatorTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)(&hulk_at_0049850c), (void*)(&hulk_at_004bacf0), 0)) != 0;
}

