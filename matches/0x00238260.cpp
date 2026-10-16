// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/fight.h"

extern int* gTable_238260;
class CCondition_238260 {
  public:
    virtual int vfunc_0(int);
};

int fight::RandomCondition::vfunc_0(int index) {
    int* p = gTable_238260;
    return p[index];
}
