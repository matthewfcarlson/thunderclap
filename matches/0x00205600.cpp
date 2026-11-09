#include "decls/data/game/global.h"
// data: str1_205600 = DAT_0048e100, str2 = DAT_0048e0f0, str3 = DAT_0048e134, str4 = DAT_0048e0e4

#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/script.h"
extern "C" char DAT_00425be4[];
class InitBase_205600 {
  public:
    void Init(const char*, int);
};
// Function's fields (include/decls/data/script.h) after the vftable, then the member-function pointer.
class Method3_205600 {
  public:
    Method3_205600(const char*, ScriptMemberFn);
    hulk_intptr vptr;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn f1c;      // 0x1c
};
Method3_205600::Method3_205600(const char* a, ScriptMemberFn b) {
    ((InitBase_205600*)this)->Init(a, 3);
    vptr = ((hulk_intptr)DAT_00425be4);
    f1c = b;
    f.retType = (char)FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = (char)FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[1] = (char)FUN_001d04d0(((char*)&DAT_0048e134));
    f.argTypes[2] = (char)FUN_001d04d0(((char*)&DAT_0048e0e4));
}
