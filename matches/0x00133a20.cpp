// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_133a20;
class CCondition_133a20 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::GrappleHoverTrack::vfunc_0(int index) {
    int* p = gTable_133a20;
    return p[index];
}
