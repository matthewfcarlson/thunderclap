// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_49140;
class CCondition_49140 {
  public:
    virtual int vfunc_0(int);
};

int CSmartPropAttachedCondition::vfunc_0(int index) {
    int* p = gTable_49140;
    return p[index];
}
