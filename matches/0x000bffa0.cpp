#include "decls/data/game/global.h"
#include "decls/data/script.h"

// Closure1<Owner, void, const char*>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_bffa0 {};
typedef void (Owner_bffa0::*Fn_bffa0)(const char*);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char lookup(const void*);
class Base : public CtorV_001d0480 {
  public:
    Base(const char* n) : CtorV_001d0480(n, 1) { }
};
class Closure1_bffa0 : public Base {
  public:
    virtual void f();
    Fn_bffa0 name;
    Closure1_bffa0(const char*, Fn_bffa0);
};
class Closure1 : public Closure1_bffa0 {
  public:
    virtual void g();
    Owner_bffa0* p;
    Closure1(const char*, Owner_bffa0*, Fn_bffa0);
};
Closure1_bffa0::Closure1_bffa0(const char* n, Fn_bffa0 s) : Base(n) {
    name = s;
    retType = lookup(((int*)&DAT_0048e100));
    argTypes[0] = lookup(((int*)&DAT_0048e0f0));
}
Closure1::Closure1(const char* n, Owner_bffa0* v, Fn_bffa0 s) : Closure1_bffa0(n, s) {
    p = v;
}
