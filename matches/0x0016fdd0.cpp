// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_16fdd0;
class CCondition_16fdd0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::ChargeTrack::vfunc_0(int index) {
    int* p = gTable_16fdd0;
    return p[index];
}
