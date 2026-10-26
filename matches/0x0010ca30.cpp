// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_10ca30;
class CCondition_10ca30 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::PropsToChuckCondition::vfunc_0(int index) {
    int* p = gTable_10ca30;
    return p[index];
}
