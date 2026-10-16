// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_1805d0;
class CCondition_1805d0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::PropMissionCriticalCondition::vfunc_0(int index) {
    int* p = gTable_1805d0;
    return p[index];
}
