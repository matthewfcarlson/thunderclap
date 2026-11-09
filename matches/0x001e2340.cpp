#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
class CSPManager;
// Function (include/decls/data/script.h): the vftable, then Function's fields.
class Function_1e2340 : public ScriptFunctionFields {
  public:
    virtual void f();
    Function_1e2340(const char*, int);
};
class Method1 : public Function_1e2340 {
  public:
    virtual void f();
    ScriptMemberFn data;  // 0x1c
    Method1(const char* p, ScriptMemberFn d) : Function_1e2340(p, 1) {
        data = d;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    CSPManager* mgr;  // 0x20
    Closure1(const char*, CSPManager*, ScriptMemberFn);
};
Closure1::Closure1(const char* p, CSPManager* m, ScriptMemberFn d) : Method1(p, d) {
    mgr = m;
}
