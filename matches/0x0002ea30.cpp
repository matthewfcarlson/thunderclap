#include "compat/ptr.h"
#include "decls/data/script.h"
#include "decls/data/game/global.h"

extern void* VT_Method1[2];
extern void* VT_Closure1[2];

// Closure1's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2ea30 {};
typedef void (Owner_2ea30::*Fn_2ea30)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag(const void* tbl);

class Closure1 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2ea30 fn;            // 0x1c
    Owner_2ea30* owner;     // 0x20
    Closure1(const char* a1, Owner_2ea30* a2, Fn_2ea30 a3);
};

Closure1::Closure1(const char* a1, Owner_2ea30* a2, Fn_2ea30 a3) : FUN_001d0480(a1, 1) {
    vfptr = (void*)VT_Method1;
    fn = a3;
    f.retType = LookupFlag(((void**)&DAT_0048e0f0));
    f.argTypes[0] = LookupFlag(((void**)&DAT_0048e0f0));
    vfptr = (void*)VT_Closure1;
    owner = a2;
}
