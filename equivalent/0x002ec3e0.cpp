// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_002ec3e0 @ 0x002ec3e0
struct Huft;

struct ZStream {
    char pad0[0x18];
    const char *msg;
    char pad1c[4];
    void *(*zalloc)(void *opaque, unsigned int items, unsigned int size);
    void (*zfree)(void *opaque, void *address);
    void *opaque;
};

// equiv-conv: FUN_002ebef0 ecx eax stack stack stack stack stack stack stack stack
int FUN_002ebef0(unsigned int *c, unsigned int *bits, unsigned int n, unsigned int s,
                 unsigned int *base, unsigned int *extra, Huft **t, Huft *hp,
                 unsigned int *hn, unsigned int *v);

int FUN_002ec3e0(unsigned int *c, unsigned int *bb, Huft **tb, Huft *hp, ZStream *z)
{
    int r;
    unsigned int hn = 0;
    unsigned int *v = (unsigned int *)z->zalloc(z->opaque, 19, 4);
    if (v == 0)
        return -4;

    r = FUN_002ebef0(c, bb, 19, 19, 0, 0, tb, hp, &hn, v);
    if (r == -3) {
        z->msg = "oversubscribed dynamic bit lengths tree";
    } else if (r == -5 || *bb == 0) {
        z->msg = "incomplete dynamic bit lengths tree";
        r = -3;
    }
    z->zfree(z->opaque, v);
    return r;
}
