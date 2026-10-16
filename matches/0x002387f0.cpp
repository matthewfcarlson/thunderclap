#include "gen/fight.h"

extern "C" char DAT_00428210[];
extern "C" void* __cdecl alloc(unsigned int);
struct RandomCondition_2387f0 {
    int vf;
    int pad[2];
    int value;
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<fight::RandomCondition>::vfunc_5() {
    RandomCondition_2387f0* p = (RandomCondition_2387f0*)alloc(0x10);
    if (p) {
        p->Init(0);
        p->vf = ((int)DAT_00428210);
        p->value = 0;
    } else {
        p = 0;
    }
    return (void*)(p);
}
