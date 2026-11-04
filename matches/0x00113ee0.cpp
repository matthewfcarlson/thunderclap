#include "compat/ptr.h"
extern "C" char DAT_0040d9c4[];
class DefendingCondition {
  public:
    hulk_intptr vptr;
    char pad4[8];
    unsigned char flag;
    void Init(int);
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
void* FactoryVfunc5() {
    DefendingCondition* p = (DefendingCondition*)FUN_0008d690((int)sizeof(DefendingCondition));
    if (p) {
        p->Init(0);
        p->vptr = ((hulk_intptr)DAT_0040d9c4);
        p->flag = 1;
        return p;
    }
    return 0;
}
