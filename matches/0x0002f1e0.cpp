#include "decls/data/game/global.h"
#include "decls/data/script.h"
// data: text1 = DAT_0048e0e4

// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
unsigned char __cdecl Lookup(const char*);
extern const char text2[];
class Function_2f1e0 : public CtorV_001d0480 {
  public:
    Function_2f1e0(const char* x) : CtorV_001d0480(x, 1) { }
};
class Owner_2f1e0 {};
typedef void (Owner_2f1e0::*Fn_2f1e0)();
class Method1 : public Function_2f1e0 {
  public:
    virtual void Fn();
    Fn_2f1e0 p;
    Owner_2f1e0* q;
    Method1(const char* x, Fn_2f1e0 y) : Function_2f1e0(x) {
        p = y;
        retType = Lookup(((const char*)&DAT_0048e0e4));
        argTypes[0] = Lookup(text2);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Fn();
    Closure1(const char*, Owner_2f1e0*, Fn_2f1e0);
};
Closure1::Closure1(const char* x, Owner_2f1e0* y, Fn_2f1e0 z) : Method1(x, z) {
    q = y;
}
