#include "decls/data/game/global.h"

#include "compat/ptr.h"
#include "decls/data/script.h"
#include "decls/address.h"
extern "C" char DAT_00423468[];
// Method3's initializer (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer; returns this.
class Method3_1e0ac0 {
  public:
    hulk_intptr x;
    ScriptFunctionFields f;
    ScriptMemberFn m1c;
    void Init(const char*, int);
    Method3_1e0ac0* Run(const char*, ScriptMemberFn);
};
Method3_1e0ac0* Method3_1e0ac0::Run(const char* a, ScriptMemberFn b) {
    Init(a, 3);
    x = ((hulk_intptr)DAT_00423468);
    m1c = b;
    f.retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e134));
    f.argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e134));
    f.argTypes[2] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    return this;
}