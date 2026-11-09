#include "decls/data/game/global.h"

#include "compat/ptr.h"
#include "decls/data/script.h"
extern "C" char DAT_00425354[];
struct Ctor_001d0480 {
    Ctor_001d0480(const char*, int);
};
extern "C" char __cdecl ReadBool(const char*);
// Function's fields (include/decls/data/script.h) after the vftable, then the member-function pointer.
class Method4_1ff150 : public Ctor_001d0480 {
  public:
    hulk_intptr vptr;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn value;    // 0x1c
    Method4_1ff150(const char* x, ScriptMemberFn y);
};
Method4_1ff150::Method4_1ff150(const char* x, ScriptMemberFn y) : Ctor_001d0480(x, 4) {
    vptr = ((hulk_intptr)DAT_00425354);
    value = y;
    f.retType = ReadBool(((const char*)&DAT_0048e0e4));
    f.argTypes[0] = ReadBool(((const char*)&DAT_0048e0f0));
    f.argTypes[1] = ReadBool(((const char*)&DAT_0048e134));
    f.argTypes[2] = ReadBool(((const char*)&DAT_0048e134));
    f.argTypes[3] = ReadBool(((const char*)&DAT_0048e0e4));
}
