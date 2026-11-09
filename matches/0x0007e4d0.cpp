#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// Closure2's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method2's member-function pointer and Closure2's object.
class Owner_7e4d0 {};
typedef void (Owner_7e4d0::*Fn_7e4d0)();
class Function_7e4d0 : public ScriptFunctionFields {
  public:
    virtual void fn();
    Function_7e4d0(const char*, int);
    Fn_7e4d0 u;
};
class Method2 : public Function_7e4d0 {
  public:
    virtual void fn();
    Method2(const char* p, Fn_7e4d0 r) : Function_7e4d0(p, 2) {
        u = r;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
        argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
};
class Closure2 : public Method2 {
  public:
    virtual void fn();
    Owner_7e4d0* v;
    Closure2(const char*, Owner_7e4d0*, Fn_7e4d0);
};
Closure2::Closure2(const char* p, Owner_7e4d0* q, Fn_7e4d0 r) : Method2(p, r) {
    v = q;
}
