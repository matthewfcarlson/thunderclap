#include "decls/data/script.h"
// Closure1<Owner, R, A1>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_94a30 {};
typedef int (Owner_94a30::*Fn_94a30)(int);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char readFlag(const char*);
extern char flagA[];
extern char flagB[];
class Function_94a30 : public CtorV_001d0480 {
  public:
    Function_94a30(const char* s) : CtorV_001d0480(s, 1) { }
};
class Method1 : public Function_94a30 {
  public:
    virtual void run();
    Fn_94a30 value;
    Method1(const char* s, Fn_94a30 v) : Function_94a30(s) {
        value = v;
        retType = readFlag(flagA);
        argTypes[0] = readFlag(flagB);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void run();
    Owner_94a30* extra;
    Closure1(const char* s, Owner_94a30* v, Fn_94a30 e);
};
Closure1::Closure1(const char* s, Owner_94a30* v, Fn_94a30 e) : Method1(s, e) {
    extra = v;
}
