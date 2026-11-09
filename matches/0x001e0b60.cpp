#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/data/script.h"
#include "decls/address.h"
extern "C" char DAT_00423478[];
// Method3's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class Method3_1e0b60 {
  public:
    void Init(const char*, int);
    hulk_intptr m0;
    ScriptFunctionFields f;
    ScriptMemberFn m1c;
    Method3_1e0b60(const char*, ScriptMemberFn);
};
Method3_1e0b60::Method3_1e0b60(const char* x, ScriptMemberFn y) {
    Init(x, 3);
    m0 = ((hulk_intptr)DAT_00423478);
    m1c = y;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e128));
}