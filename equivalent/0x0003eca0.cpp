// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 10/10)
// FUN_0003eca0 @ 0x0003eca0
// FUN_0003eca0: look up a named value by key, -1 when absent
#include "decls/data/game/global.h"
#include "gen/owners.h"

struct Key_3eca0 {
    int lo;
    int hi;
    void FUN_0027af00();
};

struct Entry_3eca0 {
    int lo;
    int hi;
    float value;
    int pad;
};


extern "C" void __cdecl FUN_00363ba0();
extern "C" int __cdecl atexit(void (__cdecl *fn)());

class Table_3eca0 {
public:
    char pad00[0x1ba8];
    Entry_3eca0 entries[14];
    int count;

    float FUN_0003eca0(const char *name);
};

float Table_3eca0::FUN_0003eca0(const char *name)
{
    if (!((*(unsigned int*)&DAT_004dc2d0) & 1)) {
        (*(unsigned int*)&DAT_004dc2d0) |= 1;
        (*(Key_3eca0*)&DAT_004dc2c8).FUN_0027af00();
        atexit(FUN_00363ba0);
    }
    ((owners::Target_27b040 *)&((*(Key_3eca0*)&DAT_004dc2c8)))->FUN_0027b040((hulk_uintptr)name);
    for (int i = 0; i < count; i++) {
        if (entries[i].lo == (*(Key_3eca0*)&DAT_004dc2c8).lo && entries[i].hi == (*(Key_3eca0*)&DAT_004dc2c8).hi)
            return entries[i].value;
    }
    return -1.0f;
}
