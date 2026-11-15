// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178d00..0x00178de0 (kind game, layer game, confidence high), dominant class hulkfight::motion::JointTrackerTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f6ef1ee0 {
#define TREE_TU_END }
namespace fn_f6ef1ee0 {} using namespace fn_f6ef1ee0;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f6ef1ee0 {
class Track_178d00 {};
extern char DAT_0049850c;
extern char DAT_004b9d48;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_f6ef1ee0
namespace fight {
class TrackFactoryCaster_178d00 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class JointTrackerTrack_178d00;
} }


// 0x00178d00 fight::TrackFactoryCasterTemplate<hulkfight::motion::JointTrackerTrack>::vfunc_0 (36 B): matches/0x00178d00.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VJointTrackerTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::JointTrackerTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b9d48, 0) != 0;
}

