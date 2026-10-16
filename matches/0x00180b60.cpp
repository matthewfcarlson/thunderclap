// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_180b60;
class CCondition_180b60 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::PropActorToPropTrack::vfunc_0(int index) {
    int* p = gTable_180b60;
    return p[index];
}
