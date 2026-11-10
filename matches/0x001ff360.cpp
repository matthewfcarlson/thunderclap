#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_00425384[];
extern "C" char DAT_0048e10c[];
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
// Function's fields (include/decls/data/script.h) after the vftable, then the member-function pointer.
class Method5_1ff360 : public FUN_001d0480 {
  public:
    void* vft;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn m1c;      // 0x1c
    Method5_1ff360(const char*, ScriptMemberFn);
};
Method5_1ff360::Method5_1ff360(const char* s, ScriptMemberFn x) : FUN_001d0480(s, 5) {
    vft = (void*)((hulk_intptr)DAT_00425384);
    m1c = x;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[4] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}
