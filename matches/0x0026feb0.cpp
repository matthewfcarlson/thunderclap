#include "gen/core.h"

class MemPoolParent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual char Stats(int* a, int* b, int* c, int* d);
};

bool core::MemoryPool::vfunc_9(void* __p0, void* __p1, void* __p2, void* __p3) { int * a = (int *)__p0; int * b = (int *)__p1; int * c = (int *)__p2; int * d = (int *)__p3;

    if (a)
        *a = 0;
    if (b)
        *b = 0;
    if (c)
        *c = 0;
    if (d)
        *d = 0;
    if ((*(MemPoolParent * *)&this->f_30))
        (*(MemPoolParent * *)&this->f_30)->Stats(a, b, c, d);
    if (a)
        *a += (this->f_20 - this->f_28) * this->f_1c;
    if (b)
        *b += this->f_1c;
    if (c)
        *c += this->f_28;
    if (d)
        *d += this->f_2c * this->f_1c;
    return (bool)(1);
}
