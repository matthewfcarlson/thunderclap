// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00179b60..0x00179c10 (kind game, layer game, confidence high), dominant class hulkfight::motion::FootPivotTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0d3ef45 {
#define TREE_TU_END }
namespace fn_f0d3ef45 {} using namespace fn_f0d3ef45;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f0d3ef45 {
extern "C" int __cdecl check(void*, int, const void*, const void*, int);
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

    return check(p, 0, &DAT_0049850c, &DAT_004baef0, 0) != 0;
}

