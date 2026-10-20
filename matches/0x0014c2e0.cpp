#include "compat/ptr.h"
extern "C" char DAT_00413578[];
extern "C" void* __cdecl alloc(hulk_uintptr);
class Base_14c2e0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* F();
};
class Cond_14c2e0 {
  public:
    void Init(int);
};
class Sub_14c2e0 {
  public:
    void Init();
};
class Factory_14c2e0 : public Base_14c2e0 {
  public:
    char pad[8];
    int field;
    Sub_14c2e0 sub;
    void* F();
};
void* Factory_14c2e0::F() {
    Factory_14c2e0* p = (Factory_14c2e0*)alloc(0x18);
    if (p) {
        ((Cond_14c2e0*)p)->Init(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00413578);
        p->field = 0;
        p->sub.Init();
        return p;
    }
    return 0;
}