// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_10c810;
class CCondition_10c810 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::DefendingCondition::vfunc_0(int index) {
    int* p = gTable_10c810;
    return p[index];
}
