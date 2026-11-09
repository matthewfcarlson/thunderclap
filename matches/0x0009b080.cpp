// FUN_0009b080 @ 0x0009b080
// 0x0009b080: Method6 callback object constructor (bool/byte flags from the per-type descriptor words)
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern char DAT_00404cc0[];

// Method6<Owner, void, int, int, float, int, int, float>'s initializer (name, member function): Function's
// fields (include/decls/data/script.h), then the member-function pointer.
class Owner_9b080 {};
typedef void (Owner_9b080::*Fn_9b080)(int, int, float, int, int, float);
class Method6_9b080 {
public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_9b080 p1c;
    void FUN_001d0480(const char*, int);
    Method6_9b080* Init(const char* arg, Fn_9b080 value);
};

Method6_9b080* Method6_9b080::Init(const char* arg, Fn_9b080 value)
{
    FUN_001d0480(arg, 6);
    vptr = (void*)DAT_00404cc0;
    p1c = value;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e134));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e134));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[3] = FUN_001d04d0(((char*)&DAT_0048e134));
    f.argTypes[4] = FUN_001d04d0(((char*)&DAT_0048e134));
    f.argTypes[5] = FUN_001d04d0(((char*)&DAT_0048e128));
    return this;
}
