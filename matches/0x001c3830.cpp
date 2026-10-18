class Inner_1c3830 {
  public:
    void f(int, int);
};
class Outer_1c3830 {
  public:
    Inner_1c3830* p;
    void g(int, int);
};
void Outer_1c3830::g(int a0, int a1) {
    p->f(a0, a1);
}