#include "gen/global.h"

class ScriptHandler_1d42f0 {
  public:
    void Call(const char*, const char*, const char*, const char*);
};

template <> void Closure4<ScriptHandler, void, const char *, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** args = (const char **)__p1; void * b = (void *)__p2;

    const char** p = args;
    const char* x = *p++;
    const char* y = *p++;
    const char* z = *p++;
    const char* w = *p++;
    ((*(ScriptHandler_1d42f0 * *)&this->f_20)->*(*(void (ScriptHandler_1d42f0::**)(const char *, const char *, const char *, const char *))&this->f_1c))(x, y, z, w);
}
