// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_10d390;
class CCondition_10d390 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::ButtonTrack::vfunc_0(int index) {
    int* p = gTable_10d390;
    return p[index];
}
