#include "decls/data/game/global.h"
// data: hulk_at_0048e100 = DAT_0048e100, hulk_at_0048e134 = DAT_0048e134

#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/script.h"
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class CSubtitleManager;
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Base : public CtorV_001d0480 {
  public:
    Base(const char*);
};
Base::Base(const char* p) : CtorV_001d0480(p, 1) {
}
class Closure1_1bfea0 : public Base {
  public:
    virtual void call(int);
    ScriptMemberFn fn;
    Closure1_1bfea0(const char*, ScriptMemberFn);
};
class Closure1 : public Closure1_1bfea0 {
  public:
    virtual void call(int);
    CSubtitleManager* owner;
    Closure1(const char*, CSubtitleManager*, ScriptMemberFn);
};
Closure1_1bfea0::Closure1_1bfea0(const char* p, ScriptMemberFn m) : Base(p) {
    fn = m;
    retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
}
Closure1::Closure1(const char* p, CSubtitleManager* o, ScriptMemberFn m) : Closure1_1bfea0(p, m) {
    owner = o;
}
