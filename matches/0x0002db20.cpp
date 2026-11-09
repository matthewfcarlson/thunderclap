#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_003f425c[];
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
// Method3's initializer (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer; returns this.
class Owner_2db20 {};
typedef void (Owner_2db20::*Fn_2db20)();
class Method3_2db20 {
  public:
    void* vftable;
    ScriptFunctionFields f;
    Fn_2db20 member1c;
    Method3_2db20* Init(const char*, Fn_2db20);
};
Method3_2db20* Method3_2db20::Init(const char* arg1, Fn_2db20 arg2) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(arg1, 3);
    vftable = (void*)DAT_003f425c;
    member1c = arg2;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}
