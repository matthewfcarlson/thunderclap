// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178d00..0x0017e1a0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/JointTrackerTrack_3.cpp
// piece 0x001798e0..0x00179960 (kind game, layer game, confidence high, dominant class hulkfight::motion::TeleportRelativeTrack); was game/hulkfight/motion/TeleportRelativeTrack_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f1775de3 {
#define TREE_TU_END }
namespace fn_f1775de3 {} using namespace fn_f1775de3;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f1775de3 {
extern char DAT_0049850c;
extern char DAT_004bab80;
extern "C" int __cdecl check(void*, int, const void*, const void*, int);
} // namespace fn_f1775de3
namespace fight {
class TrackFactoryCaster_1798e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class TeleportRelativeTrack_1798e0;
} }


// 0x001798e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportRelativeTrack>::vfunc_0 (36 B): matches/0x001798e0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VTeleportRelativeTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportRelativeTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_0049850c, &DAT_004bab80, 0) != 0;
}

