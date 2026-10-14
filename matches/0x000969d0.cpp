extern const float gZero_969d0;
struct Q_969d0 {
    float Get();
};
struct C_969d0 {
    char pad[0x12c];
    int v;
};
struct B_969d0 {
    char pad[0xc];
    int kind;
};
struct I_969d0 {
    char pad[0xec];
    Q_969d0* q;
    char pad2[0x110 - 0xf0];
    char flag;
    char pad3[3];
    B_969d0* b;
    char pad4[0x148 - 0x118];
    C_969d0* c;
};
struct N_969d0 {
    char pad[8];
    I_969d0* i;
    int kind;
};
N_969d0* __cdecl Target(N_969d0* n) {
    if (!n)
        return 0;
    if (n->kind == 5) {
        I_969d0* i = n->i;
        if (i) {
            if (i->c) {
                if (i->c->v)
                    return (N_969d0*)i->c->v;
            }
            B_969d0* b = i->b;
            if (b && b->kind == 1) {
                if (i->q->Get() > gZero_969d0) {
                    if (!i->flag)
                        return (N_969d0*)b;
                }
            }
        }
    }
    return n;
}
