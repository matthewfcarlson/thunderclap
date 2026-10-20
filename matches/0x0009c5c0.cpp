#include "gen/global.h"

struct P9C5C0_9c5c0 {
    char a;
    char pad[3];
    char b;
    char pad2[3];
    char c;
};
class Mgr_9c5c0 {
  public:
    void f(unsigned char, unsigned char, unsigned char);
};
class Function_9c5c0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Closure3<CCameraManager, void, bool, bool, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; P9C5C0_9c5c0 * p = (P9C5C0_9c5c0 *)__p1; void * c = (void *)__p2;

    char t = p->a;
    p->a = t;
    ((*(Mgr_9c5c0 * *)&this->f_20)->*(*(void (Mgr_9c5c0::**)(unsigned char, unsigned char, unsigned char))&this->f_1c))((unsigned char)t, (unsigned char)p->b, (unsigned char)p->c);
}
