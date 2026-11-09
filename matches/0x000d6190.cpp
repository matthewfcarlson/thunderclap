#include "decls/data/game/global.h"
#include "decls/data/script.h"
// data: name1 = DAT_0048e100, name2 = DAT_0048e0e4
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.

typedef unsigned char u8;
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" u8 __cdecl FUN_001d04d0(const char*);
class Function_d6190 : public CtorV_001d0480 {
  public:
    Function_d6190(const char* x) : CtorV_001d0480(x, 1) { }
};
class Method1 : public Function_d6190 {
  public:
    virtual void Invoke();
    ScriptMemberFn member;
    Method1(const char* x, ScriptMemberFn y) : Function_d6190(x) {
        member = y;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke();
    void* last;
    Closure1(const char* a, void* b, ScriptMemberFn c);
};
Closure1::Closure1(const char* a, void* b, ScriptMemberFn c) : Method1(a, c) {
    last = b;
}
