// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_133980;
class CCondition_133980 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::FlyingDashTrack::vfunc_0(int index) {
    int* p = gTable_133980;
    return p[index];
}
