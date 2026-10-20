#include "gen/global.h"

class CActorManager_2d640 {
  public:
    bool Method(const char*, int);
};
class Function_2d640 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
};

template <> void Method2<CActorManager, bool, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2d640 * object = (CActorManager_2d640 *)__p0; void * args = (void *)__p1; bool * out = (bool *)__p2;

    struct Args {
        const char* name;
        int id;
    };
    Args* a = (Args*)args;
    bool (CActorManager_2d640::*f)(const char*, int) = (*(bool (CActorManager_2d640::**)(const char *, int))&this->f_1c);
    const char* name = a->name;
    int id = a->id;
    bool result = (object->*f)(name, id);
    if (out)
        *out = result;
}
