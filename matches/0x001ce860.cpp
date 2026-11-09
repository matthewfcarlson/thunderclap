#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class Function_1ce860 : public ScriptFunctionFields {
  public:
    Function_1ce860(const char*, int);
    virtual void f();
    ScriptMemberFn c;
};
class Method1 : public Function_1ce860 {
  public:
    Method1(const char* x, ScriptMemberFn y) : Function_1ce860(x, 1) {
        c = y;
        retType = FUN_001d04d0(&DAT_004c55f0);
        argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e134));
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(const char* x, void* y, ScriptMemberFn z);
    virtual void f();
    void* d;
};
Closure1::Closure1(const char* x, void* y, ScriptMemberFn z) : Method1(x, z) {
    d = y;
}
