#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
class CSPManager;
// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct Function_1e1f40 : public ScriptFunctionFields {
    virtual void run();
    ScriptMemberFn fn;  // 0x1c
    Function_1e1f40(const char*, int);
};
struct Method1 : Function_1e1f40 {
    virtual void run();
    Method1(const char* x, ScriptMemberFn z) : Function_1e1f40(x, 1) {
        fn = z;
        retType = FUN_001d04d0(((const char*)&DAT_0048e0e4));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
};
struct Closure1 : Method1 {
    virtual void run();
    CSPManager* mgr;  // 0x20
    Closure1(const char*, CSPManager*, ScriptMemberFn);
};
Closure1::Closure1(const char* x, CSPManager* m, ScriptMemberFn z) : Method1(x, z) {
    mgr = m;
}
