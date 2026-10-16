// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_193f90;
class CCondition_193f90 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::AccuracyLatencyTrack::vfunc_0(int index) {
    int* p = gTable_193f90;
    return p[index];
}
