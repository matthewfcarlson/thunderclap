// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_6b160;
class CCondition_6b160 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CWallSlideTrack::vfunc_0(int index) {
    int* p = gTable_6b160;
    return p[index];
}
