#include "compat/ptr.h"
class ConditionFactoryCaster_11a980 {
  public:
    virtual void Cast();
};
class ConditionFactoryCasterTemplate_11a980 : public ConditionFactoryCaster_11a980 {
  public:
    virtual void Cast();
};
extern void* Find(int, ConditionFactoryCaster_11a980*);
class Owner {
  public:
    void Set(void*);
};
extern "C" void FUN_0011a980(Owner* owner, hulk_intptr id) {
    ConditionFactoryCasterTemplate_11a980 caster;
    void* result = Find(id, &caster);
    owner->Set(result);
}