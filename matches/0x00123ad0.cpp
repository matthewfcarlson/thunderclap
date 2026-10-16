// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_123ad0;
class CCondition_123ad0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::TargetDirectionYCondition::vfunc_0(int index) {
    int* p = gTable_123ad0;
    return p[index];
}
