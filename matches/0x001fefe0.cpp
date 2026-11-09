#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
extern "C" char DAT_00425334[];
extern "C" char DAT_0048e10c[];
// Function's fields (include/decls/data/script.h) after the vftable, then the member-function pointer.
class Method3_1fefe0 {
  public:
    hulk_intptr vftable;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn p1c;      // 0x1c
    void Init(const char*, int);
    Method3_1fefe0* Build(const char*, ScriptMemberFn);
};
Method3_1fefe0* Method3_1fefe0::Build(const char* arg1, ScriptMemberFn arg2) {
    Init(arg1, 3);
    vftable = ((hulk_intptr)DAT_00425334);
    p1c = arg2;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    return this;
}
