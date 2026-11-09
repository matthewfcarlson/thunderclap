#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Closure2<Owner, void, int, int>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class Owner_d0080 {};
typedef void (Owner_d0080::*Fn_d0080)(int, int);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Base_d0080 : public CtorV_001d0480 {
  public:
    Base_d0080(const char* p) : CtorV_001d0480(p, 2) { }
};
class Closure2_d0080 : public Base_d0080 {
  public:
    virtual void f();
    Fn_d0080 m1;
    Closure2_d0080(const char*, Owner_d0080*, Fn_d0080);
};
Closure2_d0080::Closure2_d0080(const char* p, Owner_d0080* a, Fn_d0080 b) : Base_d0080(p) {
    m1 = b;
    retType = FUN_001d04d0(((int*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((int*)&DAT_0048e134));
    argTypes[1] = FUN_001d04d0(((int*)&DAT_0048e134));
}
class Closure2 : public Closure2_d0080 {
  public:
    virtual void f();
    Owner_d0080* m2;
    Closure2(const char*, Owner_d0080*, Fn_d0080);
};
Closure2::Closure2(const char* p, Owner_d0080* a, Fn_d0080 b) : Closure2_d0080(p, a, b) {
    m2 = a;
}
