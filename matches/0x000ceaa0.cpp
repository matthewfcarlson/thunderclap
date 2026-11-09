// FUN_000ceaa0 @ 0x000ceaa0
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_0048e10c[];
extern "C" char DAT_0040a500[];
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
// Method4<Owner, void, const char*, float, float, int>'s initializer (name, member function): Function's
// fields (include/decls/data/script.h), then the member-function pointer.
class Owner_ceaa0 {};
typedef void (Owner_ceaa0::*Fn_ceaa0)(const char*, float, float, int);
class Method4_ceaa0 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_ceaa0 fn;
    Method4_ceaa0* FUN_000ceaa0(const char*, Fn_ceaa0);
};
Method4_ceaa0* Method4_ceaa0::FUN_000ceaa0(const char* name, Fn_ceaa0 fp) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 4);
    vptr = (void*)DAT_0040a500;
    fn = fp;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[3] = FUN_001d04d0(DAT_0048e10c);
    return this;
}
