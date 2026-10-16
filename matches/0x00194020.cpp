// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_194020;
class CCondition_194020 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::FireBeamTrack::vfunc_0(int index) {
    int* p = gTable_194020;
    return p[index];
}
