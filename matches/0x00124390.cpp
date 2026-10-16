// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_124390;
class CCondition_124390 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::AcquireTargetTrack::vfunc_0(int index) {
    int* p = gTable_124390;
    return p[index];
}
