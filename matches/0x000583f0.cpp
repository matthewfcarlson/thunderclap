#include "gen/fight.h"

extern "C" char DAT_003f7550[];
void* operator new(unsigned int);
class CMotionClimbAngleCondition_583f0 {
  public:
    void Init(int);
    int w[6];
};

template <> void* fight::ConditionFactoryTemplate<CMotionClimbAngleCondition>::vfunc_5() {
    CMotionClimbAngleCondition_583f0* p = (CMotionClimbAngleCondition_583f0*)operator new(0x18);
    if (p) {
        p->Init(0);
        p->w[0] = ((int)DAT_003f7550);
        p->w[3] = 0;
        p->w[4] = 0x3fc90fdb;
        p->w[5] = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
