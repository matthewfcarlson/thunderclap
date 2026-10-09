class C {
  public:
    char pad[0x484];
    int a;
    int b;
    int c;
    void f(int* x, int* y, int* z);
};
void C::f(int* x, int* y, int* z) {
    *x = a;
    *y = b;
    *z = c;
}