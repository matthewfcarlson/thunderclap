// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186680..0x0018b4e0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/PropMissionCriticalCondition.cpp
// piece 0x00187160..0x001871e0 (kind game, layer game, confidence high, dominant class hulkfight::motion::PropSetStateByIndexTrack); was game/hulkfight/motion/PropSetStateByIndexTrack_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0fc7646 {
#define TREE_TU_END }
namespace fn_f0fc7646 {} using namespace fn_f0fc7646;
#include "game/hulkfight/motion.h"
// (gfx2) __RTDynamicCast's own name (CRT, C linkage): the stand-ins below bound nothing natively
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f0fc7646 {
extern char DAT_0049850c;
extern char DAT_004be240;
class Track_187160 {};
class Caster {
  public:
    virtual bool Check(void*);
    virtual void Other();
};

} // namespace fn_f0fc7646

// 0x00187160 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_0 (36 B): matches/0x00187160.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropSetStateByIndexTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast((void*)(hulk_uintptr)(p), 0, (void*)(hulk_uintptr)((void*)&DAT_0049850c), (void*)(hulk_uintptr)((void*)&DAT_004be240), 0) != 0;
}

