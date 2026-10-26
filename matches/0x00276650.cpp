#include "decls/data/engine/core.h"

extern "C" void __cdecl Init(void*);
extern "C" void __cdecl Register(void*, int, int, int, int, const char*, int);
extern "C" void __cdecl FUN_00276650(int a, int b) {
    Init(((char*)&DAT_0052a208));
    Register(((char*)&DAT_0052a224), 0x24, a, 0, b, "InstanceDrive", 4);
}