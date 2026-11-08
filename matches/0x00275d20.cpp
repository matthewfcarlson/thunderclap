#include "decls/data/engine/core.h"
#include "decls/data/records.h"
// data: fileName = DAT_0042bc9c

#include "compat/ptr.h"
extern "C" void FUN_0026d820(void* arg);
void FUN_002702a0(void** out, int a, int b, int c, int d, hulk_intptr e, int f);
// the "File" pool (0x00275d50 allocates from it): items are core::File (records.h CoreFile, 0x168 bytes on the
// 32-bit build)
extern "C" void __cdecl FUN_00275d20(int a, int b) {
    HULK_SIZE32(CoreFile, 0x168);
    FUN_0026d820(((char*)&DAT_0052a1e8));
    FUN_002702a0((void**)((char*)&DAT_0052a204), (int)sizeof(CoreFile), a, 0, b, (hulk_intptr)DAT_0042bc9c, 4);
}
