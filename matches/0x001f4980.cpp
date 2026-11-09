#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
extern "C" char DAT_00424b0c[];
// Function's fields (include/decls/data/script.h) after the vftable, then the member-function pointer.
class Method3_1f4980 {
  public:
    void Init(const char*, int);
    hulk_intptr vf;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn a;        // 0x1c
    Method3_1f4980* Fn(const char*, ScriptMemberFn);
};
Method3_1f4980* Method3_1f4980::Fn(const char* p, ScriptMemberFn v) {
    Init(p, 3);
    vf = ((hulk_intptr)DAT_00424b0c);
    a = v;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    return this;
}
