struct B_232b80 {
    int f();
};
struct A_232b80 {
    void g(int, int, int, int);
    void target(int, int, int);
};
void A_232b80::target(int a, int b, int c) {
    B_232b80* x = (B_232b80*)b;
    int r = x->f();
    g(a, b, r, c);
}