#include "gen/owners.h"
typedef unsigned int u32_1caf80;
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern void __cdecl CopyText(char*, unsigned int, const char*, const char*);
owners::Obj_1caf80* owners::Obj_1caf80::FUN_001caf80(const char* a, u32_1caf80 b) {
    memset(this, 0, 0x54);
    data[0] = 0x54;
    data[1] = 0x1d;
    CopyText((char*)&data[5], 0x40, "%s", a);
    data[4] = b;
    return this;
}