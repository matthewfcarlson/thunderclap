#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Closure1<Owner, const char*, int>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_91270 {};
typedef const char* (Owner_91270::*Fn_91270)(int);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_91270 : public CtorV_001d0480 {
  public:
    Function_91270(const char* s) : CtorV_001d0480(s, 1) { }
    Fn_91270 f1c;
};
class Method1 : public Function_91270 {
  public:
    virtual void invoke();
    Method1(const char* s, Fn_91270 n) : Function_91270(s) {
        f1c = n;
        retType = FUN_001d04d0(((const char*)&DAT_0048e0f0));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e134));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void invoke();
    Owner_91270* f20;
    Closure1(const char* s, Owner_91270* n, Fn_91270 m);
};
Closure1::Closure1(const char* s, Owner_91270* n, Fn_91270 m) : Method1(s, m), f20(n) {}
