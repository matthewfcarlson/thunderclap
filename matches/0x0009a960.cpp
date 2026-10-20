#include "gen/global.h"

class CCameraManager_9a960 {
  public:
    void Do(float, float, bool);
};
struct Args {
    float a, b;
    bool c;
};
class Function_9a960 {
  public:
    virtual void F0();
    virtual void F1();
};

template <> void Method3<CCameraManager, void, float, float, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CCameraManager_9a960 * obj = (CCameraManager_9a960 *)__p0; Args * args = (Args *)__p1; int unused = (int)__p2;

    Args* p = args;
    *(volatile float*)&args = p->a;
    (obj->*(*(void (CCameraManager_9a960::**)(float, float, bool))&this->f_1c))(*(float*)&args, p->b, p->c);
}
