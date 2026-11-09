// FUN_0009ad40 @ 0x0009ad40
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_00404c80[];

// Method5<Owner, void, bool, bool, bool, bool, float>'s initializer (name, member function): Function's
// fields (include/decls/data/script.h), then the member-function pointer.
class Owner_9ad40 {};
typedef void (Owner_9ad40::*Fn_9ad40)(bool, bool, bool, bool, float);
class Method5_9ad40 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_9ad40 p1c;
    void FUN_001d0480(const char*, int);
    Method5_9ad40* Init(const char*, Fn_9ad40);
};

Method5_9ad40* Method5_9ad40::Init(const char* arg, Fn_9ad40 value) {
    FUN_001d0480(arg, 5);
    vptr = (void*)DAT_00404c80;
    p1c = value;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}
