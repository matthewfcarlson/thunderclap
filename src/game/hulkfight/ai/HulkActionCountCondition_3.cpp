// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001113e0..0x00111480 (kind game, layer game, confidence high), dominant class hulkfight::ai::HulkActionCountCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f52721fd {
#define TREE_TU_END }
namespace fn_f52721fd {} using namespace fn_f52721fd;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f52721fd {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_f52721fd
namespace fight {
class ConditionFactoryCaster_1113e0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class HulkActionCountCondition_1113e0 {};
} }
namespace fn_f52721fd {
extern char DAT_00491ca8;
extern char DAT_004a4120;

} // namespace fn_f52721fd

// 0x001113e0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::HulkActionCountCondition>::vfunc_0 (36 B): matches/0x001113e0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VHulkActionCountCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::HulkActionCountCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a4120, 0) != 0;
}

