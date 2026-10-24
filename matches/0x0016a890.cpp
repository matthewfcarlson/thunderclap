#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004b7340;
namespace fight {
class ConditionFactoryCaster_16a890 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CharacterPropStatusCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b7340, 0) != 0;
}
