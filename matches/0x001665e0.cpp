// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_1665e0;
class CCondition_1665e0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::ShoreNearCondition::vfunc_0(int index) {
    int* p = gTable_1665e0;
    return p[index];
}
