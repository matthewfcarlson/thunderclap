#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_004246cc[];
struct Function_1f0af0 {
    hulk_uintptr vt;
    void Init(const char*, int);
};
// Method3's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
struct Method3_1f0af0 : Function_1f0af0 {
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn m1c;      // 0x1c
    Method3_1f0af0* Run(const char*, ScriptMemberFn);
};
Method3_1f0af0* Method3_1f0af0::Run(const char* a, ScriptMemberFn b) {
    Init(a, 3);
    vt = ((hulk_intptr)DAT_004246cc);
    m1c = b;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}
