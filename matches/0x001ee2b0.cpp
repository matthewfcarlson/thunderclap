#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Base : public CtorV_001d0480 {
  public:
    Base(const char* p) : CtorV_001d0480(p, 1) { }
};
class Closure1_1ee2b0 : public Base {
  public:
    virtual void Invoke(bool);
    ScriptMemberFn fn;  // 0x1c
    Closure1_1ee2b0(const char* p, ScriptMemberFn r);
};
class Closure1 : public Closure1_1ee2b0 {
  public:
    virtual void Invoke(bool);
    void* owner;  // 0x20
    Closure1(const char* p, void* q, ScriptMemberFn r);
};
Closure1_1ee2b0::Closure1_1ee2b0(const char* p, ScriptMemberFn r) : Base(p) {
    fn = r;
    retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0e4));
}
Closure1::Closure1(const char* p, void* q, ScriptMemberFn r) : Closure1_1ee2b0(p, r) {
    owner = q;
}
