// Same code shape as 0x001c3830 (propagated; names are from that function)
class Inner_1c3840 {
  public:
    void f(int, int);
};
class Outer_1c3840 {
  public:
    Inner_1c3840* p;
    void g(int, int);
};
void Outer_1c3840::g(int a0, int a1) {
    p->f(a0, a1);
}