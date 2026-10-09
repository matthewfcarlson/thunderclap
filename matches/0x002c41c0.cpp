class C {
    char pad[0x64];

  public:
    int a, b, c;
    void f(int* x, int* y, int* z);
};
void C::f(int* x, int* y, int* z) {
    *x = a;
    *y = b;
    *z = c;
}