#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
extern const char DAT_0048e10c[];
// Closure1<Owner, void, A1>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_cfb90 {};
typedef void (Owner_cfb90::*Fn_cfb90)(int);
class Function_cfb90 : public ScriptFunctionFields {
  public:
    Function_cfb90(const char*, int);
    virtual void f();
};
class Method1 : public Function_cfb90 {
  public:
    Method1(const char* a, Fn_cfb90 c) : Function_cfb90(a, 1) {
        p = c;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(DAT_0048e10c);
    }
    virtual void g();
    Fn_cfb90 p;
};
class Closure1 : public Method1 {
  public:
    Closure1(const char*, Owner_cfb90*, Fn_cfb90);
    virtual void g();
    Owner_cfb90* q;
};
Closure1::Closure1(const char* a, Owner_cfb90* b, Fn_cfb90 c) : Method1(a, c) {
    q = b;
}
