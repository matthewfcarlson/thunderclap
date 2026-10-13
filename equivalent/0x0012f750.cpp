// STATUS: equivalent (tools/equiv.py level 3: 2355 inputs, branch coverage 36/36)
// hulkfight::DialogueAction::vfunc_3 @ 0x0012f750
struct Item { char pad[0x1c]; int f1c; };
struct Info {
    char pad0[0x10];
    int f10;
    const char *name14;
    char pad2[4];
    int f1c;
    const char *name20;
    char flag24;
};
struct Sub { const char *FUN_000443b0(); };
struct Player {
    char pad0[0x11c];
    Sub *sub11c;
    char pad1[0x334 - 0x120];
    Player *f334;
    char pad2[0x20b0 - 0x338];
    int f20b0;
    const char *FUN_00036d00();
};
struct Mgr { Player *FUN_00059a30(); };
struct Obj3 { char FUN_00092de0(); };
struct Holder { char pad[8]; int f8; Mgr *FUN_000592a0(); };
struct Svc { Obj3 *FUN_00086340(int n); };
struct Target { void FUN_001ecda0(char *a, int b, char *c, int d); };
struct Sink2 { char pad[0x34]; Target *t34; };
extern Svc *DAT_004dd6ec;
extern Sink2 *DAT_004dd700;
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
struct Name64 { char c[0x40]; };
class DialogueAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(int a, int b);
    char pad[0x1c - 4];
    Info *info;
    Holder *f20;
};

char DialogueAction::vfunc_3(int a, int b)
{
    unsigned int cookie0 = DAT_004d9968;
    if (f20 == 0) {
        __security_check_cookie(cookie0);
        return 0;
    }
    Player *pl = 0;
    Mgr *mgr = f20->FUN_000592a0();
    if (mgr)
        pl = mgr->FUN_00059a30();
    Info *inf = info;
    if (inf->flag24) {
        if (pl && pl->f334)
            pl = pl->f334;
    }
    if (pl && pl->f20b0) {
        __security_check_cookie(cookie0);
        return 0;
    }
    char nameB[0x40] = "";
    char nameA[0x44] = "";
    unsigned int *cookie = (unsigned int *)(nameA + 0x40);
    *cookie = cookie0;
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
    DAT_004dd700->t34->FUN_001ecda0(nameA, info->f1c, nameB, info->f10);
    __security_check_cookie(*cookie);
    return 1;
}
