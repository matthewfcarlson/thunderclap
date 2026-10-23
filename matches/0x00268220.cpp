#include "gen/core.h"

namespace core {

struct Timer_268220 {
    unsigned fun(core::TimerList*, unsigned, unsigned, unsigned, unsigned, unsigned);
};
struct Source {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual Timer_268220* get();
};

} // namespace core
void core::TimerList::vfunc_3(int __p0, int __p1, int __p2, int __p3, int __p4, int __p5) { unsigned int * result = (unsigned int *)__p0; unsigned int a = (unsigned int)__p1; unsigned int b = (unsigned int)__p2; unsigned int c = (unsigned int)__p3; unsigned int d = (unsigned int)__p4; unsigned int e = (unsigned int)__p5;

    Timer_268220* timer = (*(Source * *)&this->f_18)->get();
    *result = timer ? timer->fun(this, a, b, c, d, e) : 0;
}
