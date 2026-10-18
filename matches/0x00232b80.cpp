struct B_232b80 {
    int f();
};
struct A_232b80 {
    int g(int, int, int, int);
    int target(int, int, int);
};
int A_232b80::target(int a, int b, int c) {
    B_232b80* x = (B_232b80*)b;
    int r = x->f();
    return g(a, b, r, c);
}