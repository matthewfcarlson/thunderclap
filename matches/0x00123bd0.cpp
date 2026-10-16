// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_123bd0;
class CCondition_123bd0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::TargetTypeCondition::vfunc_0(int index) {
    int* p = gTable_123bd0;
    return p[index];
}
