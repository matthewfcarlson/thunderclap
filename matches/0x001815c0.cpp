// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_1815c0;
class CCondition_1815c0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::PropSpawnTrack::vfunc_0(int index) {
    int* p = gTable_1815c0;
    return p[index];
}
