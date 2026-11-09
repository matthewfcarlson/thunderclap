#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// data: a_cfe50 = DAT_0048e100
// Closure2<Owner, void, bool, float>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class Owner_cfe50 {};
typedef void (Owner_cfe50::*Fn_cfe50)(bool, float);
class Function_cfe50 : public ScriptFunctionFields {
  public:
    virtual void f();
    Function_cfe50(const char*, int);
};
class Method2 : public Function_cfe50 {
  public:
    virtual void g();
    Fn_cfe50 obj;
    Method2(const char* p, Fn_cfe50 q) : Function_cfe50(p, 2) {
        obj = q;
        retType = FUN_001d04d0(((char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(&DAT_0048e0e4);
        argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e128));
    }
};
class Closure2 : public Method2 {
  public:
    virtual void h();
    Owner_cfe50* extra;
    Closure2(const char* p, Owner_cfe50* q, Fn_cfe50 r);
};
Closure2::Closure2(const char* p, Owner_cfe50* q, Fn_cfe50 r) : Method2(p, r) {
    extra = q;
}
