// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_133d60;
class CCondition_133d60 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::FallTrack::vfunc_0(int index) {
    int* p = gTable_133d60;
    return p[index];
}
