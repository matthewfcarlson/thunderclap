// Same code shape as 0x00272ba0 (propagated; names are from that function)
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