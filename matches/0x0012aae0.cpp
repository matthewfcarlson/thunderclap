#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0040feb4[];
typedef unsigned int u32_12aae0;
typedef unsigned char u8;
struct AcquireTargetCondition_12aae0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad4[8];
    float a;
    float b;
    u8 c;
    void Initialize(int);
};
void* __cdecl alloc(unsigned int);

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::AcquireTargetCondition>::vfunc_5() {
    AcquireTargetCondition_12aae0* p = (AcquireTargetCondition_12aae0*)alloc(0x18);
    if (p) {
        p->Initialize(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040feb4);
        p->a = 1.57079637f;
        p->b = 100.0f;
        p->c = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
