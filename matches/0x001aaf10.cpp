// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_1aaf10;
class CCondition_1aaf10 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::scenario::Event_WaypointCondition::vfunc_0(int index) {
    int* p = gTable_1aaf10;
    return p[index];
}
