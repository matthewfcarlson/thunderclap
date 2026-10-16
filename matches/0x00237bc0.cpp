// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/fight.h"

extern int* gTable_237bc0;
class CCondition_237bc0 {
  public:
    virtual int vfunc_0(int);
};

int fight::SequenceTrack::vfunc_0(int index) {
    int* p = gTable_237bc0;
    return p[index];
}
