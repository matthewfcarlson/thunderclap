// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_123d90;
class CCondition_123d90 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::TargetDistanceYCondition::vfunc_0(int index) {
    int* p = gTable_123d90;
    return p[index];
}
