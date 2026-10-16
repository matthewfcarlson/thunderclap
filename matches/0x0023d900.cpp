// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/fight.h"

extern int* gTable_23d900;
class CCondition_23d900 {
  public:
    virtual int vfunc_0(int);
};

int fight::CommentTrack::vfunc_0(int index) {
    int* p = gTable_23d900;
    return p[index];
}
