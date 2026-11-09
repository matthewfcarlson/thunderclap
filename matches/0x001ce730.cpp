#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class CScenarioManager;
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
struct Function_1ce730 : public CtorV_001d0480 {
    Function_1ce730(const char* a) : CtorV_001d0480(a, 1) { }
};
class Method1 : public Function_1ce730 {
  public:
    virtual void fn();
    ScriptMemberFn arg;
    Method1(const char*, ScriptMemberFn);
};
class Closure1 : public Method1 {
  public:
    virtual void fn();
    void* extra;
    Closure1(const char*, void*, ScriptMemberFn);
};
inline Method1::Method1(const char* a, ScriptMemberFn c) : Function_1ce730(a) {
    arg = c;
    retType = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e134));
}
Closure1::Closure1(const char* a, void* b, ScriptMemberFn c) : Method1(a, c) {
    extra = b;
}
