// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_4a0d0;
class CCondition_4a0d0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CGrappleCharacterTemplateCondition::vfunc_0(int index) {
    int* p = gTable_4a0d0;
    return p[index];
}
