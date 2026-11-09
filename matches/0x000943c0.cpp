// FUN_000943c0 @ 0x000943c0
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
extern "C" char DAT_0040470c[];
// Method7<Owner, void, const char*, int, const char* x4, int>'s initializer (name, member function): Function's
// fields (include/decls/data/script.h), then the member-function pointer; returns this.
class Owner_943c0 {};
typedef void (Owner_943c0::*Fn_943c0)(const char*, int, const char*, const char*, const char*, const char*, int);
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
class Method7_943c0 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_943c0 func;
    Method7_943c0* Init(const char* name, Fn_943c0 fn);
};
Method7_943c0* Method7_943c0::Init(const char* name, Fn_943c0 fn) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 7);
    vptr = (void*)DAT_0040470c;
    func = fn;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[5] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[6] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    return this;
}
