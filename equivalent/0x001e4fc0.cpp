// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 16/16)
// FUN_001e4fc0 @ 0x001e4fc0
// FUN_001e4fc0 @ 0x001e4fc0: like 0x001e5070 but skips a missing entry
struct Settings_1e4fc0 {
    int FUN_00088fa0();
    int FUN_00088fb0();
};
struct Config_1e4fc0 {
    char pad00[0x80];
    Settings_1e4fc0 settings;
};
struct Manager_1e4fc0 {
    Config_1e4fc0 *FUN_00086310();
};
struct Global_1e4fc0 {
    char pad00[0x54];
    Manager_1e4fc0 *manager;
};
extern Global_1e4fc0 *DAT_004dd700;

struct Triple_1e4fc0 {
    unsigned a;
    unsigned b;
    unsigned c;
};

void *__cdecl FUN_001d68e0(unsigned kind);

class Emitter_1e4fc0 {
public:
    void FUN_001e4c40(void *entry, Triple_1e4fc0 *v, unsigned kind, unsigned w, unsigned x, unsigned y);
    void FUN_001e4fc0(unsigned kind, unsigned a, unsigned b, unsigned c);
};

void Emitter_1e4fc0::FUN_001e4fc0(unsigned kind, unsigned a, unsigned b, unsigned c)
{
    int flag = DAT_004dd700->manager->FUN_00086310()->settings.FUN_00088fa0();
    int mode = DAT_004dd700->manager->FUN_00086310()->settings.FUN_00088fb0();
    if (flag == 0 && (mode == 1 || mode == 10)) {
        if (kind == 1 || kind == 2 || kind == 3 || kind == 4)
            return;
    }
    void *entry = FUN_001d68e0(kind);
    if (entry == 0)
        return;
    Triple_1e4fc0 v;
    v.a = a;
    v.b = b;
    v.c = c;
    FUN_001e4c40(entry, &v, kind, 0, 0, 1);
}

