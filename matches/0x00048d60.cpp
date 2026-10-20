#include "compat/ptr.h"
extern "C" char DAT_003f7010[];
class Sub_48d60 {
  public:
    void Init();
};
class CNameFlagConditionBase {
  public:
    int m0;
    char pad[8];
    int mC;
    Sub_48d60 sub;
    CNameFlagConditionBase();
};
struct ThisCall_00234590 {
    void FUN_00234590(int);
};
CNameFlagConditionBase::CNameFlagConditionBase() {
    ((ThisCall_00234590*)(this))->FUN_00234590(0);
    m0 = ((hulk_intptr)DAT_003f7010);
    mC = 0;
    sub.Init();
}