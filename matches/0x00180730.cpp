// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_180730;
class CCondition_180730 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::PropGrabbableIsThrownCondition::vfunc_0(int index) {
    int* p = gTable_180730;
    return p[index];
}
