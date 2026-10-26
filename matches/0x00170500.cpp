// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_170500;
class CCondition_170500 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::DriftToHulkTrack::vfunc_0(int index) {
    int* p = gTable_170500;
    return p[index];
}
