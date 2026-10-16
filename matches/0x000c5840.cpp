#include "gen/global.h"

class ISoundManager_c5840 {
  public:
    virtual void f0();
    virtual void f1(void*, void*);
    virtual void f2();
};
class Helper_c5840 {
  public:
    void run(void*, void*);
};

void CFESoundManager::vfunc_1(void* __p0, void* __p1) { void * a = (void *)__p0; void * b = (void *)__p1;

    if ((*(void * *)&this->f_04))
        ((Helper_c5840*)(*(void * *)&this->f_04))->run(a, b);
}
