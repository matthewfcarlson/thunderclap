struct Src {
    int a;
    int b;
    int c;
};

struct Tgt {
    char pad[0x18];
    int m18;
    int m1c;
    int m20;
    char Set(const Src* p);
};

char Tgt::Set(const Src* p) {
    m18 = p->a;
    m1c = p->b;
    m20 = p->c;
    return 1;
}
