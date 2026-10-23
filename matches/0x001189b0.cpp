#include "gen/fight.h"

extern int __cdecl Find(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a5628;
namespace fight {
class ConditionFactoryCaster_1189b0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class ComputeDropZoneCondition_1189b0 {};
} // namespace ai
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::ComputeDropZoneCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Find(p, 0, &DAT_00491ca8, &DAT_004a5628, 0) != 0;
}
