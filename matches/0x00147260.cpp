// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_147260;
class CCondition_147260 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::CivilianAttachedCondition::vfunc_0(int index) {
    int* p = gTable_147260;
    return p[index];
}
