// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/fight.h"

extern int* gTable_235af0;
class CCondition_235af0 {
  public:
    virtual int vfunc_0(int);
};

int fight::FightNodeParentCondition::vfunc_0(int index) {
    int* p = gTable_235af0;
    return p[index];
}
