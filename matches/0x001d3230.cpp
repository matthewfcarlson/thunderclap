#include "gen/global.h"

class ScriptHandler_1d3230 {
  public:
    int Do(const char*);
};
class Function_1d3230 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(ScriptHandler_1d3230*, const char**, int*);
    char pad[24];
};

template <> void Method1<ScriptHandler, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { ScriptHandler_1d3230 * obj = (ScriptHandler_1d3230 *)__p0; const char ** arg = (const char **)__p1; int * out = (int *)__p2;

    int (ScriptHandler_1d3230::*fn)(const char*) = (*(int (ScriptHandler_1d3230::**)(const char *))&this->f_1c);
    const char* v = *arg;
    int result = (obj->*fn)(v);
    if (out)
        *out = result;
}
