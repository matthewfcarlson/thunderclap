#include "decls/data/engine/core.h"
#include "decls/data/records.h"

#include "compat/ptr.h"
#include "gen/core.h"
extern "C" void FUN_0026d820(void* arg);
void FUN_002702a0(void** out, int a, int b, int c, int d, hulk_intptr e, int f);
// the "InstanceDrive" pool (0x00276680 allocates from it): items are core::InstanceDrive (0x24 bytes on the 32-bit build)
extern "C" void __cdecl FUN_00276650(int a, int b) {
    HULK_SIZE32(core::InstanceDrive, 0x24);
    FUN_0026d820(((char*)&DAT_0052a208));
    FUN_002702a0((void**)((char*)&DAT_0052a224), (int)sizeof(core::InstanceDrive), a, 0, b, (hulk_intptr)"InstanceDrive", 4);
}
