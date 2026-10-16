// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_165a50;
class CCondition_165a50 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::ChargeCondition::vfunc_0(int index) {
    int* p = gTable_165a50;
    return p[index];
}
