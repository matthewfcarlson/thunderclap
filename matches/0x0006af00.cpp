// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_6af00;
class CCondition_6af00 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CAIHintTrack::vfunc_0(int index) {
    int* p = gTable_6af00;
    return p[index];
}
