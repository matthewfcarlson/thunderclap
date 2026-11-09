// FUN_001f0dd0 @ 0x001f0dd0
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_0042470c[];

// Method5's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class Method5_1f0dd0 {
  public:
    hulk_intptr vptr;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn p1c;      // 0x1c
    void FUN_001d0480(const char*, int);
    Method5_1f0dd0* Init(const char*, ScriptMemberFn);
};

Method5_1f0dd0* Method5_1f0dd0::Init(const char* arg, ScriptMemberFn value) {
    FUN_001d0480(arg, 5);
    vptr = (hulk_intptr)DAT_0042470c;
    p1c = value;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}
