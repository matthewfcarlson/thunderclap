#include "decls/data/game/global.h"
#include "decls/data/script.h"
// data: keyA = DAT_0048e100, keyB = DAT_0048e134
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.

struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char __cdecl lookup(const char*);
class Function_d73a0 : public CtorV_001d0480 {
  public:
    Function_d73a0(const char* a) : CtorV_001d0480(a, 1) { }
};
class Method1 : public Function_d73a0 {
  public:
    virtual void run();
    ScriptMemberFn value;
    Method1(const char* a, ScriptMemberFn c) : Function_d73a0(a) {
        value = c;
        retType = lookup(((const char*)&DAT_0048e100));
        argTypes[0] = lookup(((const char*)&DAT_0048e134));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void run();
    void* other;
    Closure1(const char* a, void* b, ScriptMemberFn c);
};
Closure1::Closure1(const char* a, void* b, ScriptMemberFn c) : Method1(a, c), other(b) {}
