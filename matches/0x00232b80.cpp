struct B {
    int f();
};
struct A {
    void g(int, int, int, int);
    void target(int, int, int);
};
void A::target(int a, int b, int c) {
    B* x = (B*)b;
    int r = x->f();
    g(a, b, r, c);
}