#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/address.h"
#include "decls/data/script.h"

extern void* VT_Method2[2];
extern void* VT_Closure2[2];

// Closure2<Owner, void, const char*, int>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class Owner_090eb0 {};
typedef void (Owner_090eb0::*Fn_090eb0)(const char*, int);
struct Ctor_001d0480 {
    Ctor_001d0480(const char* a1, int b);
};

class Closure2 : public Ctor_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_090eb0 fn;            // 0x1c
    Owner_090eb0* owner;     // 0x20

    Closure2(const char* a1, Owner_090eb0* a2, Fn_090eb0 a3);
};

Closure2::Closure2(const char* a1, Owner_090eb0* a2, Fn_090eb0 a3) : Ctor_001d0480(a1, 2) {
    vfptr = (void*)VT_Method2;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e134));
    vfptr = (void*)VT_Closure2;
    owner = a2;
}
