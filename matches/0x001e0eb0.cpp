#include "compat/ptr.h"
#include "decls/data/script.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_004234c8[];
struct Ctor_001d0480 {
    Ctor_001d0480(const char*, int);
};
// Method6's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class Method6_1e0eb0 : public Ctor_001d0480 {
  public:
    hulk_intptr vp;
    ScriptFunctionFields f;
    ScriptMemberFn m1c;
    Method6_1e0eb0(const char*, ScriptMemberFn);
};
Method6_1e0eb0::Method6_1e0eb0(const char* a, ScriptMemberFn b) : Ctor_001d0480(a, 6) {
    vp = ((hulk_intptr)DAT_004234c8);
    m1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[4] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[5] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
}