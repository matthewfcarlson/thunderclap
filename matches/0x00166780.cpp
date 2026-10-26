// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_166780;
class CCondition_166780 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::HealthCondition::vfunc_0(int index) {
    int* p = gTable_166780;
    return p[index];
}
