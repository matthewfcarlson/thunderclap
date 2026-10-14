// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 8/8)
// FUN_00215350 @ 0x00215350
// equiv-conv: FUN_00215350 eax edx
struct Elem {
    int a, b;
};

struct Chain {
    Chain *next;
    int f4;
    Elem *p;
};

struct Pair {
    Elem *a;
    Elem *b;
    char pad8[8];
};

struct Heap {
    char pad0[8];
    Elem *f8;
    int fc;
    char pad10[4];
    Pair *last;
    char pad18[4];
    Elem *base;
    char pad20[8];
    Pair *first;
    char pad2c[0x48 - 0x2c];
    Chain *chain;
};

void __cdecl FUN_00215350(Heap *h, Elem *old)
{
    h->f8 = h->base + (h->f8 - old);
    for (Chain *c = h->chain; c != 0; c = c->next)
        c->p = h->base + (c->p - old);
    for (Pair *p = h->first; p <= h->last; p++) {
        p->b = h->base + (p->b - old);
        p->a = h->base + (p->a - old);
    }
    h->fc = *(int *)h->last;
}
