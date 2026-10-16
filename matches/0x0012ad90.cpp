#include "gen/fight.h"

extern "C" char DAT_0040ff34[];
extern void* __cdecl Allocate(unsigned int);
class TargetInvincibleCondition_12ad90 {
  public:
    TargetInvincibleCondition_12ad90(int);
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[8];
    unsigned char flag;
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetInvincibleCondition>::vfunc_5() {
    TargetInvincibleCondition_12ad90* p = (TargetInvincibleCondition_12ad90*)Allocate(0x10);
    if (p) {
        p->TargetInvincibleCondition_12ad90::TargetInvincibleCondition_12ad90(0);
        *(unsigned int*)p = ((int)DAT_0040ff34);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)((TargetInvincibleCondition_12ad90*)0);
}
