// Same code shape as 0x000244a0 (propagated; names are from that function)
struct Y_324590 {
    void g();
};
struct X_324590 {
    char pad[4];
    Y_324590* p;
    void f();
};
void X_324590::f() {
    p->g();
}