// Same code shape as 0x000244a0 (propagated; names are from that function)
struct Y_ae8a0 {
    void g();
};
struct X_ae8a0 {
    char pad[4];
    Y_ae8a0* p;
    void f();
};
void X_ae8a0::f() {
    p->g();
}