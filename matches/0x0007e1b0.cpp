#include "decls/data/game/global.h"
#include "decls/data/script.h"
// data: key1 = DAT_0048e100, key2 = DAT_0048e134
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char Decode(const void*);
class Function_7e1b0 : public CtorV_001d0480 {
  public:
    Function_7e1b0(const char* p) : CtorV_001d0480(p, 1) { }
};
class Owner_7e1b0 {};
typedef void (Owner_7e1b0::*Fn_7e1b0)(int);
class Method1 : public Function_7e1b0 {
  public:
    virtual void Invoke(int);
    Fn_7e1b0 arg;
    Method1(const char* p, Fn_7e1b0 x) : Function_7e1b0(p) {
        arg = x;
        retType = Decode(((int*)&DAT_0048e100));
        argTypes[0] = Decode(((int*)&DAT_0048e134));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke(int);
    Owner_7e1b0* data;
    Closure1(const char*, Owner_7e1b0*, Fn_7e1b0);
};
Closure1::Closure1(const char* p, Owner_7e1b0* x, Fn_7e1b0 y) : Method1(p, y) {
    data = x;
}
