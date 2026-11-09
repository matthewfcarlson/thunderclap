#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
extern char DAT_0048e10c[];
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class Function_2f290 : public ScriptFunctionFields {
  public:
    virtual void f();
    Function_2f290(const char*, int);
};
class Owner_2f290 {};
typedef void (Owner_2f290::*Fn_2f290)();
class Method1_2f290 : public Function_2f290 {
  public:
    virtual void f();
    Fn_2f290 c;
    Method1_2f290(const char* s, Fn_2f290 x) : Function_2f290(s, 1) {
        c = x;
        retType = FUN_001d04d0(((char*)&DAT_0048e0f0));
        argTypes[0] = FUN_001d04d0(DAT_0048e10c);
    }
};
class Closure1_2f290 : public Method1_2f290 {
  public:
    virtual void f();
    Owner_2f290* d;
    Closure1_2f290(const char*, Owner_2f290*, Fn_2f290);
};
Closure1_2f290::Closure1_2f290(const char* s, Owner_2f290* x, Fn_2f290 y) : Method1_2f290(s, y) {
    d = x;
}
