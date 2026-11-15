// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186dc0..0x00186e40 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropActorThinkingTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f6208f8e {
#define TREE_TU_END }
namespace fn_f6208f8e {} using namespace fn_f6208f8e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f6208f8e {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_f6208f8e
namespace fight {
class TrackFactoryCaster_186dc0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropActorThinkingTrack_186dc0 {};
} }
namespace fn_f6208f8e {
extern char DAT_0049850c;
extern char DAT_004bde18;

} // namespace fn_f6208f8e

// 0x00186dc0 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropActorThinkingTrack>::vfunc_0 (36 B): matches/0x00186dc0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropActorThinkingTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropActorThinkingTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004bde18, 0) != 0;
}

