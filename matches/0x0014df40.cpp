// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_14df40;
class CCondition_14df40 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::InterruptPriorityTrack::vfunc_0(int index) {
    int* p = gTable_14df40;
    return p[index];
}
