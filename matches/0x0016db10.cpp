#include "compat/ptr.h"
extern char VT_16db10[];
extern void* __cdecl alloc(hulk_uintptr);
class TargetCondition {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* Create();
    int x;
    int y;
    int z;
    int w;
    TargetCondition(int);
};
void* TargetCondition::Create() {
    TargetCondition* p = (TargetCondition*)alloc(0x14);
    if (p) {
        p->TargetCondition::TargetCondition(0);
        *(void**)p = VT_16db10;
        p->z = 0;
        p->w = 0;
        return p;
    }
    return 0;
}