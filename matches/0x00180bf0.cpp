// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_180bf0;
class CCondition_180bf0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::PropSetStateByNameTrack::vfunc_0(int index) {
    int* p = gTable_180bf0;
    return p[index];
}
