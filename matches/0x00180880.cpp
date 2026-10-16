// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_180880;
class CCondition_180880 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::PropIsAttachedCondition::vfunc_0(int index) {
    int* p = gTable_180880;
    return p[index];
}
