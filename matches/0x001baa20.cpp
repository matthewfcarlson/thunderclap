#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// data: key1 = DAT_0048e100, key2 = DAT_0048e128
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.

struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char __cdecl query(const void*);
class Base : public CtorV_001d0480 {
  public:
    Base(const char* name) : CtorV_001d0480(name, 1) { }
};
class Closure1_1baa20 : public Base {
  public:
    virtual void f();
    ScriptMemberFn fn;
    Closure1_1baa20(const char*, ScriptMemberFn);
};
class Closure1 : public Closure1_1baa20 {
  public:
    virtual void f();
    void* owner;
    Closure1(const char*, void*, ScriptMemberFn);
};
Closure1_1baa20::Closure1_1baa20(const char* name, ScriptMemberFn m) : Base(name) {
    fn = m;
    retType = query(((char*)&DAT_0048e100));
    argTypes[0] = query(((char*)&DAT_0048e128));
}
Closure1::Closure1(const char* name, void* obj, ScriptMemberFn m) : Closure1_1baa20(name, m) {
    owner = obj;
}
