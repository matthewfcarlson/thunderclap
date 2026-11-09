#include "decls/address.h"
#include "decls/data/script.h"
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern const char a[], b[];
class Function_7e120 : public CtorV_001d0480 {
  public:
    Function_7e120(const char* s) : CtorV_001d0480(s, 1) { }
};
class Owner_7e120 {};
typedef void (Owner_7e120::*Fn_7e120)();
class Method1 : public Function_7e120 {
  public:
    virtual void f();
    Fn_7e120 name;
    Method1(const char* s, Fn_7e120 p) : Function_7e120(s) {
        name = p;
        retType = FUN_001d04d0(a);
        argTypes[0] = FUN_001d04d0(b);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    Owner_7e120* obj;
    Closure1(const char*, Owner_7e120*, Fn_7e120);
};
Closure1::Closure1(const char* s, Owner_7e120* o, Fn_7e120 p) : Method1(s, p) {
    obj = o;
}
