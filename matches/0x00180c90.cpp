// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_180c90;
class CCondition_180c90 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::PropActorThinkingTrack::vfunc_0(int index) {
    int* p = gTable_180c90;
    return p[index];
}
