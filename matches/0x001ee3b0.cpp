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
    Base(const char* x) : CtorV_001d0480(x, 1) { }
};
class Closure1_1ee3b0 : public Base {
  public:
    virtual void f();
    ScriptMemberFn p;  // 0x1c
    Closure1_1ee3b0(const char*, void*, ScriptMemberFn);
};
class Closure1 : public Closure1_1ee3b0 {
  public:
    virtual void f();
    void* q;  // 0x20
    Closure1(const char*, void*, ScriptMemberFn);
};
Closure1::Closure1(const char* x, void* y, ScriptMemberFn z) : Closure1_1ee3b0(x, y, z) {
    q = y;
}
Closure1_1ee3b0::Closure1_1ee3b0(const char* x, void* y, ScriptMemberFn z) : Base(x) {
    p = z;
    retType = FUN_001d04d0(((char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((char*)&DAT_0049cad8));
}
