// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_123d20;
class CCondition_123d20 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::TargetDirectionCondition::vfunc_0(int index) {
    int* p = gTable_123d20;
    return p[index];
}
