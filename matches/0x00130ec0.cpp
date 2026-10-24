#include "gen/fight.h"

struct Token {
    int x;
};
extern char DAT_00491ca8;
extern char DAT_004aaa68;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_130ec0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
class ChapterMissionCondition_130ec0 {};
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ChapterMissionCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004aaa68, 0) != 0;
}
