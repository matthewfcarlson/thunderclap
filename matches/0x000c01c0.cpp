#include "gen/global.h"

class CFEManager_c01c0 {
  public:
    void method(const char*, const char*, const char*, const char*, const char*, const char*);
};
inline const char* take(const char**& p) {
    return *p++;
}

template <> void Closure6<CFEManager, void, const char *, const char *, const char *, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char ** a = (const char **)__p1;

    const char* t0 = take(a);
    const char* t1 = take(a);
    const char* t2 = take(a);
    const char* t3 = take(a);
    const char* t4 = take(a);
    const char* t5 = take(a);
    ((*(CFEManager_c01c0 * *)&this->f_20)->*(*(void (CFEManager_c01c0::**)(const char *, const char *, const char *, const char *, const char *, const char *))&this->f_1c))(t0, t1, t2, t3, t4, t5);
}
