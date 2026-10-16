// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_14e100;
class CCondition_14e100 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::ClearFightParamsHitRecordTrack::vfunc_0(int index) {
    int* p = gTable_14e100;
    return p[index];
}
