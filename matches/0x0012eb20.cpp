// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_12eb20;
class CCondition_12eb20 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::DialogueTrack::vfunc_0(int index) {
    int* p = gTable_12eb20;
    return p[index];
}
