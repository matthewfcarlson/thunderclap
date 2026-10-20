// Same code shape as 0x0018b6f0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_18b9a0;
void* __cdecl alloc(unsigned int);
struct InitObj_18b9a0 {
    void init(int);
};
extern int vtable_18b9a0;

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PropIsAttachedCondition>::vfunc_5() {
    char* p = (char*)alloc(0x14);
    if (p) {
        ((InitObj_18b9a0*)p)->init(0);
        *(hulk_uintptr*)p = (hulk_uintptr)&vtable_18b9a0;
        *(u32_18b9a0*)(p + 0xc) = 0xffffffff;
        p[0x10] = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
