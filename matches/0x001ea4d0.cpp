#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Function (include/decls/data/script.h): the vftable, then Function's fields.
class Function_1ea4d0 : public ScriptFunctionFields {
  public:
    Function_1ea4d0(const char*, int);
    virtual void run();
};
class Method1 : public Function_1ea4d0 {
  public:
    ScriptMemberFn value;  // 0x1c
    Method1(const char* x, ScriptMemberFn v) : Function_1ea4d0(x, 1), value(v) {
        retType = FUN_001d04d0(((int*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((int*)&DAT_0048e134));
    }
    virtual void run();
};
class Closure1 : public Method1 {
  public:
    void* other;  // 0x20
    Closure1(const char* x, void* y, ScriptMemberFn z);
    virtual void run();
};
Closure1::Closure1(const char* x, void* y, ScriptMemberFn z) : Method1(x, z), other(y) {}
