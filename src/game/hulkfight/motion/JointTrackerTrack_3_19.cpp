// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178d00..0x0017e1a0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/JointTrackerTrack_3.cpp
// piece 0x00179ae0..0x00179b60 (kind game, layer game, confidence high, dominant class hulkfight::motion::VisibilityTrack); was game/hulkfight/motion/VisibilityTrack_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f65cd6aa {
#define TREE_TU_END }
namespace fn_f65cd6aa {} using namespace fn_f65cd6aa;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f65cd6aa {
extern char DAT_0049850c;
extern char DAT_004bae48;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_f65cd6aa
namespace fight {
class TrackFactoryCaster_179ae0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class VisibilityTrack_179ae0;
} }


// 0x00179ae0 fight::TrackFactoryCasterTemplate<hulkfight::motion::VisibilityTrack>::vfunc_0 (36 B): matches/0x00179ae0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VVisibilityTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::VisibilityTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004bae48, 0) != 0;
}

