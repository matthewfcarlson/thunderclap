// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000be950 @ 0x000be950
// 0x000be950: Method6 callback object constructor (bool/byte flags from the per-type descriptor words)
#include "decls/address.h"
extern char DAT_00409108[];
extern char DAT_0048e100[];
extern char DAT_0048e0f0[];
extern char DAT_0048e0f0[];
extern char DAT_0048e0f0[];
extern char DAT_0048e0f0[];
extern char DAT_0048e0f0[];
extern char DAT_0048e0f0[];

class Callback_be950 {
public:
    int vptr;
    char pad04[12];
    char b10, b11, b12, b13, b14, b15;
    char pad16[2];
    char b18;
    char pad19[3];
    void* p1c;
    void FUN_001d0480(void*, int);
    Callback_be950* Init(void* arg, void* value);
};

Callback_be950* Callback_be950::Init(void* arg, void* value)
{
    FUN_001d0480(arg, 6);
    vptr = (int)DAT_00409108;
    p1c = value;
    b18 = FUN_001d04d0(DAT_0048e100);
    b10 = FUN_001d04d0(DAT_0048e0f0);
    b11 = FUN_001d04d0(DAT_0048e0f0);
    b12 = FUN_001d04d0(DAT_0048e0f0);
    b13 = FUN_001d04d0(DAT_0048e0f0);
    b14 = FUN_001d04d0(DAT_0048e0f0);
    b15 = FUN_001d04d0(DAT_0048e0f0);
    return this;
}
