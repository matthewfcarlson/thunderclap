#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/data/script.h"
#include "decls/address.h"
extern "C" char DAT_004233f8[];
// Method5's initializer (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer; returns this.
class Method5_1e0550 {
  public:
    hulk_intptr v;
    ScriptFunctionFields f;
    ScriptMemberFn m1c;
    char p20[0x20];
    void Init(const char*, int);
    Method5_1e0550* Make(const char*, ScriptMemberFn);
};
Method5_1e0550* Method5_1e0550::Make(const char* p, ScriptMemberFn x) {
    Init(p, 5);
    v = ((hulk_intptr)DAT_004233f8);
    m1c = x;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[3] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[4] = FUN_001d04d0(((char*)&DAT_0048e128));
    return this;
}