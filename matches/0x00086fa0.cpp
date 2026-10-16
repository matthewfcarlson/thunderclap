#include "gen/global.h"

class Function_86fa0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, void**, void**);
};

template <> void Function2<const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * ignored = (void *)__p0; void ** args = (void **)__p1; void ** out = (void **)__p2;

    void* a = args[0];
    void* b = args[1];
    void* fn = (*(void * *)&this->f_1c);
    void* value = ((void*(__cdecl*)(void*, void*))fn)(a, b);
    if (out)
        *out = value;
}
