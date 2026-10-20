#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_18b6f0;
void* __cdecl alloc(hulk_uintptr);
struct InitObj_18b6f0 {
    void init(int);
};
extern int vtable_18b6f0;

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PropMissionCriticalCondition>::vfunc_5() {
    char* p = (char*)alloc(0x14);
    if (p) {
        ((InitObj_18b6f0*)p)->init(0);
        *(hulk_uintptr*)p = (hulk_uintptr)&vtable_18b6f0;
        *(u32_18b6f0*)(p + 0xc) = 0xffffffff;
        p[0x10] = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
