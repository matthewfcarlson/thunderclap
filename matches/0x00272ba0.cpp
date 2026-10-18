struct C_272ba0 {
    void g(int);
};
struct D {
    char pad[0x14];
    C_272ba0 c;
    void f(int);
};
void D::f(int a0) {
    c.g(a0);
}