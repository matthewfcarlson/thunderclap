// STATUS: equivalent (tools/equiv.py level 3: 14639 inputs, branch coverage 36/36)
// hulkfight::DialogueAction::vfunc_3 @ 0x0012f750
// cl-flags: /GS
#include "gen/hulkfight.h"
#include "decls/address.h"

struct Item_12f750 { char pad[0x1c]; int f1c; };
struct Info_12f750 {
    char pad0[0x10];
    int f10;
    const char *name14;
    char pad2[4];
    int f1c;
    const char *name20;
    char flag24;
};
struct Sub_12f750 { const char *FUN_000443b0(); };
struct Player_12f750 {
    char pad0[0x11c];
    Sub_12f750 *sub11c;
    char pad1[0x334 - 0x120];
    Player_12f750 *f334;
    char pad2[0x20b0 - 0x338];
    int f20b0;
    const char *FUN_00036d00();
};
struct Mgr_12f750 { Player_12f750 *FUN_00059a30(); };
struct Obj3_12f750 { char FUN_00092de0(); };
struct Holder_12f750 { char pad[8]; int f8; Mgr_12f750 *FUN_000592a0(); };
struct Singleton_4dd6ec { Obj3_12f750 *FUN_00086340(int n); };
struct Target_12f750 { void FUN_001ecda0(char *a, int b, char *c, int d); };
struct World { char pad[0x34]; Target_12f750 *t34; };
struct Name64 { char c[0x40]; };

bool hulkfight::DialogueAction::vfunc_3(int a, int b) {
    if ((*(Holder_12f750 * *)&this->f_20) == 0) {
        return (bool)(0);
    }
    Player_12f750 *pl = 0;
    Mgr_12f750 *mgr = (*(Holder_12f750 * *)&this->f_20)->FUN_000592a0();
    if (mgr)
        pl = mgr->FUN_00059a30();
    Info_12f750 *inf = (*(Info_12f750 * *)&this->f_1c);
    if (inf->flag24) {
        if (pl && pl->f334)
            pl = pl->f334;
    }
    if (pl && pl->f20b0) {
        return (bool)(0);
    }
    char nameB[0x40] = "";
    char nameA[0x40] = "";
    if (inf->name14) {
        const char *s = inf->name14;
        char *d = nameA;
        char c;
        do { c = *s++; *d++ = c; } while (c);
    }
    if (inf->name20) {
        const char *s = inf->name20;
        char *d = nameB;
        char c;
        do { c = *s++; *d++ = c; } while (c);
    }
    if (nameB[0] == 0 && pl) {
        const char *r = pl->FUN_00036d00();
        const char *h = "hulk";
        int k = 0;
        while (k < 5 && r[k] == h[k]) k++;
        if (k == 5) {
            if (DAT_004dd6ec->FUN_00086340(2)->FUN_00092de0() != 0)
                for (int i = 0; i < 5; i++) nameB[i] = h[i];
        } else {
            const char *s = pl->FUN_00036d00();
            char *d = nameB;
            char c;
            do { c = *s++; *d++ = c; } while (c);
            if (nameA[0] == 0) {
                s = pl->sub11c->FUN_000443b0();
                d = nameA;
                do { c = *s++; *d++ = c; } while (c);
            }
        }
    }
    DAT_004dd700->t34->FUN_001ecda0(nameA, (*(Info_12f750 * *)&this->f_1c)->f1c, nameB, (*(Info_12f750 * *)&this->f_1c)->f10);
    return (bool)(1);
}
