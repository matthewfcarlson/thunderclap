struct C {
    void g();
};
struct D {
    char pad[0x14];
    C c;
    void f();
};
void D::f() {
    c.g();
}