// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153f40..0x00158f00 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/InterruptAccumulatorCondition.cpp
// piece 0x001549a0..0x00154a60 (kind game, layer game, confidence high, dominant class hulkfight::motion::HitReactionFloatTrack); was game/hulkfight/motion/HitReactionFloatTrack_params_factory.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3dfe215 {
#define TREE_TU_END }
namespace fn_f3dfe215 {} using namespace fn_f3dfe215;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f3dfe215 {
struct TrackFactoryCaster_1549a0 {
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int hulk_at_0049850c, hulk_at_004b2e30;

} // namespace fn_f3dfe215

// 0x001549a0 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitReactionFloatTrack>::vfunc_0 (36 B): matches/0x001549a0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitReactionFloatTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &hulk_at_0049850c, &hulk_at_004b2e30, 0) != 0;
}

