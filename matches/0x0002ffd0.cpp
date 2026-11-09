#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_2ffd0 : public CtorV_001d0480 {
  public:
    Function_2ffd0(const char* a) : CtorV_001d0480(a, 1) { }
};
class Owner_2ffd0 {};
typedef void (Owner_2ffd0::*Fn_2ffd0)();
class Method1 : public Function_2ffd0 {
  public:
    virtual void invoke();
    Fn_2ffd0 data;
    Method1(const char* a, Fn_2ffd0 c) : Function_2ffd0(a) {
        data = c;
        retType = FUN_001d04d0(((char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0e4));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void invoke();
    Owner_2ffd0* extra;
    Closure1(const char* a, Owner_2ffd0* b, Fn_2ffd0 c);
};
Closure1::Closure1(const char* a, Owner_2ffd0* b, Fn_2ffd0 c) : Method1(a, c) {
    extra = b;
}
