#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// data: textA = DAT_0048e128, textB = DAT_0048e0f0

// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" char __cdecl Check(const char*);
class Base : public CtorV_001d0480 {
  public:
    Base(const char* x) : CtorV_001d0480(x, 1) { }
};
class Owner_2e790 {};
typedef void (Owner_2e790::*Fn_2e790)();
class Method : public Base {
  public:
    virtual void f();
    Fn_2e790 name;
    Owner_2e790* val;
    Method(const char*, Owner_2e790*, Fn_2e790);
};
class Closure1_2e790 : public Method {
  public:
    virtual void g();
    Closure1_2e790(const char*, Owner_2e790*, Fn_2e790);
};
Closure1_2e790::Closure1_2e790(const char* x, Owner_2e790* y, Fn_2e790 z) : Method(x, y, z) {
    val = y;
}
Method::Method(const char* x, Owner_2e790* y, Fn_2e790 z) : Base(x) {
    name = z;
    retType = Check(((const char*)&DAT_0048e128));
    argTypes[0] = Check(((const char*)&DAT_0048e0f0));
}
