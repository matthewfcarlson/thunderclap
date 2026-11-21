// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186680..0x0018b4e0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/PropMissionCriticalCondition.cpp
// piece 0x00186f60..0x00186fe0 (kind game, layer game, confidence high, dominant class hulkfight::motion::GrapplePropDamageTrack); was game/hulkfight/motion/GrapplePropDamageTrack_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f9bb6ced {
#define TREE_TU_END }
namespace fn_f9bb6ced {} using namespace fn_f9bb6ced;
#include "game/hulkfight/motion.h"
// (gfx2) __RTDynamicCast's own name (CRT, C linkage): the stand-ins below bound nothing natively
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f9bb6ced {
class TrackFactoryCaster_186f60 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
extern const char hulk_at_0049850c[], hulk_at_004be028[];

} // namespace fn_f9bb6ced

// 0x00186f60 fight::TrackFactoryCasterTemplate<hulkfight::motion::GrapplePropDamageTrack>::vfunc_0 (36 B): matches/0x00186f60.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VGrapplePropDamageTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::GrapplePropDamageTrack>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast((void*)(hulk_uintptr)(s), 0, (void*)(hulk_uintptr)(hulk_at_0049850c), (void*)(hulk_uintptr)(hulk_at_004be028), 0)) != 0;
}

