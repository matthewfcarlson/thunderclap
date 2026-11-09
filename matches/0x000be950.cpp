// FUN_000be950 @ 0x000be950
// 0x000be950: Method6 callback object constructor (bool/byte flags from the per-type descriptor words)
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
extern char DAT_00409108[];

// Method6<Owner, void, const char*, const char*, const char*, const char*, const char*, const char*>'s initializer (name, member function): Function's
// fields (include/decls/data/script.h), then the member-function pointer.
class Owner_be950 {};
typedef void (Owner_be950::*Fn_be950)(const char*, const char*, const char*, const char*, const char*, const char*);
class Method6_be950 {
public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_be950 p1c;
    void FUN_001d0480(const char*, int);
    Method6_be950* Init(const char* arg, Fn_be950 value);
};

Method6_be950* Method6_be950::Init(const char* arg, Fn_be950 value)
{
    FUN_001d0480(arg, 6);
    vptr = (void*)DAT_00409108;
    p1c = value;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[3] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[4] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[5] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    return this;
}
