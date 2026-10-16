// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_15b860;
class CCondition_15b860 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::PhaseCondition::vfunc_0(int index) {
    int* p = gTable_15b860;
    return p[index];
}
