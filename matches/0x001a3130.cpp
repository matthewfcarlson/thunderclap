// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_1a3130;
class CCondition_1a3130 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::scenario::EffectTrack::vfunc_0(int index) {
    int* p = gTable_1a3130;
    return p[index];
}
