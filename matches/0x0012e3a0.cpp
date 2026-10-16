// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_12e3a0;
class CCondition_12e3a0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::UnlockableCondition::vfunc_0(int index) {
    int* p = gTable_12e3a0;
    return p[index];
}
