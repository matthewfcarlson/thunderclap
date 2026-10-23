#include "gen/fight.h"

extern int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004bda50;
namespace fight {
class ConditionFactoryCaster_186b60 {
  public:
    virtual bool Cast(void*);
    virtual void Other();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class PropCollidedWithWorldCondition_186b60;
}
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_00491ca8, &DAT_004bda50, 0) != 0;
}
