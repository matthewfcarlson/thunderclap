// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_18f210;
class CCondition_18f210 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::SimulationTrack::vfunc_0(int index) {
    int* p = gTable_18f210;
    return p[index];
}
