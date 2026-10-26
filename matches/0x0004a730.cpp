// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_4a730;
class CCondition_4a730 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CCharacterFloatCondition::vfunc_0(int index) {
    int* p = gTable_4a730;
    return p[index];
}
