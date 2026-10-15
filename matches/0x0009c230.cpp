extern int g;
class X {
  public:
    void callee(int, int, int, int, int, int, int, int);
    void target(int a, int b, int c, int d, int e, int f, int h);
};
void X::target(int a, int b, int c, int d, int e, int f, int h) {
    callee(g, a, b, c, d, e, f, h);
}