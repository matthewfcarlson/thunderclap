// FUN_001feca0 @ 0x001feca0
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_0048e10c[];
extern "C" char DAT_004252e4[];
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
// Function's fields (include/decls/data/script.h) after the vftable, then the member-function pointer.
class Method4_1feca0 {
  public:
    hulk_intptr vptr;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn fn;       // 0x1c
    Method4_1feca0* FUN_001feca0(const char*, ScriptMemberFn);
};
Method4_1feca0* Method4_1feca0::FUN_001feca0(const char* name, ScriptMemberFn fp) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 4);
    vptr = (hulk_intptr)DAT_004252e4;
    fn = fp;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e0e4));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(DAT_0048e10c);
    f.argTypes[2] = FUN_001d04d0(DAT_0048e10c);
    f.argTypes[3] = FUN_001d04d0(((char*)&DAT_0048e128));
    return this;
}
