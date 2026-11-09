#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
extern "C" char DAT_004243b8[];
struct Ctor_001d0480 {
    Ctor_001d0480(const char*, int);
};
// Method4's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class Method4_1ede10 : public Ctor_001d0480 {
  public:
    Method4_1ede10(const char*, ScriptMemberFn);
    int* vptr;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn m1c;      // 0x1c
};
Method4_1ede10::Method4_1ede10(const char* a, ScriptMemberFn b) : Ctor_001d0480(a, 4) {
    vptr = (int*)((hulk_intptr)DAT_004243b8);
    m1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
}
