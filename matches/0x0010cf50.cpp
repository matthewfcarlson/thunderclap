// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_10cf50;
class CCondition_10cf50 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::RandomKeyWordWaitCondition::vfunc_0(int index) {
    int* p = gTable_10cf50;
    return p[index];
}
