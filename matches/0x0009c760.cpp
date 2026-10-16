#include "gen/global.h"

class CCameraManager_9c760 {
  public:
    void Set(int, int, int, bool, float);
};
union V {
    bool b;
    int n;
    float f;
};

template <> void Closure5<CCameraManager, void, bool, bool, bool, bool, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { V * args = (V *)__p1;

    V a, b, c;
    a.b = args->b;
    ++args;
    b.b = args->b;
    ++args;
    c.b = args->b;
    ++args;
    ((*(CCameraManager_9c760 * *)&this->f_20)->*(*(void (CCameraManager_9c760::**)(int, int, int, bool, float))&this->f_1c))(a.n, b.n, c.n, args->b, (args + 1)->f);
}
