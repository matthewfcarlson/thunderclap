#include "decls/data/script.h"
// Closure1<Owner, R, A1>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_9c9a0 {};
typedef void (Owner_9c9a0::*Fn_9c9a0)(float);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char Check(const void*);
extern char gA[];
extern char gB[];
class Function_9c9a0 : public CtorV_001d0480 {
  public:
    Function_9c9a0(const char* p) : CtorV_001d0480(p, 1) { }
};
class Method1 : public Function_9c9a0 {
  public:
    virtual void invoke(float);
    Fn_9c9a0 x;
    Method1(const char* p, Fn_9c9a0 v) : Function_9c9a0(p) {
        x = v;
        retType = Check(gB);
        argTypes[0] = Check(gA);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void invoke(float);
    Owner_9c9a0* y;
    Closure1(const char* p, Owner_9c9a0* w, Fn_9c9a0 v);
};
Closure1::Closure1(const char* p, Owner_9c9a0* w, Fn_9c9a0 v) : Method1(p, v) {
    y = w;
}
