// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_10c950;
class CCondition_10c950 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::HulkActionLargestCondition::vfunc_0(int index) {
    int* p = gTable_10c950;
    return p[index];
}
