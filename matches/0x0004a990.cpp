// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_4a990;
class CCondition_4a990 {
  public:
    virtual int vfunc_0(int);
};

int CClimbEdgeCondition::vfunc_0(int index) {
    int* p = gTable_4a990;
    return p[index];
}
