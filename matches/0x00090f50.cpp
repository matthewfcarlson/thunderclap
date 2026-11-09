#include "decls/data/game/global.h"
#include "decls/data/script.h"
// data: key1 = DAT_0048e100, key2 = DAT_0048e0f0

// Closure1<Owner, void, const char*>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_90f50 {};
typedef void (Owner_90f50::*Fn_90f50)(const char*);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char lookup(const char*);
class Function_90f50 : public CtorV_001d0480 {
  public:
    Function_90f50(const char* p) : CtorV_001d0480(p, 1) { }
};
class Method1 : public Function_90f50 {
  public:
    virtual void fn();
    Fn_90f50 arg2;
    Owner_90f50* arg3;
    Method1(const char* p, Fn_90f50 a) : Function_90f50(p) {
        arg2 = a;
        retType = lookup(((char*)&DAT_0048e100));
        argTypes[0] = lookup(((char*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void fn();
    Closure1(const char* p, Owner_90f50* a, Fn_90f50 b);
};
Closure1::Closure1(const char* p, Owner_90f50* a, Fn_90f50 b) : Method1(p, b) {
    arg3 = a;
}
