struct H {
    int get();
};
struct C {
    char pad[0x44];
    H* h;
    void f(int a, int b, int c);
    void other(int, int, int, int);
};
void C::f(int a, int b, int c) {
    int x = h->get();
    other(x, a, b, c);
}