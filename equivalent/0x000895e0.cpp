// STATUS: equivalent (tools/equiv.py level 3: 2056 inputs, branch coverage 18/20, incomplete)
// FUN_000895e0 @ 0x000895e0
#include "decls/address.h"
int __cdecl FUN_00267760(char* dest, int size, const char* fmt, ...);
int __cdecl strncmp(const char*, const char*, unsigned int);
struct LevelInfo {
    bool FUN_000b4c80(const char* name);
};
struct LevelTable {
    LevelInfo* FUN_00086280();
};
struct World {
    char pad[0x54];
    LevelTable* levels;
};
struct LevelAbbrev {
    const char* name;
    const char* abbrev;
};
class LevelName {
public:
    char pad0[0x20];
    char name[0x20];
    char shortName[0x20];
    char displayName[0x20];
    void SetName(const char* levelName);
};
void LevelName::SetName(const char* levelName) {
    char* cur = name;
    if (cur && cur[0])
        FUN_00267760(displayName, 0x20, "%s", cur);
    else
        displayName[0] = 0;
    if (levelName == 0) {
        cur[0] = 0;
        shortName[0] = 0;
        return;
    }
    if (!DAT_004dd700->levels->FUN_00086280()->FUN_000b4c80(levelName))
        return;
    LevelAbbrev table[16] = {
        { "downtown", "dt" },
        { "outskirts", "os" },
        { "industrial", "in" },
        { "sandbox", "sb" },
        { "division_bio_facility", "bf" },
        { "proving_ground", "pg" },
        { "nuclear_power_plant", "pp" },
        { "turning_point", "tp" },
        { "crossroads", "cr" },
        { "the_dam", "dm" },
        { "vault_interior", "vi" },
        { "church", "ch" },
        { "tutorial", "tu" },
        { "banners_cabin", "bc" },
        { "desert_tutorial", "ot" },
        { 0, 0 }
    };
    int len = 0;
    while (levelName[len])
        len++;
    const char* suffix = levelName + len;
    while (*suffix != '_')
        suffix--;
    suffix++;
    for (const LevelAbbrev* e = table; e->name; e++) {
        if (strncmp(e->name, levelName, 4) == 0)
            FUN_00267760(shortName, 0x20, "%s_%s", e->abbrev, suffix);
    }
    if (shortName[0])
        FUN_00267760(cur, 0x20, "%s", levelName);
}
