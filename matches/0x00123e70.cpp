// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_123e70;
class CCondition_123e70 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::ProjectileDistanceCondition::vfunc_0(int index) {
    int* p = gTable_123e70;
    return p[index];
}
