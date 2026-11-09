#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
typedef unsigned char u8;
// Closure2<Owner, void, float, float>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class Owner_9c440 {};
typedef void (Owner_9c440::*Fn_9c440)(float, float);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_9c440 : public CtorV_001d0480 {
  public:
    Function_9c440(const char* a) : CtorV_001d0480(a, 2) { }
};
class Method2 : public Function_9c440 {
  public:
    virtual void Fn();
    Fn_9c440 p1;
    Owner_9c440* p2;
    Method2(const char* a, Fn_9c440 b) : Function_9c440(a) {
        p1 = b;
        retType = FUN_001d04d0(((int*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((int*)&DAT_0048e128));
        argTypes[1] = FUN_001d04d0(((int*)&DAT_0048e128));
    }
};
class Closure2 : public Method2 {
  public:
    virtual void Fn();
    Closure2(const char*, Owner_9c440*, Fn_9c440);
};
Closure2::Closure2(const char* a, Owner_9c440* b, Fn_9c440 c) : Method2(a, c) {
    p2 = b;
}
