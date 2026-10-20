#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_13e370;
extern void* __cdecl alloc(unsigned int);
struct Init_13e370 {
    void f(int);
};
struct Sub_13e370 {
    void f();
};
struct FrameReachedCondition_13e370 {
    u32_13e370 vptr;
    char pad[0x1c];
};
extern u32_13e370 frame_vtable;

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::FrameReachedCondition>::vfunc_5() {
    FrameReachedCondition_13e370* p = (FrameReachedCondition_13e370*)alloc(0x20);
    if (p) {
        ((Init_13e370*)p)->f(0);
        p->vptr = (hulk_uintptr)&frame_vtable;
        ((Sub_13e370*)((char*)p + 0x10))->f();
        *(u32_13e370*)((char*)p + 0x18) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
