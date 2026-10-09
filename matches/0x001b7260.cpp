class C {
  public:
    char pad[0x118];
    int a;
    int b;
    int c;
    char gap[8];
    int d;
    void f(int x, int y, int z, int w);
};
void C::f(int x, int y, int z, int w) {
    a = x;
    b = y;
    c = z;
    d = w;
}