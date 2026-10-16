// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_143880;
class CCondition_143880 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::WorldDamageTrack::vfunc_0(int index) {
    int* p = gTable_143880;
    return p[index];
}
