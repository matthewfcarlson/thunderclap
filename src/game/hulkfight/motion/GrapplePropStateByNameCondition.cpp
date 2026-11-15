// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186780..0x00186800 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrapplePropStateByNameCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f85af9a8 {
#define TREE_TU_END }
namespace fn_f85af9a8 {} using namespace fn_f85af9a8;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f85af9a8 {
class ConditionFactoryCaster_186780 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class GrapplePropStateByNameCondition_186780 {};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004bd420;

} // namespace fn_f85af9a8

// 0x00186780 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_0 (36 B): matches/0x00186780.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VGrapplePropStateByNameCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004bd420, 0) != 0;
}

