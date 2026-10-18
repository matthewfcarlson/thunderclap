// Same code shape as 0x00272ba0 (propagated; names are from that function)
struct C_272bb0 {
    void g(int);
};
struct D {
    char pad[0x14];
    C_272bb0 c;
    void f(int);
};
void D::f(int a0) {
    c.g(a0);
}