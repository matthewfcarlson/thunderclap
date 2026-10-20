#include "compat/ptr.h"
#include "gen/fight.h"
extern "C" char DAT_00428b64[];
class Factory_23d780 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* V5();
    char pad[8];
    int m0c;
    int m10;
};
struct DebugCondition_nv_23d780 {
    void InitFn(int);
};
extern "C" void* __cdecl Alloc(unsigned int);
void* Factory_23d780::V5() {
    Factory_23d780* p = (Factory_23d780*)Alloc(0x14);
    if (p) {
        ((DebugCondition_nv_23d780*)(((fight::DebugCondition*)p)))->InitFn(0);
        *(hulk_ulongptr*)p = ((hulk_intptr)DAT_00428b64);
        p->m0c = 0;
        p->m10 = 0;
        return p;
    }
    return 0;
}