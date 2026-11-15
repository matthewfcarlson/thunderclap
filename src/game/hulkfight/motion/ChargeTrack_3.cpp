// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178de0..0x00178e80 (kind game, layer game, confidence high), dominant class hulkfight::motion::ChargeTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fc9c2f5f {
#define TREE_TU_END }
namespace fn_fc9c2f5f {} using namespace fn_fc9c2f5f;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fight {
class TrackFactoryCaster_178de0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class ChargeTrack_178de0 {};
} }
namespace fn_fc9c2f5f {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004b9df8;

} // namespace fn_fc9c2f5f

// 0x00178de0 fight::TrackFactoryCasterTemplate<hulkfight::motion::ChargeTrack>::vfunc_0 (36 B): matches/0x00178de0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VChargeTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::ChargeTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b9df8, 0) != 0;
}

