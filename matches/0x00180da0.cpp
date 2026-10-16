// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_180da0;
class CCondition_180da0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::PropAnimationTrack::vfunc_0(int index) {
    int* p = gTable_180da0;
    return p[index];
}
