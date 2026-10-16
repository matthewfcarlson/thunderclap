// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_147790;
class CCondition_147790 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::GrappleExecuteTrack::vfunc_0(int index) {
    int* p = gTable_147790;
    return p[index];
}
