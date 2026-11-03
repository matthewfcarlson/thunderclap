// FUN_000c3db0 @ 0x000c3db0
#include "decls/data/game/global.h"
#include "gen/owners.h"

class CUnlockable_c3db0 {
  public:
    virtual void v0();
};
class CUnlockableGallery_c3db0 : public CUnlockable_c3db0 {
  public:
    const char* FUN_00092320();
    const char* FUN_00092330();
};
class ItemTable_c3db0 {
  public:
};

class Screen_c3db0 {
  public:
    char pad0[0x10];
    int field10;
    char pad1[0x4c - 0x14];
    ItemTable_c3db0* items;
    char pad2[0x1878 - 0x50];
    char flag1878;
    char pad3[3];
    int selected;
    char pad4[0x1a04 - 0x1880];
    char flag1a04;
    char pad5[3];
    int field1a08;
    void FUN_000ba040();
    char FUN_000c3900(const char* a, int b, int c, int d, const char* e, int f, int g);
    void FUN_000c3db0();
};

void Screen_c3db0::FUN_000c3db0() {
    CUnlockableGallery_c3db0* g = dynamic_cast<CUnlockableGallery_c3db0*>(((CUnlockable_c3db0 *)((owners::C_92ad0 *)items)->FUN_00092ad0((hulk_intptr)selected)));
    if (g == 0)
        return;
    if (FUN_000c3900(g->FUN_00092330(), DAT_0049fb34, DAT_0049fb38, 1, g->FUN_00092320(), 0, 1000)) {
        flag1a04 = 0;
        flag1878 = 1;
        field10 = 0;
        ((owners::Target_92360 *)g)->FUN_00092360(0);
        FUN_000ba040();
        field1a08 = 0;
    }
}
