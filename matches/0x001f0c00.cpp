#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_004246ec[];
class Function_1f0c00 {
  public:
    Function_1f0c00(const char*, int);
};
// Method6's constructor (name, member function): the vftable, Function's fields (include/decls/data/script.h),
// then the member-function pointer.
class Method6_1f0c00 : public Function_1f0c00 {
  public:
    void* vftable;           // 0x00
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn p1c;      // 0x1c
    Method6_1f0c00(const char*, ScriptMemberFn);
};
Method6_1f0c00::Method6_1f0c00(const char* a, ScriptMemberFn c) : Function_1f0c00(a, 6) {
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_004246ec);
    p1c = c;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[5] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
}
