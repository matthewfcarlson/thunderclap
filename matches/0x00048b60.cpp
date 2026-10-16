// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_48b60;
class CCondition_48b60 {
  public:
    virtual int vfunc_0(int);
};

int CCollisionHitLocationCondition::vfunc_0(int index) {
    int* p = gTable_48b60;
    return p[index];
}
