// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_12efc0;
class CCondition_12efc0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::StatTrack::vfunc_0(int index) {
    int* p = gTable_12efc0;
    return p[index];
}
