#include "decls/data/game/global.h"
#include "decls/data/script.h"
// data: key1 = DAT_0048e100, key2 = DAT_0048e0f0
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.

struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char FUN_001d04d0(const char*);
class Function_1cbeb0 : public CtorV_001d0480 {
  public:
    Function_1cbeb0(const char* s) : CtorV_001d0480(s, 1) { }
};
class Method1 : public Function_1cbeb0 {
  public:
    virtual void f();
    ScriptMemberFn fn;
    Method1(const char* s, ScriptMemberFn o) : Function_1cbeb0(s) {
        fn = o;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    void* owner;
    Closure1(const char*, void*, ScriptMemberFn);
};
Closure1::Closure1(const char* s, void* a, ScriptMemberFn o) : Method1(s, o) {
    owner = a;
}
