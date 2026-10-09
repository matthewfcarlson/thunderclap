// Same code shape as 0x000244a0 (propagated; names are from that function)
struct Y {
    void g();
};
struct X {
    char pad[4];
    Y* p;
    void f();
};
void X::f() {
    p->g();
}