// Same code shape as 0x000244a0 (propagated; names are from that function)
struct Y_ae980 {
    void g();
};
struct X_ae980 {
    char pad[4];
    Y_ae980* p;
    void f();
};
void X_ae980::f() {
    p->g();
}