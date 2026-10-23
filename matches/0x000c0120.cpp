#include "gen/global.h"

struct CFEManager_c0120 {
    void Do(const char*, const char*, const char*, const char*, const char*, const char*, const char*);
};
struct Args {
    const char* values[7];
};
class Function_c0120 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, void*, void*);
};

template <> void Closure7<CFEManager, void, const char *, const char *, const char *, const char *, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * p0 = (void *)__p0; void * p1 = (void *)__p1; void * p2 = (void *)__p2;

    Args* args = (Args*)p1;
    const char** a = args->values;
    const char* v0 = *a++;
    const char* v1 = *a++;
    const char* v2 = *a++;
    const char* v3 = *a++;
    const char* v4 = *a++;
    const char* v5 = *a++;
    const char* v6 = *a++;
    ((*(CFEManager_c0120 * *)&this->f_20)->*(*(void (CFEManager_c0120::**)(const char *, const char *, const char *, const char *, const char *, const char *, const char *))&this->f_1c))(v0, v1, v2, v3, v4, v5, v6);
}
