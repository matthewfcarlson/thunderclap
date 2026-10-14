class Inner_1c3830 {
  public:
    void f();
};
class Outer_1c3830 {
  public:
    Inner_1c3830* p;
    void g();
};
void Outer_1c3830::g() {
    p->f();
}