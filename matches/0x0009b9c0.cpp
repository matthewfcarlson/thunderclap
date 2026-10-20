#include "gen/global.h"

class CCameraManager_9b9c0 {
  public:
    void Fn(char*, char*, char*, char*);
};
class Function_9b9c0 {
  public:
    virtual void f0();
    virtual void f1();
};
inline char* next(char**& p) {
    return *p++;
}

template <> void Method4<CCameraManager, void, char *, char *, char *, char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CCameraManager_9b9c0 * obj = (CCameraManager_9b9c0 *)__p0; char ** args = (char **)__p1;

    char* a = next(args);
    char* b = next(args);
    char* c = next(args);
    char* d = next(args);
    (obj->*(*(void (CCameraManager_9b9c0::**)(char *, char *, char *, char *))&this->f_1c))(a, b, c, d);
}
