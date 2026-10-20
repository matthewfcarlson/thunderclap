#include "compat/ptr.h"
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern void* timerVtable;
struct TimerCondition {
    void* vptr;
    char pad[8];
    int a;
    int b;
    int c;
    char flag;
    char pad2[3];
    int d;
    void Init(int);
};
TimerCondition* factory_vfunc5() {
    TimerCondition* p = (TimerCondition*)Alloc(0x20);
    if (p) {
        p->Init(0);
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->flag = 0;
        p->d = 0;
        p->vptr = &timerVtable;
        return p;
    }
    return 0;
}