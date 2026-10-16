// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_170c30;
class CCondition_170c30 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::TeleportRelativeTrack::vfunc_0(int index) {
    int* p = gTable_170c30;
    return p[index];
}
