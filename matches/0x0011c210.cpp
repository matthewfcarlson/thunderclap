// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_11c210;
class CCondition_11c210 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::PathLocatorTestCondition::vfunc_0(int index) {
    int* p = gTable_11c210;
    return p[index];
}
