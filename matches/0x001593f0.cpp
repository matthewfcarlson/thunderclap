#include "compat/ptr.h"
#include "gen/fight.h"

class HitPushbackCondition_1593f0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    int pad[2];
    unsigned char flag;
    void Init(int);
};
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern int vtable_1593f0;

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::HitPushbackCondition>::vfunc_5() {
    HitPushbackCondition_1593f0* p = (HitPushbackCondition_1593f0*)Alloc(0x10);
    if (p) {
        p->Init(0);
        *(hulk_intptr*)p = (hulk_intptr)&vtable_1593f0;
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
