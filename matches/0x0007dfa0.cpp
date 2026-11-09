#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// data: a_7dfa0 = DAT_0048e100
// Closure2's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method2's member-function pointer and Closure2's object.
class Function_7dfa0 : public ScriptFunctionFields {
  public:
    Function_7dfa0(const char*, int);
    virtual void f();
};
class Owner_7dfa0 {};
typedef void (Owner_7dfa0::*Fn_7dfa0)();
class Method2_7dfa0 : public Function_7dfa0 {
  public:
    Method2_7dfa0(const char*, Fn_7dfa0);
    virtual void f();
    Fn_7dfa0 arg;
};
class Closure2_7dfa0 : public Method2_7dfa0 {
  public:
    virtual void f();
    Owner_7dfa0* extra;
    Closure2_7dfa0(const char*, Owner_7dfa0*, Fn_7dfa0);
};
inline Method2_7dfa0::Method2_7dfa0(const char* s, Fn_7dfa0 v) : Function_7dfa0(s, 2) {
    arg = v;
    retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e0e4));
}
Closure2_7dfa0::Closure2_7dfa0(const char* s, Owner_7dfa0* v, Fn_7dfa0 w) : Method2_7dfa0(s, w) {
    extra = v;
}
