#include "gen/fight.h"

extern "C" char DAT_003f7274[];
typedef unsigned int U_58600;
extern void* __cdecl alloc(unsigned int);
struct CPropActorStateCondition_58600 {
    virtual void v0();
    U_58600 x[4];
    void setup(int);
};

template <> void* fight::ConditionFactoryTemplate<CPropActorStateCondition>::vfunc_5() {
    CPropActorStateCondition_58600* p = (CPropActorStateCondition_58600*)alloc(0x14);
    if (p) {
        p->setup(0);
        *(U_58600*)p = ((int)DAT_003f7274);
        *(U_58600*)((char*)p + 0xc) = 2;
        *(U_58600*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
