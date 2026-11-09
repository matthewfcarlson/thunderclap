#include "decls/address.h"
#include "decls/data/script.h"
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class CRenderManager;
extern const char g1[], g2[];
class Function_1ba850 : public ScriptFunctionFields {
  public:
    Function_1ba850(const char*, int);
    virtual void f();
};
class Method1 : public Function_1ba850 {
  public:
    virtual void f();
    ScriptMemberFn fn;
    Method1(const char* p, ScriptMemberFn m) : Function_1ba850(p, 1) {
        fn = m;
        retType = FUN_001d04d0(g1);
        argTypes[0] = FUN_001d04d0(g2);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    CRenderManager* owner;
    Closure1(const char*, CRenderManager*, ScriptMemberFn);
};
Closure1::Closure1(const char* p, CRenderManager* q, ScriptMemberFn m) : Method1(p, m) {
    owner = q;
}
