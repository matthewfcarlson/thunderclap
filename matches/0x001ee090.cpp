struct Sub {
    int Check();
};

struct A {
    char pad[0xec];
    Sub* s;
    char pad2[0x11c - 0xf0];
    int m11c;
    char pad3[0x128 - 0x120];
    int m128;
};

struct M {
    void F1(A* a, int b, A* c, int d);
    void F2(A* a, const char* n, float f, int z);
    void F3(A* a, const char* n);
    void Run(A* a, A* b, A* c, int d);
};

void M::Run(A* a, A* b, A* c, int d) {
    if (b && b->m128) {
        F1(a, b->m128, c, d);
    }
    if (a && a->m11c && b && b->m11c && c && c->s && c->s->Check()) {
        F2(c, "impact_big", 100.0f, 0);
        F3(b, "impact_big");
    }
}
