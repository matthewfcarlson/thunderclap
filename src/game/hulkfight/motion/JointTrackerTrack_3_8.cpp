// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178d00..0x0017e1a0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/JointTrackerTrack_3.cpp
// piece 0x001792a0..0x00179360 (kind game, layer game, confidence high, dominant class hulkfight::motion::DriftToPositionTrack); was game/hulkfight/motion/DriftToPositionTrack_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ff203ab8 {
#define TREE_TU_END }
namespace fn_ff203ab8 {} using namespace fn_ff203ab8;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_ff203ab8 {
extern char DAT_0049850c;
extern char DAT_004ba360;
extern "C" void* Find(void*, int, void*, void*, int);
} // namespace fn_ff203ab8
namespace fight {
class TrackFactoryCaster_1792a0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class DriftToPositionTrack_1792a0;
} }


// 0x001792a0 fight::TrackFactoryCasterTemplate<hulkfight::motion::DriftToPositionTrack>::vfunc_0 (36 B): matches/0x001792a0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::DriftToPositionTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Find(p, 0, &DAT_0049850c, &DAT_004ba360, 0) != 0;
}

