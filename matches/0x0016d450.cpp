#include "gen/fight.h"

extern "C" char DAT_00416698[];
class AllocThing {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class InitThing {
  public:
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::IntentionButtonDownAnyCondition>::vfunc_5() {
    InitThing* p = (InitThing*)FUN_0008d690(0x10);
    if (p) {
        p->Init(0);
        *(void**)p = (void*)((int)DAT_00416698);
        *((char*)p + 0xc) = 1;
        return (void*)(p);
    }
    return (void*)((void*)0);
}
