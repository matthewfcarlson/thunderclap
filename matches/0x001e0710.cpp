#include "compat/ptr.h"
#include "decls/data/script.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" char DAT_00423418[];
extern "C" char DAT_0048e10c[];
class CSPManager;
// Method4's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class Method4_1e0710 {
  public:
    hulk_intptr vtable;
    ScriptFunctionFields f;
    ScriptMemberFn mgr;
    Method4_1e0710(const char*, ScriptMemberFn);
};
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
Method4_1e0710::Method4_1e0710(const char* s, ScriptMemberFn m) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(s, 4);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00423418);
    mgr = m;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
}