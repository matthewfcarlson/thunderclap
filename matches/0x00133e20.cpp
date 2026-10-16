// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_133e20;
class CCondition_133e20 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::FlyingAutoTargetTrack::vfunc_0(int index) {
    int* p = gTable_133e20;
    return p[index];
}
