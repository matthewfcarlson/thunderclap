// Same code shape as 0x0002caf0 (propagated; names are from that function)
#include "gen/global.h"

struct Function_1e0f50 {
    virtual void f0();
    virtual void f1();
};
void FUN_0002cb10(const char*, const char*, const char*, int);

template <> void Method6<CSPManager, void, int, float, float, float, float, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_0002cb10(a, b, c, (*(int *)&this->f_1c));
}
