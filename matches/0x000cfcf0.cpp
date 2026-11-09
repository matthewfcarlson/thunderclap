#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Closure2<Owner, void, int, A2>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class Owner_cfcf0 {};
typedef void (Owner_cfcf0::*Fn_cfcf0)(int, int);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern char DAT_0048e10c[];
class Function_cfcf0 : public CtorV_001d0480 {
  public:
    Function_cfcf0(const char* x) : CtorV_001d0480(x, 2) { }
};
class Method2 : public Function_cfcf0 {
  public:
    virtual void f();
    Fn_cfcf0 d;
    Method2(const char* x, Fn_cfcf0 y) : Function_cfcf0(x) {
        d = y;
        retType = FUN_001d04d0(((char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e134));
        argTypes[1] = FUN_001d04d0(DAT_0048e10c);
    }
};
class Closure2 : public Method2 {
  public:
    virtual void f();
    Owner_cfcf0* e;
    Closure2(const char*, Owner_cfcf0*, Fn_cfcf0);
};
Closure2::Closure2(const char* x, Owner_cfcf0* y, Fn_cfcf0 z) : Method2(x, z) {
    e = y;
}
