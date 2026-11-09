#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class Function_1c00d0 : public ScriptFunctionFields {
  public:
    Function_1c00d0(const char*, int);
    virtual void Run();
};
class Method1 : public Function_1c00d0 {
  public:
    Method1(const char* a, ScriptMemberFn c) : Function_1c00d0(a, 1) {
        p = c;
        retType = FUN_001d04d0(((char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e128));
    }
    virtual void Run();
    ScriptMemberFn p;
};
class Closure1 : public Method1 {
  public:
    Closure1(const char* a, void* b, ScriptMemberFn c);
    virtual void Run();
    void* q;
};
Closure1::Closure1(const char* a, void* b, ScriptMemberFn c) : Method1(a, c) {
    q = b;
}
