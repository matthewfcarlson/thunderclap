#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// Method4's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
extern "C" char DAT_00420e84[];
extern "C" char DAT_0048e10c[];
struct Method4_1ba090 {
    hulk_intptr v;
    ScriptFunctionFields f;
    ScriptMemberFn p1c;
    void Init(const char*, int);
    Method4_1ba090(const char*, ScriptMemberFn);
};
Method4_1ba090::Method4_1ba090(const char* x, ScriptMemberFn y) {
    Init(x, 4);
    v = ((hulk_intptr)DAT_00420e84);
    p1c = y;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0049b95c)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}
