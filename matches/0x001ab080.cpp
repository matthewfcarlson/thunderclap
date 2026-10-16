// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_1ab080;
class CCondition_1ab080 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::scenario::Event_PathNameCondition::vfunc_0(int index) {
    int* p = gTable_1ab080;
    return p[index];
}
