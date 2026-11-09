// FUN_001e0030 @ 0x001e0030
#include "compat/ptr.h"
#include "decls/data/script.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_00423388[];

// Method5's initializer (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer; returns this.
class Method5_1e0030 {
  public:
    hulk_intptr vptr;
    ScriptFunctionFields f;
    ScriptMemberFn p1c;
    void FUN_001d0480(const char*, int);
    Method5_1e0030* Init(const char*, ScriptMemberFn);
};

Method5_1e0030* Method5_1e0030::Init(const char* arg, ScriptMemberFn value) {
    FUN_001d0480(arg, 5);
    vptr = (hulk_intptr)DAT_00423388;
    p1c = value;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    return this;
}
