struct Src_1151a0 {
    int a;
    int b;
    int c;
};

struct Tgt {
    char pad[0x18];
    int m18;
    int m1c;
    int m20;
    char Set(const Src_1151a0* p);
};

char Tgt::Set(const Src_1151a0* p) {
    m18 = p->a;
    m1c = p->b;
    m20 = p->c;
    return 1;
}
