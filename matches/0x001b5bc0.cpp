#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
// data: str1_1b5bc0 = DAT_0048e100, str2 = DAT_0048e128

#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/script.h"
// Method3's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
extern "C" char DAT_0041da1c[];
struct This_FUN_001d0480 {
    int FUN_001d0480(const char*, int);
};
class Method3_1b5bc0 {
  public:
    hulk_intptr vtable;
    ScriptFunctionFields f;
    ScriptMemberFn value1c;
    Method3_1b5bc0(const char*, ScriptMemberFn);
};
Method3_1b5bc0::Method3_1b5bc0(const char* a, ScriptMemberFn b) {
    ((This_FUN_001d0480*)this)->FUN_001d0480(a, 3);
    vtable = ((hulk_intptr)DAT_0041da1c);
    value1c = b;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e128));
}
