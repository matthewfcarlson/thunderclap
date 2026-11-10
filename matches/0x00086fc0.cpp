#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
extern "C" char DAT_003ffb80[];
extern "C" char DAT_0048e10c[];
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
// Function4's constructor (name, function): Function's fields (include/decls/data/script.h), then the bound
// function pointer.
typedef bool (*Fn_86fc0)();
class Function4_86fc0 : public FUN_001d0480 {
  public:
    void* vt;
    ScriptFunctionFields f;
    Fn_86fc0 member1c;
    Function4_86fc0(const char*, Fn_86fc0);
};
Function4_86fc0::Function4_86fc0(const char* a, Fn_86fc0 b) : FUN_001d0480(a, 4) {
    vt = (void*)DAT_003ffb80;
    member1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
}
