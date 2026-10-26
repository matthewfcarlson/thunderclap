// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_180960;
class CCondition_180960 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::PropStateByIndexCondition::vfunc_0(int index) {
    int* p = gTable_180960;
    return p[index];
}
