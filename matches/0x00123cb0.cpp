// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_123cb0;
class CCondition_123cb0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::TargetAngleYCondition::vfunc_0(int index) {
    int* p = gTable_123cb0;
    return p[index];
}
