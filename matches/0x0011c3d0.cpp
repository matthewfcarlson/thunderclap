// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_11c3d0;
class CCondition_11c3d0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::PathFormationTrack::vfunc_0(int index) {
    int* p = gTable_11c3d0;
    return p[index];
}
