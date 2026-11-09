// FUN_000d5890 @ 0x000d5890
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_0040b1f8[];
extern "C" char DAT_0048e10c[];

// Method5<Owner, void, int, const char*, int, int, float>'s initializer (name, member function): Function's
// fields (include/decls/data/script.h), then the member-function pointer.
class Owner_d5890 {};
typedef void (Owner_d5890::*Fn_d5890)(int, const char*, int, int, float);
class Method5_d5890 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_d5890 p1c;
    void FUN_001d0480(const char*, int);
    Method5_d5890* Init(const char*, Fn_d5890);
};

Method5_d5890* Method5_d5890::Init(const char* arg, Fn_d5890 value) {
    FUN_001d0480(arg, 5);
    vptr = (void*)DAT_0040b1f8;
    p1c = value;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}
