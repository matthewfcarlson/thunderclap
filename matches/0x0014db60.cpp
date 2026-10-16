// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_14db60;
class CCondition_14db60 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::InterruptAccumulatorSetTrack::vfunc_0(int index) {
    int* p = gTable_14db60;
    return p[index];
}
