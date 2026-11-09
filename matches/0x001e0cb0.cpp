// FUN_001e0cb0 @ 0x001e0cb0
#include "compat/ptr.h"
#include "decls/data/script.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_00423498[];
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
// Method4's initializer (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer; returns this.
class Method4_1e0cb0 {
  public:
    hulk_intptr vptr;
    ScriptFunctionFields f;
    ScriptMemberFn fn;
    Method4_1e0cb0* FUN_001e0cb0(const char*, ScriptMemberFn);
};
Method4_1e0cb0* Method4_1e0cb0::FUN_001e0cb0(const char* name, ScriptMemberFn m) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 4);
    vptr = (hulk_intptr)DAT_00423498;
    fn = m;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e0e4));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[3] = FUN_001d04d0(((char*)&DAT_0048e134));
    return this;
}
