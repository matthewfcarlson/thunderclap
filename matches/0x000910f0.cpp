#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Closure1<Owner, int, const char*>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_910f0 {};
typedef int (Owner_910f0::*Fn_910f0)(const char*);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_910f0 : public CtorV_001d0480 {
  public:
    Function_910f0(const char* s) : CtorV_001d0480(s, 1) { }
};
class Method1 : public Function_910f0 {
  public:
    virtual void f();
    Fn_910f0 z;
    Method1(const char* s, Fn_910f0 n) : Function_910f0(s) {
        z = n;
        retType = FUN_001d04d0(((const char*)&DAT_0048e134));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void g();
    Owner_910f0* w;
    Closure1(const char*, Owner_910f0*, Fn_910f0);
};
Closure1::Closure1(const char* s, Owner_910f0* n, Fn_910f0 v) : Method1(s, v) {
    w = n;
}
