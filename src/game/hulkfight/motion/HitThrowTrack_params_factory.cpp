// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00154900..0x001549a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitThrowTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5e9ef75 {
#define TREE_TU_END }
namespace fn_f5e9ef75 {} using namespace fn_f5e9ef75;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fight {
class TrackFactoryCaster_154900 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class HitThrowTrack_154900 {};
} }
namespace fn_f5e9ef75 {
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004b2d80;

} // namespace fn_f5e9ef75

// 0x00154900 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitThrowTrack>::vfunc_0 (36 B): matches/0x00154900.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHitThrowTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitThrowTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b2d80, 0) != 0;
}

