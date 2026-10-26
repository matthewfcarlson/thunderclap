// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_12e950;
class CCondition_12e950 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::NISSoundTrack::vfunc_0(int index) {
    int* p = gTable_12e950;
    return p[index];
}
