#include "compat/ptr.h"
#include "gen/global.h"

struct Vector_9b740 {
    int x, y, z;
};
struct CCameraManager_9b740 {
    void f(Vector_9b740, unsigned char);
};
struct Function_9b740 {
    virtual void a();
    virtual void b();
};

template <> void Method2<CCameraManager, void,math::Vector, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; Vector_9b740 * p = (Vector_9b740 *)__p1; hulk_intptr c = (hulk_intptr)__p2;

    ((CCameraManager_9b740*)a->*(*(void (CCameraManager_9b740::**)(Vector_9b740, unsigned char))&this->f_1c))(*p, *((unsigned char*)p + 12));
}
