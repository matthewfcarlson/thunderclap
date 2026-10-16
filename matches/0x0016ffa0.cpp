// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_16ffa0;
class CCondition_16ffa0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::JointRelativeTrack::vfunc_0(int index) {
    int* p = gTable_16ffa0;
    return p[index];
}
