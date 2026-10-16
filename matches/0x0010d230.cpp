// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_10d230;
class CCondition_10d230 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::HulkActionTrack::vfunc_0(int index) {
    int* p = gTable_10d230;
    return p[index];
}
