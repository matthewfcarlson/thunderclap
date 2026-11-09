#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_00424d6c[];
// Function's fields (include/decls/data/script.h) after the vftable, then the member-function pointer.
class Method3_1f78c0 {
  public:
    hulk_intptr vtable;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn field1c;  // 0x1c
    void Base(const char*, int);
    Method3_1f78c0* Build(const char*, ScriptMemberFn);
};
Method3_1f78c0* Method3_1f78c0::Build(const char* a, ScriptMemberFn b) {
    Base(a, 3);
    vtable = ((hulk_intptr)DAT_00424d6c);
    field1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0049b95c)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}
