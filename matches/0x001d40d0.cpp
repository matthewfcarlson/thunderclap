// Same code shape as 0x00090eb0 (propagated; names are from that function)
#include "decls/data/game/global.h"
#include "decls/address.h"
#include "decls/data/script.h"

extern void* VT_Method2[2];
extern void* VT_Closure2[2];

// Closure2<ScriptHandler, void, const char*, const char*>'s constructor (name, object, member function): Function's
// fields (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class ScriptHandler_1d40d0 {};
typedef void (ScriptHandler_1d40d0::*Fn_1d40d0)(const char*, const char*);
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_1d40d0 fn;            // 0x1c
    ScriptHandler_1d40d0* owner;  // 0x20

    Closure2(const char* a1, ScriptHandler_1d40d0* a2, Fn_1d40d0 a3);
};

Closure2::Closure2(const char* a1, ScriptHandler_1d40d0* a2, Fn_1d40d0 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)VT_Method2;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)VT_Closure2;
    owner = a2;
}
