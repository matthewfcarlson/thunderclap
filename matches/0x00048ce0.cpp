// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_48ce0;
class CCondition_48ce0 {
  public:
    virtual int vfunc_0(int);
};

int CCollisionPushbackDirectionCondition::vfunc_0(int index) {
    int* p = gTable_48ce0;
    return p[index];
}
