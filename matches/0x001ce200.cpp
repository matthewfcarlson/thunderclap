#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class Function_1ce200 : public ScriptFunctionFields {
  public:
    virtual void Invoke(float);
    Function_1ce200(const char*, int);
};
class Method1 : public Function_1ce200 {
  public:
    virtual void Invoke(float);
    ScriptMemberFn fn;
    Method1(const char* p, ScriptMemberFn q) : Function_1ce200(p, 1) {
        fn = q;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke(float);
    void* owner;
    Closure1(const char*, void*, ScriptMemberFn);
};
Closure1::Closure1(const char* p, void* q, ScriptMemberFn r) : Method1(p, r) {
    owner = q;
}
