// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_180b00;
class CCondition_180b00 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::CSMPropIsCharacterCondition::vfunc_0(int index) {
    int* p = gTable_180b00;
    return p[index];
}
