// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_170800;
class CCondition_170800 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::TeleportTrack::vfunc_0(int index) {
    int* p = gTable_170800;
    return p[index];
}
