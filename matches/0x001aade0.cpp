// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_1aade0;
class CCondition_1aade0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::scenario::Event_TriggerVolumeNameCondition::vfunc_0(int index) {
    int* p = gTable_1aade0;
    return p[index];
}
