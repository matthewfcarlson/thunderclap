#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.

typedef unsigned char byte;
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" byte __cdecl GetFlag(void*);
class Base : public CtorV_001d0480 {
  public:
    Base(const char* p) : CtorV_001d0480(p, 1) { }
};
class Closure1_d7310 : public Base {
  public:
    virtual void Fn();
    ScriptMemberFn obj;
    Closure1_d7310(const char* p, ScriptMemberFn c);
};
class Closure1 : public Closure1_d7310 {
  public:
    virtual void Fn();
    void* extra;
    Closure1(const char* p, void* e, ScriptMemberFn c);
};
Closure1_d7310::Closure1_d7310(const char* p, ScriptMemberFn c) : Base(p) {
    obj = c;
    retType = GetFlag(((int*)&DAT_0048e100));
    argTypes[0] = GetFlag(((int*)&DAT_0048e0e4));
}
Closure1::Closure1(const char* p, void* e, ScriptMemberFn c) : Closure1_d7310(p, c), extra(e) {}
