// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_10cbe0;
class CCondition_10cbe0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::KeyWordWaitCondition::vfunc_0(int index) {
    int* p = gTable_10cbe0;
    return p[index];
}
