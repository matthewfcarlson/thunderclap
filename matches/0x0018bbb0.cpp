#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0041926c[];
typedef unsigned int u32_18bbb0;
typedef unsigned char u8;
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
class Condition_18bbb0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    char pad[8];
    int fieldC;
    u8 flag10;
    void init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_5() {
    Condition_18bbb0* p = (Condition_18bbb0*)FUN_0008d690((int)sizeof(Condition_18bbb0));
    if (p) {
        p->init(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0041926c);
        p->fieldC = 0;
        p->flag10 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
