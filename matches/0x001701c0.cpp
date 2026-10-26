// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_1701c0;
class CCondition_1701c0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::SuckTrack::vfunc_0(int index) {
    int* p = gTable_1701c0;
    return p[index];
}
