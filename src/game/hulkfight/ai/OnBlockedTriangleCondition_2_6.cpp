// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110e60..0x001133f0 (kind game, layer game, confidence high), merged by D32: hulkfight/ai/OnBlockedTriangleCondition_2.cpp
// piece 0x001111e0..0x001112e0 (kind game, layer game, confidence high, dominant class hulkfight::ai::KeyWordWaitCondition); was game/hulkfight/ai/KeyWordWaitCondition.cpp until D46
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f74dcadf {
#define TREE_TU_END }
namespace fn_f74dcadf {} using namespace fn_f74dcadf;
#include "game/hulkfight/ai.h"
// (gfx2) __RTDynamicCast's own name (CRT, C linkage): the stand-ins below bound nothing natively
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f74dcadf {
extern int hulk_at_00491ca8;
extern int hulk_at_004a3e50;
} // namespace fn_f74dcadf
namespace fight {
class ConditionFactoryCaster_1111e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_f74dcadf {
extern char DAT_00491ca8;
extern char DAT_004a3f00;
extern hulk_intptr FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);

} // namespace fn_f74dcadf

// 0x001111e0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::LeashedCondition>::vfunc_0 (36 B): matches/0x001111e0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VLeashedCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::LeashedCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast((void*)(hulk_uintptr)(p), 0, (void*)(hulk_uintptr)(&hulk_at_00491ca8), (void*)(hulk_uintptr)(&hulk_at_004a3e50), 0)) != 0;
}


// 0x00111240 fight::ConditionFactoryCasterTemplate<hulkfight::ai::KeyWordWaitCondition>::vfunc_0 (36 B): matches/0x00111240.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VKeyWordWaitCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::KeyWordWaitCondition>::vfunc_0(void* __p0) { hulk_intptr a = (hulk_intptr)__p0;

    return (int)FUN_00344e74(a, 0, (hulk_intptr)&DAT_00491ca8, (hulk_intptr)&DAT_004a3f00, 0) ? 1 : 0;
}

