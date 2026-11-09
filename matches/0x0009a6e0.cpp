#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_00404c00[];
// Method6<Owner, void, float x6>'s initializer (name, member function): Function's fields
// (include/decls/data/script.h), then the member-function pointer; returns this.
class Owner_9a6e0 {};
typedef void (Owner_9a6e0::*Fn_9a6e0)(float, float, float, float, float, float);
class Method6_9a6e0 {
  public:
    void* v;
    ScriptFunctionFields f;
    Fn_9a6e0 m1c;
    void Init(const char*, int);
    Method6_9a6e0* Run(const char*, Fn_9a6e0);
};
Method6_9a6e0* Method6_9a6e0::Run(const char* a, Fn_9a6e0 b) {
    Init(a, 6);
    v = (void*)DAT_00404c00;
    m1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[4] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[5] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}
