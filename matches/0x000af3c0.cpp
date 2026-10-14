// Same code shape as 0x000244a0 (propagated; names are from that function)
struct Y_af3c0 {
    void g();
};
struct X_af3c0 {
    char pad[4];
    Y_af3c0* p;
    void f();
};
void X_af3c0::f() {
    p->g();
}