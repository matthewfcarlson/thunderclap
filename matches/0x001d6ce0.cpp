#include "compat/ptr.h"
#include "gen/global.h"

struct V {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int, int);
};
struct A_1d6ce0 {
    bool run();
};
struct B_1d6ce0 {
    bool run();
};
struct G_1d6ce0 {
    char pad[8];
    B_1d6ce0* p;
};
extern G_1d6ce0* g_4dd700;

void CSPHulkPropInstance::vfunc_8(hulk_intptr x, int y) {
    if ((*(A_1d6ce0 * *)&this->f_ec)->run() && g_4dd700->p->run())
        return;
    (*(V * *)&this->f_9c)->f8(x, y);
}
