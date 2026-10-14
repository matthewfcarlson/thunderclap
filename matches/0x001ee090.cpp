struct Sub_1ee090 {
    int Check();
};

struct A_1ee090 {
    char pad[0xec];
    Sub_1ee090* s;
    char pad2[0x11c - 0xf0];
    int m11c;
    char pad3[0x128 - 0x120];
    int m128;
};

struct M_1ee090 {
    void F1(A_1ee090* a, int b, A_1ee090* c, int d);
    void F2(A_1ee090* a, const char* n, float f, int z);
    void F3(A_1ee090* a, const char* n);
    void Run(A_1ee090* a, A_1ee090* b, A_1ee090* c, int d);
};

void M_1ee090::Run(A_1ee090* a, A_1ee090* b, A_1ee090* c, int d) {
    if (b && b->m128) {
        F1(a, b->m128, c, d);
    }
    if (a && a->m11c && b && b->m11c && c && c->s && c->s->Check()) {
        F2(c, "impact_big", 100.0f, 0);
        F3(b, "impact_big");
    }
}
