#include "decls/data/game/global.h"
#include "decls/data/script.h"

// Closure1<Owner, void, bool>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_9caf0 {};
typedef void (Owner_9caf0::*Fn_9caf0)(bool);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char query(void*);
class Function_9caf0 : public CtorV_001d0480 {
  public:
    Function_9caf0(const char* p) : CtorV_001d0480(p, 1) { }
};
class Method1 : public Function_9caf0 {
  public:
    virtual void invoke();
    Fn_9caf0 owner;
    Owner_9caf0* extra;
    Method1(const char* p, Fn_9caf0 o) : Function_9caf0(p) {
        owner = o;
        retType = query(((void**)&DAT_0048e100));
        argTypes[0] = query(((void**)&DAT_0048e0e4));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void invoke();
    Closure1(const char* p, Owner_9caf0* x, Fn_9caf0 o);
};
Closure1::Closure1(const char* p, Owner_9caf0* x, Fn_9caf0 o) : Method1(p, o) {
    extra = x;
}
