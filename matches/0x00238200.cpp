// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/fight.h"

extern int* gTable_238200;
class CCondition_238200 {
  public:
    virtual int vfunc_0(int);
};

int fight::MaybeCondition::vfunc_0(int index) {
    int* p = gTable_238200;
    return p[index];
}
