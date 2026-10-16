#include "gen/global.h"

struct Function_1f7af0 {
    virtual void f0();
    virtual void f1();
};
struct Dummy_1f7af0 {
    int x;
};
typedef bool (Dummy_1f7af0::*Fn_1f7af0)(bool);

template <> void Method1<CEffectManager, bool, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; bool * b = (bool *)__p1; bool * out = (bool *)__p2;

    Fn_1f7af0 f = (*(Fn_1f7af0 *)&this->f_1c);
    bool bv = *b;
    bool v = (((Dummy_1f7af0*)a)->*f)(bv);
    if (out)
        *out = v;
}
