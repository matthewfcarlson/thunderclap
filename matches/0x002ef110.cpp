struct A_2ef110 {
    void f1();
};
struct B_2ef110 {
    void f2();
};
struct D {
    void f3();
};
struct C_2ef110 {
    char p0[0x70];
    A_2ef110 a;
    char p1[0x3f];
    B_2ef110 b;
    char p2[0xff];
    D c;
    C_2ef110* target(unsigned char flag);
    void cleanup();
};
void destroy(C_2ef110*);
C_2ef110* C_2ef110::target(unsigned char flag) {
    c.f3();
    b.f2();
    a.f1();
    cleanup();
    if (flag & 1)
        destroy(this);
    return this;
}