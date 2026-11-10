#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/script.h"
extern "C" char DAT_003f421c[];
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
// Method4's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class Owner_2d830 {};
typedef void (Owner_2d830::*Fn_2d830)();
class Method4_2d830 : public FUN_001d0480 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_2d830 m1c;
    Method4_2d830(const char*, Fn_2d830);
};
Method4_2d830::Method4_2d830(const char* a, Fn_2d830 b) : FUN_001d0480(a, 4) {
    vptr = (void*)DAT_003f421c;
    m1c = b;
    f.retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e128));
    f.argTypes[2] = FUN_001d04d0(((const char*)&DAT_0048e128));
    f.argTypes[3] = FUN_001d04d0(((const char*)&DAT_0048e128));
}
