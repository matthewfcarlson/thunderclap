#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned char u8;
typedef unsigned int u32_23ce70;
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern u32_23ce70 PlatformVtable;
class PlatformCondition_23ce70 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    char pad[8];
    void init(int);
    u8 flags[4];
};

template <> void* fight::ConditionFactoryTemplate<fight::PlatformCondition>::vfunc_5() {
    PlatformCondition_23ce70* p = (PlatformCondition_23ce70*)Alloc(0x10);
    if (p != 0) {
        p->init(0);
        p->flags[0] = 1;
        p->flags[1] = 1;
        p->flags[2] = 1;
        p->flags[3] = 1;
        *(hulk_uintptr*)p = (hulk_uintptr)&PlatformVtable;
        return (void*)(p);
    }
    return (void*)(0);
}
