// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_1aaf80;
class CCondition_1aaf80 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::scenario::Event_CharacterTemplateCondition::vfunc_0(int index) {
    int* p = gTable_1aaf80;
    return p[index];
}
