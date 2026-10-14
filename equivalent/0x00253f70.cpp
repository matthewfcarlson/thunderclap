// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00253f70 @ 0x00253f70
struct Inner3c_253f70 {
    char pad0[0x90];
    char v90[0xc];
    char v9c[0xc];
    int fa8;
};
struct Pair_253f70 { int a; int b; };
struct Inner4 {
    char pad0[0x38];
    Pair_253f70 *p38;
};
struct Src_253f70 {
    char pad0[4];
    Inner4 *f4;
    char pad8[0x34 - 8];
    int f34;
    char pad38[4];
    Inner3c_253f70 *f3c;
};

void *FUN_0024b0c0(int a, int b);
void FUN_0024cb50(void *h, void *v);
void FUN_0024cb70(void *h, void *v);
void FUN_0024c910(void *h, int a, int b);
void FUN_0024c950(void *h, int v);

void __stdcall FUN_00253f70(Src_253f70 *s)
{
    void *h = FUN_0024b0c0(s->f34, 0);
    if (h) {
        FUN_0024cb50(h, (char *)s->f3c + 0x90);
        FUN_0024cb70(h, (char *)s->f3c + 0x9c);
        Pair_253f70 *p = s->f4->p38;
        FUN_0024c910(h, p->a, p->b);
        FUN_0024c950(h, s->f3c->fa8);
    }
}
