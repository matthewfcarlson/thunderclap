// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_10c730;
class CCondition_10c730 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::OnBlockedTriangleCondition::vfunc_0(int index) {
    int* p = gTable_10c730;
    return p[index];
}
