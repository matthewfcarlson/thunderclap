// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_4a210;
class CCondition_4a210 {
  public:
    virtual int vfunc_0(int);
};

int CMotionStateCondition::vfunc_0(int index) {
    int* p = gTable_4a210;
    return p[index];
}
