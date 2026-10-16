// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_10c870;
class CCondition_10c870 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::AIHistoryNameCondition::vfunc_0(int index) {
    int* p = gTable_10c870;
    return p[index];
}
