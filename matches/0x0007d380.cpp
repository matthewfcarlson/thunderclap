#include "decls/data/game/global.h"

#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/script.h"
extern "C" char DAT_003ff014[];
extern const char s3[];
class Function_7d380 {
  public:
    void Init(const char*, int);
};
// Method4's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class Owner_7d380 {};
typedef void (Owner_7d380::*Fn_7d380)();
class Method4_7d380 : public Function_7d380 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_7d380 member1c;
    Method4_7d380(const char*, Fn_7d380);
};
Method4_7d380::Method4_7d380(const char* p, Fn_7d380 x) {
    Init(p, 4);
    vptr = (void*)DAT_003ff014;
    member1c = x;
    f.retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e134));
    f.argTypes[2] = FUN_001d04d0(s3);
    f.argTypes[3] = FUN_001d04d0(s3);
}
