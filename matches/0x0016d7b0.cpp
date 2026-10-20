#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_16d7b0;
typedef unsigned char u8;
void* __cdecl Allocate(unsigned int);
struct IntentionInputCondition_16d7b0 {
    u8 pad[16];
    void Init(int);
};
extern u32_16d7b0 gVft;

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::IntentionInputCondition>::vfunc_5() {
    IntentionInputCondition_16d7b0* p = (IntentionInputCondition_16d7b0*)Allocate(0x10);
    if (p) {
        p->Init(0);
        ((u8*)p)[0xd] = 1;
        ((u8*)p)[0xe] = 1;
        ((u8*)p)[0xf] = 1;
        *(hulk_uintptr*)p = (hulk_uintptr)&gVft;
        ((u8*)p)[0xc] = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
