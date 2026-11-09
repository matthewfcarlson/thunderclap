#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// Closure1<Owner, void, float>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_cf960 {};
typedef void (Owner_cf960::*Fn_cf960)(float);
class Function_cf960 : public ScriptFunctionFields {
  public:
    virtual void Invoke(float);
    Function_cf960(const char*, int);
};
class Method1 : public Function_cf960 {
  public:
    virtual void Invoke(float);
    Fn_cf960 obj;
    Method1(const char* x, Fn_cf960 y) : Function_cf960(x, 1) {
        obj = y;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke(float);
    Owner_cf960* extra;
    Closure1(const char*, Owner_cf960*, Fn_cf960);
};
Closure1::Closure1(const char* x, Owner_cf960* y, Fn_cf960 z) : Method1(x, z) {
    extra = y;
}
