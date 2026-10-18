// FUN_000286b0 @ 0x000286b0
#include "decls/data/game/unknown.h"

extern "C" int atexit(void (*)());
void FUN_00363b60();

struct NameKey_286b0 {
    int lo, hi;
    void FUN_0027af00();
    void FUN_0027b040(const char* s);
};

struct Registry_286b0 {
    void FUN_00066a10(NameKey_286b0* key);
};

Registry_286b0* FUN_000678d0();

// Looks up the static name key in the registry.
void __stdcall FUN_000286b0(int unused, const char* name)
{
    if (((*(unsigned int*)&DAT_004dc150) & 1) == 0) {
        (*(unsigned int*)&DAT_004dc150) |= 1;
        (*(NameKey_286b0*)&DAT_004dc148).FUN_0027af00();
        atexit(FUN_00363b60);
    }
    (*(NameKey_286b0*)&DAT_004dc148).FUN_0027b040(name);
    NameKey_286b0 key = (*(NameKey_286b0*)&DAT_004dc148);
    FUN_000678d0()->FUN_00066a10(&key);
}
