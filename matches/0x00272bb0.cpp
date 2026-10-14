// Same code shape as 0x00272ba0 (propagated; names are from that function)
struct C_272bb0 {
    void g();
};
struct D {
    char pad[0x14];
    C_272bb0 c;
    void f();
};
void D::f() {
    c.g();
}