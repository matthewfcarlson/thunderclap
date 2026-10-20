#include "compat/ptr.h"
extern "C" char DAT_0040d9c4[];
class DefendingCondition {
  public:
    int vptr;
    char pad4[8];
    unsigned char flag;
    void Init(int);
};
extern void* __cdecl Alloc(unsigned int);
void* FactoryVfunc5() {
    DefendingCondition* p = (DefendingCondition*)Alloc(0x10);
    if (p) {
        p->Init(0);
        p->vptr = ((hulk_intptr)DAT_0040d9c4);
        p->flag = 1;
        return p;
    }
    return 0;
}
