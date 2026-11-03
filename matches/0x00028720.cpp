// FUN_00028720 @ 0x00028720
#include "decls/data/game/unknown.h"
#include "gen/owners.h"

extern "C" int atexit(void (*)());
void FUN_00363b70();

struct NameKey_28720 {
    int lo, hi;
    void FUN_0027af00();
};

struct Registry_28720 {
    void FUN_00065ee0(NameKey_28720* key);
};

Registry_28720* FUN_000678d0();

// Looks up the static name key in the registry.
void __stdcall FUN_00028720(const char* name, int unused)
{
    if (((*(unsigned int*)&DAT_004dc160) & 1) == 0) {
        (*(unsigned int*)&DAT_004dc160) |= 1;
        (*(NameKey_28720*)&DAT_004dc158).FUN_0027af00();
        atexit(FUN_00363b70);
    }
    ((owners::Target_27b040 *)&((*(NameKey_28720*)&DAT_004dc158)))->FUN_0027b040((hulk_uintptr)name);
    NameKey_28720 key = (*(NameKey_28720*)&DAT_004dc158);
    FUN_000678d0()->FUN_00065ee0(&key);
}
