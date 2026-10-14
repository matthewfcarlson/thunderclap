// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 8/8)
// FUN_00215350 @ 0x00215350
// equiv-conv: FUN_00215350 eax edx
struct Elem_215350 {
    int a, b;
};

struct Chain_215350 {
    Chain_215350 *next;
    int f4;
    Elem_215350 *p;
};

struct Pair_215350 {
    Elem_215350 *a;
    Elem_215350 *b;
    char pad8[8];
};

struct Heap_215350 {
    char pad0[8];
    Elem_215350 *f8;
    int fc;
    char pad10[4];
    Pair_215350 *last;
    char pad18[4];
    Elem_215350 *base;
    char pad20[8];
    Pair_215350 *first;
    char pad2c[0x48 - 0x2c];
    Chain_215350 *chain;
};

void __cdecl FUN_00215350(Heap_215350 *h, Elem_215350 *old)
{
    h->f8 = h->base + (h->f8 - old);
    for (Chain_215350 *c = h->chain; c != 0; c = c->next)
        c->p = h->base + (c->p - old);
    for (Pair_215350 *p = h->first; p <= h->last; p++) {
        p->b = h->base + (p->b - old);
        p->a = h->base + (p->a - old);
    }
    h->fc = *(int *)h->last;
}
