#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_1113e0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class HulkActionCountCondition_1113e0 {};
} // namespace ai
} // namespace hulkfight
extern char DAT_00491ca8;
extern char DAT_004a4120;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::HulkActionCountCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a4120, 0) != 0;
}
