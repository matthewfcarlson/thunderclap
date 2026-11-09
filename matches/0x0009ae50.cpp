// FUN_0009ae50 @ 0x0009ae50
// Method7 registration constructor: base init, vftable, then the seven result/argument type tags.
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_00404c90[];

// Method7<Owner, void, bool, bool, bool, bool, bool, bool, float>'s initializer (name, member function): Function's
// fields (include/decls/data/script.h), then the member-function pointer.
class Owner_9ae50 {};
typedef void (Owner_9ae50::*Fn_9ae50)(bool, bool, bool, bool, bool, bool, float);
class Method7_9ae50 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_9ae50 owner;
    void FUN_001d0480(const char*, int);
    Method7_9ae50* Init(const char*, Fn_9ae50);
};

Method7_9ae50* Method7_9ae50::Init(const char* name, Fn_9ae50 value) {
    FUN_001d0480(name, 7);
    vptr = (void*)DAT_00404c90;
    owner = value;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[5] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[6] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}
