class C {
    char pad0[0x14];
    int a;
    char pad1[0x0c];
    int b;

  public:
    void f(int x, int y);
};
void C::f(int x, int y) {
    a = x;
    b = y;
}