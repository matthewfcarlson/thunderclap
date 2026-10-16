// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_10d4c0;
class CCondition_10d4c0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::TokenTrack::vfunc_0(int index) {
    int* p = gTable_10d4c0;
    return p[index];
}
