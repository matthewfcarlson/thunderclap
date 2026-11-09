#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
extern int b;
// Closure2<Owner, void, A1, bool>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class Owner_9ce20 {};
typedef void (Owner_9ce20::*Fn_9ce20)(int, bool);
class Function_9ce20 : public ScriptFunctionFields {
  public:
    Function_9ce20(const char*, int) throw();
    virtual void f();
    Fn_9ce20 p;
};
class Method2 : public Function_9ce20 {
  public:
    Method2(const char* arg1, Fn_9ce20 arg3) throw() : Function_9ce20(arg1, 2) {
        p = arg3;
        retType = FUN_001d04d0(((int*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(&b);
        argTypes[1] = FUN_001d04d0(((int*)&DAT_0048e0e4));
    }
    virtual void f();
};
class Closure2 : public Method2 {
  public:
    Closure2(const char*, Owner_9ce20*, Fn_9ce20) throw();
    virtual void f();
    Owner_9ce20* q;
};
Closure2::Closure2(const char* arg1, Owner_9ce20* arg2, Fn_9ce20 arg3) throw() : Method2(arg1, arg3) {
    q = arg2;
}
