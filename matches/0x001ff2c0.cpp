#include "decls/data/game/global.h"

#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/script.h"
extern "C" char DAT_00425374[];
struct Function_1ff2c0 {
    void Init(const char*, int);
};
// Function's fields (include/decls/data/script.h) after the vftable, then the member-function pointer.
class Method3_1ff2c0 : public Function_1ff2c0 {
  public:
    Method3_1ff2c0(const char*, ScriptMemberFn);
    hulk_intptr m0;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn m1c;      // 0x1c
};
Method3_1ff2c0::Method3_1ff2c0(const char* a, ScriptMemberFn c) {
    Init(a, 3);
    m0 = ((hulk_intptr)DAT_00425374);
    m1c = c;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e134));
    f.argTypes[2] = FUN_001d04d0(&DAT_0048e0e4);
}
