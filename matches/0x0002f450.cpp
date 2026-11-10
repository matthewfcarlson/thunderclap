// Same code shape as 0x00090eb0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "decls/data/script.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

extern void* VT_Method2[2];
extern void* VT_Closure2[2];
extern void* TAB_48e0f0;

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2f450 {};
typedef void (Owner_2f450::*Fn_2f450)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2f450 fn;            // 0x1c
    Owner_2f450* owner;     // 0x20
    Closure2(const char* a1, Owner_2f450* a2, Fn_2f450 a3);
};

Closure2::Closure2(const char* a1, Owner_2f450* a2, Fn_2f450 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)VT_Method2;
    fn = a3;
    f.retType = LookupFlag(((void**)&DAT_0048e100));
    f.argTypes[0] = LookupFlag(&TAB_48e0f0);
    f.argTypes[1] = LookupFlag(((void**)&DAT_0048e128));
    vfptr = (void*)VT_Closure2;
    owner = a2;
}
