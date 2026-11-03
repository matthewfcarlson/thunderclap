#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void* memset(void*, int, unsigned int);
extern void Copy(void*, unsigned int, const char*, const char*);
owners::Obj_1cb050* owners::Obj_1cb050::FUN_001cb050(hulk_intptr a, unsigned int b) {
    memset(data, 0, 84);
    data[0] = 0x54;
    data[1] = 0x1e;
    Copy(&data[5], 0x40, "%s", (const char*)((hulk_uintptr)a));
    data[4] = b;
    return this;
}
