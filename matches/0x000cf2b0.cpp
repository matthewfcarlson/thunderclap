// FUN_000cf2b0 @ 0x000cf2b0
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
extern "C" char DAT_0040a5c0[];
extern "C" char DAT_0048e10c[];

// Method5<Owner, int, int, const char*, int, int, int>'s initializer (name, member function): Function's
// fields (include/decls/data/script.h), then the member-function pointer.
class Owner_cf2b0 {};
typedef int (Owner_cf2b0::*Fn_cf2b0)(int, const char*, int, int, int);
class Method5_cf2b0 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_cf2b0 p1c;
    void FUN_001d0480(const char*, int);
    Method5_cf2b0* Init(const char*, Fn_cf2b0);
};

Method5_cf2b0* Method5_cf2b0::Init(const char* arg, Fn_cf2b0 value) {
    FUN_001d0480(arg, 5);
    vptr = (void*)DAT_0040a5c0;
    p1c = value;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)DAT_0048e10c));
    return this;
}
