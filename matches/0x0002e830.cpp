#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"

extern "C" char DAT_003f407c[];
extern "C" char DAT_003f439c[];
typedef unsigned char u8;
struct ThisCall_001d0480 {
    void InitHelper(const char*, int);
};
u8 GetHelper(const void*);
// Closure1's initializer (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object; returns this.
class Owner_2e830 {};
typedef void (Owner_2e830::*Fn_2e830)();
struct Closure1_2e830 {
    void* vptr;
    ScriptFunctionFields f;
    Fn_2e830 m1c;
    Owner_2e830* m20;
    Closure1_2e830* Build(const char*, Owner_2e830*, Fn_2e830);
};
Closure1_2e830* Closure1_2e830::Build(const char* a, Owner_2e830* b, Fn_2e830 c) {
    ((ThisCall_001d0480*)(this))->InitHelper(a, 1);
    vptr = (void*)DAT_003f407c;
    m1c = c;
    f.retType = GetHelper((const void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[0] = GetHelper((const void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    vptr = (void*)DAT_003f439c;
    m20 = b;
    return this;
}
