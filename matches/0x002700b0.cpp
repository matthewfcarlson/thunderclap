#include "gen/core.h"

class PoolOther {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(void*);
};

void core::MemoryPool::vfunc_4(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    unsigned int a = (unsigned int)p;
    unsigned int b = this->f_18;
    if (a >= b && a < (*(unsigned int *)&this->f_20) * (*(unsigned int *)&this->f_1c) + b) {
        *p = (unsigned int)(*(unsigned int * *)&this->f_10);
        (*(unsigned int * *)&this->f_10) = p;
        --this->f_28;
        return;
    }
    if ((*(PoolOther * *)&this->f_30))
        (*(PoolOther * *)&this->f_30)->f4(p);
    --this->f_28;
}
