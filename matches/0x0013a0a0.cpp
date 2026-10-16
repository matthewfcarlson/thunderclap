// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_13a0a0;
class CCondition_13a0a0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::FrameCondition::vfunc_0(int index) {
    int* p = gTable_13a0a0;
    return p[index];
}
