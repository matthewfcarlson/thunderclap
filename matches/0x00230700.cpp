class X;
class Y {
  public:
    void f(int, X*);
};
class X {
  public:
    void g(int a, Y* y);
};
void X::g(int a, Y* y) {
    y->f(a, this);
}