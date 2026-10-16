// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_12e250;
class CCondition_12e250 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::MissionProgressCondition::vfunc_0(int index) {
    int* p = gTable_12e250;
    return p[index];
}
