// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_48f80;
class CCondition_48f80 {
  public:
    virtual int vfunc_0(int);
};

int CCollisionPushbackVelocityCondition::vfunc_0(int index) {
    int* p = gTable_48f80;
    return p[index];
}
