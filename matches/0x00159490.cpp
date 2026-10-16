#include "gen/fight.h"

extern "C" char DAT_00414070[];
class Condition_159490 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    void Init(int);
    char pad[8];
    char flag;
};
extern void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionTargetIsTargetCondition>::vfunc_5() {
    Condition_159490* p = (Condition_159490*)FUN_0008d690(0x10);
    if (p) {
        p->Init(0);
        *((int*)p) = ((int)DAT_00414070);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
