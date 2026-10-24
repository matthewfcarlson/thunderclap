#include "gen/fight.h"

namespace fight {
class ConditionFactory_16ab50 {
  public:
    virtual ~ConditionFactory_16ab50() throw();
};
template <class T> class ConditionFactoryTemplate_16ab50 : public ConditionFactory_16ab50 {};
class ConditionFactoryCaster_16ab50 {
  public:
    virtual bool vfunc_0(ConditionFactory_16ab50*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class RageModeStateCondition_16ab50;
} // namespace motion
} // namespace hulkfight
// the original asks whether a factory is the RageModeStateCondition one: dynamic_cast to
// fight::ConditionFactoryTemplate<hulkfight::motion::RageModeStateCondition> (RTTI 0x004b77d0) from fight::ConditionFactory
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::RageModeStateCondition>::vfunc_0(void* __p0) { fight::ConditionFactory_16ab50 * p = (fight::ConditionFactory_16ab50 *)__p0;

    return dynamic_cast<fight::ConditionFactoryTemplate_16ab50<hulkfight::motion::RageModeStateCondition_16ab50>*>(p) != 0;
}
