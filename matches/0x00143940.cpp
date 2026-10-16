// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_143940;
class CCondition_143940 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::WorldConeDamageTrack::vfunc_0(int index) {
    int* p = gTable_143940;
    return p[index];
}
