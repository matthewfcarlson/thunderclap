// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_1806b0;
class CCondition_1806b0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::GrapplePropStateByNameCondition::vfunc_0(int index) {
    int* p = gTable_1806b0;
    return p[index];
}
