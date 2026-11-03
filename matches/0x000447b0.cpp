// FUN_000447b0 @ 0x000447b0
#include "decls/data/game/global.h"
#include "gen/owners.h"

extern "C" int __cdecl strcmp(const char*, const char*);
void owners::Config_447b0::FUN_000447b0(const char* name) {
    if (!name)
        return;
    for (int i = 0; i < 4; i++) {
        if (strcmp(name, ((const char**)&DAT_0048f6a4)[i]) == 0) {
            mode = i;
            return;
        }
    }
}
