#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// data: name1 = DAT_0048e0e4, name2 = DAT_0048e0f0
// Method1's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_2c790 : public CtorV_001d0480 {
  public:
    Function_2c790(const char* s) : CtorV_001d0480(s, 1) { }
};
class Owner_2c790 {};
typedef void (Owner_2c790::*Fn_2c790)();
class Method1 : public Function_2c790 {
  public:
    virtual void fn();
    Fn_2c790 c;
    Method1(const char*, Fn_2c790);
};
Method1::Method1(const char* s, Fn_2c790 v) : Function_2c790(s) {
    c = v;
    retType = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
}
