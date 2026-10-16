#include "gen/fight.h"

extern "C" char DAT_003f7034[];
typedef unsigned int u32_57960;
struct CCollisionInterruptCondition_57960 {
    u32_57960 vf;
    char pad[8];
    unsigned char flag;
};
extern void* __cdecl allocate(unsigned int);
struct Initializer_57960 {
    void init(int);
};

template <> void* fight::ConditionFactoryTemplate<CCollisionInterruptCondition>::vfunc_5() {
    CCollisionInterruptCondition_57960* p = (CCollisionInterruptCondition_57960*)allocate(0x10);
    if (p) {
        ((Initializer_57960*)p)->init(0);
        p->vf = ((int)DAT_003f7034);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)((CCollisionInterruptCondition_57960*)0);
}
