// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_123b40;
class CCondition_123b40 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::TargetArcCondition::vfunc_0(int index) {
    int* p = gTable_123b40;
    return p[index];
}
