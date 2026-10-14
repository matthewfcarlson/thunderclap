// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_001cc910 @ 0x001cc910
struct Part {
    void FUN_001dcab0();
    void FUN_001fc790();
    void FUN_00025410();
};

struct Mgr {
    void FUN_001d1710();
};

struct Link;

struct Sub {
    void FUN_00098ed0(Link *l);
};

struct Link {
    char pad0[8];
    Sub *f8;
    Part *fc;
    char pad10[0x20 - 0x10];
    Part *f20;
    char pad24[4];
    Part *f28;
};

class Screen {
public:
    char pad0[4];
    Link *link;
    char pad8[0x1194 - 8];
    int mode;
    void FUN_001cc910(int m);
};

Mgr *FUN_001d4c90();

void Screen::FUN_001cc910(int m)
{
    mode = m;
    if (link != 0 && link->fc != 0)
        link->fc->FUN_001dcab0();
    if (link != 0 && link->f28 != 0)
        link->f28->FUN_001fc790();
    if (link != 0 && link->f20 != 0)
        link->f20->FUN_00025410();
    Link *l = link;
    if (l != 0 && l->f8 != 0)
        l->f8->FUN_00098ed0(l);
    Mgr *mgr = FUN_001d4c90();
    if (mgr != 0)
        mgr->FUN_001d1710();
}
