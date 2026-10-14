class C_1b8820 {
    char pad[0x34];

  public:
    int a, b, c;
    void f(int*, int*, int*);
};
void C_1b8820::f(int* x, int* y, int* z) {
    *x = a;
    *y = b;
    *z = c;
}