#include "decls/data/engine/core.h"

#include "compat/ptr.h"
extern "C" void FUN_0026d820(void* arg);
void FUN_002702a0(void** out, int a, int b, int c, int d, hulk_intptr e, int f);
extern "C" void __cdecl FUN_00276650(int a, int b) {
    FUN_0026d820(((char*)&DAT_0052a208));
    FUN_002702a0((void**)((char*)&DAT_0052a224), 0x24, a, 0, b, (hulk_intptr)"InstanceDrive", 4);
}