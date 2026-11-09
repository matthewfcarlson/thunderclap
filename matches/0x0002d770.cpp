#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/script.h"
extern "C" char DAT_003f420c[];
// Method4's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class Owner_2d770 {};
typedef void (Owner_2d770::*Fn_2d770)();
class Method4_2d770 {
  public:
    void* vt;
    ScriptFunctionFields f;
    Fn_2d770 m1c;
    Method4_2d770(const char*, Fn_2d770);
};
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
Method4_2d770::Method4_2d770(const char* p, Fn_2d770 q) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(p, 4);
    vt = (void*)DAT_003f420c;
    m1c = q;
    f.retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e128));
    f.argTypes[2] = FUN_001d04d0(((const char*)&DAT_0048e134));
    f.argTypes[3] = FUN_001d04d0(((const char*)&DAT_0048e128));
}
