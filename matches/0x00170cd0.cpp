// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_170cd0;
class CCondition_170cd0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::IntentionClearTrack::vfunc_0(int index) {
    int* p = gTable_170cd0;
    return p[index];
}
