// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_1aaeb0;
class CCondition_1aaeb0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::scenario::Event_FirstTimeCondition::vfunc_0(int index) {
    int* p = gTable_1aaeb0;
    return p[index];
}
