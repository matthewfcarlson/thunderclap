#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_00425b54[];
class Function_2050f0 {
  public:
    void Init(const char*, int);
};
// Function's fields (include/decls/data/script.h) after the vftable, then the member-function pointer.
class Method3_2050f0 : public Function_2050f0 {
  public:
    Method3_2050f0(const char*, ScriptMemberFn);
    void* vf;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn mgr;      // 0x1c
};
Method3_2050f0::Method3_2050f0(const char* a, ScriptMemberFn b) {
    Init(a, 3);
    vf = (void*)((hulk_intptr)DAT_00425b54);
    mgr = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}
