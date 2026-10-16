// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_115720;
class CCondition_115720 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::LocatorDistanceCondition::vfunc_0(int index) {
    int* p = gTable_115720;
    return p[index];
}
