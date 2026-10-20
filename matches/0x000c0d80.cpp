#include "compat/ptr.h"
extern "C" char DAT_003fef7c[];
struct Obj_c0d80 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3(void*, unsigned long long);
};
extern unsigned long long Get(void*);
int Target(Obj_c0d80* p, int b) {
    unsigned long long x = Get((void*)b);
    struct Local {
        void* v;
    };
    Local local;
    local.v = (void*)((hulk_intptr)DAT_003fef7c);
    return p->f3(&local, x);
}
