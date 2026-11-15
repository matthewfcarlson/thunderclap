// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178e80..0x00178f00 (kind game, layer game, confidence high), dominant class hulkfight::motion::RestPoseTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f10a76b6 {
#define TREE_TU_END }
namespace fn_f10a76b6 {} using namespace fn_f10a76b6;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f10a76b6 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004b9ea0;
} // namespace fn_f10a76b6
namespace fight {
class TrackFactoryCaster_178e80 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class RestPoseTrack_178e80 {};
} }


// 0x00178e80 fight::TrackFactoryCasterTemplate<hulkfight::motion::RestPoseTrack>::vfunc_0 (36 B): matches/0x00178e80.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VRestPoseTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::RestPoseTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b9ea0, 0) != 0;
}

