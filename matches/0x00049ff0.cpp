// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_49ff0;
class CCondition_49ff0 {
  public:
    virtual int vfunc_0(int);
};

int CCharacterTemplateVariationCondition::vfunc_0(int index) {
    int* p = gTable_49ff0;
    return p[index];
}
