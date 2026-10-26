// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_170b90;
class CCondition_170b90 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::SuckInPropsTrack::vfunc_0(int index) {
    int* p = gTable_170b90;
    return p[index];
}
