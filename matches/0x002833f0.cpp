class A_2833f0 {
  public:
    virtual void f();
    virtual void g();
};
struct B_2833f0 {
    char pad0[0x14];
    int m14;
    A_2833f0* m18;
    int m1c;
};
struct C_2833f0 {
    A_2833f0* m0;
    char pad4[0xc];
    B_2833f0* m10;
    void target();
};
void C_2833f0::target() {
    B_2833f0* b = m10;
    if (b->m18) {
        b->m18->g();
        b->m18 = 0;
    }
    b->m1c = 0;
    b->m14 = 0xf;
    if (m0) {
        m0->g();
        m0 = 0;
    }
}