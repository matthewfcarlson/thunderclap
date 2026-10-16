// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_4a920;
class CCondition_4a920 {
  public:
    virtual int vfunc_0(int);
};

int CIntentionSpeedCondition::vfunc_0(int index) {
    int* p = gTable_4a920;
    return p[index];
}
