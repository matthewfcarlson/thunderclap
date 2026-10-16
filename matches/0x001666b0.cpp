// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_1666b0;
class CCondition_1666b0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::ThinkingCondition::vfunc_0(int index) {
    int* p = gTable_1666b0;
    return p[index];
}
