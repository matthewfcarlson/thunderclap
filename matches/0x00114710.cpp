#include "gen/fight.h"

extern "C" char DAT_0040db44[];
typedef unsigned char u8;
typedef unsigned int u32_114710;
void* __cdecl Allocate(unsigned int);
struct InitObj_114710 {
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TokenCondition>::vfunc_5() {
    void* p = Allocate(0x10);
    if (p) {
        ((InitObj_114710*)p)->Init(0);
        ((u8*)p)[0xc] = 1;
        ((u8*)p)[0xd] = 1;
        *(u32_114710*)p = ((int)DAT_0040db44);
        return (void*)(p);
    }
    return (void*)((void*)0);
}
