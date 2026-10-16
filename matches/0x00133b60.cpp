// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_133b60;
class CCondition_133b60 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::BounceTrack::vfunc_0(int index) {
    int* p = gTable_133b60;
    return p[index];
}
