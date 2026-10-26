// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_48a90;
class CCondition_48a90 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CCharacterSizeCondition::vfunc_0(int index) {
    int* p = gTable_48a90;
    return p[index];
}
