// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_1ab000;
class CCondition_1ab000 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::scenario::Event_CharacterTemplateVariationCondition::vfunc_0(int index) {
    int* p = gTable_1ab000;
    return p[index];
}
