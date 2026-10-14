// Same code shape as 0x001c3830 (propagated; names are from that function)
class Inner_1c3840 {
  public:
    void f();
};
class Outer_1c3840 {
  public:
    Inner_1c3840* p;
    void g();
};
void Outer_1c3840::g() {
    p->f();
}