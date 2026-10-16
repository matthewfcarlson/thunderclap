// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_133ee0;
class CCondition_133ee0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::FlyingAttackTrack::vfunc_0(int index) {
    int* p = gTable_133ee0;
    return p[index];
}
