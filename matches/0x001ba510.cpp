// Same code shape as 0x00090eb0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/script.h"
extern void* VT_Method2[2];
extern void* VT_Closure2[2];
extern void* TAB_48e100;
extern void* TAB_48e0f0;
extern void* TAB_48e134;

struct Ctor_001d0480 {
    Ctor_001d0480(const char* a1, int b);
};

// Closure2's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method2's member-function pointer and Closure2's object.
class Closure2 : public Ctor_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn fn;       // 0x1c
    void* owner;             // 0x20

    Closure2(const char* a1, void* a2, ScriptMemberFn a3);
};

Closure2::Closure2(const char* a1, void* a2, ScriptMemberFn a3) : Ctor_001d0480(a1, 2) {
    vfptr = (void*)VT_Method2;
    fn = a3;
    f.retType = FUN_001d04d0(&TAB_48e100);
    f.argTypes[0] = FUN_001d04d0(&TAB_48e0f0);
    f.argTypes[1] = FUN_001d04d0(&TAB_48e134);
    vfptr = (void*)VT_Closure2;
    owner = a2;
}
