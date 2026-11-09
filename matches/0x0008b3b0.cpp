#include "decls/data/game/global.h"
#include "decls/data/script.h"
// data: key = DAT_0048e0f0
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char __cdecl get(const char*);
struct Function_8b3b0 : public CtorV_001d0480 {
    Function_8b3b0(const char* s) : CtorV_001d0480(s, 1) { }
};
class Owner_8b3b0 {};
typedef void (Owner_8b3b0::*Fn_8b3b0)(const char*);
class Method1 : public Function_8b3b0 {
  public:
    virtual void f();
    Fn_8b3b0 name;
    Method1(const char* s, Fn_8b3b0 n) : Function_8b3b0(s) {
        name = n;
        retType = get(((const char*)&DAT_0048e0f0));
        argTypes[0] = get(((const char*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    Owner_8b3b0* val;
    Closure1(const char* s, Owner_8b3b0* v, Fn_8b3b0 n);
};
Closure1::Closure1(const char* s, Owner_8b3b0* v, Fn_8b3b0 n) : Method1(s, n) {
    val = v;
}
