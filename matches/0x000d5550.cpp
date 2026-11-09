// FUN_000d5550 @ 0x000d5550
// Method7 registration constructor: base init, vftable, then the seven result/argument type tags.
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
extern "C" char DAT_0040b1a8[];

// Method7<Owner, void, const char*, const char*, const char*, const char*, const char*, const char*, const char*>'s initializer (name, member function): Function's
// fields (include/decls/data/script.h), then the member-function pointer.
class Owner_d5550 {};
typedef void (Owner_d5550::*Fn_d5550)(const char*, const char*, const char*, const char*, const char*, const char*, const char*);
class Method7_d5550 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_d5550 owner;
    void FUN_001d0480(const char*, int);
    Method7_d5550* Init(const char*, Fn_d5550);
};

Method7_d5550* Method7_d5550::Init(const char* name, Fn_d5550 value) {
    FUN_001d0480(name, 7);
    vptr = (void*)DAT_0040b1a8;
    owner = value;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[5] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[6] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    return this;
}
