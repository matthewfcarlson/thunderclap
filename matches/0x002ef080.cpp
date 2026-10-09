struct A {
    void one();
};
struct B {
    void two();
};
struct C {
    void three();
};
struct Obj {
    char p70[0x70];
    C c;
    char p_after_c[0x3f];
    B b;
    char p_after_b[0xff];
    A a;
    void target();
    void finish();
};
void Obj::target() {
    a.one();
    b.two();
    c.three();
    finish();
}
