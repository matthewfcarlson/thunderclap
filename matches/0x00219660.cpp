struct G {
    char p[0x14];
    unsigned flags;
};
struct N {
    N* next;
    char a[1];
    unsigned char b;
    char c[2];
    unsigned* d;
    unsigned e[2];
};
struct S {
    char p[0x10];
    G* g;
    char q[0x34];
    N* head;
};
void F1(S*, N*);
void F2(S*, N*, int, int);
void FUN(S* s, unsigned lim) {
    G* g = s->g;
    N* n = s->head;
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