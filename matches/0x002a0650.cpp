struct H {
    int get();
};
struct C_2a0650 {
    char pad[0x44];
    H* h;
    void f(int a, int b, int c);
    void other(int, int, int, int);
};
void C_2a0650::f(int a, int b, int c) {
    int x = h->get();
    other(x, a, b, c);
}