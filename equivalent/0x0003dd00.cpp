// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0003dd00 @ 0x0003dd00
struct Sub_3dd00 {
    void FUN_00232240();
};

struct Mgr_3dd00 {
    void FUN_00222b90(bool flag);
};

struct Owner_3dd00 {
    char pad[0x18];
    Mgr_3dd00 *mgr;
    Mgr_3dd00 *FUN_00059a40();
};

struct CCharacter_3dd00 {
    char pad00[0x10];
    Owner_3dd00 *owner;
    char pad14[0xb4 - 0x14];
    Sub_3dd00 subB4;
    char padB5[0xdc - 0xb5];
    Sub_3dd00 subDC;
    char padDD[0x114 - 0xdd];
    int refs;
    char pad118[1];
    bool enabled;
    char pad11a[0x1b1c - 0x11a];
    int enableDepth;
    void FUN_000393c0();
    void FUN_0003dd00(bool enable);
};

void CCharacter_3dd00::FUN_0003dd00(bool enable)
{
    enabled = enable;
    if (enable) {
        enableDepth++;
        refs++;
        owner->FUN_00059a40()->FUN_00222b90(true);
        subB4.FUN_00232240();
        subDC.FUN_00232240();
        FUN_000393c0();
    } else {
        enableDepth--;
        refs--;
    }
}
