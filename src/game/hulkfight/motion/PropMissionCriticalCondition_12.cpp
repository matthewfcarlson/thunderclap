// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186680..0x0018b4e0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/PropMissionCriticalCondition.cpp
// piece 0x00186d40..0x00186dc0 (kind game, layer game, confidence high, dominant class hulkfight::motion::PropSetStateByNameTrack); was game/hulkfight/motion/PropSetStateByNameTrack_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f356d859 {
#define TREE_TU_END }
namespace fn_f356d859 {} using namespace fn_f356d859;
#include "game/hulkfight/motion.h"
// (gfx2) __RTDynamicCast's own name (CRT, C linkage): the stand-ins below bound nothing natively
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f356d859 {
struct Base {
    virtual bool Check(void*);
    virtual void other();
};
extern void* hulk_at_0049850c;
extern void* hulk_at_004bdd60;

} // namespace fn_f356d859

// 0x00186d40 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSetStateByNameTrack>::vfunc_0 (36 B): matches/0x00186d40.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropSetStateByNameTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSetStateByNameTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast((void*)(hulk_uintptr)(p), 0, (void*)(hulk_uintptr)(&hulk_at_0049850c), (void*)(hulk_uintptr)(&hulk_at_004bdd60), 0)) != 0;
}

