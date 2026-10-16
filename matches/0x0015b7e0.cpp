// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_15b7e0;
class CCondition_15b7e0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::JointPlantedCondition::vfunc_0(int index) {
    int* p = gTable_15b7e0;
    return p[index];
}
