struct Y_244a0 {
    void g();
};
struct X_244a0 {
    char pad[4];
    Y_244a0* p;
    void f();
};
void X_244a0::f() {
    p->g();
}