// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_1a2ea0;
class CCondition_1a2ea0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::scenario::Event_LocomotionStateNamePreviousCondition::vfunc_0(int index) {
    int* p = gTable_1a2ea0;
    return p[index];
}
