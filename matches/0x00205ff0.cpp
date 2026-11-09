#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_205ff0 : public CtorV_001d0480 {
  public:
    Function_205ff0(const char* x) : CtorV_001d0480(x, 1) { }
};
class Method1 : public Function_205ff0 {
  public:
    virtual void f();
    ScriptMemberFn c;  // 0x1c
    Method1(const char* x, ScriptMemberFn y) : Function_205ff0(x) {
        c = y;
        retType = FUN_001d04d0(((const char*)&DAT_0048e0e4));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e134));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    void* d;  // 0x20
    Closure1(const char*, void*, ScriptMemberFn);
};
Closure1::Closure1(const char* x, void* y, ScriptMemberFn z) : Method1(x, z) {
    d = y;
}
