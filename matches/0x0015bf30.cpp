// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_15bf30;
class CCondition_15bf30 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::LocomotionSprintTrack::vfunc_0(int index) {
    int* p = gTable_15bf30;
    return p[index];
}
