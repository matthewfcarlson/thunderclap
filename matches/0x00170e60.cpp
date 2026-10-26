// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_170e60;
class CCondition_170e60 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::ChargeClearTrack::vfunc_0(int index) {
    int* p = gTable_170e60;
    return p[index];
}
