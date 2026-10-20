// FUN_0009b080 @ 0x0009b080
// 0x0009b080: Method6 callback object constructor (bool/byte flags from the per-type descriptor words)
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern char DAT_00404cc0[];

class Callback_9b080 {
public:
    hulk_intptr vptr;
    char pad04[12];
    char b10, b11, b12, b13, b14, b15;
    char pad16[2];
    char b18;
    char pad19[3];
    void* p1c;
    void FUN_001d0480(void*, int);
    Callback_9b080* Init(void* arg, void* value);
};

Callback_9b080* Callback_9b080::Init(void* arg, void* value)
{
    FUN_001d0480(arg, 6);
    vptr = (hulk_intptr)DAT_00404cc0;
    p1c = value;
    b18 = FUN_001d04d0(((char*)&DAT_0048e100));
    b10 = FUN_001d04d0(((char*)&DAT_0048e134));
    b11 = FUN_001d04d0(((char*)&DAT_0048e134));
    b12 = FUN_001d04d0(((char*)&DAT_0048e128));
    b13 = FUN_001d04d0(((char*)&DAT_0048e134));
    b14 = FUN_001d04d0(((char*)&DAT_0048e134));
    b15 = FUN_001d04d0(((char*)&DAT_0048e128));
    return this;
}
