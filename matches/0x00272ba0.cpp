struct C_272ba0 {
    void g();
};
struct D {
    char pad[0x14];
    C_272ba0 c;
    void f();
};
void D::f() {
    c.g();
}