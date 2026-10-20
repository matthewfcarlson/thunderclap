#include "gen/global.h"

class CRenderManager_1ba4f0 {
  public:
    void invoke(int, int, int);
};
class Function_1ba4f0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Args {
    volatile int a, b, c;
};

template <> void Closure3<CRenderManager, void, int, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { Args * args = (Args *)__p1;

    int a = args->a;
    int c = args->c;
    int b = args->b;
    ((*(CRenderManager_1ba4f0 * *)&this->f_20)->*(*(void (CRenderManager_1ba4f0::**)(int, int, int))&this->f_1c))(a, b, c);
}
