#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(const char*, const char*, const char*, const char*, int);
namespace fight {
class ConditionFactoryCaster_111540 {
  public:
    virtual int vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class RandomKeyWordWaitCondition_111540 {};
} // namespace ai
} // namespace hulkfight
extern const char DAT_00491ca8[];
extern const char DAT_004a4290[];
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, DAT_00491ca8, DAT_004a4290, 0) != 0;
}
