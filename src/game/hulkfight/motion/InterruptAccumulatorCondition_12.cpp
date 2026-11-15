// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153f40..0x00158f00 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/InterruptAccumulatorCondition.cpp
// piece 0x00154a60..0x00154b80 (kind game, layer game, confidence high, dominant class hulkfight::motion::HitReactionTrack); was game/hulkfight/motion/HitReactionTrack_params_factory.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f182fbb4 {
#define TREE_TU_END }
namespace fn_f182fbb4 {} using namespace fn_f182fbb4;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f182fbb4 {
} // namespace fn_f182fbb4
namespace fight {
class TrackFactoryCaster_154a60 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class HitPauseTrack_154a60 {};
} }
namespace fn_f182fbb4 {
extern char DAT_0049850c;
extern char DAT_004b2ee0;
} // namespace fn_f182fbb4
namespace fight {
class TrackFactoryCaster_154ac0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class HitReactionTrack_154ac0 {};
} }
namespace fn_f182fbb4 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004b2f88;

} // namespace fn_f182fbb4

// 0x00154a60 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPauseTrack>::vfunc_0 (36 B): matches/0x00154a60.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHitPauseTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPauseTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, &DAT_0049850c, &DAT_004b2ee0, 0) != 0;
}


// 0x00154ac0 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitReactionTrack>::vfunc_0 (36 B): matches/0x00154ac0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHitReactionTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitReactionTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b2f88, 0) != 0;
}

