// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_1242a0;
class CCondition_1242a0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::CanSeeTargetCondition::vfunc_0(int index) {
    int* p = gTable_1242a0;
    return p[index];
}
