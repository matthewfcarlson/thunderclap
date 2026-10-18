// Same code shape as 0x000244a0 (propagated; names are from that function)
struct Y_af3c0 {
    void g(int);
};
struct X_af3c0 {
    char pad[4];
    Y_af3c0* p;
    void f(int);
};
void X_af3c0::f(int a0) {
    p->g(a0);
}