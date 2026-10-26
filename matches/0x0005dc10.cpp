#include "compat/ptr.h"
#include "gen/global.h"

class A_5dc10;
class Arg_5dc10 {
  public:
    A_5dc10* A1();
};
class A_5dc10 {
  public:
    A_5dc10* B();
    void* D();
};
class R_5dc10 {
  public:
    unsigned int E(void*, void*);
};
class Q_5dc10 {
  public:
    int F(void*, void*, unsigned int);
};
extern void* __cdecl FUN_0008d690(unsigned int);

hulk_intptr COpportunityBallTrack::vfunc_12(hulk_intptr __p0) { void * arg = (void *)__p0;

    A_5dc10* a = ((Arg_5dc10*)arg)->A1();
    a = a->B();
    if (!a)
        return 0;
    void* m = (*(void * *)&this->f_18);
    void* n = (*(void * *)&this->f_1c);
    unsigned int r = ((R_5dc10*)a->D())->E(m, n);
    if (r != 0xffff) {
        Q_5dc10* q = (Q_5dc10*)FUN_0008d690(0x5c);
        if (q)
            return q->F(this, arg, r);
    }
    return 0;
}
