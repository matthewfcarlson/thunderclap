#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// Method5's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.

extern "C" char DAT_0041d9a4[];
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
extern char __cdecl FUN_001d04d0(hulk_intptr);
class Function5_1b38b0 : public FUN_001d0480 {
  public:
    void* vftable;
    ScriptFunctionFields f;
    ScriptMemberFn field1c;
    Function5_1b38b0(const char*, ScriptMemberFn);
};
Function5_1b38b0::Function5_1b38b0(const char* a, ScriptMemberFn b) : FUN_001d0480(a, 5) {
    *(volatile hulk_intptr*)this = ((hulk_intptr)DAT_0041d9a4);
    field1c = b;
    f.retType = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[1] = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[2] = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[4] = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e128)));
}
