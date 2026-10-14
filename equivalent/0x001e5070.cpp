// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_001e5070 @ 0x001e5070
// FUN_001e5070 @ 0x001e5070: same as 0x001e5110 with the trailing flag set
struct Settings {
    int FUN_00088fa0();
    int FUN_00088fb0();
};
struct Config {
    char pad00[0x80];
    Settings settings;
};
struct Manager {
    Config *FUN_00086310();
};
struct Global {
    char pad00[0x54];
    Manager *manager;
};
extern Global *DAT_004dd700;

struct Triple {
    unsigned a;
    unsigned b;
    unsigned c;
};

void *__cdecl FUN_001d68e0(unsigned kind);

class Emitter {
public:
    void FUN_001e4c40(void *entry, Triple *v, unsigned kind, unsigned w, unsigned x, unsigned y);
    void FUN_001e5070(unsigned kind, unsigned a, unsigned b, unsigned c, unsigned w);
};

void Emitter::FUN_001e5070(unsigned kind, unsigned a, unsigned b, unsigned c, unsigned w)
{
    int flag = DAT_004dd700->manager->FUN_00086310()->settings.FUN_00088fa0();
    int mode = DAT_004dd700->manager->FUN_00086310()->settings.FUN_00088fb0();
    if (flag == 0 && (mode == 1 || mode == 10)) {
        if (kind == 1 || kind == 2 || kind == 3 || kind == 4)
            return;
    }
    void *entry = FUN_001d68e0(kind);
    Triple v;
    v.a = a;
    v.b = b;
    v.c = c;
    FUN_001e4c40(entry, &v, kind, w, 0, 1);
}

