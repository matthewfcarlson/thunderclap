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