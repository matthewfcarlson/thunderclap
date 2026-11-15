// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00179a60..0x00179ae0 (kind game, layer game, confidence high), dominant class hulkfight::motion::ChargeClearTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f1942bfb {
#define TREE_TU_END }
namespace fn_f1942bfb {} using namespace fn_f1942bfb;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f1942bfb {
extern "C" char DAT_0049850c, DAT_004bada0;
} // namespace fn_f1942bfb
namespace hulkfight { namespace motion {
class ChargeClearTrack_179a60;
} }
namespace fight {
class TrackFactoryCaster_179a60 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}


// 0x00179a60 fight::TrackFactoryCasterTemplate<hulkfight::motion::ChargeClearTrack>::vfunc_0 (36 B): matches/0x00179a60.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VChargeClearTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::ChargeClearTrack>::vfunc_0(void* __p0) { void * object = (void *)__p0;

    return __RTDynamicCast(object, 0, (void*)(&DAT_0049850c), (void*)(&DAT_004bada0), 0) != 0;
}

