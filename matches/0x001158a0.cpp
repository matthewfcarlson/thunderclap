// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_1158a0;
class CCondition_1158a0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::MotionFleeTrack::vfunc_0(int index) {
    int* p = gTable_1158a0;
    return p[index];
}
