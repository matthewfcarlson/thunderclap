// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_4a7a0;
class CCondition_4a7a0 {
  public:
    virtual int vfunc_0(int);
};

int CCharacterBoolCondition::vfunc_0(int index) {
    int* p = gTable_4a7a0;
    return p[index];
}
