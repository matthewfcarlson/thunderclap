// FUN_0002cb60 @ 0x0002cb60
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_003f40dc[];
extern "C" char DAT_0048e10c[];
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
// Method7's initializer (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer; returns this.
class Owner_2cb60 {};
typedef void (Owner_2cb60::*Fn_2cb60)();
class Method7_2cb60 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_2cb60 func;
    Method7_2cb60* Init(const char* name, Fn_2cb60 fn);
};
Method7_2cb60* Method7_2cb60::Init(const char* name, Fn_2cb60 fn) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 7);
    vptr = (void*)DAT_003f40dc;
    func = fn;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[5] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[6] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    return this;
}
