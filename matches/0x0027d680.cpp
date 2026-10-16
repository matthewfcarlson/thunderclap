#include "gen/pure3d.h"

struct Ref_27d680 {
    virtual void f0();
    virtual void f1();
};
struct Child_27d680 {
    virtual void f0();
};
struct H;
struct H {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13(Child_27d680*);
};

void pure3d::prop::StateProp::vfunc_13(void* __p0) { Child_27d680 * p = (Child_27d680 *)__p0;

    if (p)
        p->f0();
    Ref_27d680*& cur = (*(Ref_27d680 * *)&this->f_10);
    if (cur)
        cur->f1();
    cur = (Ref_27d680*)p;
    (*(H * *)&this->f_9c)->a13(p);
}
