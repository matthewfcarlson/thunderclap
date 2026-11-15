// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110f00..0x00111060 (kind game, layer game, confidence high), dominant class hulkfight::ai::AIHistoryNameCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5cad1e3 {
#define TREE_TU_END }
namespace fn_f5cad1e3 {} using namespace fn_f5cad1e3;
#include "game/hulkfight/ai.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace hulkfight { namespace ai {
class AIFightNodeCondition_110f00 {};
} }
namespace fn_f5cad1e3 {
} // namespace fn_f5cad1e3
namespace fight {
class ConditionFactoryCaster_110f00 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_f5cad1e3 {
extern char DAT_00491ca8;
extern char DAT_004a3a00;
} // namespace fn_f5cad1e3
namespace fight {
class ConditionFactoryCaster_110f60 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class DefendingCondition_110f60 {};
} }
namespace fn_f5cad1e3 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004a3ab0;
} // namespace fn_f5cad1e3
namespace fight {
class ConditionFactoryCaster_110fc0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class AIHistoryNameCondition_110fc0;
} }
namespace fn_f5cad1e3 {
extern char DAT_004a3b68;

} // namespace fn_f5cad1e3

// 0x00110f00 fight::ConditionFactoryCasterTemplate<hulkfight::ai::AIFightNodeCondition>::vfunc_0 (36 B): matches/0x00110f00.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VAIFightNodeCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::AIFightNodeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &DAT_00491ca8, &DAT_004a3a00, 0)) != 0;
}


// 0x00110f60 fight::ConditionFactoryCasterTemplate<hulkfight::ai::DefendingCondition>::vfunc_0 (36 B): matches/0x00110f60.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VDefendingCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::DefendingCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a3ab0, 0) != 0;
}


// 0x00110fc0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::AIHistoryNameCondition>::vfunc_0 (36 B): matches/0x00110fc0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::AIHistoryNameCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a3b68, 0) != 0;
}

