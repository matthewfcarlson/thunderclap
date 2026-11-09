#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"

extern "C" char DAT_00424b2c[];
// Function's fields (include/decls/data/script.h) after the vftable, then the member-function pointer.
class Method4_1f4aa0 {
  public:
    hulk_intptr vptr;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn m1c;      // 0x1c
    Method4_1f4aa0(const char*, ScriptMemberFn);
};
struct ThisCall_001d0480 {
    void Init(const char*, int);
};
extern "C" char __cdecl Get(void*);
Method4_1f4aa0::Method4_1f4aa0(const char* a, ScriptMemberFn b) {
    ((ThisCall_001d0480*)(this))->Init(a, 4);
    vptr = ((hulk_intptr)DAT_00424b2c);
    m1c = b;
    f.retType = Get((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = Get((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[1] = Get((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[2] = Get((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[3] = Get((void*)((hulk_intptr)((char*)&DAT_0048e134)));
}
