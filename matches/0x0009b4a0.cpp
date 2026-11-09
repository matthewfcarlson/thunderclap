#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_00404d20[];
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
// Method6<Owner, bool, float, float, float, float, float, float>'s initializer (name, member function): Function's
// fields (include/decls/data/script.h), then the member-function pointer.
class Owner_9b4a0 {};
typedef bool (Owner_9b4a0::*Fn_9b4a0)(float, float, float, float, float, float);
class Method6_9b4a0 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_9b4a0 p1c;
    Method6_9b4a0* Run(const char*, Fn_9b4a0);
};
Method6_9b4a0* Method6_9b4a0::Run(const char* arg, Fn_9b4a0 value) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(arg, 6);
    vptr = (void*)DAT_00404d20;
    p1c = value;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[5] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}