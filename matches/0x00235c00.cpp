// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

extern int* gTable_235c00;
class CCondition_235c00 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr fight::FightNodeTimeCondition::vfunc_0(int index) {
    int* p = gTable_235c00;
    return p[index];
}
