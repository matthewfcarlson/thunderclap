#include "compat/ptr.h"
#include "decls/data/script.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_00423438[];
// Method4's initializer (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer; returns this.
class Method4_1e08c0 {
  public:
    hulk_intptr vtable;
    ScriptFunctionFields f;
    ScriptMemberFn field1c;
    Method4_1e08c0* Init(const char*, ScriptMemberFn);
};
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
Method4_1e08c0* Method4_1e08c0::Init(const char* p, ScriptMemberFn b) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(p, 4);
    vtable = ((hulk_intptr)DAT_00423438);
    field1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}