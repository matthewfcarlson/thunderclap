#include "decls/data/engine/core.h"
#include "decls/data/records.h"
// data: tag = DAT_0042b904

#include "compat/ptr.h"
#include "gen/core.h"
extern "C" void FUN_0026d820(void* arg);
void FUN_002702a0(void** out, int a, int b, int c, int d, hulk_intptr e, int f);
// the "FileRequest" pool (0x00273560 allocates from it): every core::Request the drives queue comes from it, so
// its item is the largest request class, core::DriveFindFirstRequest (0x114 bytes on the 32-bit build)
extern "C" void FUN_00273530(int a, int b) {
    HULK_SIZE32(core::DriveFindFirstRequest, 0x114);
    FUN_0026d820(((char*)&DAT_0052a1c8));
    FUN_002702a0((void**)((char*)&DAT_0052a1e4), (int)sizeof(core::DriveFindFirstRequest), a, 0, b, (hulk_intptr)DAT_0042b904, 4);
}
