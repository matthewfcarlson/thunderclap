class A {
  public:
    virtual void f();
    virtual void g();
};
struct B {
    char pad0[0x14];
    int m14;
    A* m18;
    int m1c;
};
struct C {
    A* m0;
    char pad4[0xc];
    B* m10;
    void target();
};
void C::target() {
    B* b = m10;
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