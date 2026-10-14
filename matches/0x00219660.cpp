struct G_219660 {
    char p[0x14];
    unsigned flags;
};
struct N_219660 {
    N_219660* next;
    char a[1];
    unsigned char b;
    char c[2];
    unsigned* d;
    unsigned e[2];
};
struct S_219660 {
    char p[0x10];
    G_219660* g;
    char q[0x34];
    N_219660* head;
};
void F1(S_219660*, N_219660*);
void F2(S_219660*, N_219660*, int, int);
void FUN(S_219660* s, unsigned lim) {
    G_219660* g = s->g;
    N_219660* n = s->head;
    while (n && (unsigned)n->d >= lim) {
        s->head = n->next;
        if (n->b & (g->flags ^ 3)) {
            F2(s, n, 0x14, 0);
        } else {
            unsigned* o = n->d;
            unsigned* p = n->e;
            p[0] = o[0];
            p[1] = o[1];
            n->d = p;
            F1(s, n);
        }
        n = s->head;
    }
}