// Same code shape as 0x000244a0 (propagated; names are from that function)
struct Y_ae8a0 {
    void g(int);
};
struct X_ae8a0 {
    char pad[4];
    Y_ae8a0* p;
    void f(int);
};
void X_ae8a0::f(int a0) {
    p->g(a0);
}