// Same code shape as 0x000244a0 (propagated; names are from that function)
struct Y_3245a0 {
    void g();
};
struct X_3245a0 {
    char pad[4];
    Y_3245a0* p;
    void f();
};
void X_3245a0::f() {
    p->g();
}