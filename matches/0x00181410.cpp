// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_181410;
class CCondition_181410 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::PropAddToCollisionTrack::vfunc_0(int index) {
    int* p = gTable_181410;
    return p[index];
}
