// STATUS: equivalent (tools/equiv.py level 3: 229 inputs, branch coverage 85/98, incomplete)
// FUN_000b5ca0 @ 0x000b5ca0
// equiv-map: ??_R0?AVFEObject@@@8 = 0x0049dba4
// equiv-map: ??_R0?AVTextSelector@@@8 = 0x0049dbbc

class FEObject {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22();
};

struct Item {
    char pad0[0x14];
    int value;                       // 0x14
    char pad18[0x24 - 0x18];
};

struct Entry {
    int enabled;                     // 0
    int id;                          // 4
    char pad8[0x14 - 8];
    Item *items;                     // 0x14
    char pad18[0x20 - 0x18];
    int sel;                         // 0x20
    char pad24[0x38 - 0x24];
};

class TextSelector : public FEObject {
public:
    char pad_ts[0x168 - 4];
    Entry entries[127];              // 0x168
    char pad_end[0x1d58 - 0x168 - 127 * 0x38];
    int count;                       // 0x1d58
};

struct Loc2 {
    char pad0[0x14];
    int f14;
    char pad18[0x24 - 0x18];
    void FUN_000f7930();
    void FUN_000f8500(const char *key, int a, int b);
    void FUN_000f7960();
};

struct Menu {
    void FUN_00092870(int i, int v);
};

struct Getter {
    void FUN_00203870(const char *s);
};

struct Reg {
    Getter *FUN_000862a0();
};

struct World {
    char pad0[0x54];
    Reg *f54;
};
extern World *DAT_004dd700;

FEObject *__cdecl FUN_000fc260(const char *name);

struct Frame {
    int i;                           // S+0x10
    Entry *p;                        // 0x14
    TextSelector *t;                 // 0x18
    Loc2 A;                          // 0x1c
    Loc2 B;                          // 0x40
    Loc2 C;                          // 0x64
};

#define CHEAT(NAME, KEY, K) \
    f.B.FUN_000f8500(NAME, 0, 1); \
    if (cur == f.B.f14) { \
        DAT_004dd700->f54->FUN_000862a0()->FUN_00203870(KEY); \
        f4c->FUN_00092870(K, 1); \
    }

#define OPTION(NAME, IDX) \
    f.A.FUN_000f8500(NAME, 0, 1); \
    if (id == f.A.f14) \
        f4c->FUN_00092870(IDX, cur == on);

class Env {
public:
    char pad0[0x4c];
    Menu *f4c;
    void FUN_000b5ca0();
};

void Env::FUN_000b5ca0()
{
    Frame f;
    f.t = dynamic_cast<TextSelector *>(FUN_000fc260("unlocked_cheats"));
    if (f.t == 0)
        return;
    int n;
    for (n = 0; n <= 12; n++)
        f4c->FUN_00092870(n, 0);
    f4c->FUN_00092870(0xe, 0);
    f4c->FUN_00092870(0xd, 0);
    f.i = 0;
    if (f.t->count <= 0)
        return;
    f.p = &f.t->entries[0];
    do {
        if (f.p->enabled != 0 || f.p->id != -1) {
            int id = f.p->id;
            if (id != -1) {
                int cur = f.p->items[f.p->sel].value;
                f.A.FUN_000f7930();
                f.A.FUN_000f8500("TBS_CHEAT_CHARACTER", 0, 1);
                if (id == f.A.f14) {
                    f.B.FUN_000f7930();
                    f.B.FUN_000f8500("TBS_CHEAT_HULK", 0, 1);
                    if (cur == f.B.f14) {
                        DAT_004dd700->f54->FUN_000862a0()->FUN_00203870("hulk");
                    }
            CHEAT("TBS_CHEAT_GREY_HULK", "grey_hulk", 0x1)
            CHEAT("TBS_CHEAT_JOE_FIXIT", "joefixit", 0x2)
            CHEAT("TBS_CHEAT_ABOMINATION", "abomination_ashulk", 0x3)
            CHEAT("TBS_CHEAT_SAVAGE_BANNER", "banner_savage", 0x4)
            CHEAT("TBS_CHEAT_FLAG_CANADA", "hulk_canada", 0x5)
            CHEAT("TBS_CHEAT_FLAG_AUSTRALIA", "hulk_australia", 0x0)
            CHEAT("TBS_CHEAT_FLAG_AMERICA", "hulk_us", 0x6)
            CHEAT("TBS_CHEAT_FLAG_ENGLAND", "hulk_uk", 0x7)
            CHEAT("TBS_CHEAT_FLAG_FRANCE", "hulk_france", 0x8)
            CHEAT("TBS_CHEAT_FLAG_GERMANY", "hulk_german", 0x9)
            CHEAT("TBS_CHEAT_FLAG_ITALY", "hulk_italy", 0xa)
            CHEAT("TBS_CHEAT_FLAG_SPAIN", "hulk_spain", 0xb)
            CHEAT("TBS_CHEAT_FLAG_JAPAN", "hulk_japan", 0xc)
                    f.B.FUN_000f7960();
                    f.A.FUN_000f7960();
                } else {
                    f.A.FUN_000f8500("TBS_CHEAT_RENDER_MODE", 0, 1);
                    if (id == f.A.f14) {
                        f.C.FUN_000f7930();
                        f.C.FUN_000f8500("TBS_CHEAT_SEPIA", 0, 1);
                        if (cur == f.C.f14)
                            f4c->FUN_00092870(0xe, 1);
                        f.C.FUN_000f8500("TBS_CHEAT_BLACK_AND_WHITE", 0, 1);
                        if (cur == f.C.f14)
                            f4c->FUN_00092870(0xd, 1);
                        f.C.FUN_000f7960();
                    }
                    f.A.FUN_000f8500("TBS_MENU_ITEM_CHOICE_ON", 0, 1);
                    int on = f.A.f14;
            OPTION("TBS_CHEAT_INVULNERABILITY", 0x2e4)
            OPTION("TBS_CHEAT_DOUBLE_DAMAGE", 0x14)
            OPTION("TBS_CHEAT_DOUBLE_HEALTH_COLLECTABLE", 0x15)
            OPTION("TBS_CHEAT_CABS", 0x16)
            OPTION("TBS_CHEAT_GIANT_BLUE_GORILLA", 0x1a)
            OPTION("TBS_CHEAT_LOW_GRAVITY", 0x13)
            OPTION("TBS_CHEAT_ROAD_RAGE", 0x25)
            OPTION("TBS_CHEAT_MASS_TRANSIT", 0x26)
            OPTION("TBS_CHEAT_COLOUR_CONCEPT_1", 0x27)
            OPTION("TBS_CHEAT_COLOUR_CONCEPT_2", 0x28)
            OPTION("TBS_CHEAT_COLOUR_CONCEPT_3", 0x29)
            OPTION("TBS_CHEAT_COW_MISSILES", 0x2f)
                    f.A.FUN_000f7960();
                }
            }
        }
        f.i++;
        f.p++;
    } while (f.i < f.t->count);
}
