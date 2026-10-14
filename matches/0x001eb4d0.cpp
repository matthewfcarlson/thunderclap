// Same code shape as 0x001c3830 (propagated; names are from that function)
class Inner_1eb4d0 {
  public:
    void f();
};
class Outer_1eb4d0 {
  public:
    Inner_1eb4d0* p;
    void g();
};
void Outer_1eb4d0::g() {
    p->f();
}