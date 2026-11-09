#include "decls/data/game/global.h"

#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/script.h"
extern "C" char DAT_00424d4c[];
class Function_1f7720 {
  public:
    Function_1f7720(const char*, int);
};
extern char sC[];
// Function's fields (include/decls/data/script.h) after the vftable, then the member-function pointer.
class Method3_1f7720 : public Function_1f7720 {
  public:
    Method3_1f7720(const char*, ScriptMemberFn);
    void* vftable;           // 0x00
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn m1c;      // 0x1c
};
Method3_1f7720::Method3_1f7720(const char* a, ScriptMemberFn b) : Function_1f7720(a, 3) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00424d4c);
    m1c = b;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e134));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(sC);
    f.argTypes[2] = FUN_001d04d0(sC);
}
