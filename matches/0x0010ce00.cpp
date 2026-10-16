// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_10ce00;
class CCondition_10ce00 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::HulkActionCountCondition::vfunc_0(int index) {
    int* p = gTable_10ce00;
    return p[index];
}
