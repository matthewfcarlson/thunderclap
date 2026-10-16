// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_170620;
class CCondition_170620 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::MomentumXZAddTrack::vfunc_0(int index) {
    int* p = gTable_170620;
    return p[index];
}
