#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Method3's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
extern "C" char DAT_00420e24[];
class Function_1b9c50 {
  public:
    void Init(const char*, int);
};
class Method3_1b9c50 : public Function_1b9c50 {
  public:
    void* vftable;
    ScriptFunctionFields f;
    ScriptMemberFn member1c;
    Method3_1b9c50(const char* p, ScriptMemberFn x);
};
Method3_1b9c50::Method3_1b9c50(const char* p, ScriptMemberFn x) {
    Init(p, 3);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00420e24);
    member1c = x;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
}
