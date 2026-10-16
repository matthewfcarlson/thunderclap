// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_180a40;
class CCondition_180a40 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::PropCollidedWithWorldCondition::vfunc_0(int index) {
    int* p = gTable_180a40;
    return p[index];
}
