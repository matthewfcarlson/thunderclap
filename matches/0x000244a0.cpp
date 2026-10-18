struct Y_244a0 {
    void g(int);
};
struct X_244a0 {
    char pad[4];
    Y_244a0* p;
    void f(int);
};
void X_244a0::f(int a0) {
    p->g(a0);
}