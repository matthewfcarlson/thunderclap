// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_170ef0;
class CCondition_170ef0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::VisibilityTrack::vfunc_0(int index) {
    int* p = gTable_170ef0;
    return p[index];
}
