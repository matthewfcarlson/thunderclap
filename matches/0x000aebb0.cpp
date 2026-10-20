#include "gen/global.h"

class Function_aebb0 {
  public:
    virtual void v0();
    virtual void v1();
};
struct Args {
    int a;
    bool b;
};
class CControllerManager_aebb0 {
  public:
    void fn(int, bool);
};

template <> void Method2<CControllerManager, void, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CControllerManager_aebb0 * obj = (CControllerManager_aebb0 *)__p0; Args * args = (Args *)__p1;

    (obj->*(*(void (CControllerManager_aebb0::**)(int, bool))&this->f_1c))(args->a, args->b);
}
