// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 24/28, incomplete)
// FUN_0008a8f0 @ 0x0008a8f0
extern "C" int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);
void __cdecl FUN_00035db0(int v);
extern char DAT_004dd83a;
extern char DAT_004dd83b;

struct Bag {
    void FUN_001eb870();
    void FUN_001eb890();
    void FUN_001eb9e0(int v);
    void FUN_001eba30(int v);
    void FUN_001eba80(int v);
    void FUN_001ebad0(int v);
};

struct FlagObj {
    char pad0[0xc];
    char flag;
    void FUN_001be490();
};

struct Opt1 { void FUN_000ae930(int v); };
struct Opt2 { void FUN_000afe10(bool v); };
struct Bits {
    void FUN_00093600(int i, bool v);
    void FUN_00092870(int i, bool v);
    void FUN_000929a0(int i, int v);
};
struct Pool { void FUN_000901d0(int i, int v); };
struct Pair {
    void FUN_000b46c0();
    void FUN_000c3ea0();
};

struct World {
    Bag *FUN_000862e0();
    Opt1 *FUN_000862c0();
    Opt2 *FUN_00086330();
    Bits *FUN_00086340();
    Pool *FUN_00086370();
    Pair *FUN_00086280();
    FlagObj *FUN_00086380();
};
extern World *DAT_004dd6ec;

struct Rec24 {
    int a, b, c, d, e, f;
};

struct Level {
    char pad0[0x18];
    unsigned char b18;
    unsigned char b19;
    unsigned char b1a;
    char pad1b;
    int f1c;
    int f20;
    int f24;
    unsigned char b28;
    unsigned char b29;
    unsigned char b2a;
    unsigned char b2b;
    unsigned char b2c;
    char pad2d[7];
    unsigned char b34;
    unsigned char b35;
    unsigned char b36;
    char pad37;
    int bits1[32];      // 0x38
    int bits2[32];      // 0xb8
    Rec24 recs[100];    // 0x138
    int arr[51];        // 0xa98
    int count;          // 0xb64
    char padb68[0xbe8 - 0xb68];
};

class Game {
public:
    char pad0[0x80];
    int f80;
    int f84;
    char pad88[0x20];
    int fa8;
    int fac;
    char padb0[0x20];
    int fd0;
    int fd4;
    char name[0x20];
    char padf8[0x60];
    Rec24 recs[100];    // 0x158
    int fab8;
    char padabc[3];
    char babf;
    char pad_ac0[8];
    Level *table;       // 0xac8
    bool FUN_0008a8f0(int idx, World *w);
    void FUN_0008a120();
};

bool Game::FUN_0008a8f0(int idx, World *w)
{
    DAT_004dd6ec->FUN_000862e0()->FUN_001eb870();
    Level *lv = &table[idx];
    fd4 = lv->b19;
    fd0 = lv->b18;
    FUN_00267760(name, 0x20, "c%02dm%02d", lv->b18, lv->b19);
    babf = lv->b1a;
    f84 = -1;
    f80 = -1;
    fac = -1;
    fa8 = -1;
    w->FUN_000862e0()->FUN_001eb9e0(lv->f1c);
    w->FUN_000862e0()->FUN_001eba30(lv->f20);
    w->FUN_000862e0()->FUN_001eba80(lv->f24);
    bool f = lv->b29 != 0;
    FlagObj *fo = w->FUN_00086380();
    if (fo->flag != f)
        fo->FUN_001be490();
    fo->flag = f;
    w->FUN_000862e0()->FUN_001ebad0(lv->b28);
    FUN_00035db0(lv->b34);
    DAT_004dd83a = lv->b35;
    DAT_004dd83b = lv->b36;
    w->FUN_000862c0()->FUN_000ae930(lv->b2b);
    w->FUN_00086330()->FUN_000afe10(lv->b2a != 0);
    fab8 = lv->b2c;
    if (fab8 < 0 || fab8 > 2)
        fab8 = 1;
    Bits *bits = w->FUN_00086340();
    for (int i = 0; i < 0x2fe; i++) {
        bits->FUN_00093600(i, 1);
        bits->FUN_00092870(i, 0);
    }
    for (int i = 0; i < 0x2fe; i++) {
        unsigned int mask = 1 << (i % 32);
        bits->FUN_00093600(i, (mask & lv->bits1[i / 32]) != 0);
        bits->FUN_00092870(i, (mask & lv->bits2[i / 32]) != 0);
    }
    for (int i = 0; i < 0x2fe; i++)
        bits->FUN_000929a0(i, 0);
    Pool *pool = w->FUN_00086370();
    for (int i = 0; i < lv->count; i++)
        pool->FUN_000901d0(i, lv->arr[i]);
    for (int k = 0; k < 100; k++) {
        recs[k].a = lv->recs[k].a;
        recs[k].b = lv->recs[k].b;
        recs[k].c = lv->recs[k].c;
        recs[k].d = lv->recs[k].d;
        recs[k].e = lv->recs[k].e;
        recs[k].f = lv->recs[k].f;
    }
    FUN_0008a120();
    w->FUN_00086280()->FUN_000b46c0();
    w->FUN_00086280()->FUN_000c3ea0();
    DAT_004dd6ec->FUN_000862e0()->FUN_001eb890();
    return true;
}
