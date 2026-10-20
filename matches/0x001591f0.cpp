#include "compat/ptr.h"
extern void* __cdecl Alloc(hulk_uintptr);
extern void* vtable_1591f0;
class Condition {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual Condition* vfunc_5();
    char pad[8];
    int x;
    int y;
    void Init(int);
};
Condition* Condition::vfunc_5() {
    Condition* p = (Condition*)Alloc(0x14);
    if (p) {
        p->Init(0);
        *(void**)p = &vtable_1591f0;
        p->x = 0;
        p->y = 0;
        return p;
    }
    return 0;
}