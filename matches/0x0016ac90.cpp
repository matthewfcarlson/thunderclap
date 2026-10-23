#include "gen/fight.h"

extern int typeA;
extern int typeB;
extern "C" void* __cdecl castThing(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_16ac90 {
  public:
    virtual bool Check(void*);
    virtual void Other();
};

} // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::ThinkingCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return castThing(p, 0, &typeA, &typeB, 0) != 0;
}
