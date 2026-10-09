extern const float gZero;
struct Q {
    float Get();
};
struct C {
    char pad[0x12c];
    int v;
};
struct B {
    char pad[0xc];
    int kind;
};
struct I {
    char pad[0xec];
    Q* q;
    char pad2[0x110 - 0xf0];
    char flag;
    char pad3[3];
    B* b;
    char pad4[0x148 - 0x118];
    C* c;
};
struct N {
    char pad[8];
    I* i;
    int kind;
};
N* __cdecl Target(N* n) {
    if (!n)
        return 0;
    if (n->kind == 5) {
        I* i = n->i;
        if (i) {
            if (i->c) {
                if (i->c->v)
                    return (N*)i->c->v;
            }
            B* b = i->b;
            if (b && b->kind == 1) {
                if (i->q->Get() > gZero) {
                    if (!i->flag)
                        return (N*)b;
                }
            }
        }
    }
    return n;
}
