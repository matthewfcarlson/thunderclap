class C {
    char pad[0xd0];

  public:
    unsigned a, b;
    void F(unsigned* x, unsigned* y);
};
void C::F(unsigned* x, unsigned* y) {
    *x = a;
    *y = b;
}