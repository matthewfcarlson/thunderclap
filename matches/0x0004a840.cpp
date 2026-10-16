// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_4a840;
class CCondition_4a840 {
  public:
    virtual int vfunc_0(int);
};

int CFightNodePrevCondition::vfunc_0(int index) {
    int* p = gTable_4a840;
    return p[index];
}
