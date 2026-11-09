#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// Closure1<ScriptHandler, float, const char*>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_1d4170 : public CtorV_001d0480 {
  public:
    Function_1d4170(const char* x) : CtorV_001d0480(x, 1) { }
};
class ScriptHandler_1d4170 {};
typedef float (ScriptHandler_1d4170::*Fn_1d4170)(const char*);
class Method1_1d4170 : public Function_1d4170 {
  public:
    virtual void f();
    Fn_1d4170 fn;
    Method1_1d4170(const char* x, Fn_1d4170 z) : Function_1d4170(x) {
        fn = z;
        retType = FUN_001d04d0(((int*)&DAT_0048e128));
        argTypes[0] = FUN_001d04d0(((int*)&DAT_0048e0f0));
    }
};
class Closure1_1d4170 : public Method1_1d4170 {
  public:
    virtual void f();
    ScriptHandler_1d4170* val;
    Closure1_1d4170(const char*, ScriptHandler_1d4170*, Fn_1d4170);
};
Closure1_1d4170::Closure1_1d4170(const char* x, ScriptHandler_1d4170* y, Fn_1d4170 z) : Method1_1d4170(x, z) {
    val = y;
}
