#include "decls/data/game/global.h"
#include "decls/data/script.h"
// data: tag1 = DAT_004c5d10, tag2 = DAT_0048e0f0

// Closure1<ScriptHandler, ScriptHandler::script_state, const char*>'s constructor (name, object, member function):
// Function's fields (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class ScriptHandler_1d4320 {
  public:
    enum script_state { s0 };
};
typedef ScriptHandler_1d4320::script_state (ScriptHandler_1d4320::*Fn_1d4320)(const char*);
class Root : public ScriptFunctionFields {
  public:
    Root(const char*, int);
    virtual void f();
    Fn_1d4320 x;
};
extern int check(const char*);
class Closure1_1d4320 : public Root {
  public:
    Closure1_1d4320(const char*, ScriptHandler_1d4320*, Fn_1d4320);
    virtual void f();
};
class Closure1 : public Closure1_1d4320 {
  public:
    Closure1(const char*, ScriptHandler_1d4320*, Fn_1d4320);
    virtual void f();
    ScriptHandler_1d4320* y;
};
Closure1_1d4320::Closure1_1d4320(const char* s, ScriptHandler_1d4320* x0, Fn_1d4320 x1) : Root(s, 1) {
    x = x1;
    retType = check(((const char*)&DAT_004c5d10));
    argTypes[0] = check(((const char*)&DAT_0048e0f0));
}
Closure1::Closure1(const char* s, ScriptHandler_1d4320* x0, Fn_1d4320 x1) : Closure1_1d4320(s, x0, x1) {
    y = x0;
}
