// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_170d60;
class CCondition_170d60 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::TeleportToLocatorTrack::vfunc_0(int index) {
    int* p = gTable_170d60;
    return p[index];
}
