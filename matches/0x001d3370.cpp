#include "gen/global.h"

class ScriptHandler_1d3370;
class ScriptHandler_1d3370 {
  public:
    enum script_state { s0, s1 };
    script_state Get(const char* s);
};
typedef ScriptHandler_1d3370::script_state (ScriptHandler_1d3370::*Fn_1d3370)(const char*);
struct Function_1d3370 {
    virtual void f0();
    virtual void f1();
};

template <> void Method1<ScriptHandler,ScriptHandler::script_state, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { ScriptHandler_1d3370 * a = (ScriptHandler_1d3370 *)__p0; const char ** p = (const char **)__p1; ScriptHandler_1d3370::script_state * out = (ScriptHandler_1d3370::script_state *)__p2;

    Fn_1d3370 f = (*(Fn_1d3370 *)&this->f_1c);
    const char* s = *p;
    ScriptHandler_1d3370::script_state x = (a->*f)(s);
    if (out)
        *out = x;
}
