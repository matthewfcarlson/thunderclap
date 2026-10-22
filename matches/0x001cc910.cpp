// FUN_001cc910 @ 0x001cc910
struct Part_1cc910 {
    void FUN_001dcab0();
    void FUN_001fc790();
    void FUN_00025410();
};

struct Mgr_1cc910 {
    void FUN_001d1710();
};

struct Link_1cc910;

struct Sub_1cc910 {
    void FUN_00098ed0(Link_1cc910 *l);
};

struct Link_1cc910 {
    char pad0[8];
    Sub_1cc910 *f8;
    Part_1cc910 *fc;
    char pad10[0x20 - 0x10];
    Part_1cc910 *f20;
    char pad24[4];
    Part_1cc910 *f28;
};

class CScenarioManager_1cc910 {
public:
    char pad0[4];
    Link_1cc910 *link;
    char pad8[0x1194 - 8];
    int mode;
    void FUN_001cc910(int m);
};

Mgr_1cc910 *FUN_001d4c90();

void CScenarioManager_1cc910::FUN_001cc910(int m)
{
    mode = m;
    if (link != 0 && link->fc != 0)
        link->fc->FUN_001dcab0();
    if (link != 0 && link->f28 != 0)
        link->f28->FUN_001fc790();
    if (link != 0 && link->f20 != 0)
        link->f20->FUN_00025410();
    Link_1cc910 *l = link;
    if (l != 0 && l->f8 != 0)
        l->f8->FUN_00098ed0(l);
    Mgr_1cc910 *mgr = FUN_001d4c90();
    if (mgr != 0)
        mgr->FUN_001d1710();
}
