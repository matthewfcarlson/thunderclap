#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class Function_2f150 : public ScriptFunctionFields {
  public:
    Function_2f150(const char*, int);
    virtual void v();
};
class Owner_2f150 {};
typedef void (Owner_2f150::*Fn_2f150)();
class Method1 : public Function_2f150 {
  public:
    Fn_2f150 value;
    Method1(const char* p, Fn_2f150 x) : Function_2f150(p, 1) {
        value = x;
        retType = FUN_001d04d0(((char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e134));
    }
    virtual void v();
};
class Closure1 : public Method1 {
  public:
    Owner_2f150* value2;
    Closure1(const char* p, Owner_2f150* n, Fn_2f150 x);
    virtual void v();
};
Closure1::Closure1(const char* p, Owner_2f150* n, Fn_2f150 x) : Method1(p, x) {
    value2 = n;
}
