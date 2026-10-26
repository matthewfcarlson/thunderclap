// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_180d10;
class CCondition_180d10 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::PropDropTrack::vfunc_0(int index) {
    int* p = gTable_180d10;
    return p[index];
}
