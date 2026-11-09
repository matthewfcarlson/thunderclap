#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Closure1<Owner, void, bool>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_b0350 {};
typedef void (Owner_b0350::*Fn_b0350)(bool);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_b0350 : public CtorV_001d0480 {
  public:
    Function_b0350(const char* n) : CtorV_001d0480(n, 1) { }
};
class Method1 : public Function_b0350 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    Fn_b0350 arg;
    Method1(const char* n, Fn_b0350 v) : Function_b0350(n) {
        arg = v;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    Owner_b0350* extra;
    Closure1(const char* n, Owner_b0350* v, Fn_b0350 z);
};
Closure1::Closure1(const char* n, Owner_b0350* v, Fn_b0350 z) : Method1(n, z) {
    extra = v;
}
