// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_193c80;
class CCondition_193c80 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::FireProjectileTrack::vfunc_0(int index) {
    int* p = gTable_193c80;
    return p[index];
}
