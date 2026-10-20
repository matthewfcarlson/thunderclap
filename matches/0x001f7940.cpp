#include "gen/global.h"

class CEffectManager_1f7940 {
  public:
    unsigned int Do(char*, float, float);
};
class Function_1f7940 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(CEffectManager_1f7940*, void*, unsigned int*);
};

template <> void Method3<CEffectManager, unsigned int, char *, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CEffectManager_1f7940 * obj = (CEffectManager_1f7940 *)__p0; void * args = (void *)__p1; unsigned int * result = (unsigned int *)__p2;

    struct Args {
        char* a;
        float b;
        float c;
    };
    Args* p = (Args*)args;
    unsigned int (CEffectManager_1f7940::*fn)(char*, float, float) = (*(unsigned int (CEffectManager_1f7940::**)(char *, float, float))&this->f_1c);
    char* a = p->a;
    float b = p->b;
    float c = p->c;
    unsigned int r = (obj->*fn)(a, b, c);
    if (result)
        *result = r;
}
