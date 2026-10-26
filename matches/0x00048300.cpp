#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_48300;
class CCondition_48300 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CStageCondition::vfunc_0(int index) {
    int* p = gTable_48300;
    return p[index];
}
