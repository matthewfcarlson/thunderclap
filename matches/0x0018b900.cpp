#include "compat/ptr.h"
struct PropAtRestCondition {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[8];
    unsigned char flag;
    void Init(int);
};
extern void* __cdecl alloc(hulk_uintptr);
extern int prop_vtable;
void* Factory_vfunc5() {
    PropAtRestCondition* p = (PropAtRestCondition*)alloc(0x10);
    if (p) {
        p->Init(0);
        *((hulk_intptr*)p) = (hulk_intptr)&prop_vtable;
        p->flag = 1;
        return p;
    }
    return 0;
}
