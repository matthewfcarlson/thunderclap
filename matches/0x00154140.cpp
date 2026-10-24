#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004b1f30;
namespace fight {
class ConditionFactoryCaster_154140 {
  public:
    virtual int Check(void*);
    virtual void Other();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class CollisionSourceTypeCondition_154140;
}
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b1f30, 0) != 0;
}
