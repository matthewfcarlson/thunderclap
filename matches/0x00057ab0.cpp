#include "gen/fight.h"

#include "compat/ptr.h"
class ConditionFactory_57ab0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
};
class Entity_57ab0 {};
class LoadObject_57ab0 {};
class IRefCount_57ab0 {};
extern int CCollisionPushbackVelocityCondition_vftable;
class CCollisionPushbackVelocityCondition_57ab0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    int pad[2];
    int a, b, c;
    void Init(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::ConditionFactoryTemplate<CCollisionPushbackVelocityCondition>::vfunc_5() {
    CCollisionPushbackVelocityCondition_57ab0* p = (CCollisionPushbackVelocityCondition_57ab0*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        ((hulk_intptr*)p)[0] = (hulk_intptr)&CCollisionPushbackVelocityCondition_vftable;
        p->a = 0;
        p->b = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
