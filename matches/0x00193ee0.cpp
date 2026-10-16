// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_193ee0;
class CCondition_193ee0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::MissilePunchTrack::vfunc_0(int index) {
    int* p = gTable_193ee0;
    return p[index];
}
