#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
extern "C" char DAT_003f40cc[];
struct Ctor_001d0480 {
    Ctor_001d0480(const char*, int);
};
// Method6's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class Owner_2ca50 {};
typedef void (Owner_2ca50::*Fn_2ca50)();
class Method6 : public Ctor_001d0480 {
  public:
    void* vt;
    ScriptFunctionFields f;
    Fn_2ca50 m1c;
    Method6(const char*, Fn_2ca50);
};
Method6::Method6(const char* a, Fn_2ca50 b) : Ctor_001d0480(a, 6) {
    vt = (void*)((hulk_intptr)DAT_003f40cc);
    m1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[4] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[5] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
}
