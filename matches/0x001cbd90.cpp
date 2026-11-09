#include "decls/data/game/global.h"
#include "decls/data/script.h"
// data: name1 = DAT_0048e0e4, name2 = DAT_0048e0f0
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.

typedef unsigned int uint;
extern "C" unsigned char FUN_001d04d0(const char*);
class Function_1cbd90 : public ScriptFunctionFields {
  public:
    Function_1cbd90(const char*, int);
    virtual void f();
};
class Method1 : public Function_1cbd90 {
  public:
    ScriptMemberFn m;
    Method1(const char* p, ScriptMemberFn v) : Function_1cbd90(p, 1) {
        m = v;
        retType = FUN_001d04d0((const char*)&(*(const char**)&DAT_0048e0e4));
        argTypes[0] = FUN_001d04d0((const char*)&(*(const char**)&DAT_0048e0f0));
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    void* n;
    Closure1(const char* p, void* q, ScriptMemberFn v);
    virtual void f();
};
Closure1::Closure1(const char* p, void* q, ScriptMemberFn v) : Method1(p, v) {
    n = q;
}
