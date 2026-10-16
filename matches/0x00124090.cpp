// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_124090;
class CCondition_124090 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::AcquireTargetCondition::vfunc_0(int index) {
    int* p = gTable_124090;
    return p[index];
}
