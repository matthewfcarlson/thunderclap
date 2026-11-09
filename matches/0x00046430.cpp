#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class Owner_46430 {};
typedef void (Owner_46430::*Fn_46430)();
class Base : public ScriptFunctionFields {
  public:
    virtual void f();
    Base(const char*, int);
    Fn_46430 c;
};
class Closure1_46430 : public Base {
  public:
    Closure1_46430(const char*, Fn_46430);
    virtual void f();
};
Closure1_46430::Closure1_46430(const char* s, Fn_46430 x) : Base(s, 1) {
    c = x;
    retType = FUN_001d04d0(((char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
}
class Closure1 : public Closure1_46430 {
  public:
    Owner_46430* d;
    Closure1(const char*, Owner_46430*, Fn_46430);
    virtual void f();
};
Closure1::Closure1(const char* s, Owner_46430* x, Fn_46430 y) : Closure1_46430(s, y) {
    d = x;
}
