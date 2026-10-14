// Same code shape as 0x000244a0 (propagated; names are from that function)
struct Y_ae990 {
    void g();
};
struct X_ae990 {
    char pad[4];
    Y_ae990* p;
    void f();
};
void X_ae990::f() {
    p->g();
}