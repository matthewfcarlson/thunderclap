#include "gen/global.h"

struct CWorldStreamManager_205680 {};
struct Arguments {
    const char* volatile name;
    volatile int number;
    bool flag;
};
struct Function_205680 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method3<CWorldStreamManager, void, const char *, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CWorldStreamManager_205680 * object = (CWorldStreamManager_205680 *)__p0; Arguments * arguments = (Arguments *)__p1; void * unused = (void *)__p2;

    const char* name = arguments->name;
    (object->*(*(void (CWorldStreamManager_205680::**)(const char *, int, bool))&this->f_1c))(name, arguments->number, arguments->flag);
}
