#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_003f5d4c[];
struct Ctor_001d0480 {
    Ctor_001d0480(const char*, int);
};
// Method3's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class Owner_3efb0 {};
typedef void (Owner_3efb0::*Fn_3efb0)();
class Function3_3efb0 : public Ctor_001d0480 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_3efb0 m1c;
    Function3_3efb0(const char*, Fn_3efb0);
};
Function3_3efb0::Function3_3efb0(const char* a, Fn_3efb0 b) : Ctor_001d0480(a, 3) {
    vptr = (void*)DAT_003f5d4c;
    m1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}
