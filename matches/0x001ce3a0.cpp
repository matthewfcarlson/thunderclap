#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class Function_1ce3a0 : public ScriptFunctionFields {
  public:
    Function_1ce3a0(const char*, int);
    virtual void f();
    ScriptMemberFn x;
    void* y;
};
class Method1 : public Function_1ce3a0 {
  public:
    Method1(const char* a, ScriptMemberFn c) : Function_1ce3a0(a, 1) {
        x = c;
        retType = FUN_001d04d0(((int*)&DAT_0048e128));
        argTypes[0] = FUN_001d04d0(((int*)&DAT_0048e134));
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(const char* a, void* b, ScriptMemberFn c);
    virtual void f();
};
Closure1::Closure1(const char* a, void* b, ScriptMemberFn c) : Method1(a, c) {
    y = b;
}
