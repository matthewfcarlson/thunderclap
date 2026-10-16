// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_14dbf0;
class CCondition_14dbf0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::HitThrowTrack::vfunc_0(int index) {
    int* p = gTable_14dbf0;
    return p[index];
}
