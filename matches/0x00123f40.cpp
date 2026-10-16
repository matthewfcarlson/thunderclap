// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_123f40;
class CCondition_123f40 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::TargetVelocityYCondition::vfunc_0(int index) {
    int* p = gTable_123f40;
    return p[index];
}
