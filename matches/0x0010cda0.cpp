// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_10cda0;
class CCondition_10cda0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::InActiveCondition::vfunc_0(int index) {
    int* p = gTable_10cda0;
    return p[index];
}
