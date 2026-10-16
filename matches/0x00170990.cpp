// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_170990;
class CCondition_170990 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::SurfTrack::vfunc_0(int index) {
    int* p = gTable_170990;
    return p[index];
}
