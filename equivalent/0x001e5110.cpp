// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_001e5110 @ 0x001e5110
// FUN_001e5110 @ 0x001e5110: spawns an effect entry for a kind unless suppressed by settings
#include "decls/address.h"
struct Settings_1e5110 {
    int FUN_00088fa0();
    int FUN_00088fb0();
};
struct Config_1e5110 {
    char pad00[0x80];
    Settings_1e5110 settings;
};
struct Manager_1e5110 {
    Config_1e5110 *FUN_00086310();
};
struct World {
    char pad00[0x54];
    Manager_1e5110 *manager;
};

struct Triple_1e5110 {
    unsigned a;
    unsigned b;
    unsigned c;
};

void *__cdecl FUN_001d68e0(unsigned kind);

class CSPManager_1e5110 {
public:
    void FUN_001e4c40(void *entry, Triple_1e5110 *v, unsigned kind, unsigned w, unsigned x, unsigned y);
    void FUN_001e5110(unsigned kind, unsigned a, unsigned b, unsigned c, unsigned w);
};

void CSPManager_1e5110::FUN_001e5110(unsigned kind, unsigned a, unsigned b, unsigned c, unsigned w)
{
    int flag = DAT_004dd700->manager->FUN_00086310()->settings.FUN_00088fa0();
    int mode = DAT_004dd700->manager->FUN_00086310()->settings.FUN_00088fb0();
    if (flag == 0 && (mode == 1 || mode == 10)) {
        if (kind == 1 || kind == 2 || kind == 3 || kind == 4)
            return;
    }
    void *entry = FUN_001d68e0(kind);
    Triple_1e5110 v;
    v.a = a;
    v.b = b;
    v.c = c;
    FUN_001e4c40(entry, &v, kind, w, 0, 0);
}

