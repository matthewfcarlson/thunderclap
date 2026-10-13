// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 22/22)
// FUN_002ec490 @ 0x002ec490
struct Huft;

struct ZStream {
    char pad0[0x18];
    const char *msg;
    char pad1c[4];
    void *(*zalloc)(void *opaque, unsigned int items, unsigned int size);
    void (*zfree)(void *opaque, void *address);
    void *opaque;
};

extern unsigned int DAT_00430e78[];
extern unsigned int DAT_00430ef8[];
extern unsigned int DAT_00430f78[];
extern unsigned int DAT_00430ff0[];

// equiv-conv: FUN_002ebef0 ecx eax stack stack stack stack stack stack stack stack
int FUN_002ebef0(unsigned int *c, unsigned int *bits, unsigned int n, unsigned int s,
                 unsigned int *base, unsigned int *extra, Huft **t, Huft *hp,
                 unsigned int *hn, unsigned int *v);

int FUN_002ec490(unsigned int nl, unsigned int nd, unsigned int *c, unsigned int *bl,
                 unsigned int *bd, Huft **tl, Huft **td, Huft *hp, ZStream *z)
{
    int r;
    unsigned int hn = 0;
    unsigned int *v = (unsigned int *)z->zalloc(z->opaque, 288, 4);
    if (v == 0)
        return -4;

    r = FUN_002ebef0(c, bl, nl, 257, DAT_00430e78, DAT_00430ef8, tl, hp, &hn, v);
    if (r != 0 || *bl == 0) {
        if (r == -3) {
            z->msg = "oversubscribed literal/length tree";
        } else if (r != -4) {
            z->msg = "incomplete literal/length tree";
            r = -3;
        }
        z->zfree(z->opaque, v);
        return r;
    }

    r = FUN_002ebef0(c + nl, bd, nd, 0, DAT_00430f78, DAT_00430ff0, td, hp, &hn, v);
    if (r != 0 || (*bd == 0 && nl > 257)) {
        if (r == -3) {
            z->msg = "oversubscribed distance tree";
        } else if (r == -5) {
            z->msg = "incomplete distance tree";
            r = -3;
        } else if (r != -4) {
            z->msg = "empty distance tree with lengths";
            r = -3;
        }
        z->zfree(z->opaque, v);
        return r;
    }

    z->zfree(z->opaque, v);
    return 0;
}
