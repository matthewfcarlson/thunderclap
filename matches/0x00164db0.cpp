#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00415950[];
class Entity_164db0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
};
class Factory_164db0 : public Entity_164db0 {
    char pad[12];
};
extern void* __cdecl FUN_0008d690(unsigned int);
class Init_164db0 {
  public:
    void InitIt(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::LocomotingCondition>::vfunc_5() {
    Init_164db0* p = (Init_164db0*)FUN_0008d690(0x10);
    if (p) {
        p->InitIt(0);
        *(void**)p = (void*)((hulk_intptr)DAT_00415950);
        *((char*)p + 0xc) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
