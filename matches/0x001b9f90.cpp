#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// Method4's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
extern "C" char DAT_00420e74[];
struct Ctor_001d0480 {
    Ctor_001d0480(const char*, unsigned int);
};
class Method4_1b9f90 : public Ctor_001d0480 {
  public:
    Method4_1b9f90(const char*, ScriptMemberFn);
    hulk_intptr vptr;
    ScriptFunctionFields f;
    ScriptMemberFn field1c;
};
Method4_1b9f90::Method4_1b9f90(const char* a, ScriptMemberFn b) : Ctor_001d0480(a, 4) {
    vptr = ((hulk_intptr)DAT_00420e74);
    field1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0049b95c)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}
